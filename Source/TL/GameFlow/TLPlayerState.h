#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "../Resources/ResourceTypes.h"
#include "TLPlayerState.generated.h"

class ULordDefinition;
class AUnit;
class AHexTile;
class UShippingComponent;
class UContractDefinition;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoldChanged, int32, NewGold);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResourceChanged, EResourceType, Resource, int32, NewAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitAcquired, AUnit*, Unit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContractTaken, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContractFulfilled, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVictoryPointsChanged, int32, NewVP);

UCLASS()
class TL_API ATLPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATLPlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 Gold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TMap<EResourceType, int32> ResourceStock;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	ULordDefinition* SelectedLord;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	TArray<AUnit*> OwnedUnits;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	TArray<AHexTile*> OwnedHexes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UShippingComponent* ShippingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 AvailableMerchants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 UsedMerchants;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	TArray<UContractDefinition*> ActiveContracts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 VictoryPoints;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnGoldChanged OnGoldChanged;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnResourceChanged OnResourceChanged;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnUnitAcquired OnUnitAcquired;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnContractTaken OnContractTaken;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnContractFulfilled OnContractFulfilled;

	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnVictoryPointsChanged OnVictoryPointsChanged;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddGold(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Player")
	bool SpendGold(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddResource(EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Player")
	bool SpendResource(EResourceType Resource, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Player")
	int32 GetResourceAmount(EResourceType Resource) const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SelectLord(ULordDefinition* Lord);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddUnit(AUnit* Unit);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddHex(AHexTile* Hex);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddVictoryPoints(int32 Points);
};
