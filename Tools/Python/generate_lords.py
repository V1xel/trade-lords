"""
Generate Lord DataAssets from JSON definition file

Reads lord definitions from .claude/context/Gameplay/Lords/lords.json
and creates DataAssets with all properties correctly set.
"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties


# Mapping from JSON ability type names to enum values
ABILITY_TYPE_MAP = {
    'Passive': 'Passive',
    'Triggered': 'Triggered',
    'Active': 'Active'
}


def load_lords_data():
    """Load lord definitions from JSON file"""
    # Path to lords.json in .claude/context/Gameplay/Lords
    json_path = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))),
        '.claude',
        'context',
        'Gameplay',
        'Lords',
        'lords.json'
    )

    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Lords data file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    return data['lords']


def create_lord_properties(lord_data):
    """
    Convert JSON lord data to DataAsset properties

    Args:
        lord_data (dict): Lord definition from JSON

    Returns:
        dict: Properties to set on the DataAsset
    """
    properties = {}

    # Set LordName
    properties['LordName'] = lord_data['lord_name']

    # Set LordTitle
    properties['LordTitle'] = lord_data['lord_title']

    # Set HouseColorPrimary (LinearColor with RGBA)
    properties['HouseColorPrimary'] = tuple(lord_data['color_primary'])

    # Set HouseColorSecondary (LinearColor with RGBA)
    properties['HouseColorSecondary'] = tuple(lord_data['color_secondary'])

    # Set StartingGold
    properties['StartingGold'] = lord_data['starting_gold']

    # Set StartingMerchants
    properties['StartingMerchants'] = lord_data['starting_merchants']

    # Set StartingShipping
    properties['StartingShipping'] = lord_data['starting_shipping']

    # Set AbilityType enum
    if lord_data['ability_type'] in ABILITY_TYPE_MAP:
        properties['AbilityType'] = {
            'enum': '/Script/TL.EAbilityType',
            'value': ABILITY_TYPE_MAP[lord_data['ability_type']]
        }

    # Set AbilityDescription
    properties['AbilityDescription'] = lord_data['ability_description']

    return properties


def generate_lord_data_assets():
    """Load lord data from JSON and generate DataAsset assets"""

    print("Loading lords data from JSON...")
    lords = load_lords_data()
    print(f"Loaded {len(lords)} lord definitions\n")

    for lord_data in lords:
        print(f"\nCreating {lord_data['name']}...")
        print(f"  Name: {lord_data['lord_name']}")
        print(f"  Title: {lord_data['lord_title']}")
        print(f"  Starting Gold: {lord_data['starting_gold']}")
        print(f"  Starting Merchants: {lord_data['starting_merchants']}")
        print(f"  Starting Shipping: {lord_data['starting_shipping']}")
        print(f"  Ability Type: {lord_data['ability_type']}")

        # Convert to data asset properties
        properties = create_lord_properties(lord_data)

        # Create the data asset
        result = create_data_asset_with_properties(
            '/Script/TL.LordDefinition',
            '/Game/Lords',
            lord_data['name'],
            properties
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {lord_data['name']}")
        else:
            print(f"  [FAILED] Failed to create {lord_data['name']}")
            print(f"    Error: {result.get('result', 'Unknown error')}")


if __name__ == '__main__':
    generate_lord_data_assets()
