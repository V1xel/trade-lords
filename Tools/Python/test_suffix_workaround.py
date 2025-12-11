"""Test if adding _V1 suffix works for all resources"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor

# Load resources.json
json_path = r'C:\Users\vital\Projects\TL\.claude\context\Gameplay\Resources\resources.json'
with open(json_path, 'r') as f:
    data = json.load(f)

executor = UnrealRemoteExecutor()

if not executor.connect():
    print("Failed to connect")
    sys.exit(1)

# Try creating just the first few resources with _V1 suffix
resources_to_test = ['Wool', 'Milk', 'Grain']

code = f"""
import unreal

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

test_resources = {resources_to_test}

for resource_name in test_resources:
    # Try with _V1 suffix
    asset_name = f'DA_Resource_{{resource_name}}_V1'

    print(f"\\nCreating {{asset_name}}...")

    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

    asset = asset_tools.create_asset(
        asset_name,
        '/Game/Resources',
        None,
        factory
    )

    if asset:
        print(f"  ✓ SUCCESS: {{asset.get_path_name()}}")
        # Clean up
        unreal.EditorAssetLibrary.delete_asset(asset.get_path_name())
    else:
        print(f"  ✗ FAILED")
"""

result = executor.execute(code)
executor.disconnect()

print("\n" + "="*60)
print("If all succeeded, we can use _V1 suffix as a workaround!")
print("="*60)
