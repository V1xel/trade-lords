#pragma once

#include "CoreMinimal.h"
#include "TLTypes.generated.h"

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	Setup,
	LordSelection,
	Action,
	Production,
	Scoring,
	GameEnd
};

UENUM(BlueprintType)
enum class EPlayerAction : uint8
{
	PlaceUnit,
	BuyResource,
	SellResource,
	TakeContract,
	FulfillContract,
	UpgradeShipping,
	UpgradeUnit,
	Pass
};

UENUM(BlueprintType)
enum class ETerrainType : uint8
{
	Grassland,
	Forest,
	Mountain,
	Loch,
	River
};

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	Wool,
	Milk,
	Grain,
	Cheese,
	Bread,
	Whisky,
	Beer,
	Wood,
	Stone,
	Cotton,
	Tobacco,
	SugarCane,
	Hops
};

UENUM(BlueprintType)
enum class EResourceCategory : uint8
{
	Basic,
	Processed,
	Import,
	Material
};

UENUM(BlueprintType)
enum class EUnitType : uint8
{
	Sheep,
	Cow,
	Field,
	Woodcutter,
	Miner,
	Fisherman,
	CheeseDairy,
	Bakery,
	Distillery,
	Brewery
};

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	Passive,
	Triggered,
	Active
};

USTRUCT(BlueprintType)
struct FResourceStock
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;

	FResourceStock()
		: ResourceType(EResourceType::Wool)
		, Amount(0)
	{}

	FResourceStock(EResourceType InType, int32 InAmount)
		: ResourceType(InType)
		, Amount(InAmount)
	{}
};

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
