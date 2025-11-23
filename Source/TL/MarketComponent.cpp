#include "MarketComponent.h"

UMarketComponent::UMarketComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMarketComponent::InitializePrices()
{
	ResourcePrices.Empty();
	ResourcePrices.Add(EResourceType::Wool, 3);
	ResourcePrices.Add(EResourceType::Milk, 3);
	ResourcePrices.Add(EResourceType::Grain, 3);
	ResourcePrices.Add(EResourceType::Cheese, 5);
	ResourcePrices.Add(EResourceType::Bread, 5);
	ResourcePrices.Add(EResourceType::Whisky, 8);
	ResourcePrices.Add(EResourceType::Beer, 6);
	ResourcePrices.Add(EResourceType::Wood, 4);
	ResourcePrices.Add(EResourceType::Stone, 6);
}

int32 UMarketComponent::GetPrice(EResourceType Resource) const
{
	const int32* Price = ResourcePrices.Find(Resource);
	return Price ? *Price : 0;
}

void UMarketComponent::SetPrice(EResourceType Resource, int32 NewPrice)
{
	ResourcePrices.Add(Resource, NewPrice);
	OnPriceChanged.Broadcast(Resource, NewPrice);
}

bool UMarketComponent::BuyResource(ATLPlayerState* Buyer, EResourceType Resource, int32 Amount)
{
	if (!Buyer || Amount <= 0)
	{
		return false;
	}

	int32 Price = GetPrice(Resource);
	OnResourceBought.Broadcast(Resource, Amount, Price, Buyer);
	return true;
}

bool UMarketComponent::SellResource(ATLPlayerState* Seller, EResourceType Resource, int32 Amount)
{
	if (!Seller || Amount <= 0)
	{
		return false;
	}

	int32 Price = GetPrice(Resource);
	OnResourceSold.Broadcast(Resource, Amount, Price, Seller);
	return true;
}

void UMarketComponent::SavePriceSnapshot(int32 Round)
{
	FMarketPriceSnapshot Snapshot;
	Snapshot.Round = Round;
	Snapshot.Prices = ResourcePrices;
	PriceHistory.Add(Snapshot);
}
