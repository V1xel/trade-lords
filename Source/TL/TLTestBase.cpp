#include "TLTestBase.h"
#include "TLGameMode.h"
#include "TLGameState.h"
#include "TLPlayerState.h"
#include "HexTile.h"
#include "Unit.h"

FTLTestBase::FTLTestBase(FAutomationTestBase* InTestRunner)
	: TestRunner(InTestRunner)
{
}

void FTLTestBase::LogHeader(const FString& TestName)
{
	UE_LOG(LogTemp, Display, TEXT("========================================"));
	UE_LOG(LogTemp, Display, TEXT("TEST: %s"), *TestName);
	UE_LOG(LogTemp, Display, TEXT("========================================"));
}

void FTLTestBase::LogSection(const FString& SectionName)
{
	UE_LOG(LogTemp, Display, TEXT(""));
	UE_LOG(LogTemp, Display, TEXT("--- %s ---"), *SectionName);
}

void FTLTestBase::LogEvent(const FString& EventName)
{
	UE_LOG(LogTemp, Display, TEXT(""));
	UE_LOG(LogTemp, Display, TEXT("EVENT: %s"), *EventName);
}

void FTLTestBase::LogStateChange(const FString& Property, const FString& OldValue, const FString& NewValue)
{
	UE_LOG(LogTemp, Display, TEXT("  STATE CHANGE: %s: %s -> %s"), *Property, *OldValue, *NewValue);
}

void FTLTestBase::LogExpectedState(const FString& Property, const FString& Value)
{
	UE_LOG(LogTemp, Display, TEXT("  EXPECTED: %s = %s"), *Property, *Value);
}

void FTLTestBase::LogAssertion(const FString& AssertionText, bool bPassed)
{
	if (bPassed)
	{
		UE_LOG(LogTemp, Display, TEXT("  ASSERTION PASSED: %s"), *AssertionText);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("  ASSERTION FAILED: %s"), *AssertionText);
	}
}

void FTLTestBase::LogError(const FString& ErrorText)
{
	UE_LOG(LogTemp, Error, TEXT("  ERROR: %s"), *ErrorText);
}

void FTLTestBase::LogInfo(const FString& InfoText)
{
	UE_LOG(LogTemp, Display, TEXT("  INFO: %s"), *InfoText);
}

void FTLTestBase::LogPlayerState(const FString& Prefix, ATLPlayerState* Player)
{
	if (!Player)
	{
		LogError(FString::Printf(TEXT("%s Player is NULL"), *Prefix));
		return;
	}

	LogInfo(FString::Printf(TEXT("%s Player State:"), *Prefix));
	LogInfo(FString::Printf(TEXT("  Gold: £%d"), Player->Gold));
	LogInfo(FString::Printf(TEXT("  Victory Points: %d"), Player->VictoryPoints));
	LogInfo(FString::Printf(TEXT("  Available Merchants: %d"), Player->AvailableMerchants));
	LogInfo(FString::Printf(TEXT("  Used Merchants: %d"), Player->UsedMerchants));
	LogInfo(FString::Printf(TEXT("  Owned Units: %d"), Player->OwnedUnits.Num()));
	LogInfo(FString::Printf(TEXT("  Owned Hexes: %d"), Player->OwnedHexes.Num()));
	LogInfo(FString::Printf(TEXT("  Has Passed: %s"), Player->bHasPassed ? TEXT("Yes") : TEXT("No")));

	if (Player->ResourceStock.Num() > 0)
	{
		LogInfo(TEXT("  Resources:"));
		for (auto& Pair : Player->ResourceStock)
		{
			LogInfo(FString::Printf(TEXT("    %s: %d"), *FormatResource(Pair.Key), Pair.Value));
		}
	}
	else
	{
		LogInfo(TEXT("  Resources: None"));
	}
}

void FTLTestBase::LogGameState(const FString& Prefix, ATLGameState* GameState)
{
	if (!GameState)
	{
		LogError(FString::Printf(TEXT("%s GameState is NULL"), *Prefix));
		return;
	}

	LogInfo(FString::Printf(TEXT("%s Game State:"), *Prefix));
	LogInfo(FString::Printf(TEXT("  Round: %d"), GameState->CurrentRound));
	LogInfo(FString::Printf(TEXT("  Phase: %s"), *FormatPhase(GameState->CurrentPhase)));
	LogInfo(FString::Printf(TEXT("  Hex Grid Size: %d"), GameState->HexGrid.Num()));
	LogInfo(FString::Printf(TEXT("  Available Lords: %d"), GameState->AvailableLords.Num()));
}

void FTLTestBase::LogHexState(const FString& Prefix, AHexTile* Hex)
{
	if (!Hex)
	{
		LogError(FString::Printf(TEXT("%s Hex is NULL"), *Prefix));
		return;
	}

	LogInfo(FString::Printf(TEXT("%s Hex State:"), *Prefix));
	LogInfo(FString::Printf(TEXT("  Terrain Cost: £%d"), Hex->TerrainCost));
	LogInfo(FString::Printf(TEXT("  Is Occupied: %s"), Hex->bIsOccupied ? TEXT("Yes") : TEXT("No")));
	LogInfo(FString::Printf(TEXT("  Is River Delta: %s"), Hex->bIsRiverDelta ? TEXT("Yes") : TEXT("No")));
	LogInfo(FString::Printf(TEXT("  Adjacent Hexes: %d"), Hex->AdjacentHexes.Num()));
}

