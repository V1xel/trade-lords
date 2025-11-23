#include "ShippingComponent.h"

UShippingComponent::UShippingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ShippingLevel = 0;
	MaxShippingLevel = 5;
	UpgradeCost = {4, 4, 4, 4, 4};
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

	if (ShippingLevel < UpgradeCost.Num())
	{
		return UpgradeCost[ShippingLevel];
	}

	return 4;
}

bool UShippingComponent::CanUpgrade() const
{
	return ShippingLevel < MaxShippingLevel;
}
