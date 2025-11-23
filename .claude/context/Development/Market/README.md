# Market Module - C++ Classes

## Overview

C++ component for market system. Manages dynamic pricing and trading actions.

## Classes

### UMarketComponent

**Purpose:**
Component attached to GameState. Handles market pricing, buy/sell actions, and price adjustments.

**State:**
- ResourcePrices (TMap<EResourceType, int32>) - Current market prices
- PriceHistory (TArray<FMarketPriceSnapshot>) - Price tracking per round

**Events:**
- OnResourceBought (EResourceType Resource, int32 Amount, int32 Price, ATLPlayerState* Buyer)
- OnResourceSold (EResourceType Resource, int32 Amount, int32 Price, ATLPlayerState* Seller)
- OnPriceChanged (EResourceType Resource, int32 NewPrice)

## Structs

### FMarketPriceSnapshot

**Purpose:**
Snapshot of market prices at a point in time.

**State:**
- Round (int32)
- Prices (TMap<EResourceType, int32>)

## Related Modules

- **Resources** - Resources being traded
- **GameFlow** - GameState holds market component
- **Lords** - Isolde affects market prices
