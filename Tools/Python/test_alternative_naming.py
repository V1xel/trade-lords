"""Test alternative naming patterns"""

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

# Test different naming patterns for Wool
test_names = [
    'DA_ResourceWool',      # No underscore before resource name
    'DAResource_Wool',      # No underscore after DA
    'DAResourceWool',        # No underscores at all
]

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
        # Set a property to verify it works
        ResourceType = type(asset.get_editor_property('ResourceType'))
        asset.set_editor_property('ResourceType', ResourceType.WOOL)
        unreal.EditorAssetLibrary.save_loaded_asset(asset)

        # Verify
        rt = asset.get_editor_property('ResourceType')
        print(f"    ResourceType set to: {rt}")

        # Keep this one if it worked
        if name == 'DA_ResourceWool':
            print(f"    Keeping this asset for testing")
        else:
            unreal.EditorAssetLibrary.delete_asset(asset.get_path_name())
    else:
        print(f"  ✗ FAILED")
"""

result = executor.execute(code)
executor.disconnect()
