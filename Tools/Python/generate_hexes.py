"""
Generate Hex Tile Blueprints from JSON definition file

Reads hex tile definitions from .claude/context/Gameplay/Hexes/hexes.json
and creates Blueprints with all properties correctly set.
"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties


# Mapping from JSON terrain names to enum values
TERRAIN_TYPE_MAP = {
    'Grassland': 'Grassland',
    'Forest': 'Forest',
    'Mountain': 'Mountain',
    'Loch': 'Loch',
    'River': 'River'
}


def load_hexes_data():
    """Load hex tile definitions from JSON file"""
    # Path to hexes.json in .claude/context/Gameplay/Hexes
    json_path = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))),
        '.claude',
        'context',
        'Gameplay',
        'Hexes',
        'hexes.json'
    )

    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Hexes data file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    return data['hexes']


def create_hex_properties(hex_data):
    """
    Convert JSON hex data to Blueprint properties

    Args:
        hex_data (dict): Hex definition from JSON

    Returns:
        dict: Properties to set on the Blueprint CDO
    """
    properties = {}

    # Set TerrainType enum
    if hex_data['terrain_type'] in TERRAIN_TYPE_MAP:
        properties['TerrainType'] = {
            'enum': '/Script/TL.ETerrainType',
            'value': TERRAIN_TYPE_MAP[hex_data['terrain_type']]
        }

    # Set TerrainCost
    properties['TerrainCost'] = hex_data['terrain_cost']

    # Set TileColor (LinearColor with RGBA)
    properties['TileColor'] = tuple(hex_data['tile_color'])

    # Set bIsRiverDelta
    properties['bIsRiverDelta'] = hex_data['is_river_delta']

    return properties


def generate_hex_blueprints():
    """Load hex data from JSON and generate Blueprint assets"""

    print("Loading hex tiles data from JSON...")
    hexes = load_hexes_data()
    print(f"Loaded {len(hexes)} hex tile definitions\n")

    for hex_data in hexes:
        print(f"\nCreating {hex_data['name']}...")
        print(f"  Terrain: {hex_data['terrain_type']}")
        print(f"  Cost: {hex_data['terrain_cost']} gold")
        print(f"  River Delta: {hex_data['is_river_delta']}")

        # Convert to blueprint properties
        properties = create_hex_properties(hex_data)

        # Create the blueprint
        result = create_blueprint_with_properties(
            '/Script/TL.HexTile',
            '/Game/Hexes',
            hex_data['name'],
            properties
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {hex_data['name']}")
        else:
            print(f"  [FAILED] Failed to create {hex_data['name']}")
            print(f"    Error: {result.get('result', 'Unknown error')}")


if __name__ == '__main__':
    generate_hex_blueprints()
