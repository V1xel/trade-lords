#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TLTypes.h"
#include "ContractDefinition.generated.h"

UCLASS(BlueprintType)
class TL_API UContractDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	FText ContractName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	TMap<EResourceType, int32> RequiredResources;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	int32 GoldReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	EResourceType ImportGoodReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	int32 ImportGoodAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	int32 VictoryPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Contract")
	UTexture2D* ContractIcon;

	UContractDefinition()
		: GoldReward(0)
		, ImportGoodReward(EResourceType::Cotton)
		, ImportGoodAmount(0)
		, VictoryPoints(0)
		, ContractIcon(nullptr)
	{}
};
