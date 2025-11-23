import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties


def generate_hex_blueprints():
    hex_tiles = [
        {
            'name': 'BP_HexTile_Grassland',
            'terrain_cost': 1,
            'tile_color': (0.176, 0.314, 0.086, 1.0),
        },
        {
            'name': 'BP_HexTile_Forest',
            'terrain_cost': 2,
            'tile_color': (0.102, 0.188, 0.063, 1.0),
        },
        {
            'name': 'BP_HexTile_Mountain',
            'terrain_cost': 3,
            'tile_color': (0.439, 0.439, 0.439, 1.0),
        },
        {
            'name': 'BP_HexTile_Loch',
            'terrain_cost': 0,
            'tile_color': (0.118, 0.302, 0.545, 1.0),
        },
        {
            'name': 'BP_HexTile_River',
            'terrain_cost': 2,
            'tile_color': (0.2, 0.4, 0.5, 1.0),
        },
    ]

    for hex_data in hex_tiles:
        print(f"\nCreating {hex_data['name']}...")
        result = create_blueprint_with_properties(
            '/Script/TL.HexTile',
            '/Game/Hexes',
            hex_data['name'],
            {
                'TerrainCost': hex_data['terrain_cost'],
                'TileColor': hex_data['tile_color'],
                'bIsRiverDelta': False,
            }
        )
        print(f"Result: {result.get('success')}")


if __name__ == '__main__':
    generate_hex_blueprints()
