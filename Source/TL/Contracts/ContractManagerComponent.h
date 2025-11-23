#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContractDefinition.h"
#include "ContractManagerComponent.generated.h"

class ATLPlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractTaken, ATLPlayerState*, Player, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractFulfilled, ATLPlayerState*, Player, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContractsRefreshed);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UContractManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UContractManagerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contracts")
	TArray<UContractDefinition*> AvailableContracts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Contracts")
	TMap<ATLPlayerState*, TArray<UContractDefinition*>> FulfilledContracts;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractTaken OnContractTaken;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractFulfilled OnContractFulfilled;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractsRefreshed OnContractsRefreshed;

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool TakeContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool FulfillContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	void RefreshContracts(TArray<UContractDefinition*> NewContracts);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool IsContractAvailable(UContractDefinition* Contract) const;
};
