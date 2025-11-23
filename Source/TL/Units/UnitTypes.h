#pragma once

#include "CoreMinimal.h"
#include "UnitTypes.generated.h"

UENUM(BlueprintType)
enum class EUnitType : uint8
{
	Sheep UMETA(DisplayName = "Sheep"),
	Cow UMETA(DisplayName = "Cow"),
	Field UMETA(DisplayName = "Field"),
	Woodcutter UMETA(DisplayName = "Woodcutter"),
	Miner UMETA(DisplayName = "Miner"),
	Fisherman UMETA(DisplayName = "Fisherman"),
	CheeseDairy UMETA(DisplayName = "Cheese Dairy"),
	Bakery UMETA(DisplayName = "Bakery"),
	Distillery UMETA(DisplayName = "Distillery"),
	Brewery UMETA(DisplayName = "Brewery")
};
