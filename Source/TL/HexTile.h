#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TLTypes.h"
#include "HexTile.generated.h"

class AUnit;
class ATLPlayerState;

UCLASS(Blueprintable)
class TL_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	AHexTile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	TArray<ETerrainType> TerrainTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	int32 TerrainCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	AUnit* OccupyingUnit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	ATLPlayerState* OwningPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	bool bIsOccupied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	bool bIsRiverDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	TArray<AHexTile*> AdjacentHexes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hex")
	UStaticMeshComponent* TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex")
	FLinearColor TileColor;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnitPlaced, AUnit*, Unit, ATLPlayerState*, Owner);
	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnUnitPlaced OnUnitPlaced;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHexSelected);
	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnHexSelected OnHexSelected;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHexHovered);
	UPROPERTY(BlueprintAssignable, Category = "Hex")
	FOnHexHovered OnHexHovered;

	UFUNCTION(BlueprintCallable, Category = "Hex")
	bool PlaceUnit(AUnit* Unit, ATLPlayerState* Owner);

	UFUNCTION(BlueprintCallable, Category = "Hex")
	bool HasTerrainType(ETerrainType TerrainType) const;

	UFUNCTION(BlueprintCallable, Category = "Hex")
	void AddAdjacentHex(AHexTile* Hex);
};
