"""
Create Blueprint assets in Unreal Engine via remote execution
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def create_blueprint_with_properties(parent_class_path, blueprint_path, blueprint_name, properties):
    """
    Create a Blueprint child class and set its properties

    Args:
        parent_class_path (str): Path to parent C++ class (e.g., '/Script/TL.GameTile')
        blueprint_path (str): Unreal content path for the Blueprint (e.g., '/Game/Blueprints')
        blueprint_name (str): Name of the Blueprint asset (e.g., 'BP_GrassTile')
        properties (dict): Dictionary of property_name: property_value to set

    Returns:
        dict: Result from the operation
    """
    executor = UnrealRemoteExecutor()

    if not executor.connect():
        return {"success": False, "result": "Failed to connect to Unreal Engine"}

    # Separate enum and non-enum properties
    enum_properties = {}
    regular_properties = {}

    for prop_name, prop_value in properties.items():
        if isinstance(prop_value, dict) and 'enum' in prop_value:
            enum_properties[prop_name] = prop_value
        else:
            regular_properties[prop_name] = prop_value

    # Build enum class retrieval code
    enum_setup = ""
    if enum_properties:
        enum_setup = "\n        # Get enum classes from the CDO\n"
        seen_enum_types = {}
        for prop_name, prop_value in enum_properties.items():
            enum_type = prop_value['enum']
            # Extract the enum class name (e.g., '/Script/TL.EUnitType' -> 'UnitType')
            enum_class_name = enum_type.split('.')[-1][1:]  # Remove 'E' prefix
            if enum_class_name not in seen_enum_types:
                enum_setup += f"        {enum_class_name} = type(cdo.get_editor_property('{prop_name}'))\n"
                seen_enum_types[enum_class_name] = True

    # Build property assignments for regular properties
    property_assignments = ""
    for prop_name, prop_value in regular_properties.items():
        if isinstance(prop_value, bool):
            value_str = "True" if prop_value else "False"
        elif isinstance(prop_value, str):
            escaped_value = prop_value.replace("'", "\\'")
            value_str = f"'{escaped_value}'"
        elif isinstance(prop_value, (list, tuple)) and len(prop_value) == 4:
            value_str = f"unreal.LinearColor({prop_value[0]}, {prop_value[1]}, {prop_value[2]}, {prop_value[3]})"
        else:
            value_str = str(prop_value)
        property_assignments += f"        cdo.set_editor_property('{prop_name}', {value_str})\n"

    # Build property assignments for enum properties
    for prop_name, prop_value in enum_properties.items():
        enum_type = prop_value['enum']
        enum_value = prop_value['value']
        enum_class_name = enum_type.split('.')[-1][1:]  # Remove 'E' prefix
        # Convert enum value to UPPERCASE with underscores
        # Handle CamelCase by adding underscores before capitals (e.g., 'SugarCane' -> 'SUGAR_CANE')
        import re
        enum_value_snake = re.sub(r'(?<!^)(?=[A-Z])', '_', enum_value)
        enum_value_upper = enum_value_snake.upper()
        property_assignments += f"        cdo.set_editor_property('{prop_name}', {enum_class_name}.{enum_value_upper})\n"

    code = f"""
import unreal

# Get asset tools
asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

# Ensure destination directory exists
if not unreal.EditorAssetLibrary.does_directory_exist('{blueprint_path}'):
    unreal.EditorAssetLibrary.make_directory('{blueprint_path}')

# Create Blueprint factory
factory = unreal.BlueprintFactory()
factory.set_editor_property('parent_class', unreal.load_class(None, '{parent_class_path}'))

# Create the Blueprint asset
asset = asset_tools.create_asset(
    '{blueprint_name}',
    '{blueprint_path}',
    unreal.Blueprint,
    factory
)

if asset:
    print(f'Successfully created Blueprint: {{asset.get_path_name()}}')

    # Get the generated class and CDO
    bp_class = asset.generated_class()
    if bp_class:
        cdo = unreal.get_default_object(bp_class)
{enum_setup}
        # Set properties
{property_assignments}

        print(f'Properties configured for {{cdo.get_class().get_name()}}')

    # Save the asset
    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print(f'Saved Blueprint: {blueprint_path}/{blueprint_name}')
else:
    print(f'Failed to create Blueprint: {blueprint_path}/{blueprint_name}')
"""

    result = executor.execute(code)
    executor.disconnect()

    return result


if __name__ == "__main__":
    # Test: Create two GameTile Blueprint children

    print("Creating BP_GrassTile...")
    result1 = create_blueprint_with_properties(
        '/Script/TL.GameTile',
        '/Game/Blueprints/Tiles',
        'BP_GrassTile2',
        {
            'TileName': 'Grass Tile',
            'TileColor': (0.2, 0.8, 0.3, 1.0),  # Green
            'MovementCost': 1,
            'bCanStop': True,
            'bIsPassable': True,
            'bProvidesCover': False,
            'ResourceAmount': 0
        }
    )
    print(f"Result: {result1}\n")

    print("Creating BP_MountainTile...")
    result2 = create_blueprint_with_properties(
        '/Script/TL.GameTile',
        '/Game/Blueprints/Tiles',
        'BP_MountainTile2',
        {
            'TileName': 'Mountain Tile',
            'TileColor': (0.5, 0.5, 0.5, 1.0),  # Gray
            'MovementCost': 3,
            'bCanStop': True,
            'bIsPassable': True,
            'bProvidesCover': True,
            'ResourceAmount': 20
        }
    )
    print(f"Result: {result2}")
