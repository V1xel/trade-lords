#include "ContractManagerComponent.h"
#include "ContractDefinition.h"

UContractManagerComponent::UContractManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UContractManagerComponent::TakeContract(ATLPlayerState* Player, UContractDefinition* Contract)
{
	if (!Player || !Contract)
	{
		return false;
	}

	if (!AvailableContracts.Contains(Contract))
	{
		return false;
	}

	AvailableContracts.Remove(Contract);
	OnContractTaken.Broadcast(Player, Contract);
	return true;
}

bool UContractManagerComponent::FulfillContract(ATLPlayerState* Player, UContractDefinition* Contract)
{
	if (!Player || !Contract)
	{
		return false;
	}

	TArray<UContractDefinition*>& PlayerFulfilledContracts = FulfilledContracts.FindOrAdd(Player);
	PlayerFulfilledContracts.Add(Contract);

	OnContractFulfilled.Broadcast(Player, Contract);
	return true;
}

void UContractManagerComponent::RefreshContracts(const TArray<UContractDefinition*>& NewContracts)
{
	AvailableContracts = NewContracts;
	OnContractsRefreshed.Broadcast();
}

int32 UContractManagerComponent::GetPlayerContractCount(ATLPlayerState* Player) const
{
	if (!Player)
	{
		return 0;
	}

	const TArray<UContractDefinition*>* PlayerContracts = FulfilledContracts.Find(Player);
	return PlayerContracts ? PlayerContracts->Num() : 0;
}
