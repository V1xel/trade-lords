"""Test correct enum access methods"""

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

print("Testing enum access methods...")

# Method 1: Direct import
try:
    from unreal import EResourceType
    print(f"Method 1 SUCCESS: Imported EResourceType directly")
    print(f"  EResourceType: {EResourceType}")
    print(f"  Dir: {[x for x in dir(EResourceType) if not x.startswith('_')]}")
    print(f"  EResourceType.WOOL: {EResourceType.WOOL}")
except Exception as e:
    print(f"Method 1 FAILED: {e}")

# Method 2: Access via unreal module
try:
    wool = unreal.EResourceType.WOOL
    print(f"Method 2 SUCCESS: unreal.EResourceType.WOOL = {wool}")
except Exception as e:
    print(f"Method 2 FAILED: {e}")

# Method 3: Try load_object
try:
    enum_obj = unreal.load_object(None, '/Script/TL.EResourceType')
    print(f"Method 3: load_object returned {enum_obj}")
except Exception as e:
    print(f"Method 3 FAILED: {e}")

# Method 4: Find the enum class
try:
    import inspect
    # Look for the enum in the unreal module
    if hasattr(unreal, 'EResourceType'):
        print(f"Method 4 SUCCESS: Found EResourceType in unreal module")
        print(f"  Type: {type(unreal.EResourceType)}")
except Exception as e:
    print(f"Method 4 FAILED: {e}")

# Now test setting it on an actual asset
print("\\nTesting on actual asset...")
try:
    # Delete old test asset if it exists
    test_path = '/Game/Resources/DA_Resource_TestEnum2'
    if unreal.EditorAssetLibrary.does_asset_exist(test_path + '.DA_Resource_TestEnum2'):
        unreal.EditorAssetLibrary.delete_asset(test_path + '.DA_Resource_TestEnum2')

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    factory = unreal.DataAssetFactory()
    factory.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

    asset = asset_tools.create_asset('DA_Resource_TestEnum2', '/Game/Resources', None, factory)

    if asset:
        print(f"Created asset: {asset.get_path_name()}")

        # Try setting with direct access
        asset.set_editor_property('ResourceType', unreal.EResourceType.WOOL)
        asset.set_editor_property('ResourceCategory', unreal.EResourceCategory.BASIC)
        asset.set_editor_property('EndGameValue', 1)
        asset.set_editor_property('BaseMarketPrice', 3)

        unreal.EditorAssetLibrary.save_loaded_asset(asset)
        print("SUCCESS: Asset created and properties set!")

        # Verify
        rt = asset.get_editor_property('ResourceType')
        print(f"Verified ResourceType: {rt}")

    else:
        print("ERROR: Failed to create asset")

except Exception as e:
    import traceback
    print(f"ERROR: {e}")
    print(traceback.format_exc())
"""

result = executor.execute(code)
executor.disconnect()
