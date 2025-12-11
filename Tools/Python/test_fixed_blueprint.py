"""Test the fixed blueprint creation"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties
from unreal_remote import UnrealRemoteExecutor

# Delete old test asset if it exists
executor = UnrealRemoteExecutor()
if executor.connect():
    delete_code = """
import unreal
if unreal.EditorAssetLibrary.does_asset_exist('/Game/Blueprints/Tiles/BP_TestGrassTile.BP_TestGrassTile'):
    unreal.EditorAssetLibrary.delete_asset('/Game/Blueprints/Tiles/BP_TestGrassTile.BP_TestGrassTile')
    print("Deleted old test asset")
"""
    executor.execute(delete_code)
    executor.disconnect()

# Create test blueprint with enum properties
print("Creating test blueprint with enum properties...")
result = create_blueprint_with_properties(
    '/Script/TL.GameTile',
    '/Game/Blueprints/Tiles',
    'BP_TestGrassTile',
    {
        'TileName': 'Test Grass Tile',
        'TileColor': (0.2, 0.8, 0.3, 1.0),
        'MovementCost': 1,
        'bCanStop': True,
        'bIsPassable': True,
        'bProvidesCover': False,
        'ResourceAmount': 0
    }
)

print("\n" + "="*60)
print("RESULT:")
print("="*60)
print(result)
