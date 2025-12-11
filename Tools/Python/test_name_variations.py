"""Test different naming variations"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor

executor = UnrealRemoteExecutor()

if not executor.connect():
    print("Failed to connect")
    sys.exit(1)

code = """
import unreal

# Test various names
test_names = [
    'DA_Resource_Wool',
    'ResourceWool',
    'Wool_DA',
    'WoolResource',
    'DA_Wool',
]

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

for name in test_names:
    print(f"\\nTrying name: {name}")

    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

    asset = asset_tools.create_asset(
        name,
        '/Game/Resources',
        None,
        factory
    )

    if asset:
        print(f"  SUCCESS: {asset.get_path_name()}")
        # Delete it immediately
        unreal.EditorAssetLibrary.delete_asset(asset.get_path_name())
    else:
        print(f"  FAILED")
"""

result = executor.execute(code)
executor.disconnect()
