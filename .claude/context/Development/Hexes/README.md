# Hexes Module - C++ Classes

## Overview

C++ classes for hex tile system. Base class extended by Blueprint variants for each terrain type.

## Classes

### AHexTile

**Purpose:**
Base actor class for hex tiles on the game board. Extended in Blueprint for specific terrain types (Grassland, Forest, Mountain, Loch, River).

**State:**
- TerrainType (ETerrainType enum or array)
- TerrainCost (int32) - Placement cost £1-£6
- OccupyingUnit (AUnit*) - Reference to placed unit
- OwningPlayer (ATLPlayerState*) - Player who owns this hex
- bIsOccupied (bool)
- bIsRiverDelta (bool)
- AdjacentHexes (TArray<AHexTile*>) - 6 neighbors
- TileMesh (UStaticMeshComponent*)
- TileColor (FLinearColor) - Visual color per terrain

**Events:**
- OnUnitPlaced (AUnit* Unit, ATLPlayerState* Owner)
- OnHexSelected
- OnHexHovered

## Blueprint Variants

Documented in `Content/Hexes/`:
- BP_HexTile_Grassland
- BP_HexTile_Forest
- BP_HexTile_Mountain
- BP_HexTile_Loch
- BP_HexTile_River

Each Blueprint configures terrain type, cost, and visual mesh.

## Related Modules

- **Units** - Units placed on hexes
- **GameFlow** - PlayerState tracks owned hexes
