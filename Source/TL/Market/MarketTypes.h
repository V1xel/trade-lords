#pragma once

#include "CoreMinimal.h"
#include "../Resources/ResourceTypes.h"
#include "MarketTypes.generated.h"

USTRUCT(BlueprintType)
struct FMarketPriceSnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Round;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EResourceType, int32> Prices;

	FMarketPriceSnapshot()
		: Round(0)
	{}
};