void FTLTestBase::LogUnitState(const FString& Prefix, AUnit* Unit)
{
	if (!Unit)
	{
		LogError(FString::Printf(TEXT("%s Unit is NULL"), *Prefix));
		return;
	}

	LogInfo(FString::Printf(TEXT("%s Unit State:"), *Prefix));
	LogInfo(FString::Printf(TEXT("  Unit Cost: £%d"), Unit->UnitCost));
	LogInfo(FString::Printf(TEXT("  Generates Income: £%d"), Unit->GeneratesIncome));
	LogInfo(FString::Printf(TEXT("  Is Upgraded: %s"), Unit->bIsUpgraded ? TEXT("Yes") : TEXT("No")));
	LogInfo(FString::Printf(TEXT("  Current Income: £%d"), Unit->GetCurrentIncome()));
}

bool FTLTestBase::AssertEqual(int32 Actual, int32 Expected, const FString& Description)
{
	bool bPassed = Actual == Expected;
	FString Message = FString::Printf(TEXT("%s (Expected: %d, Actual: %d)"), *Description, Expected, Actual);
	LogAssertion(Message, bPassed);

	if (TestRunner)
	{
		TestRunner->TestEqual(Description, Actual, Expected);
	}

	return bPassed;
}

bool FTLTestBase::AssertEqual(bool Actual, bool Expected, const FString& Description)
{
	bool bPassed = Actual == Expected;
	FString Message = FString::Printf(TEXT("%s (Expected: %s, Actual: %s)"),
		*Description,
		Expected ? TEXT("true") : TEXT("false"),
		Actual ? TEXT("true") : TEXT("false"));
	LogAssertion(Message, bPassed);

	if (TestRunner)
	{
		TestRunner->TestEqual(Description, Actual, Expected);
	}

	return bPassed;
}

bool FTLTestBase::AssertNotNull(UObject* Object, const FString& Description)
{
	bool bPassed = Object != nullptr;
	FString Message = FString::Printf(TEXT("%s is not null"), *Description);
	LogAssertion(Message, bPassed);

	if (TestRunner)
	{
		TestRunner->TestNotNull(Description, Object);
	}

	return bPassed;
}

bool FTLTestBase::AssertNull(UObject* Object, const FString& Description)
{
	bool bPassed = Object == nullptr;
	FString Message = FString::Printf(TEXT("%s is null"), *Description);
	LogAssertion(Message, bPassed);

	if (TestRunner)
	{
		TestRunner->TestNull(Description, Object);
	}

	return bPassed;
}

void FTLTestBase::BeginTest(const FString& TestName)
{
	LogHeader(TestName);
	LogSection(TEXT("INITIAL STATE"));
}

void FTLTestBase::EndTest(bool bSuccess)
{
	LogSection(TEXT("TEST COMPLETE"));
	if (bSuccess)
	{
		LogInfo(TEXT("TEST PASSED"));
	}
	else
	{
		LogError(TEXT("TEST FAILED"));
	}
	UE_LOG(LogTemp, Display, TEXT("========================================"));
}

FString FTLTestBase::FormatValue(int32 Value)
{
	return FString::FromInt(Value);
}

FString FTLTestBase::FormatValue(bool Value)
{
	return Value ? TEXT("true") : TEXT("false");
}

FString FTLTestBase::FormatPhase(EGamePhase Phase)
{
	switch (Phase)
	{
	case EGamePhase::Setup: return TEXT("Setup");
	case EGamePhase::LordSelection: return TEXT("LordSelection");
	case EGamePhase::Action: return TEXT("Action");
	case EGamePhase::Production: return TEXT("Production");
	case EGamePhase::Scoring: return TEXT("Scoring");
	case EGamePhase::GameEnd: return TEXT("GameEnd");
	default: return TEXT("Unknown");
	}
}

FString FTLTestBase::FormatResource(EResourceType Resource)
{
	switch (Resource)
	{
	case EResourceType::Wool: return TEXT("Wool");
	case EResourceType::Milk: return TEXT("Milk");
	case EResourceType::Grain: return TEXT("Grain");
	case EResourceType::Cheese: return TEXT("Cheese");
	case EResourceType::Bread: return TEXT("Bread");
	case EResourceType::Whisky: return TEXT("Whisky");
	case EResourceType::Beer: return TEXT("Beer");
	case EResourceType::Wood: return TEXT("Wood");
	case EResourceType::Stone: return TEXT("Stone");
	case EResourceType::Cotton: return TEXT("Cotton");
	case EResourceType::Tobacco: return TEXT("Tobacco");
	case EResourceType::SugarCane: return TEXT("SugarCane");
	case EResourceType::Hops: return TEXT("Hops");
	default: return TEXT("Unknown");
	}
}
