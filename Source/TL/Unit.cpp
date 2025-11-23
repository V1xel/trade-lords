#include "Unit.h"
#include "HexTile.h"
#include "Components/StaticMeshComponent.h"

AUnit::AUnit()
{
	PrimaryActorTick.bCanEverTick = false;

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnitMesh"));
	RootComponent = UnitMesh;

	UnitType = EUnitType::Sheep;
	UnitCost = 2;
	GeneratesIncome = 0;
	bIsUpgraded = false;
	UpgradedIncome = 0;
	OwningPlayer = nullptr;
	PlacedOnHex = nullptr;
	ProducesResource = EResourceType::Wool;
	ConsumesResource = EResourceType::Wool;
	ProcessesIntoResource = EResourceType::Wool;
}

bool AUnit::CanPlaceOnTerrain(AHexTile* Hex) const
{
	if (!Hex)
	{
		return false;
	}

	if (RequiredTerrain.Num() == 0)
	{
		return true;
	}

	for (ETerrainType Terrain : RequiredTerrain)
	{
		if (Hex->HasTerrainType(Terrain))
		{
			return true;
		}
	}

	return false;
}

void AUnit::Produce()
{
	OnProduction.Broadcast(ProducesResource, 1);
}

void AUnit::GenerateGold()
{
	int32 Income = GetCurrentIncome();
	if (Income > 0)
	{
		OnIncomeGenerated.Broadcast(Income);
	}
}

bool AUnit::Upgrade()
{
	if (bIsUpgraded)
	{
		return false;
	}

	bIsUpgraded = true;
	OnUpgraded.Broadcast();
	return true;
}

int32 AUnit::GetCurrentIncome() const
{
	return bIsUpgraded ? UpgradedIncome : GeneratesIncome;
}
