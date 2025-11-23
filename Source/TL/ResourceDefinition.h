#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TLTypes.h"
#include "ResourceDefinition.generated.h"

UCLASS(BlueprintType)
class TL_API UResourceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	FText ResourceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	EResourceCategory ResourceCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	int32 EndGameValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	UTexture2D* ResourceIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	int32 BaseMarketPrice;

	UResourceDefinition()
		: ResourceType(EResourceType::Wool)
		, ResourceCategory(EResourceCategory::Basic)
		, EndGameValue(0)
		, ResourceIcon(nullptr)
		, BaseMarketPrice(3)
	{}
};
