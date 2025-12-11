"""Test different ways to access enums in Unreal Python"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor

executor = UnrealRemoteExecutor()

if not executor.connect():
    print("Failed to connect")
    sys.exit(1)

# Test 1: Try load_enum with attribute access
code1 = """
import unreal

print("Test 1: load_enum with attribute access")
try:
    resource_enum = unreal.load_enum('/Script/TL.EResourceType')
    print(f"Loaded enum: {resource_enum}")
    print(f"Dir: {dir(resource_enum)}")
    wool_value = resource_enum.Wool
    print(f"Wool value: {wool_value}")
except Exception as e:
    print(f"ERROR: {e}")
"""

print("=" * 60)
print("TEST 1: load_enum with attribute access")
print("=" * 60)
result1 = executor.execute(code1)

# Test 2: Try creating DataAsset with simplified approach
code2 = """
import unreal

print("\\nTest 2: Create DataAsset")
try:
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    print(f"Asset tools: {asset_tools}")

    # Ensure directory exists
    if not unreal.EditorAssetLibrary.does_directory_exist('/Game/Resources'):
        unreal.EditorAssetLibrary.make_directory('/Game/Resources')
        print("Created /Game/Resources directory")

    # Create factory
    factory = unreal.DataAssetFactory()
    resource_class = unreal.load_class(None, '/Script/TL.ResourceDefinition')
    print(f"Resource class: {resource_class}")
    factory.set_editor_property('data_asset_class', resource_class)

    # Create asset
    asset = asset_tools.create_asset(
        'DA_Resource_TestEnum',
        '/Game/Resources',
        None,
        factory
    )

    if asset:
        print(f"Created asset: {asset.get_path_name()}")

        # Try setting enum property
        resource_enum = unreal.load_enum('/Script/TL.EResourceType')
        wool_value = resource_enum.Wool
        print(f"Setting ResourceType to: {wool_value}")
        asset.set_editor_property('ResourceType', wool_value)

        # Set other properties
        category_enum = unreal.load_enum('/Script/TL.EResourceCategory')
        basic_value = category_enum.Basic
        asset.set_editor_property('ResourceCategory', basic_value)
        asset.set_editor_property('EndGameValue', 1)
        asset.set_editor_property('BaseMarketPrice', 3)

        # Save
        unreal.EditorAssetLibrary.save_loaded_asset(asset)
        print("Asset saved successfully!")
    else:
        print("ERROR: create_asset returned None")

except Exception as e:
    import traceback
    print(f"ERROR: {e}")
    print(traceback.format_exc())
"""

print("\n" + "=" * 60)
print("TEST 2: Create DataAsset with enums")
print("=" * 60)
result2 = executor.execute(code2)

executor.disconnect()
