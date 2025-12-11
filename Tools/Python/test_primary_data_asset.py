"""Test creating Primary Data Asset"""

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

print("Testing Primary Data Asset creation...")

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()

# Method 1: Try with DataAssetFactory (what we've been using)
print("\\nMethod 1: DataAssetFactory")
factory1 = unreal.DataAssetFactory()
factory1.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

asset1 = asset_tools.create_asset(
    'DA_Resource_Wool_Method1',
    '/Game/Resources',
    None,
    factory1
)
print(f"  Result: {asset1}")

# Method 2: Try specifying the asset class in create_asset
print("\\nMethod 2: Specify class in create_asset")
factory2 = unreal.DataAssetFactory()
factory2.set_editor_property('data_asset_class', unreal.load_class(None, '/Script/TL.ResourceDefinition'))

asset2 = asset_tools.create_asset(
    'DA_Resource_Wool_Method2',
    '/Game/Resources',
    unreal.load_class(None, '/Script/TL.ResourceDefinition'),
    factory2
)
print(f"  Result: {asset2}")

# Method 3: Try with AssetFactory
print("\\nMethod 3: Using generic Factory")
factory3 = unreal.Factory()

asset3 = asset_tools.create_asset(
    'DA_Resource_Wool_Method3',
    '/Game/Resources',
    unreal.load_class(None, '/Script/TL.ResourceDefinition'),
    factory3
)
print(f"  Result: {asset3}")

# Method 4: Try creating with EditorAssetLibrary.duplicate_asset from a working asset
print("\\nMethod 4: Duplicate from working asset")
if unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_TestBasic.DA_Resource_TestBasic'):
    duplicated = unreal.EditorAssetLibrary.duplicate_asset(
        '/Game/Resources/DA_Resource_TestBasic.DA_Resource_TestBasic',
        '/Game/Resources/DA_Resource_Wool_Method4'
    )
    print(f"  Result: {duplicated}")
else:
    print("  Source asset not found")
"""

result = executor.execute(code)
executor.disconnect()
