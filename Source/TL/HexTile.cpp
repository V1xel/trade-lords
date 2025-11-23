#include "HexTile.h"
#include "Components/StaticMeshComponent.h"

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
	TileColor = FLinearColor::White;
}

bool AHexTile::PlaceUnit(AUnit* Unit, ATLPlayerState* Owner)
{
	if (!Unit || !Owner || bIsOccupied)
	{
		return false;
	}

	OccupyingUnit = Unit;
	OwningPlayer = Owner;
	bIsOccupied = true;

	OnUnitPlaced.Broadcast(Unit, Owner);
	return true;
}

bool AHexTile::HasTerrainType(ETerrainType TerrainType) const
{
	return TerrainTypes.Contains(TerrainType);
}

void AHexTile::AddAdjacentHex(AHexTile* Hex)
{
	if (Hex && !AdjacentHexes.Contains(Hex))
	{
		AdjacentHexes.Add(Hex);
	}
}
