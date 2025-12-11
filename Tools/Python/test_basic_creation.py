"""Test basic asset creation without properties"""

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

print("Testing basic DataAsset creation...")

# Make sure directory exists
if not unreal.EditorAssetLibrary.does_directory_exist('/Game/Resources'):
    unreal.EditorAssetLibrary.make_directory('/Game/Resources')
    print("Created /Game/Resources directory")

# Get asset tools
asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
print(f"Asset tools: {asset_tools}")

# Load the ResourceDefinition class
resource_class = unreal.load_class(None, '/Script/TL.ResourceDefinition')
print(f"ResourceDefinition class: {resource_class}")

# Create factory
factory = unreal.DataAssetFactory()
print(f"Factory: {factory}")

# Set the data asset class
factory.set_editor_property('data_asset_class', resource_class)
print(f"Factory class set to: {factory.get_editor_property('data_asset_class')}")

# Try to create the asset
print("\\nAttempting to create asset...")
asset = asset_tools.create_asset(
    'DA_Resource_TestBasic',
    '/Game/Resources',
    None,
    factory
)

print(f"create_asset returned: {asset}")
print(f"Type: {type(asset)}")

if asset:
    print(f"SUCCESS! Created: {asset.get_path_name()}")

    # Try to save
    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print("Asset saved!")

    # Verify it exists
    exists = unreal.EditorAssetLibrary.does_asset_exist(f'/Game/Resources/DA_Resource_TestBasic.DA_Resource_TestBasic')
    print(f"Asset exists: {exists}")
else:
    print("FAILED: create_asset returned None")

    # Try to see if it was created anyway
    exists = unreal.EditorAssetLibrary.does_asset_exist(f'/Game/Resources/DA_Resource_TestBasic.DA_Resource_TestBasic')
    print(f"Asset exists anyway: {exists}")
"""

result = executor.execute(code)
executor.disconnect()
