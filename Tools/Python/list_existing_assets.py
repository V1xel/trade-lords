"""List all existing assets in Content folders"""

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

# List assets in each folder
folders = [
    '/Game/Resources',
    '/Game/Units',
    '/Game/Hexes',
    '/Game/Lords',
]

for folder in folders:
    print(f"\\n{'='*60}")
    print(f"Folder: {folder}")
    print('='*60)

    if not unreal.EditorAssetLibrary.does_directory_exist(folder):
        print("  Folder does not exist")
        continue

    assets = unreal.EditorAssetLibrary.list_assets(folder, recursive=False)
    if not assets:
        print("  No assets found")
    else:
        for asset_path in assets:
            print(f"  {asset_path}")
"""

result = executor.execute(code)
executor.disconnect()
