// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameTile.h"
#include "Components/StaticMeshComponent.h"

AGameTile::AGameTile()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create static mesh component
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	RootComponent = TileMesh;

	// Default values
	TileName = TEXT("Default Tile");
	TileColor = FLinearColor::White;
	MovementCost = 1;
	bCanStop = true;
	bIsPassable = true;
	bProvidesCover = false;
	ResourceAmount = 0;
}

void AGameTile::BeginPlay()
{
	Super::BeginPlay();

	// Apply tile color to mesh material
	if (TileMesh)
	{
		UMaterialInstanceDynamic* DynamicMaterial = TileMesh->CreateDynamicMaterialInstance(0);
		if (DynamicMaterial)
		{
			DynamicMaterial->SetVectorParameterValue(FName("TileColor"), TileColor);
		}
	}
}

void AGameTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
