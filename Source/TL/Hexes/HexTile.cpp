#include "HexTile.h"

AHexTile::AHexTile()
{
	PrimaryActorTick.bCanEverTick = false;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	RootComponent = TileMesh;

	TerrainCost = 1;
	bIsOccupied = false;
	bIsRiverDelta = false;
	OccupyingUnit = nullptr;
	OwningPlayer = nullptr;
}

void AHexTile::PlaceUnit(AUnit* Unit, ATLPlayerState* NewOwner)
{
	if (!Unit || bIsOccupied)
	{
		return;
	}

	OccupyingUnit = Unit;
	OwningPlayer = NewOwner;
	bIsOccupied = true;

	OnUnitPlaced.Broadcast(Unit, NewOwner);
}

void AHexTile::ClearUnit()
{
	OccupyingUnit = nullptr;
	bIsOccupied = false;
}
