#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GameFlowTypes.h"
#include "TLGameState.generated.h"

class UMarketComponent;
class UContractManagerComponent;
class ULordDefinition;
class AHexTile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMarketUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContractsRefreshed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhaseChanged, EGamePhase, NewPhase);

UCLASS()
class TL_API ATLGameState : public AGameState
{
	GENERATED_BODY()

public:
	ATLGameState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 CurrentRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	EGamePhase CurrentPhase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	UMarketComponent* MarketComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	UContractManagerComponent* ContractManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TArray<ULordDefinition*> AvailableLords;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TArray<AHexTile*> HexGrid;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnMarketUpdated OnMarketUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnContractsRefreshed OnContractsRefreshed;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnPhaseChanged OnPhaseChanged;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void SetPhase(EGamePhase NewPhase);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void IncrementRound();
};
