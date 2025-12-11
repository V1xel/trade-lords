"""
Generate Resource DataAssets from JSON definition file

Reads resource definitions from .claude/context/Gameplay/Resources/resources.json
and creates DataAssets with all properties correctly set.
"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties


# Mapping from JSON resource type names to enum values
RESOURCE_TYPE_MAP = {
    'Wool': 'Wool',
    'Milk': 'Milk',
    'Grain': 'Grain',
    'Cheese': 'Cheese',
    'Bread': 'Bread',
    'Whisky': 'Whisky',
    'Beer': 'Beer',
    'Cotton': 'Cotton',
    'Tobacco': 'Tobacco',
    'SugarCane': 'SugarCane',
    'Hops': 'Hops'
}

# Mapping from JSON category names to enum values
CATEGORY_MAP = {
    'Basic': 'Basic',
    'Processed': 'Processed',
    'Import': 'Import'
}


def load_resources_data():
    """Load resource definitions from JSON file"""
    # Path to resources.json in .claude/context/Gameplay/Resources
    json_path = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))),
        '.claude',
        'context',
        'Gameplay',
        'Resources',
        'resources.json'
    )

    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Resources data file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    return data['resources']


def create_resource_properties(resource_data):
    """
    Convert JSON resource data to DataAsset properties

    Args:
        resource_data (dict): Resource definition from JSON

    Returns:
        dict: Properties to set on the DataAsset
    """
    properties = {}

    # Set ResourceType enum
    if resource_data['resource_type'] in RESOURCE_TYPE_MAP:
        properties['ResourceType'] = {
            'enum': '/Script/TL.EResourceType',
            'value': RESOURCE_TYPE_MAP[resource_data['resource_type']]
        }

    # Set ResourceCategory enum
    if resource_data['category'] in CATEGORY_MAP:
        properties['ResourceCategory'] = {
            'enum': '/Script/TL.EResourceCategory',
            'value': CATEGORY_MAP[resource_data['category']]
        }

    # Set EndGameValue
    properties['EndGameValue'] = resource_data['end_game_value']

    # Set BaseMarketPrice
    properties['BaseMarketPrice'] = resource_data['base_market_price']

    return properties


def generate_resource_data_assets():
    """Load resource data from JSON and generate DataAsset assets"""

    print("Loading resources data from JSON...")
    resources = load_resources_data()
    print(f"Loaded {len(resources)} resource definitions\n")

    for resource_data in resources:
        print(f"\nCreating {resource_data['name']}...")
        print(f"  Type: {resource_data['resource_type']}")
        print(f"  Category: {resource_data['category']}")
        print(f"  End Game Value: {resource_data['end_game_value']} VP")
        print(f"  Base Market Price: {resource_data['base_market_price']} gold")

        # Convert to data asset properties
        properties = create_resource_properties(resource_data)

        # Create the data asset
        result = create_data_asset_with_properties(
            '/Script/TL.ResourceDefinition',
            '/Game/Resources',
            resource_data['name'],
            properties
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {resource_data['name']}")
        else:
            print(f"  [FAILED] Failed to create {resource_data['name']}")
            print(f"    Error: {result.get('result', 'Unknown error')}")


if __name__ == '__main__':
    generate_resource_data_assets()
