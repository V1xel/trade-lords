// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameTile.generated.h"

/**
 * Configurable game tile for board game
 * Base class that can be extended in Blueprints with different configurations
 */
UCLASS(Blueprintable)
class TL_API AGameTile : public AActor
{
	GENERATED_BODY()

public:
	AGameTile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Tile Properties

	/** Name of this tile type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Config")
	FString TileName;

	/** Tile color */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Config")
	FLinearColor TileColor;

	/** Movement cost to enter this tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Gameplay")
	int32 MovementCost;

	/** Can units stop on this tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Gameplay")
	bool bCanStop;

	/** Can units move through this tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Gameplay")
	bool bIsPassable;

	/** Provides cover bonus */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Gameplay")
	bool bProvidesCover;

	/** Resource amount on this tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Resources", meta = (ClampMin = "0", ClampMax = "100"))
	int32 ResourceAmount;

	/** Mesh to display for this tile */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
	class UStaticMeshComponent* TileMesh;
};
