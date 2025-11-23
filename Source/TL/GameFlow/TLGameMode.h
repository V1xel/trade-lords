#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFlowTypes.h"
#include "TLGameMode.generated.h"

class ATLPlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoundStart, int32, Round);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoundEnd, int32, Round);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamePhaseChanged, EGamePhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameEnd);

UCLASS()
class TL_API ATLGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATLGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 TotalPlayers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	int32 CurrentRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 MaxRounds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	EGamePhase GamePhase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	TArray<ATLPlayerState*> TurnOrder;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGameStart OnGameStart;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoundStart OnRoundStart;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoundEnd OnRoundEnd;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGamePhaseChanged OnPhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGameEnd OnGameEnd;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void StartRound();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void EndRound();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ChangePhase(EGamePhase NewPhase);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void EndGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void RunProductionPhase();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ProcessUnitPlacement(ATLPlayerState* Player, AHexTile* Hex, TSubclassOf<AUnit> UnitClass);

	UFUNCTION(BlueprintCallable, Category = "Game")
	bool CanPlaceUnit(ATLPlayerState* Player, AHexTile* Hex, TSubclassOf<AUnit> UnitClass) const;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ProcessBuyResource(ATLPlayerState* Player, EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ProcessSellResource(ATLPlayerState* Player, EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ProcessTakeContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ProcessFulfillContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Game")
	bool CanFulfillContract(ATLPlayerState* Player, UContractDefinition* Contract) const;

protected:
	virtual void BeginPlay() override;
};
