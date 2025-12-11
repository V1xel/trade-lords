"""
Create Contract DataAssets with TMap support
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def create_contract_with_properties(asset_class_path, asset_path, asset_name, properties, required_resources):
    """
    Create a contract DataAsset with RequiredResources TMap

    Args:
        asset_class_path: Path to C++ class
        asset_path: Unreal content path
        asset_name: Name of the asset
        properties: Dictionary of simple properties
        required_resources: Dictionary of {resource_name: amount}
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
        enum_setup = "\n    # Get enum classes from the asset\n"
        seen_enum_types = {}
        for prop_name, prop_value in enum_properties.items():
            enum_type = prop_value['enum']
            enum_class_name = enum_type.split('.')[-1][1:]  # Remove 'E' prefix
            if enum_class_name not in seen_enum_types:
                enum_setup += f"    {enum_class_name} = type(asset.get_editor_property('{prop_name}'))\n"
                seen_enum_types[enum_class_name] = True

    # Build property assignments for regular properties
    property_assignments = ""
    for prop_name, prop_value in regular_properties.items():
        if isinstance(prop_value, bool):
            value_str = "True" if prop_value else "False"
        elif isinstance(prop_value, str):
            escaped_value = prop_value.replace("'", "\\'")
            value_str = f"unreal.Text('{escaped_value}')" if 'Name' in prop_name or 'Description' in prop_name or 'Title' in prop_name else f"'{escaped_value}'"
        elif isinstance(prop_value, (list, tuple)) and len(prop_value) == 4:
            value_str = f"unreal.LinearColor({prop_value[0]}, {prop_value[1]}, {prop_value[2]}, {prop_value[3]})"
        else:
            value_str = str(prop_value)
        property_assignments += f"    asset.set_editor_property('{prop_name}', {value_str})\n"

    # Build property assignments for enum properties
    for prop_name, prop_value in enum_properties.items():
        enum_type = prop_value['enum']
        enum_value = prop_value['value']
        enum_class_name = enum_type.split('.')[-1][1:]  # Remove 'E' prefix
        # Convert enum value to UPPERCASE with underscores
        import re
        enum_value_snake = re.sub(r'(?<!^)(?=[A-Z])', '_', enum_value)
        enum_value_upper = enum_value_snake.upper()
        property_assignments += f"    asset.set_editor_property('{prop_name}', {enum_class_name}.{enum_value_upper})\n"

    # Build RequiredResources TMap
    required_resources_setup = ""
    if required_resources:
        required_resources_setup = "\n    # Set RequiredResources TMap\n"
        required_resources_setup += "    ResourceType = type(asset.get_editor_property('ImportGoodReward'))\n"
        required_resources_setup += "    required_resources_map = {}\n"
        for resource_name, amount in required_resources.items():
            # Convert resource name to enum format (e.g., 'SugarCane' -> 'SUGAR_CANE')
            import re
            resource_snake = re.sub(r'(?<!^)(?=[A-Z])', '_', resource_name)
            resource_upper = resource_snake.upper()
            required_resources_setup += f"    required_resources_map[ResourceType.{resource_upper}] = {amount}\n"
        required_resources_setup += "    asset.set_editor_property('RequiredResources', required_resources_map)\n"

    code = f"""
import unreal

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

if not unreal.EditorAssetLibrary.does_directory_exist('{asset_path}'):
    unreal.EditorAssetLibrary.make_directory('{asset_path}')

factory = unreal.DataAssetFactory()
factory.set_editor_property('data_asset_class', unreal.load_class(None, '{asset_class_path}'))

asset = asset_tools.create_asset(
    '{asset_name}',
    '{asset_path}',
    None,
    factory
)

if asset:
    print(f'Successfully created Data Asset: {{asset.get_path_name()}}')
{enum_setup}{required_resources_setup}
{property_assignments}

    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print(f'Saved Data Asset: {asset_path}/{asset_name}')
else:
    print(f'Failed to create Data Asset: {asset_path}/{asset_name}')
"""

    result = executor.execute(code)
    executor.disconnect()

    return result
