"""Debug resource creation by printing the generated code"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# Load JSON
json_path = r'C:\Users\vital\Projects\TL\.claude\context\Gameplay\Resources\resources.json'
with open(json_path, 'r') as f:
    data = json.load(f)

meta = data['_meta']
item = data['items'][0]  # Just test with Wool

# Build properties string
properties = {}

# Set ResourceType enum
properties['ResourceType'] = {
    'enum': '/Script/TL.EResourceType',
    'value': 'Wool'
}

# Set ResourceCategory enum
properties['ResourceCategory'] = {
    'enum': '/Script/TL.EResourceCategory',
    'value': 'Basic'
}

# Set EndGameValue
properties['EndGameValue'] = 1

# Set BaseMarketPrice
properties['BaseMarketPrice'] = 3

# Generate property assignments
property_assignments = ""
for prop_name, prop_value in properties.items():
    if isinstance(prop_value, bool):
        value_str = "True" if prop_value else "False"
    elif isinstance(prop_value, str):
        escaped_value = prop_value.replace("'", "\\'")
        value_str = f"unreal.Text('{escaped_value}')" if 'Name' in prop_name or 'Description' in prop_name or 'Title' in prop_name else f"'{escaped_value}'"
    elif isinstance(prop_value, (list, tuple)) and len(prop_value) == 4:
        value_str = f"unreal.LinearColor({prop_value[0]}, {prop_value[1]}, {prop_value[2]}, {prop_value[3]})"
    elif isinstance(prop_value, dict) and 'enum' in prop_value:
        enum_type = prop_value['enum']
        enum_value = prop_value['value']
        value_str = f"unreal.load_enum('{enum_type}').{enum_value}"
    else:
        value_str = str(prop_value)

    property_assignments += f"    asset.set_editor_property('{prop_name}', {value_str})\n"

# Generate full code
code = f"""
import unreal

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

if not unreal.EditorAssetLibrary.does_directory_exist('/Game/Resources'):
    unreal.EditorAssetLibrary.make_directory('/Game/Resources')

factory = unreal.DataAssetFactory()
factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

asset = asset_tools.create_asset(
    'DA_Resource_Wool_Test',
    '/Game/Resources',
    None,
    factory
)

if asset:
    print(f'Successfully created Data Asset: {{asset.get_path_name()}}')

{property_assignments}

    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print(f'Saved Data Asset')
else:
    print(f'Failed to create Data Asset')
"""

print("="*60)
print("GENERATED CODE:")
print("="*60)
print(code)
print("="*60)
