"""Delete all generated assets to regenerate them"""

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

# Delete all assets in the four folders
folders = [
    '/Game/Resources',
    '/Game/Units',
    '/Game/Hexes',
    '/Game/Lords',
]

for folder in folders:
    print(f"\\nProcessing {folder}...")
    if not unreal.EditorAssetLibrary.does_directory_exist(folder):
        print(f"  Folder doesn't exist, skipping")
        continue

    assets = unreal.EditorAssetLibrary.list_assets(folder, recursive=False)
    # Filter out README and other non-generated assets
    assets_to_delete = [a for a in assets if 'DA_' in a or 'BP_' in a]

    print(f"  Found {len(assets_to_delete)} assets to delete")

    for asset_path in assets_to_delete:
        try:
            unreal.EditorAssetLibrary.delete_asset(asset_path)
            print(f"    Deleted: {asset_path.split('/')[-1]}")
        except Exception as e:
            print(f"    Failed to delete {asset_path}: {e}")

print("\\nAll generated assets deleted!")
"""

result = executor.execute(code)
executor.disconnect()
