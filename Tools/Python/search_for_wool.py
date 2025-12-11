"""Search for any assets named Wool"""

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

print("Searching for 'Wool' assets...")

# Check specific paths
paths_to_check = [
    '/Game/Resources/DA_Resource_Wool',
    '/Game/Resources/DA_Resource_Wool.DA_Resource_Wool',
    '/Game/DA_Resource_Wool',
    '/Game/DA_Resource_Wool.DA_Resource_Wool',
]

for path in paths_to_check:
    exists = unreal.EditorAssetLibrary.does_asset_exist(path)
    print(f"  {path}: {'EXISTS' if exists else 'not found'}")

# List ALL assets in /Game recursively
print("\\nListing all assets in /Game...")
all_assets = unreal.EditorAssetLibrary.list_assets('/Game', recursive=True)
wool_assets = [a for a in all_assets if 'wool' in a.lower()]

if wool_assets:
    print(f"Found {len(wool_assets)} assets with 'wool' in name:")
    for asset in wool_assets:
        print(f"  {asset}")
else:
    print("No assets with 'wool' in name found")

# Also try to find any ResourceDefinition assets
print("\\nLooking for ResourceDefinition assets...")
resource_assets = [a for a in all_assets if 'DA_Resource' in a]
if resource_assets:
    print(f"Found {len(resource_assets)} DA_Resource assets:")
    for asset in resource_assets:
        print(f"  {asset}")
"""

result = executor.execute(code)
executor.disconnect()
