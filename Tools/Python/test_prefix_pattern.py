"""Test DA_Resource_ prefix pattern"""

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

# Test DA_Resource_ prefix with different suffixes
test_names = [
    'DA_Resource_Test',
    'DA_Resource_Milk',
    'DA_Resource_Grain',
    'DA_Resource_Cheese',
    'DAResource_Wool',  # No underscore after DA
    'DA_Res_Wool',      # Abbreviated
]

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

for name in test_names:
    print(f"\\nTrying: {name}")

    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

    asset = asset_tools.create_asset(
        name,
        '/Game/Resources',
        None,
        factory
    )

    if asset:
        print(f"  ✓ SUCCESS")
        unreal.EditorAssetLibrary.delete_asset(asset.get_path_name())
    else:
        print(f"  ✗ FAILED")
"""

result = executor.execute(code)
executor.disconnect()
