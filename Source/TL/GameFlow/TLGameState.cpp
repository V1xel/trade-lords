#include "TLGameState.h"
#include "../Market/MarketComponent.h"
#include "../Contracts/ContractManagerComponent.h"

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
