"""Test creating DA_Resource_Wool specifically"""

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

print("Testing DA_Resource_Wool creation...")

# Make sure directory exists
if not unreal.EditorAssetLibrary.does_directory_exist('/Game/Resources'):
    unreal.EditorAssetLibrary.make_directory('/Game/Resources')

# Get asset tools
asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

# Create factory
factory = unreal.DataAssetFactory()
factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

# Try to create
print("Creating asset...")
asset = asset_tools.create_asset(
    'DA_Resource_Wool',
    '/Game/Resources',
    None,
    factory
)

print(f"create_asset returned: {asset}")

if asset:
    print(f"SUCCESS! Created: {asset.get_path_name()}")

    # Get enum classes
    ResourceType = type(asset.get_editor_property('ResourceType'))
    ResourceCategory = type(asset.get_editor_property('ResourceCategory'))

    # Set properties
    asset.set_editor_property('EndGameValue', 1)
    asset.set_editor_property('BaseMarketPrice', 3)
    asset.set_editor_property('ResourceType', ResourceType.WOOL)
    asset.set_editor_property('ResourceCategory', ResourceCategory.BASIC)

    # Save
    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print("Asset saved with properties!")

    # Verify
    rt = asset.get_editor_property('ResourceType')
    rc = asset.get_editor_property('ResourceCategory')
    ev = asset.get_editor_property('EndGameValue')
    bmp = asset.get_editor_property('BaseMarketPrice')

    print(f"\\nVerified properties:")
    print(f"  ResourceType: {rt}")
    print(f"  ResourceCategory: {rc}")
    print(f"  EndGameValue: {ev}")
    print(f"  BaseMarketPrice: {bmp}")
else:
    print("FAILED: create_asset returned None")
"""

result = executor.execute(code)
executor.disconnect()
