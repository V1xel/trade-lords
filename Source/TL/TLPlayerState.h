#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TLTypes.h"
#include "TLPlayerState.generated.h"

class ULordDefinition;
class AUnit;
class AHexTile;
class UShippingComponent;
class UContractDefinition;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	ULordDefinition* SelectedLord;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TArray<AUnit*> OwnedUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TArray<AHexTile*> OwnedHexes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UShippingComponent* ShippingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 AvailableMerchants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 UsedMerchants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TArray<UContractDefinition*> ActiveContracts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int32 VictoryPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	bool bHasPassed;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoldChanged, int32, NewGold);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnGoldChanged OnGoldChanged;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResourceChanged, EResourceType, Resource, int32, NewAmount);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnResourceChanged OnResourceChanged;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitAcquired, AUnit*, Unit);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnUnitAcquired OnUnitAcquired;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContractTaken, UContractDefinition*, Contract);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnContractTaken OnContractTaken;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContractFulfilled, UContractDefinition*, Contract);
	UPROPERTY(BlueprintAssignable, Category = "Player")
	FOnContractFulfilled OnContractFulfilled;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVictoryPointsChanged, int32, NewVP);
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
	void AddUnit(AUnit* Unit);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddHex(AHexTile* Hex);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddVictoryPoints(int32 Points);

	UFUNCTION(BlueprintCallable, Category = "Player")
	bool UseMerchant();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void RefreshMerchants();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void Pass();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ResetForNewRound();
};
