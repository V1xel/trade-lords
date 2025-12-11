"""Clean up all test assets"""

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

test_assets = [
    '/Game/Resources/DA_Resource_TestEnum.DA_Resource_TestEnum',
    '/Game/Resources/DA_Resource_TestEnum2.DA_Resource_TestEnum2',
    '/Game/Resources/DA_Resource_TestEnum3.DA_Resource_TestEnum3',
    '/Game/Resources/DA_Resource_TestEnum4.DA_Resource_TestEnum4',
    '/Game/Resources/DA_Resource_TestEnum5.DA_Resource_TestEnum5',
    '/Game/Resources/DA_Resource_WoolTest.DA_Resource_WoolTest',
    '/Game/Blueprints/Tiles/BP_TestGrassTile.BP_TestGrassTile',
]

for asset_path in test_assets:
    if unreal.EditorAssetLibrary.does_asset_exist(asset_path):
        unreal.EditorAssetLibrary.delete_asset(asset_path)
        print(f"Deleted: {asset_path}")
    else:
        print(f"Not found: {asset_path}")

print("\\nTest assets cleaned up!")
"""

result = executor.execute(code)
executor.disconnect()
