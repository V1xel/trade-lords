#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContractManagerComponent.generated.h"

class UContractDefinition;
class ATLPlayerState;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TL_API UContractManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UContractManagerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contracts")
	TArray<UContractDefinition*> AvailableContracts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contracts")
	TMap<ATLPlayerState*, TArray<UContractDefinition*>> FulfilledContracts;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractTaken, ATLPlayerState*, Player, UContractDefinition*, Contract);
	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractTaken OnContractTaken;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContractFulfilled, ATLPlayerState*, Player, UContractDefinition*, Contract);
	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractFulfilled OnContractFulfilled;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContractsRefreshed);
	UPROPERTY(BlueprintAssignable, Category = "Contracts")
	FOnContractsRefreshed OnContractsRefreshed;

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool TakeContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	bool FulfillContract(ATLPlayerState* Player, UContractDefinition* Contract);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	void RefreshContracts(const TArray<UContractDefinition*>& NewContracts);

	UFUNCTION(BlueprintCallable, Category = "Contracts")
	int32 GetPlayerContractCount(ATLPlayerState* Player) const;
};
