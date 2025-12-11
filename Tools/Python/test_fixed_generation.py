"""Test the fixed resource creation"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties

# Delete old test asset if it exists
from unreal_remote import UnrealRemoteExecutor
executor = UnrealRemoteExecutor()
if executor.connect():
    delete_code = """
import unreal
if unreal.EditorAssetLibrary.does_asset_exist('/Game/Resources/DA_Resource_WoolTest.DA_Resource_WoolTest'):
    unreal.EditorAssetLibrary.delete_asset('/Game/Resources/DA_Resource_WoolTest.DA_Resource_WoolTest')
    print("Deleted old test asset")
"""
    executor.execute(delete_code)
    executor.disconnect()

# Create test resource with properties
print("Creating test resource with enum properties...")
result = create_data_asset_with_properties(
    '/Script/TL.ResourceDefinition',
    '/Game/Resources',
    'DA_Resource_WoolTest',
    {
        'ResourceType': {
            'enum': '/Script/TL.EResourceType',
            'value': 'Wool'
        },
        'ResourceCategory': {
            'enum': '/Script/TL.EResourceCategory',
            'value': 'Basic'
        },
        'EndGameValue': 1,
        'BaseMarketPrice': 3
    }
)

print("\n" + "="*60)
print("RESULT:")
print("="*60)
print(result)
