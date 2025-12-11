#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceTypes.h"
#include "ResourceDefinition.generated.h"

UCLASS(BlueprintType)
class TL_API UResourceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	EResourceCategory ResourceCategory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	int32 EndGameValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	UTexture2D* ResourceIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	int32 BaseMarketPrice;
};
