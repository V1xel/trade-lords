#include "TLGameMode.h"
#include "TLPlayerState.h"
#include "TLGameState.h"

ATLGameMode::ATLGameMode()
{
	NumPlayers = 4;
	CurrentRound = 0;
	MaxRounds = 5;
	GamePhase = EGamePhase::Setup;
	ActivePlayerIndex = 0;

	GameStateClass = ATLGameState::StaticClass();
	PlayerStateClass = ATLPlayerState::StaticClass();
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
	ActivePlayerIndex = 0;

	for (ATLPlayerState* Player : TurnOrder)
	{
		if (Player)
		{
			Player->ResetForNewRound();
		}
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
	OnPhaseChanged.Broadcast(NewPhase);

	ATLGameState* GS = GetGameState<ATLGameState>();
	if (GS)
	{
		GS->SetPhase(NewPhase);
	}
}

void ATLGameMode::EndGame()
{
	GamePhase = EGamePhase::GameEnd;
	OnGameEnd.Broadcast();
}

void ATLGameMode::NextPlayerTurn()
{
	if (TurnOrder.Num() == 0)
	{
		return;
	}

	ActivePlayerIndex = (ActivePlayerIndex + 1) % TurnOrder.Num();
}

ATLPlayerState* ATLGameMode::GetActivePlayer() const
{
	if (ActivePlayerIndex >= 0 && ActivePlayerIndex < TurnOrder.Num())
	{
		return TurnOrder[ActivePlayerIndex];
	}

	return nullptr;
}

void ATLGameMode::DetermineTurnOrder()
{
	if (TurnOrder.Num() > 1)
	{
		int32 LastIndex = TurnOrder.Num() - 1;
		for (int32 i = LastIndex; i > 0; i--)
		{
			int32 j = FMath::RandRange(0, i);
			TurnOrder.Swap(i, j);
		}
	}
}
