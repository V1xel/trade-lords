#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TLTypes.h"
#include "Unit.generated.h"

class AHexTile;
class ATLPlayerState;

UCLASS(Blueprintable)
class TL_API AUnit : public AActor
{
	GENERATED_BODY()

public:
	AUnit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EUnitType UnitType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	int32 UnitCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	TArray<ETerrainType> RequiredTerrain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	ATLPlayerState* OwningPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	AHexTile* PlacedOnHex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EResourceType ProducesResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	int32 GeneratesIncome;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EResourceType ConsumesResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EResourceType ProcessesIntoResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	bool bIsUpgraded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	int32 UpgradedIncome;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	UStaticMeshComponent* UnitMesh;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnitPlaced, ATLPlayerState*, Owner, AHexTile*, Hex);
	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnUnitPlaced OnUnitPlaced;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProduction, EResourceType, Resource, int32, Amount);
	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnProduction OnProduction;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIncomeGenerated, int32, Gold);
	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnIncomeGenerated OnIncomeGenerated;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpgraded);
	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnUpgraded OnUpgraded;

	UFUNCTION(BlueprintCallable, Category = "Unit")
	bool CanPlaceOnTerrain(AHexTile* Hex) const;

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void Produce();

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void GenerateGold();

	UFUNCTION(BlueprintCallable, Category = "Unit")
	bool Upgrade();

	UFUNCTION(BlueprintCallable, Category = "Unit")
	int32 GetCurrentIncome() const;
};
