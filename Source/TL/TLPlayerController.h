#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TLTypes.h"
#include "TLPlayerController.generated.h"

class AHexTile;
class AUnit;

UCLASS()
class TL_API ATLPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATLPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	AHexTile* SelectedHex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	AUnit* SelectedUnit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	EPlayerAction CurrentAction;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHexClicked, AHexTile*, Hex);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnHexClicked OnHexClicked;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitSelected, AUnit*, Unit);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnUnitSelected OnUnitSelected;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionConfirmed, EPlayerAction, Action);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnActionConfirmed OnActionConfirmed;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnd);
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
};
