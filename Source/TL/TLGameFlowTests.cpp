#include "TLTestBase.h"
#include "TLGameMode.h"
#include "TLGameState.h"
#include "TLPlayerState.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLGameFlowPhaseTransitionsTest, "TL.GameFlow.PhaseTransitions",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLGameFlowPhaseTransitionsTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_GameFlow_PhaseTransitions"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLGameMode* GameMode = NewObject<ATLGameMode>();
	ATLGameState* GameState = NewObject<ATLGameState>();
	GameMode->GamePhase = EGamePhase::Setup;
	GameState->CurrentPhase = EGamePhase::Setup;

	TestHelper.LogGameState(TEXT("Initial"), GameState);

	TestHelper.LogSection(TEXT("EVENT 1: Transition to LordSelection Phase"));

	EGamePhase OldPhase = GameMode->GamePhase;
	GameMode->ChangePhase(EGamePhase::LordSelection);

	TestHelper.LogStateChange(TEXT("Game Phase"),
		TestHelper.FormatPhase(OldPhase),
		TestHelper.FormatPhase(GameMode->GamePhase));

	TestHelper.LogSection(TEXT("EVENT 2: Transition to Action Phase"));

	OldPhase = GameMode->GamePhase;
	GameMode->ChangePhase(EGamePhase::Action);

	TestHelper.LogStateChange(TEXT("Game Phase"),
		TestHelper.FormatPhase(OldPhase),
		TestHelper.FormatPhase(GameMode->GamePhase));

	TestHelper.LogSection(TEXT("EVENT 3: Transition to Production Phase"));

	OldPhase = GameMode->GamePhase;
	GameMode->ChangePhase(EGamePhase::Production);

	TestHelper.LogStateChange(TEXT("Game Phase"),
		TestHelper.FormatPhase(OldPhase),
		TestHelper.FormatPhase(GameMode->GamePhase));

	TestHelper.LogSection(TEXT("EVENT 4: Transition to Scoring Phase"));

	OldPhase = GameMode->GamePhase;
	GameMode->ChangePhase(EGamePhase::Scoring);

	TestHelper.LogStateChange(TEXT("Game Phase"),
		TestHelper.FormatPhase(OldPhase),
		TestHelper.FormatPhase(GameMode->GamePhase));

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogGameState(TEXT("Final"), GameState);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual((int32)GameMode->GamePhase, (int32)EGamePhase::Scoring, TEXT("Game Phase = Scoring"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLGameFlowRoundProgressionTest, "TL.GameFlow.RoundProgression",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLGameFlowRoundProgressionTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_GameFlow_RoundProgression"));

	UWorld* World = GEngine->GetWorldContexts()[0].World();
	if (!TestHelper.AssertNotNull(World, TEXT("World")))
	{
		TestHelper.EndTest(false);
		return false;
	}

	TestHelper.LogSection(TEXT("SETUP"));

	ATLGameMode* GameMode = NewObject<ATLGameMode>();
	ATLGameState* GameState = NewObject<ATLGameState>();
	GameMode->CurrentRound = 0;
	GameMode->MaxRounds = 5;
	GameState->CurrentRound = 0;

	ATLPlayerState* Player1 = NewObject<ATLPlayerState>();
	ATLPlayerState* Player2 = NewObject<ATLPlayerState>();
	GameMode->TurnOrder.Add(Player1);
	GameMode->TurnOrder.Add(Player2);

	TestHelper.LogGameState(TEXT("Initial"), GameState);
	TestHelper.LogInfo(FString::Printf(TEXT("Max Rounds: %d"), GameMode->MaxRounds));

	TestHelper.LogSection(TEXT("EVENT 1: Start Round 1"));

	int32 OldRound = GameMode->CurrentRound;
	GameMode->StartRound();
	GameState->IncrementRound();

	TestHelper.LogStateChange(TEXT("Current Round"), FString::FromInt(OldRound), FString::FromInt(GameMode->CurrentRound));
	TestHelper.LogInfo(FString::Printf(TEXT("Player 1 Has Passed: %s"), Player1->bHasPassed ? TEXT("Yes") : TEXT("No")));
	TestHelper.LogInfo(FString::Printf(TEXT("Player 2 Has Passed: %s"), Player2->bHasPassed ? TEXT("Yes") : TEXT("No")));

	TestHelper.LogSection(TEXT("EVENT 2: End Round 1"));

	GameMode->EndRound();

	TestHelper.LogInfo(TEXT("Round ended"));

	TestHelper.LogSection(TEXT("EVENT 3: Start Round 2"));

	OldRound = GameMode->CurrentRound;
	GameMode->StartRound();
	GameState->IncrementRound();

	TestHelper.LogStateChange(TEXT("Current Round"), FString::FromInt(OldRound), FString::FromInt(GameMode->CurrentRound));

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogGameState(TEXT("Final"), GameState);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(GameMode->CurrentRound, 2, TEXT("Current Round = 2"));
	bSuccess &= TestHelper.AssertEqual(GameState->CurrentRound, 2, TEXT("GameState Round = 2"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTLGameFlowVictoryPointsTest, "TL.GameFlow.VictoryPoints",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTLGameFlowVictoryPointsTest::RunTest(const FString& Parameters)
{
	FTLTestBase TestHelper(this);
	TestHelper.BeginTest(TEXT("Test_GameFlow_VictoryPoints"));

	TestHelper.LogSection(TEXT("SETUP"));

	ATLPlayerState* Player = NewObject<ATLPlayerState>();
	Player->VictoryPoints = 0;
	TestHelper.LogPlayerState(TEXT("Initial"), Player);

	TestHelper.LogSection(TEXT("EVENT 1: Award 3 Glory Points (1st Place)"));

	int32 OldVP = Player->VictoryPoints;
	Player->AddVictoryPoints(3);

	TestHelper.LogStateChange(TEXT("Victory Points"), FString::FromInt(OldVP), FString::FromInt(Player->VictoryPoints));

	TestHelper.LogSection(TEXT("EVENT 2: Award 5 VP from Contract"));

	OldVP = Player->VictoryPoints;
	Player->AddVictoryPoints(5);

	TestHelper.LogStateChange(TEXT("Victory Points"), FString::FromInt(OldVP), FString::FromInt(Player->VictoryPoints));

	TestHelper.LogSection(TEXT("FINAL STATE VERIFICATION"));

	TestHelper.LogPlayerState(TEXT("Final"), Player);

	bool bSuccess = true;
	bSuccess &= TestHelper.AssertEqual(Player->VictoryPoints, 8, TEXT("Victory Points = 8 (3 + 5)"));

	TestHelper.EndTest(bSuccess);
	return bSuccess;
}
