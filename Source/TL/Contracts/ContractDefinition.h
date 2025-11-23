#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Resources/ResourceTypes.h"
#include "ContractDefinition.generated.h"

UCLASS(BlueprintType)
class TL_API UContractDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	FText ContractName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	TMap<EResourceType, int32> RequiredResources;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	int32 GoldReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	EResourceType ImportGoodReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	int32 ImportGoodAmount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	int32 VictoryPoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Contract")
	UTexture2D* ContractIcon;
};
