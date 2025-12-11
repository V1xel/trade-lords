"""Verify that generated assets exist and have correct properties"""

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

# Check some sample assets
test_assets = [
    '/Game/Resources/DA_Resource_Wool.DA_Resource_Wool',
    '/Game/Resources/DA_Resource_Milk.DA_Resource_Milk',
    '/Game/Units/BP_Unit_Bakery.BP_Unit_Bakery',
    '/Game/Units/BP_Unit_Sheep.BP_Unit_Sheep',
    '/Game/Hexes/BP_HexTile_Grassland.BP_HexTile_Grassland',
    '/Game/Lords/DA_Lord_Aldric.DA_Lord_Aldric',
]

print("Checking if assets exist...")
for asset_path in test_assets:
    exists = unreal.EditorAssetLibrary.does_asset_exist(asset_path)
    print(f"  {asset_path}: {'EXISTS' if exists else 'NOT FOUND'}")

    if exists:
        # Try to load and inspect
        asset = unreal.EditorAssetLibrary.load_asset(asset_path)
        if asset:
            print(f"    Loaded successfully: {type(asset)}")

            # Try to get a property
            if 'Resource' in asset_path:
                try:
                    rt = asset.get_editor_property('ResourceType')
                    rc = asset.get_editor_property('ResourceCategory')
                    print(f"      ResourceType: {rt}")
                    print(f"      ResourceCategory: {rc}")
                except Exception as e:
                    print(f"      Error reading properties: {e}")
            elif 'Unit' in asset_path:
                try:
                    # For blueprints, we need to get the CDO
                    bp_class = asset.generated_class()
                    if bp_class:
                        cdo = unreal.get_default_object(bp_class)
                        ut = cdo.get_editor_property('unit_type')
                        print(f"      UnitType: {ut}")
                except Exception as e:
                    print(f"      Error reading properties: {e}")
"""

result = executor.execute(code)
executor.disconnect()
