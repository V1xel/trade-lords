# Blueprint Creator Tool

## Purpose

Programmatically create Blueprint child classes with configured default properties.

## Location

`Tools/Python/create_blueprint.py`

## Implementation

Uses Unreal Engine's `BlueprintFactory` and `AssetTools` to create Blueprint assets, then configures Class Default Object (CDO) properties via Python remote execution.

## Usage

### Programmatic

```python
from create_blueprint import create_blueprint_with_properties

result = create_blueprint_with_properties(
    parent_class_path='/Script/TL.GameTile',
    blueprint_path='/Game/Blueprints/Tiles',
    blueprint_name='BP_CustomTile',
    properties={
        'TileName': 'Custom Tile',
        'TileColor': (0.5, 0.5, 1.0, 1.0),  # Blue
        'MovementCost': 2,
        'bCanStop': True,
        'bIsPassable': True,
        'bProvidesCover': False,
        'ResourceAmount': 10
    }
)
```

## Parameters

- `parent_class_path` - Full path to C++ parent class (e.g., `/Script/ModuleName.ClassName`)
- `blueprint_path` - Unreal content path for Blueprint location
- `blueprint_name` - Name of Blueprint asset
- `properties` - Dictionary of property_name: value pairs

## Property Types

| C++ Type | Python Type | Example |
|----------|-------------|---------|
| `bool` | `bool` | `True` / `False` |
| `int32` | `int` | `42` |
| `float` | `float` | `3.14` |
| `FString` | `str` | `"Hello"` |
| `FLinearColor` | `tuple` | `(1.0, 0.0, 0.0, 1.0)` |
| `FVector` | `tuple` | `(1.0, 2.0, 3.0)` |

## Property Naming

Property names must match C++ declarations exactly:
- Use PascalCase: `TileName` not `tile_name`
- Use `b` prefix for bools: `bCanStop` not `CanStop`

## Workflow

1. Creates Blueprint asset using `BlueprintFactory`
2. Gets Blueprint's generated class
3. Retrieves Class Default Object (CDO)
4. Sets properties on CDO using `set_editor_property()`
5. Saves Blueprint asset

## Dependencies

- Parent C++ class must exist and be compiled
- Unreal Engine with Python plugins enabled
- Remote execution configured
- `unreal_remote.py` module

## Notes

- Automatically creates destination directory if missing
- Properties must be marked `UPROPERTY` with `BlueprintReadWrite` or `EditAnywhere`
- Blueprint is saved immediately after creation
- Use Blueprint Editor to verify and extend created Blueprints
