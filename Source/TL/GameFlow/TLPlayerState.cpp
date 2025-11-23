#include "TLPlayerState.h"
#include "../Shipping/ShippingComponent.h"
#include "../Lords/LordDefinition.h"

ATLPlayerState::ATLPlayerState()
{
	Gold = 0;
	AvailableMerchants = 0;
	UsedMerchants = 0;
	VictoryPoints = 0;
	SelectedLord = nullptr;

	ShippingComponent = CreateDefaultSubobject<UShippingComponent>(TEXT("ShippingComponent"));
}

void ATLPlayerState::AddGold(int32 Amount)
{
	Gold += Amount;
	OnGoldChanged.Broadcast(Gold);
}

bool ATLPlayerState::SpendGold(int32 Amount)
{
	if (Gold < Amount)
	{
		return false;
	}

	Gold -= Amount;
	OnGoldChanged.Broadcast(Gold);
	return true;
}

void ATLPlayerState::AddResource(EResourceType Resource, int32 Amount)
{
	if (!ResourceStock.Contains(Resource))
	{
		ResourceStock.Add(Resource, 0);
	}

	ResourceStock[Resource] += Amount;
	OnResourceChanged.Broadcast(Resource, ResourceStock[Resource]);
}

bool ATLPlayerState::SpendResource(EResourceType Resource, int32 Amount)
{
	if (!ResourceStock.Contains(Resource) || ResourceStock[Resource] < Amount)
	{
		return false;
	}

	ResourceStock[Resource] -= Amount;
	OnResourceChanged.Broadcast(Resource, ResourceStock[Resource]);
	return true;
}

int32 ATLPlayerState::GetResourceAmount(EResourceType Resource) const
{
	if (ResourceStock.Contains(Resource))
	{
		return ResourceStock[Resource];
	}
	return 0;
}

void ATLPlayerState::SelectLord(ULordDefinition* Lord)
{
	if (!Lord)
	{
		return;
	}

	SelectedLord = Lord;
	Gold = Lord->StartingGold;
	AvailableMerchants = Lord->StartingMerchants;

	if (ShippingComponent)
	{
		ShippingComponent->ShippingLevel = Lord->StartingShipping;
	}
}

void ATLPlayerState::AddUnit(AUnit* Unit)
{
	if (Unit)
	{
		OwnedUnits.Add(Unit);
		OnUnitAcquired.Broadcast(Unit);
	}
}

void ATLPlayerState::AddHex(AHexTile* Hex)
{
	if (Hex)
	{
		OwnedHexes.Add(Hex);
	}
}

void ATLPlayerState::AddVictoryPoints(int32 Points)
{
	VictoryPoints += Points;
	OnVictoryPointsChanged.Broadcast(VictoryPoints);
}
