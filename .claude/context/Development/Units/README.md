# Units Module - C++ Classes

## Overview

C++ base class for all unit types. Extended by Blueprint variants for each specific unit (Sheep, Cow, Field, Woodcutter, Miner, Fisherman, and processing buildings).

## Classes

### AUnit

**Purpose:**
Base actor class for all units placed on hexes. Handles production, ownership, and terrain requirements.

**State:**
- UnitType (EUnitType enum)
- UnitCost (int32) - Purchase cost
- RequiredTerrain (ETerrainType)
- OwningPlayer (ATLPlayerState*)
- PlacedOnHex (AHexTile*)
- ProducesResource (EResourceType) - For production units
- GeneratesIncome (int32) - For workers
- ConsumesResource (EResourceType) - For processing buildings
- bIsUpgraded (bool) - For worker upgrades
- UnitMesh (UStaticMeshComponent*)

**Events:**
- OnUnitPlaced (ATLPlayerState* Owner, AHexTile* Hex)
- OnProduction (EResourceType Resource, int32 Amount)
- OnIncomeGenerated (int32 Gold)
- OnUpgraded

## Blueprint Variants

Documented in `Content/Units/`:

**Production Units:**
- BP_Unit_Sheep
- BP_Unit_Cow
- BP_Unit_Field

**Workers:**
- BP_Unit_Woodcutter
- BP_Unit_Miner
- BP_Unit_Fisherman

**Processing Buildings:**
- BP_Unit_CheeseDairy
- BP_Unit_Bakery
- BP_Unit_Distillery
- BP_Unit_Brewery

Each Blueprint configures cost, terrain requirement, and production type.

## Related Modules

- **Hexes** - Units placed on hexes
- **Resources** - Units produce resources
- **GameFlow** - PlayerState tracks owned units
