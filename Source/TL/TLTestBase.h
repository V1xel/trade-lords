#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "TLTypes.h"

class ATLGameMode;
class ATLGameState;
class ATLPlayerState;
class AHexTile;
class AUnit;

class TL_API FTLTestBase
{
public:
	FAutomationTestBase* TestRunner;

	FTLTestBase(FAutomationTestBase* InTestRunner);

	void LogHeader(const FString& TestName);
	void LogSection(const FString& SectionName);
	void LogEvent(const FString& EventName);
	void LogStateChange(const FString& Property, const FString& OldValue, const FString& NewValue);
	void LogExpectedState(const FString& Property, const FString& Value);
	void LogAssertion(const FString& AssertionText, bool bPassed);
	void LogError(const FString& ErrorText);
	void LogInfo(const FString& InfoText);

	void LogPlayerState(const FString& Prefix, ATLPlayerState* Player);
	void LogGameState(const FString& Prefix, ATLGameState* GameState);
	void LogHexState(const FString& Prefix, AHexTile* Hex);
	void LogUnitState(const FString& Prefix, AUnit* Unit);

	bool AssertEqual(int32 Actual, int32 Expected, const FString& Description);
	bool AssertEqual(bool Actual, bool Expected, const FString& Description);
	bool AssertNotNull(UObject* Object, const FString& Description);
	bool AssertNull(UObject* Object, const FString& Description);

	void BeginTest(const FString& TestName);
	void EndTest(bool bSuccess);

	FString FormatValue(int32 Value);
	FString FormatValue(bool Value);
	FString FormatPhase(EGamePhase Phase);
	FString FormatResource(EResourceType Resource);
};
