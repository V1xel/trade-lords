"""Test accessing enum values from loaded enum object"""

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

print("Loading enum with load_object...")
resource_enum = unreal.load_object(None, '/Script/TL.EResourceType')
print(f"Loaded: {resource_enum}")
print(f"Type: {type(resource_enum)}")
print(f"Dir: {[x for x in dir(resource_enum) if not x.startswith('_')]}")

# Try to get enum values
print("\\nTrying to access enum values...")
try:
    # Try getting the enum value by name
    wool = getattr(resource_enum, 'WOOL', None)
    print(f"WOOL (uppercase): {wool}")
except Exception as e:
    print(f"WOOL (uppercase) failed: {e}")

try:
    wool = getattr(resource_enum, 'Wool', None)
    print(f"Wool (PascalCase): {wool}")
except Exception as e:
    print(f"Wool (PascalCase) failed: {e}")

# Try getting enum names
try:
    names = resource_enum.get_editor_property('names') if hasattr(resource_enum, 'get_editor_property') else None
    print(f"Names property: {names}")
except Exception as e:
    print(f"Names failed: {e}")

# Check if it's an EnumClass
print(f"\\nIs EnumClass: {hasattr(resource_enum, 'enum_values')}")

# Try unreal.EnumLibrary methods
print("\\nTrying EnumLibrary methods...")
try:
    # This might not exist, but let's try
    if hasattr(unreal, 'EnumLibrary'):
        print("Found EnumLibrary")
except Exception as e:
    print(f"EnumLibrary check failed: {e}")

# Try using the integer value directly
print("\\nTrying integer enum values...")
try:
    # In UE, enum values are typically just integers
    # EResourceType::Wool is probably 0
    print("Testing with integer 0 (first enum value)...")

    # Create test asset
    if unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_TestEnum3.DA_Resource_TestEnum3'):
        unreal.EditorAssetLibrary.delete_asset('/Game/Resources/DA_Resource_TestEnum3.DA_Resource_TestEnum3')

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

    asset = asset_tools.create_asset('DA_Resource_TestEnum3', '/Game/Resources', None, factory)

    if asset:
        print(f"Created asset: {asset.get_path_name()}")

        # Try setting with integer
        print("Setting ResourceType to 0...")
        asset.set_editor_property('ResourceType', 0)

        # Try setting with the enum name as string
        print("Setting ResourceCategory to 'BASIC' string...")
        try:
            asset.set_editor_property('ResourceCategory', 'BASIC')
        except:
            print("String didn't work, trying integer 0...")
            asset.set_editor_property('ResourceCategory', 0)

        asset.set_editor_property('EndGameValue', 1)
        asset.set_editor_property('BaseMarketPrice', 3)

        unreal.EditorAssetLibrary.save_loaded_asset(asset)
        print("SUCCESS: Asset saved!")

        # Verify what was set
        rt = asset.get_editor_property('ResourceType')
        rc = asset.get_editor_property('ResourceCategory')
        print(f"Verified ResourceType: {rt} (type: {type(rt)})")
        print(f"Verified ResourceCategory: {rc} (type: {type(rc)})")

except Exception as e:
    import traceback
    print(f"ERROR: {e}")
    print(traceback.format_exc())
"""

result = executor.execute(code)
executor.disconnect()
