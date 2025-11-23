#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTypes.h"
#include "HexTile.generated.h"

class AUnit;
class ATLPlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHexUnitPlaced, AUnit*, Unit, ATLPlayerState*, Owner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHexSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHexHovered);

UCLASS(Blueprintable)
class TL_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	AHexTile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	ETerrainType TerrainType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	int32 TerrainCost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hex")
	AUnit* OccupyingUnit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hex")
	ATLPlayerState* OwningPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hex")
	bool bIsOccupied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	bool bIsRiverDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	TArray<AHexTile*> AdjacentHexes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hex")
	UStaticMeshComponent* TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	FLinearColor TileColor;

	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnHexUnitPlaced OnUnitPlaced;

	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnHexSelected OnHexSelected;

	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnHexHovered OnHexHovered;

	UFUNCTION(BlueprintCallable, Category = "Hex")
	void PlaceUnit(AUnit* Unit, ATLPlayerState* NewOwner);

	UFUNCTION(BlueprintCallable, Category = "Hex")
	void ClearUnit();
};
