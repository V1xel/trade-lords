#include "TLGameMode.h"
#include "TLGameState.h"
#include "TLPlayerState.h"
#include "../Hexes/HexTile.h"
#include "../Units/Unit.h"
#include "../Market/MarketComponent.h"
#include "../Contracts/ContractManagerComponent.h"
#include "../Contracts/ContractDefinition.h"

ATLGameMode::ATLGameMode()
{
	GameStateClass = ATLGameState::StaticClass();
	PlayerStateClass = ATLPlayerState::StaticClass();

	TotalPlayers = 2;
	CurrentRound = 0;
	MaxRounds = 6;
	GamePhase = EGamePhase::Setup;
}

void ATLGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ATLGameMode::StartGame()
{
	CurrentRound = 0;
	GamePhase = EGamePhase::Setup;
	OnGameStart.Broadcast();
}

void ATLGameMode::StartRound()
{
	CurrentRound++;

	ATLGameState* GS = GetGameState<ATLGameState>();
	if (GS)
	{
		GS->IncrementRound();
	}

	OnRoundStart.Broadcast(CurrentRound);
}

void ATLGameMode::EndRound()
{
	OnRoundEnd.Broadcast(CurrentRound);

	if (CurrentRound >= MaxRounds)
	{
		EndGame();
	}
}

void ATLGameMode::ChangePhase(EGamePhase NewPhase)
{
	GamePhase = NewPhase;

	ATLGameState* GS = GetGameState<ATLGameState>();
	if (GS)
	{
		GS->SetPhase(NewPhase);
	}

	OnPhaseChanged.Broadcast(NewPhase);
}

void ATLGameMode::EndGame()
{
	ChangePhase(EGamePhase::GameEnd);
	OnGameEnd.Broadcast();
}

void ATLGameMode::RunProductionPhase()
{
	for (ATLPlayerState* Player : TurnOrder)
	{
		if (!Player) continue;

		for (AUnit* Unit : Player->OwnedUnits)
		{
			if (Unit)
			{
				Unit->Produce();
				Player->AddResource(Unit->ProducesResource, 1);

				if (Unit->GeneratesIncome > 0)
				{
					Player->AddGold(Unit->GeneratesIncome);
				}
			}
		}
	}
}

void ATLGameMode::ProcessUnitPlacement(ATLPlayerState* Player, AHexTile* Hex, TSubclassOf<AUnit> UnitClass)
{
	if (!CanPlaceUnit(Player, Hex, UnitClass))
	{
		return;
	}

	AUnit* NewUnit = GetWorld()->SpawnActor<AUnit>(UnitClass);
	if (!NewUnit)
	{
		return;
	}

	int32 TotalCost = NewUnit->UnitCost + Hex->TerrainCost;
	Player->SpendGold(TotalCost);

	NewUnit->SetOwner(Player);
	NewUnit->SetPlacedHex(Hex);
	Hex->PlaceUnit(NewUnit, Player);

	Player->AddUnit(NewUnit);
	Player->AddHex(Hex);

	NewUnit->SetActorLocation(Hex->GetActorLocation() + FVector(0, 0, 50));
}

bool ATLGameMode::CanPlaceUnit(ATLPlayerState* Player, AHexTile* Hex, TSubclassOf<AUnit> UnitClass) const
{
	if (!Player || !Hex || !UnitClass)
	{
		return false;
	}

	if (Hex->bIsOccupied)
	{
		return false;
	}

	AUnit* TempUnit = UnitClass.GetDefaultObject();
	if (!TempUnit)
	{
		return false;
	}

	int32 TotalCost = TempUnit->UnitCost + Hex->TerrainCost;
	return Player->Gold >= TotalCost;
}

void ATLGameMode::ProcessBuyResource(ATLPlayerState* Player, EResourceType Resource, int32 Amount)
{
	ATLGameState* GS = GetGameState<ATLGameState>();
	if (!GS || !GS->MarketComponent || !Player)
	{
		return;
	}

	int32 Price = GS->MarketComponent->GetPrice(Resource);
	int32 TotalCost = Price * Amount;

	if (Player->SpendGold(TotalCost))
	{
		Player->AddResource(Resource, Amount);
		GS->MarketComponent->BuyResource(Resource, Amount, Player);
		GS->MarketComponent->AdjustPrice(Resource, Amount);
	}
}

void ATLGameMode::ProcessSellResource(ATLPlayerState* Player, EResourceType Resource, int32 Amount)
{
	ATLGameState* GS = GetGameState<ATLGameState>();
	if (!GS || !GS->MarketComponent || !Player)
	{
		return;
	}

	if (!Player->SpendResource(Resource, Amount))
	{
		return;
	}

	int32 Price = GS->MarketComponent->GetPrice(Resource);
	int32 TotalGain = Price * Amount;

	Player->AddGold(TotalGain);
	GS->MarketComponent->SellResource(Resource, Amount, Player);
	GS->MarketComponent->AdjustPrice(Resource, -Amount);
}

void ATLGameMode::ProcessTakeContract(ATLPlayerState* Player, UContractDefinition* Contract)
{
	ATLGameState* GS = GetGameState<ATLGameState>();
	if (!GS || !GS->ContractManager || !Player || !Contract)
	{
		return;
	}

	if (GS->ContractManager->TakeContract(Player, Contract))
	{
		Player->ActiveContracts.Add(Contract);
	}
}

void ATLGameMode::ProcessFulfillContract(ATLPlayerState* Player, UContractDefinition* Contract)
{
	if (!CanFulfillContract(Player, Contract))
	{
		return;
	}

	for (const TPair<EResourceType, int32>& Requirement : Contract->RequiredResources)
	{
		Player->SpendResource(Requirement.Key, Requirement.Value);
	}

	Player->AddGold(Contract->GoldReward);
	Player->AddVictoryPoints(Contract->VictoryPoints);

	if (Contract->ImportGoodAmount > 0)
	{
		Player->AddResource(Contract->ImportGoodReward, Contract->ImportGoodAmount);
	}

	Player->ActiveContracts.Remove(Contract);

	ATLGameState* GS = GetGameState<ATLGameState>();
	if (GS && GS->ContractManager)
	{
		GS->ContractManager->FulfillContract(Player, Contract);
	}
}

bool ATLGameMode::CanFulfillContract(ATLPlayerState* Player, UContractDefinition* Contract) const
{
	if (!Player || !Contract)
	{
		return false;
	}

	if (!Player->ActiveContracts.Contains(Contract))
	{
		return false;
	}

	for (const TPair<EResourceType, int32>& Requirement : Contract->RequiredResources)
	{
		if (Player->GetResourceAmount(Requirement.Key) < Requirement.Value)
		{
			return false;
		}
	}

	return true;
}
