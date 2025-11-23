# Resources Module - C++ Classes

## Overview

C++ data asset for resource definitions. Defines properties and values for all resource types in the game.

## Classes

### UResourceDefinition

**Purpose:**
Data asset defining resource properties, values, and types. Each resource (Wool, Milk, Grain, Cheese, Bread, Whisky, Beer, Import Goods) is a separate asset.

**State:**
- ResourceType (EResourceType enum)
- ResourceName (FText)
- ResourceCategory (EResourceCategory) - Basic, Processed, Import
- EndGameValue (int32) - Victory points
- ResourceIcon (UTexture2D*)
- BaseMarketPrice (int32) - Starting market price

**Events:**
- None (pure data)

## Resource Data Assets

Documented in `Content/Resources/`:
- DA_Resource_Wool
- DA_Resource_Milk
- DA_Resource_Grain
- DA_Resource_Cheese
- DA_Resource_Bread
- DA_Resource_Whisky
- DA_Resource_Beer
- DA_Resource_Cotton
- DA_Resource_Tobacco
- DA_Resource_SugarCane
- DA_Resource_Hops

Each data asset configures resource properties.

## Structs

### FResourceStock

**Purpose:**
Struct to track player resource inventory.

**State:**
- ResourceType (EResourceType)
- Amount (int32)

## Related Modules

- **Units** - Produce resources
- **Market** - Trade resources
- **Contracts** - Fulfill with resources
- **GameFlow** - PlayerState tracks resource stock
