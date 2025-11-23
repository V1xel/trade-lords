#pragma once

#include "CoreMinimal.h"
#include "HexTypes.generated.h"

UENUM(BlueprintType)
enum class ETerrainType : uint8
{
	Grassland UMETA(DisplayName = "Grassland"),
	Forest UMETA(DisplayName = "Forest"),
	Mountain UMETA(DisplayName = "Mountain"),
	Loch UMETA(DisplayName = "Loch"),
	River UMETA(DisplayName = "River")
};
