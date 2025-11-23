# Shipping Module - C++ Classes

## Overview

C++ component for shipping system. Manages shipping levels and water-based expansion.

## Classes

### UShippingComponent

**Purpose:**
Component attached to PlayerState. Tracks shipping level and calculates range for unit placement across water.

**State:**
- ShippingLevel (int32) - Range 0-5
- UpgradeCost (TArray<int32>) - Cost per level
- MaxShippingLevel (int32) - 5

**Events:**
- OnShippingUpgraded (int32 NewLevel)
- OnShippingUsed (AHexTile* SourceHex, AHexTile* TargetHex)

## Related Modules

- **Hexes** - Shipping allows placement across water hexes
- **GameFlow** - PlayerState holds shipping component
- **Lords** - Marina starts with higher shipping
