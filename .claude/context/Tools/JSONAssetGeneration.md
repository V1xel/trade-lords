# JSON Asset Generation

## Overview

The project uses a **single generic tool** (`Tools/Python/generate_from_json.py`) to generate all Unreal Engine assets from JSON definitions. This eliminates redundant scripts and provides a consistent, maintainable approach to asset creation.

## The Problem It Solves

Previously, generated assets had incorrect properties:
- **BP_Unit_Bakery** had `UnitType = Sheep` and `ConsumesResource = Wool` (wrong!)
- **DA_Resource_Beer** had redundant `ResourceName` field when the enum already provided the name
- Each asset type (Units, Resources, Hexes, Lords) required separate generation scripts with duplicated logic

## The Solution

**One generic tool** that:
1. Reads JSON definitions with embedded metadata
2. Automatically maps JSON properties to C++ class properties
3. Handles enum conversions using defined mappings
4. Works with both Blueprints and DataAssets
5. Validates data before generation

## Usage

### Generate All Assets

```bash
python Tools/Python/generate_from_json.py --all
```

This discovers all `.json` files in `.claude/context/` and generates assets from them.

### Generate From Single File

```bash
python Tools/Python/generate_from_json.py .claude/context/Gameplay/Units/units.json
```

### Generate Specific Module

```bash
# Units
python Tools/Python/generate_from_json.py .claude/context/Gameplay/Units/units.json

# Resources
python Tools/Python/generate_from_json.py .claude/context/Gameplay/Resources/resources.json

# Hexes
python Tools/Python/generate_from_json.py .claude/context/Gameplay/Hexes/hexes.json

# Lords
python Tools/Python/generate_from_json.py .claude/context/Gameplay/Lords/lords.json
```

## JSON Schema

Each JSON file must follow this structure:

```json
{
  "_meta": {
    "asset_type": "blueprint | dataasset",
    "parent_class": "/Script/TL.ClassName",
    "output_path": "/Game/FolderName",
    "enums": {
      "PropertyName": {
        "type": "/Script/TL.EEnumName",
        "mapping": {
          "json_value": "EnumValue"
        }
      }
    },
    "property_mapping": {
      "json_field_name": "UnrealPropertyName"
    }
  },
  "items": [
    {
      "name": "AssetName",
      "json_field_name": "value",
      ...
    }
  ]
}
```

### Metadata Fields

#### `_meta.asset_type`
- **"blueprint"**: Creates a Blueprint child class (uses `create_blueprint_with_properties`)
- **"dataasset"**: Creates a DataAsset (uses `create_data_asset_with_properties`)

#### `_meta.parent_class`
The C++ class to inherit from:
- `/Script/TL.Unit` - For unit blueprints
- `/Script/TL.HexTile` - For hex tile blueprints
- `/Script/TL.ResourceDefinition` - For resource data assets
- `/Script/TL.LordDefinition` - For lord data assets

#### `_meta.output_path`
Unreal content path where assets will be created:
- `/Game/Units`
- `/Game/Resources`
- `/Game/Hexes`
- `/Game/Lords`

#### `_meta.enums`
Defines how JSON values map to C++ enum values:

```json
"enums": {
  "UnitType": {
    "type": "/Script/TL.EUnitType",
    "mapping": {
      "Sheep": "Sheep",
      "Cheese Dairy": "CheeseDairy"
    }
  }
}
```

The tool automatically converts JSON string values to proper enum objects for Unreal.

#### `_meta.property_mapping`
Maps JSON field names (snake_case) to Unreal property names (PascalCase):

```json
"property_mapping": {
  "display_name": "UnitType",
  "unit_cost": "UnitCost",
  "terrain_type": "RequiredTerrain"
}
```

If no mapping is provided, the tool auto-converts `snake_case` to `PascalCase`.

### Item Fields

Each item in the `items` array represents one asset:

- **name** (required): The asset name (e.g., `BP_Unit_Sheep`, `DA_Resource_Wool`)
- **description** (optional): Documentation, not used for asset properties
- **other fields**: Mapped to Unreal properties via `property_mapping` or auto-converted

## Examples

### Units (Blueprint)

```json
{
  "_meta": {
    "asset_type": "blueprint",
    "parent_class": "/Script/TL.Unit",
    "output_path": "/Game/Units",
    "enums": {
      "UnitType": {
        "type": "/Script/TL.EUnitType",
        "mapping": { "Sheep": "Sheep", "Bakery": "Bakery" }
      },
      "RequiredTerrain": {
        "type": "/Script/TL.ETerrainType",
        "mapping": { "Grassland": "Grassland", "Forest": "Forest" }
      }
    },
    "property_mapping": {
      "display_name": "UnitType",
      "unit_cost": "UnitCost",
      "terrain_type": "RequiredTerrain"
    }
  },
  "items": [
    {
      "name": "BP_Unit_Bakery",
      "display_name": "Bakery",
      "unit_cost": 6,
      "terrain_type": "Grassland",
      "produces_resource": "Bread",
      "consumes_resource": "Grain"
    }
  ]
}
```

Result: **BP_Unit_Bakery** with:
- `UnitType = Bakery` (enum)
- `UnitCost = 6` (int)
- `RequiredTerrain = Grassland` (enum)
- `ProducesResource = Bread` (enum)
- `ConsumesResource = Grain` (enum)

### Resources (DataAsset)

