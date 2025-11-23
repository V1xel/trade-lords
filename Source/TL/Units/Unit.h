#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitTypes.h"
#include "../Resources/ResourceTypes.h"
#include "../Hexes/HexTypes.h"
#include "Unit.generated.h"

class ATLPlayerState;
class AHexTile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnitPlacedOnHex, ATLPlayerState*, Owner, AHexTile*, Hex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProduction, EResourceType, Resource, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIncomeGenerated, int32, Gold);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpgraded);

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
	ETerrainType RequiredTerrain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	ATLPlayerState* OwningPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	AHexTile* PlacedOnHex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EResourceType ProducesResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	int32 GeneratesIncome;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
	EResourceType ConsumesResource;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Unit")
	bool bIsUpgraded;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	UStaticMeshComponent* UnitMesh;

	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnUnitPlacedOnHex OnUnitPlacedEvent;

	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnProduction OnProduction;

	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnIncomeGenerated OnIncomeGenerated;

	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FOnUpgraded OnUpgraded;

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void SetOwningPlayer(ATLPlayerState* Player);

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void SetPlacedHex(AHexTile* Hex);

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void Upgrade();

	UFUNCTION(BlueprintCallable, Category = "Unit")
	void Produce();
};
