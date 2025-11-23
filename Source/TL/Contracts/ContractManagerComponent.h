#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContractDefinition.h"
#include "ContractManagerComponent.generated.h"

class ATLPlayerState;

USTRUCT(BlueprintType)
struct FPlayerContracts
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TArray<UContractDefinition*> Contracts;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractTakenByPlayer, ATLPlayerState*, Player, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractFulfilledByPlayer, ATLPlayerState*, Player, UContractDefinition*, Contract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContractPoolRefreshed);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UContractManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UContractManagerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contracts")
	TArray<UContractDefinition*> AvailableContracts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Contracts")
	TMap<ATLPlayerState*, FPlayerContracts> FulfilledContracts;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractTakenByPlayer OnContractTaken;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractFulfilledByPlayer OnContractFulfilled;

	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractPoolRefreshed OnContractsRefreshed;

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool TakeContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool FulfillContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	void RefreshContracts(TArray<UContractDefinition*> NewContracts);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool IsContractAvailable(UContractDefinition* Contract) const;
};
