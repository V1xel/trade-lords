"""
Delete old incorrectly generated assets before regeneration

Uses Unreal Engine's EditorAssetLibrary to properly delete assets.
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def delete_old_assets():
    """Delete all old generated assets from Content folder"""

    executor = UnrealRemoteExecutor()

    if not executor.connect():
        print("Failed to connect to Unreal Engine")
        return False

    # Define assets to delete
    assets_to_delete = {
        'Units': [
            '/Game/Units/BP_Unit_Sheep',
            '/Game/Units/BP_Unit_Cow',
            '/Game/Units/BP_Unit_Field',
            '/Game/Units/BP_Unit_Woodcutter',
            '/Game/Units/BP_Unit_Miner',
            '/Game/Units/BP_Unit_Fisherman',
            '/Game/Units/BP_Unit_CheeseDairy',
            '/Game/Units/BP_Unit_Bakery',
            '/Game/Units/BP_Unit_Distillery',
            '/Game/Units/BP_Unit_Brewery',
        ],
        'Resources': [
            '/Game/Resources/DA_Resource_Wool',
            '/Game/Resources/DA_Resource_Milk',
            '/Game/Resources/DA_Resource_Grain',
            '/Game/Resources/DA_Resource_Cheese',
            '/Game/Resources/DA_Resource_Bread',
            '/Game/Resources/DA_Resource_Whisky',
            '/Game/Resources/DA_Resource_Beer',
            '/Game/Resources/DA_Resource_Cotton',
            '/Game/Resources/DA_Resource_Tobacco',
            '/Game/Resources/DA_Resource_SugarCane',
            '/Game/Resources/DA_Resource_Hops',
        ],
        'Hexes': [
            '/Game/Hexes/BP_HexTile_Grassland',
            '/Game/Hexes/BP_HexTile_Forest',
            '/Game/Hexes/BP_HexTile_Mountain',
            '/Game/Hexes/BP_HexTile_Loch',
            '/Game/Hexes/BP_HexTile_River',
        ],
        'Lords': [
            '/Game/Lords/DA_Lord_Aldric',
            '/Game/Lords/DA_Lord_Godwyn',
            '/Game/Lords/DA_Lord_Isolde',
            '/Game/Lords/DA_Lord_Bertram',
            '/Game/Lords/DA_Lord_Elspeth',
            '/Game/Lords/DA_Lord_Roderick',
            '/Game/Lords/DA_Lord_Caspian',
            '/Game/Lords/DA_Lord_Marina',
            '/Game/Lords/DA_Lord_Oswald',
        ],
    }

    code = """
import unreal

editor_asset_lib = unreal.EditorAssetLibrary()

assets_to_delete = """ + str(assets_to_delete) + """

deleted_count = 0
not_found_count = 0
failed_count = 0

for category, asset_paths in assets_to_delete.items():
    print(f"\\n{'='*60}")
    print(f"Deleting {category} assets...")
    print(f"{'='*60}")

    for asset_path in asset_paths:
        asset_name = asset_path.split('/')[-1]

        # Check if asset exists
        if editor_asset_lib.does_asset_exist(asset_path):
            print(f"  Deleting: {asset_name}")

            # Delete the asset
            success = editor_asset_lib.delete_asset(asset_path)

            if success:
                print(f"    [OK] Deleted {asset_name}")
                deleted_count += 1
            else:
                print(f"    [FAILED] Could not delete {asset_name}")
                failed_count += 1
        else:
            print(f"  [SKIP] {asset_name} does not exist")
            not_found_count += 1

print(f"\\n{'='*60}")
print(f"Summary:")
print(f"  Deleted: {deleted_count}")
print(f"  Not Found: {not_found_count}")
print(f"  Failed: {failed_count}")
print(f"{'='*60}")
"""

    print("Connecting to Unreal Engine to delete old assets...")
    result = executor.execute(code)
    executor.disconnect()

    return result.get('success', False)


if __name__ == '__main__':
    success = delete_old_assets()

    if success:
        print("\nOld assets deleted successfully!")
        print("You can now run: python generate_from_json.py --all")
    else:
        print("\nFailed to delete old assets")
        sys.exit(1)
