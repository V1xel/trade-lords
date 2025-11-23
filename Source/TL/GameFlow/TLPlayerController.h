#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFlowTypes.h"
#include "TLPlayerController.generated.h"

class AHexTile;
class AUnit;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHexClicked, AHexTile*, Hex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitSelected, AUnit*, Unit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionConfirmed, EPlayerAction, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnd);

UCLASS()
class TL_API ATLPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATLPlayerController();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	AHexTile* SelectedHex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	AUnit* SelectedUnit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	EPlayerAction CurrentAction;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnHexClicked OnHexClicked;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnUnitSelected OnUnitSelected;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnActionConfirmed OnActionConfirmed;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnTurnEnd OnTurnEnd;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SelectHex(AHexTile* Hex);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SelectUnit(AUnit* Unit);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ConfirmAction(EPlayerAction Action);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void EndTurn();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ClearSelection();
};
