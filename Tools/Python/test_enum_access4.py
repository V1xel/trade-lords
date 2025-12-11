"""Test full path enum access"""

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

print("Testing full path enum notation...")

# Create test asset
if unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_TestEnum4.DA_Resource_TestEnum4'):
    unreal.EditorAssetLibrary.delete_asset('/Game/Resources/DA_Resource_TestEnum4.DA_Resource_TestEnum4')

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
factory = unreal.DataAssetFactory()
factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

asset = asset_tools.create_asset('DA_Resource_TestEnum4', '/Game/Resources', None, factory)

if asset:
    print(f"Created asset: {asset.get_path_name()}")

    # Try method 1: String with :: notation
    try:
        print("Method 1: String with :: notation...")
        asset.set_editor_property('ResourceType', 'EResourceType::Wool')
        print("  SUCCESS with EResourceType::Wool")
    except Exception as e:
        print(f"  FAILED: {e}")

    # Try method 2: Just the enum value name
    try:
        print("Method 2: Just value name...")
        asset.set_editor_property('ResourceType', 'Wool')
        print("  SUCCESS with Wool")
    except Exception as e:
        print(f"  FAILED: {e}")

    # Try method 3: Load enum and use it somehow
    try:
        print("Method 3: Using loaded enum...")
        enum_obj = unreal.load_object(None, '/Script/TL.EResourceType')
        # Try to use the enum object directly with the value name
        # Some Unreal versions support this
        value = enum_obj.get_enum_name_by_index(0)  # Get first value
        print(f"  Enum value at index 0: {value}")
    except Exception as e:
        print(f"  FAILED: {e}")

    # Try method 4: Check Python enum wrapper
    try:
        print("Method 4: Check for generated Python enum...")
        # Unreal sometimes generates Python wrappers
        import TL
        if hasattr(TL, 'EResourceType'):
            print(f"  Found TL.EResourceType!")
            wool = TL.EResourceType.WOOL
            asset.set_editor_property('ResourceType', wool)
            print(f"  SUCCESS with TL.EResourceType.WOOL")
    except ImportError:
        print("  Module TL not found")
    except Exception as e:
        print(f"  FAILED: {e}")

    # Try method 5: Using Byte
    try:
        print("Method 5: Using Byte wrapper...")
        # This is a long shot
        byte_val = unreal.Byte(0)
        asset.set_editor_property('ResourceType', byte_val)
        print(f"  SUCCESS with Byte(0)")
    except Exception as e:
        print(f"  FAILED: {e}")

    # Save whatever we have
    unreal.EditorAssetLibrary.save_loaded_asset(asset)

    # Verify
    rt = asset.get_editor_property('ResourceType')
    print(f"\\nFinal ResourceType: {rt} (type: {type(rt)})")

else:
    print("ERROR: Failed to create asset")
"""

result = executor.execute(code)
executor.disconnect()
