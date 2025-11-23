#include "Unit.h"

AUnit::AUnit()
{
	PrimaryActorTick.bCanEverTick = false;

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnitMesh"));
	RootComponent = UnitMesh;

	UnitCost = 0;
	GeneratesIncome = 0;
	bIsUpgraded = false;
	OwningPlayer = nullptr;
	PlacedOnHex = nullptr;
}

void AUnit::SetOwningPlayer(ATLPlayerState* Player)
{
	OwningPlayer = Player;
}

void AUnit::SetPlacedHex(AHexTile* Hex)
{
	PlacedOnHex = Hex;
	if (OwningPlayer && Hex)
	{
		OnUnitPlacedEvent.Broadcast(OwningPlayer, Hex);
	}
}

void AUnit::Upgrade()
{
	if (!bIsUpgraded)
	{
		bIsUpgraded = true;
		OnUpgraded.Broadcast();
	}
}

void AUnit::Produce()
{
	OnProduction.Broadcast(ProducesResource, 1);
}
