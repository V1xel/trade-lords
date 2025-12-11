"""Test lord asset naming"""

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

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

# Test different naming patterns
test_names = [
    'DA_Lord_Aldric',
    'DA_Aldric',
    'Lord_Aldric',
]

for name in test_names:
    print(f"\\nTrying: {name}")

    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.LordDefinition'))

    asset = asset_tools.create_asset(
        name,
        '/Game/Lords',
        None,
        factory
    )

    if asset:
        print(f"  ✓ SUCCESS")
        # Delete immediately
        unreal.EditorAssetLibrary.delete_asset(asset.get_path_name())
    else:
        print(f"  ✗ FAILED")
"""

result = executor.execute(code)
executor.disconnect()
