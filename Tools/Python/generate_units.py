"""
Generate Unit Blueprints from JSON definition file

Reads unit definitions from .claude/context/Data/units.json and creates
Blueprints with all properties correctly set.
"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties


# Mapping from JSON resource names to enum values
RESOURCE_MAP = {
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

# Mapping from JSON terrain names to enum values
TERRAIN_MAP = {
    'Grassland': 'Grassland',
    'Forest': 'Forest',
    'Mountain': 'Mountain',
    'Loch': 'Loch',
    'River': 'River'
}

# Mapping from JSON unit type names to enum values
UNIT_TYPE_MAP = {
    'Sheep': 'Sheep',
    'Cow': 'Cow',
    'Field': 'Field',
    'Woodcutter': 'Woodcutter',
    'Miner': 'Miner',
    'Fisherman': 'Fisherman',
    'Cheese Dairy': 'CheeseDairy',
    'Bakery': 'Bakery',
    'Distillery': 'Distillery',
    'Brewery': 'Brewery'
}


def load_units_data():
    """Load unit definitions from JSON file"""
    # Path to units.json in .claude/context/Gameplay/Units
    json_path = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))),
        '.claude',
        'context',
        'Gameplay',
        'Units',
        'units.json'
    )

    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Units data file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    return data['units']


def create_unit_properties(unit_data):
    """
    Convert JSON unit data to Blueprint properties

    Args:
        unit_data (dict): Unit definition from JSON

    Returns:
        dict: Properties to set on the Blueprint CDO
    """
    properties = {}

    # Set UnitType enum
    if unit_data['display_name'] in UNIT_TYPE_MAP:
        properties['UnitType'] = {
            'enum': '/Script/TL.EUnitType',
            'value': UNIT_TYPE_MAP[unit_data['display_name']]
        }

    # Set UnitCost
    properties['UnitCost'] = unit_data['unit_cost']

    # Set RequiredTerrain enum
    if unit_data['terrain_type'] in TERRAIN_MAP:
        properties['RequiredTerrain'] = {
            'enum': '/Script/TL.ETerrainType',
            'value': TERRAIN_MAP[unit_data['terrain_type']]
        }

    # Set ProducesResource enum (if applicable)
    if unit_data.get('produces_resource'):
        if unit_data['produces_resource'] in RESOURCE_MAP:
            properties['ProducesResource'] = {
                'enum': '/Script/TL.EResourceType',
                'value': RESOURCE_MAP[unit_data['produces_resource']]
            }

    # Set ConsumesResource enum (if applicable)
    if unit_data.get('consumes_resource'):
        if unit_data['consumes_resource'] in RESOURCE_MAP:
            properties['ConsumesResource'] = {
                'enum': '/Script/TL.EResourceType',
                'value': RESOURCE_MAP[unit_data['consumes_resource']]
            }

    # Set GeneratesIncome
    properties['GeneratesIncome'] = unit_data.get('generates_income', 0)

    return properties


def generate_unit_blueprints():
    """Load unit data from JSON and generate Blueprint assets"""

    print("Loading units data from JSON...")
    units = load_units_data()
    print(f"Loaded {len(units)} unit definitions\n")

    for unit_data in units:
        print(f"\nCreating {unit_data['name']}...")
        print(f"  Type: {unit_data['display_name']}")
        print(f"  Category: {unit_data['category']}")
        print(f"  Cost: {unit_data['unit_cost']} gold")
        print(f"  Terrain: {unit_data['terrain_type']}")

        if unit_data.get('produces_resource'):
            print(f"  Produces: {unit_data['produces_resource']}")
        if unit_data.get('consumes_resource'):
            print(f"  Consumes: {unit_data['consumes_resource']}")
        if unit_data.get('generates_income'):
            print(f"  Income: {unit_data['generates_income']} gold")

        # Convert to blueprint properties
        properties = create_unit_properties(unit_data)

        # Create the blueprint
        result = create_blueprint_with_properties(
            '/Script/TL.Unit',
            '/Game/Units',
            unit_data['name'],
            properties
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {unit_data['name']}")
        else:
            print(f"  [FAILED] Failed to create {unit_data['name']}")
            print(f"    Error: {result.get('result', 'Unknown error')}")


if __name__ == '__main__':
    generate_unit_blueprints()
