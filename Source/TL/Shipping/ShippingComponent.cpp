#include "ShippingComponent.h"

UShippingComponent::UShippingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ShippingLevel = 0;
	MaxShippingLevel = 5;
	UpgradeCost = {5, 10, 15, 20, 25};
}

bool UShippingComponent::UpgradeShipping()
{
	if (!CanUpgrade())
	{
		return false;
	}

	ShippingLevel++;
	OnShippingUpgraded.Broadcast(ShippingLevel);
	return true;
}

int32 UShippingComponent::GetUpgradeCost() const
{
	if (ShippingLevel >= MaxShippingLevel)
	{
		return 0;
	}
	return UpgradeCost[ShippingLevel];
}

bool UShippingComponent::CanUpgrade() const
{
	return ShippingLevel < MaxShippingLevel;
}
