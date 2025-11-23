#include "MarketComponent.h"

UMarketComponent::UMarketComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UMarketComponent::BuyResource(EResourceType Resource, int32 Amount, ATLPlayerState* Buyer)
{
	if (!Buyer || Amount <= 0)
	{
		return false;
	}

	int32 Price = GetPrice(Resource);
	OnResourceBought.Broadcast(Resource, Amount, Price, Buyer);
	return true;
}

bool UMarketComponent::SellResource(EResourceType Resource, int32 Amount, ATLPlayerState* Seller)
{
	if (!Seller || Amount <= 0)
	{
		return false;
	}

	int32 Price = GetPrice(Resource);
	OnResourceSold.Broadcast(Resource, Amount, Price, Seller);
	return true;
}

void UMarketComponent::AdjustPrice(EResourceType Resource, int32 Delta)
{
	if (ResourcePrices.Contains(Resource))
	{
		int32 NewPrice = ResourcePrices[Resource] + Delta;
		NewPrice = FMath::Max(1, NewPrice);
		ResourcePrices[Resource] = NewPrice;
		OnPriceChanged.Broadcast(Resource, NewPrice);
	}
}

int32 UMarketComponent::GetPrice(EResourceType Resource) const
{
	if (ResourcePrices.Contains(Resource))
	{
		return ResourcePrices[Resource];
	}
	return 0;
}

void UMarketComponent::SavePriceSnapshot(int32 Round)
{
	FMarketPriceSnapshot Snapshot;
	Snapshot.Round = Round;
	Snapshot.Prices = ResourcePrices;
	PriceHistory.Add(Snapshot);
}
