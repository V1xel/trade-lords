#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TLTypes.h"
#include "TLGameMode.generated.h"

class ATLPlayerState;

UCLASS()
class TL_API ATLGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATLGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 NumPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 CurrentRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 MaxRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	EGamePhase GamePhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TArray<ATLPlayerState*> TurnOrder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 ActivePlayerIndex;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStart);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGameStart OnGameStart;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoundStart, int32, Round);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoundStart OnRoundStart;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoundEnd, int32, Round);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoundEnd OnRoundEnd;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhaseChanged, EGamePhase, NewPhase);
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnPhaseChanged OnPhaseChanged;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameEnd);
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
	void NextPlayerTurn();

	UFUNCTION(BlueprintCallable, Category = "Game")
	ATLPlayerState* GetActivePlayer() const;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void DetermineTurnOrder();
};
