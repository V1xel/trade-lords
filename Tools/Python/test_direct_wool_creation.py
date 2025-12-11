"""Try creating DA_Resource_Wool with verbose verification"""

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

print("Attempting to create DA_Resource_Wool...")

# First, explicitly try to delete if it exists anywhere
print("\\nStep 1: Checking for existing asset...")
paths_to_check = [
    '/Game/Resources/DA_Resource_Wool',
    '/Game/Resources/DA_Resource_Wool.DA_Resource_Wool',
]
for path in paths_to_check:
    if unreal.EditorAssetLibrary.does_asset_exist(path):
        print(f"  Found existing: {path}, deleting...")
        unreal.EditorAssetLibrary.delete_asset(path)

print("\\nStep 2: Ensuring directory exists...")
if not unreal.EditorAssetLibrary.does_directory_exist('/Game/Resources'):
    unreal.EditorAssetLibrary.make_directory('/Game/Resources')
    print("  Created directory")
else:
    print("  Directory exists")

print("\\nStep 3: Creating asset...")
asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
factory = unreal.DataAssetFactory()
resource_class = unreal.load_class(None, '/Script/TL.ResourceDefinition')
factory.set_editor_property('data_asset_class', resource_class)

print(f"  Asset tools: {asset_tools}")
print(f"  Factory: {factory}")
print(f"  Resource class: {resource_class}")
print(f"  Factory data_asset_class: {factory.get_editor_property('data_asset_class')}")

print("\\nStep 4: Calling create_asset...")
asset = asset_tools.create_asset(
    'DA_Resource_Wool',
    '/Game/Resources',
    None,
    factory
)

print(f"\\nStep 5: Result...")
print(f"  Returned value: {asset}")
print(f"  Type: {type(asset) if asset else 'None'}")

if asset:
    print(f"  Path name: {asset.get_path_name()}")
    print(f"  Class: {asset.get_class().get_name()}")

    # Set properties
    print("\\nStep 6: Setting properties...")
    ResourceType = type(asset.get_editor_property('ResourceType'))
    ResourceCategory = type(asset.get_editor_property('ResourceCategory'))

    asset.set_editor_property('ResourceType', ResourceType.WOOL)
    asset.set_editor_property('ResourceCategory', ResourceCategory.BASIC)
    asset.set_editor_property('EndGameValue', 1)
    asset.set_editor_property('BaseMarketPrice', 3)

    print("\\nStep 7: Saving...")
    unreal.EditorAssetLibrary.save_loaded_asset(asset)
    print("  Saved!")

    # Verify
    print("\\nStep 8: Verification...")
    exists = unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_Wool.DA_Resource_Wool')
    print(f"  Asset exists: {exists}")

    if exists:
        loaded = unreal.EditorAssetLibrary.load_asset('/Game/Resources/DA_Resource_Wool.DA_Resource_Wool')
        print(f"  Loaded asset: {loaded}")
        rt = loaded.get_editor_property('ResourceType')
        print(f"  ResourceType: {rt}")
else:
    print("\\nFAILED: create_asset returned None")
    print("\\nChecking if it exists anyway...")
    exists = unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_Wool.DA_Resource_Wool')
    print(f"  Asset exists: {exists}")
"""

result = executor.execute(code)
executor.disconnect()