```json
{
  "_meta": {
    "asset_type": "dataasset",
    "parent_class": "/Script/TL.ResourceDefinition",
    "output_path": "/Game/Resources",
    "enums": {
      "ResourceType": {
        "type": "/Script/TL.EResourceType",
        "mapping": { "Beer": "Beer" }
      },
      "ResourceCategory": {
        "type": "/Script/TL.EResourceCategory",
        "mapping": { "Processed": "Processed" }
      }
    },
    "property_mapping": {
      "resource_type": "ResourceType",
      "category": "ResourceCategory"
    }
  },
  "items": [
    {
      "name": "DA_Resource_Beer",
      "resource_type": "Beer",
      "category": "Processed",
      "end_game_value": 3,
      "base_market_price": 6
    }
  ]
}
```

Result: **DA_Resource_Beer** with:
- `ResourceType = Beer` (enum) - NO redundant ResourceName string!
- `ResourceCategory = Processed` (enum)
- `EndGameValue = 3` (int)
- `BaseMarketPrice = 6` (int)

## Benefits

### 1. Single Source of Truth
All asset properties defined in JSON, co-located with documentation.

### 2. No More Wrong Properties
- BP_Unit_Bakery will **always** have `UnitType = Bakery`, `ConsumesResource = Grain`
- Impossible to have mismatched enum values

### 3. No Redundant Fields
Removed redundant `ResourceName` field from `ResourceDefinition.h`. The `EResourceType` enum's DisplayName provides the name.

### 4. One Tool for Everything
Single generic script handles:
- Units (Blueprints)
- Resources (DataAssets)
- Hexes (Blueprints)
- Lords (DataAssets)
- Any future asset types

### 5. Easy to Extend
To add new asset types:
1. Create JSON file with `_meta` section
2. Run `generate_from_json.py`
3. Done!

### 6. Consistent & Maintainable
- No duplicated mapping code
- Centralized enum conversions
- Self-documenting JSON structure

## JSON File Locations

All JSON definitions are stored alongside their module documentation:

```
.claude/context/Gameplay/
├── Units/
│   ├── units.json          ← Unit definitions
│   ├── README.md
│   ├── Sheep.md
│   └── ...
├── Resources/
│   ├── resources.json      ← Resource definitions
│   ├── README.md
│   ├── Wool.md
│   └── ...
├── Hexes/
│   ├── hexes.json          ← Hex tile definitions
│   ├── README.md
│   ├── Grassland.md
│   └── ...
└── Lords/
    ├── lords.json          ← Lord definitions
    ├── README.md
    ├── Aldric.md
    └── ...
```

## Type Conversions

The tool automatically handles:

### Enums
JSON string → Unreal enum via mapping:
```json
"terrain_type": "Grassland" → TerrainType = ETerrainType::Grassland
```

### Colors
JSON array → LinearColor:
```json
"tile_color": [0.2, 0.8, 0.3, 1.0] → FLinearColor(0.2, 0.8, 0.3, 1.0)
```

### Booleans
JSON boolean → Unreal boolean:
```json
"is_river_delta": false → bIsRiverDelta = false
```

### Numbers
JSON number → Unreal int/float:
```json
"unit_cost": 6 → UnitCost = 6
```

### Strings
JSON string → Unreal FText/FString:
```json
"lord_name": "Lord Aldric" → LordName = FText::FromString("Lord Aldric")
```

### Null Values
JSON null → Property not set (uses C++ default):
```json
"consumes_resource": null → ConsumesResource not set in Blueprint
```

## Validation

The tool validates:
- Required `_meta` fields present
- JSON file exists
- Enum mappings defined for enum properties
- Each item has `name` field

Errors are reported clearly:
```
ERROR: JSON file must contain '_meta' section
ERROR: No enum mapping for UnitType=InvalidValue
WARNING: Item missing 'name' field, skipping
```

## Integration with C++ Classes

The JSON properties must match C++ class properties:

**Source/TL/Units/Unit.h**:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
EUnitType UnitType;           // Mapped from display_name → UnitType enum

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
int32 UnitCost;               // Mapped from unit_cost

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
ETerrainType RequiredTerrain; // Mapped from terrain_type → RequiredTerrain enum
```

**Source/TL/Resources/ResourceDefinition.h**:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
EResourceType ResourceType;         // Mapped from resource_type → ResourceType enum

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
EResourceCategory ResourceCategory; // Mapped from category → ResourceCategory enum

// ResourceName field REMOVED - redundant with enum DisplayName
```

## Future Additions

To add new asset types:

1. **Create C++ class** with UPROPERTY fields
2. **Create JSON file** in `.claude/context/[Module]/` with:
   - `_meta` section defining asset type, parent class, enum mappings
   - `items` array with asset definitions
3. **Run tool**: `python generate_from_json.py path/to/new.json`
4. **Done!** Assets generated with correct properties

Example for new "Building" type:
```json
{
  "_meta": {
    "asset_type": "blueprint",
    "parent_class": "/Script/TL.Building",
    "output_path": "/Game/Buildings",
    "enums": { ... }
  },
  "items": [
    { "name": "BP_Building_Market", ... }
  ]
}
```

## Related Files

- **Tool**: `Tools/Python/generate_from_json.py`
- **Units JSON**: `.claude/context/Gameplay/Units/units.json`
- **Resources JSON**: `.claude/context/Gameplay/Resources/resources.json`
- **Hexes JSON**: `.claude/context/Gameplay/Hexes/hexes.json`
- **Lords JSON**: `.claude/context/Gameplay/Lords/lords.json`
- **Helper**: `Tools/Python/create_blueprint.py`
- **Helper**: `Tools/Python/create_data_asset.py`
