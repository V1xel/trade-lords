"""Test using the ResourceType class that was returned"""

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

print("Testing using returned enum type...")

# Create test asset
if unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_TestEnum5.DA_Resource_TestEnum5'):
    unreal.EditorAssetLibrary.delete_asset('/Game/Resources/DA_Resource_TestEnum5.DA_Resource_TestEnum5')

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
factory = unreal.DataAssetFactory()
factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

asset = asset_tools.create_asset('DA_Resource_TestEnum5', '/Game/Resources', None, factory)

if asset:
    print(f"Created asset: {asset.get_path_name()}")

    # Get the current value to understand the type
    current_type = asset.get_editor_property('ResourceType')
    current_category = asset.get_editor_property('ResourceCategory')

    print(f"Current ResourceType: {current_type} (type: {type(current_type)})")
    print(f"Current ResourceCategory: {current_category} (type: {type(current_category)})")

    # Get the class from the current value
    ResourceType = type(current_type)
    ResourceCategory = type(current_category)

    print(f"\\nResourceType class: {ResourceType}")
    print(f"ResourceType dir: {[x for x in dir(ResourceType) if not x.startswith('_')]}")

    # Try to access specific values
    print("\\nTrying to access enum values from the class...")
    try:
        wool = ResourceType.WOOL
        print(f"  ResourceType.WOOL = {wool}")
    except Exception as e:
        print(f"  ResourceType.WOOL failed: {e}")

    try:
        milk = ResourceType.MILK
        print(f"  ResourceType.MILK = {milk}")
    except Exception as e:
        print(f"  ResourceType.MILK failed: {e}")

    # If that worked, try setting
    try:
        print("\\nTrying to set ResourceType to MILK...")
        asset.set_editor_property('ResourceType', ResourceType.MILK)
        print("  SUCCESS!")

        # Verify
        new_type = asset.get_editor_property('ResourceType')
        print(f"  Verified: {new_type}")

        # Try setting category too
        print("\\nTrying to set ResourceCategory to PROCESSED...")
        asset.set_editor_property('ResourceCategory', ResourceCategory.PROCESSED)

        # Set numeric properties
        asset.set_editor_property('EndGameValue', 5)
        asset.set_editor_property('BaseMarketPrice', 10)

        # Save
        unreal.EditorAssetLibrary.save_loaded_asset(asset)
        print("\\nAsset saved successfully!")

        # Verify all properties
        print("\\nFinal properties:")
        print(f"  ResourceType: {asset.get_editor_property('ResourceType')}")
        print(f"  ResourceCategory: {asset.get_editor_property('ResourceCategory')}")
        print(f"  EndGameValue: {asset.get_editor_property('EndGameValue')}")
        print(f"  BaseMarketPrice: {asset.get_editor_property('BaseMarketPrice')}")

    except Exception as e:
        import traceback
        print(f"  ERROR: {e}")
        print(traceback.format_exc())

else:
    print("ERROR: Failed to create asset")
"""

result = executor.execute(code)
executor.disconnect()
