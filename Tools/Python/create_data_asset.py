import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def create_data_asset_with_properties(asset_class_path, asset_path, asset_name, properties):
    executor = UnrealRemoteExecutor()

    if not executor.connect():
        return {"success": False, "result": "Failed to connect to Unreal Engine"}

    property_assignments = ""
    for prop_name, prop_value in properties.items():
        if isinstance(prop_value, bool):
            value_str = "True" if prop_value else "False"
        elif isinstance(prop_value, str):
            # Escape single quotes in the string for generated Python code
            escaped_value = prop_value.replace("'", "\\'")
            value_str = f"unreal.Text('{escaped_value}')" if 'Name' in prop_name or 'Description' in prop_name or 'Title' in prop_name else f"'{escaped_value}'"
        elif isinstance(prop_value, (list, tuple)) and len(prop_value) == 4:
            value_str = f"unreal.LinearColor({prop_value[0]}, {prop_value[1]}, {prop_value[2]}, {prop_value[3]})"
        elif isinstance(prop_value, dict):
            value_str = str(prop_value)
        else:
            value_str = str(prop_value)

        property_assignments += f"    asset.set_editor_property('{prop_name}', {value_str})\n"

    code = f"""
import unreal

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
editor_asset_lib = unreal.EditorAssetLibrary()

if not editor_asset_lib.does_directory_exist('{asset_path}'):
    editor_asset_lib.make_directory('{asset_path}')

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

{property_assignments}

    editor_asset_lib.save_loaded_asset(asset)
    print(f'Saved Data Asset: {asset_path}/{asset_name}')
else:
    print(f'Failed to create Data Asset: {asset_path}/{asset_name}')
"""

    result = executor.execute(code)
    executor.disconnect()

    return result
