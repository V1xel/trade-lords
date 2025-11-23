#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TLTypes.h"
#include "TLGameState.generated.h"

class UMarketComponent;
class UContractManagerComponent;
class ULordDefinition;
class AHexTile;

UCLASS()
class TL_API ATLGameState : public AGameStateBase
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

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMarketUpdated);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnMarketUpdated OnMarketUpdated;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContractsRefreshed);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnContractsRefreshed OnContractsRefreshed;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhaseChanged, EGamePhase, NewPhase);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnPhaseChanged OnPhaseChanged;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void SetPhase(EGamePhase NewPhase);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void IncrementRound();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddHexToGrid(AHexTile* Hex);
};
