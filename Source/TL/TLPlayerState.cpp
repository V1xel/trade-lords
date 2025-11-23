#include "TLPlayerState.h"
#include "ShippingComponent.h"

ATLPlayerState::ATLPlayerState()
{
	Gold = 8;
	AvailableMerchants = 2;
	UsedMerchants = 0;
	VictoryPoints = 0;
	bHasPassed = false;
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
	int32& CurrentAmount = ResourceStock.FindOrAdd(Resource, 0);
	CurrentAmount += Amount;
	OnResourceChanged.Broadcast(Resource, CurrentAmount);
}

bool ATLPlayerState::SpendResource(EResourceType Resource, int32 Amount)
{
	int32* CurrentAmount = ResourceStock.Find(Resource);
	if (!CurrentAmount || *CurrentAmount < Amount)
	{
		return false;
	}

	*CurrentAmount -= Amount;
	OnResourceChanged.Broadcast(Resource, *CurrentAmount);
	return true;
}

int32 ATLPlayerState::GetResourceAmount(EResourceType Resource) const
{
	const int32* Amount = ResourceStock.Find(Resource);
	return Amount ? *Amount : 0;
}

void ATLPlayerState::AddUnit(AUnit* Unit)
{
	if (Unit && !OwnedUnits.Contains(Unit))
	{
		OwnedUnits.Add(Unit);
		OnUnitAcquired.Broadcast(Unit);
	}
}

void ATLPlayerState::AddHex(AHexTile* Hex)
{
	if (Hex && !OwnedHexes.Contains(Hex))
	{
		OwnedHexes.Add(Hex);
	}
}

void ATLPlayerState::AddVictoryPoints(int32 Points)
{
	VictoryPoints += Points;
	OnVictoryPointsChanged.Broadcast(VictoryPoints);
}

bool ATLPlayerState::UseMerchant()
{
	if (UsedMerchants >= AvailableMerchants)
	{
		return false;
	}

	UsedMerchants++;
	return true;
}

void ATLPlayerState::RefreshMerchants()
{
	UsedMerchants = 0;
}

void ATLPlayerState::Pass()
{
	bHasPassed = true;
}

void ATLPlayerState::ResetForNewRound()
{
	bHasPassed = false;
	RefreshMerchants();
}
