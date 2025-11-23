#include "ContractManagerComponent.h"

UContractManagerComponent::UContractManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UContractManagerComponent::TakeContract(ATLPlayerState* Player, UContractDefinition* Contract)
{
	if (!Player || !Contract || !IsContractAvailable(Contract))
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

	if (!FulfilledContracts.Contains(Player))
	{
		FulfilledContracts.Add(Player, FPlayerContracts());
	}

	FulfilledContracts[Player].Contracts.Add(Contract);
	OnContractFulfilled.Broadcast(Player, Contract);
	return true;
}

void UContractManagerComponent::RefreshContracts(TArray<UContractDefinition*> NewContracts)
{
	AvailableContracts = NewContracts;
	OnContractsRefreshed.Broadcast();
}

bool UContractManagerComponent::IsContractAvailable(UContractDefinition* Contract) const
{
	return AvailableContracts.Contains(Contract);
}
