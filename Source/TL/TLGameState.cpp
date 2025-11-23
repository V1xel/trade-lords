#include "TLGameState.h"
#include "MarketComponent.h"
#include "ContractManagerComponent.h"

ATLGameState::ATLGameState()
{
	CurrentRound = 0;
	CurrentPhase = EGamePhase::Setup;

	MarketComponent = CreateDefaultSubobject<UMarketComponent>(TEXT("MarketComponent"));
	ContractManager = CreateDefaultSubobject<UContractManagerComponent>(TEXT("ContractManager"));
}

void ATLGameState::SetPhase(EGamePhase NewPhase)
{
	CurrentPhase = NewPhase;
	OnPhaseChanged.Broadcast(NewPhase);
}

void ATLGameState::IncrementRound()
{
	CurrentRound++;
}

void ATLGameState::AddHexToGrid(AHexTile* Hex)
{
	if (Hex && !HexGrid.Contains(Hex))
	{
		HexGrid.Add(Hex);
	}
}
