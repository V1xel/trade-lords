#pragma once

#include "CoreMinimal.h"
#include "ResourceTypes.generated.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	Wool UMETA(DisplayName = "Wool"),
	Milk UMETA(DisplayName = "Milk"),
	Grain UMETA(DisplayName = "Grain"),
	Cheese UMETA(DisplayName = "Cheese"),
	Bread UMETA(DisplayName = "Bread"),
	Whisky UMETA(DisplayName = "Whisky"),
	Beer UMETA(DisplayName = "Beer"),
	Cotton UMETA(DisplayName = "Cotton"),
	Tobacco UMETA(DisplayName = "Tobacco"),
	SugarCane UMETA(DisplayName = "Sugar Cane"),
	Hops UMETA(DisplayName = "Hops")
};

UENUM(BlueprintType)
enum class EResourceCategory : uint8
{
	Basic UMETA(DisplayName = "Basic"),
	Processed UMETA(DisplayName = "Processed"),
	Import UMETA(DisplayName = "Import")
};

USTRUCT(BlueprintType)
struct FResourceStock
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount = 0;

	FResourceStock()
		: ResourceType(EResourceType::Wool)
		, Amount(0)
	{}

	FResourceStock(EResourceType InType, int32 InAmount)
		: ResourceType(InType)
		, Amount(InAmount)
	{}
};
