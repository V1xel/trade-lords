import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties


def generate_resource_data_assets():
    resources = [
        {
            'name': 'DA_Resource_Wool',
            'resource_name': 'Wool',
            'end_game_value': 1,
            'base_market_price': 3,
        },
        {
            'name': 'DA_Resource_Milk',
            'resource_name': 'Milk',
            'end_game_value': 1,
            'base_market_price': 3,
        },
        {
            'name': 'DA_Resource_Grain',
            'resource_name': 'Grain',
            'end_game_value': 1,
            'base_market_price': 3,
        },
        {
            'name': 'DA_Resource_Cheese',
            'resource_name': 'Cheese',
            'end_game_value': 3,
            'base_market_price': 6,
        },
        {
            'name': 'DA_Resource_Bread',
            'resource_name': 'Bread',
            'end_game_value': 3,
            'base_market_price': 6,
        },
        {
            'name': 'DA_Resource_Whisky',
            'resource_name': 'Whisky',
            'end_game_value': 4,
            'base_market_price': 8,
        },
        {
            'name': 'DA_Resource_Beer',
            'resource_name': 'Beer',
            'end_game_value': 3,
            'base_market_price': 6,
        },
        {
            'name': 'DA_Resource_Cotton',
            'resource_name': 'Cotton',
            'end_game_value': 2,
            'base_market_price': 5,
        },
        {
            'name': 'DA_Resource_Tobacco',
            'resource_name': 'Tobacco',
            'end_game_value': 2,
            'base_market_price': 5,
        },
        {
            'name': 'DA_Resource_SugarCane',
            'resource_name': 'Sugar Cane',
            'end_game_value': 2,
            'base_market_price': 5,
        },
        {
            'name': 'DA_Resource_Hops',
            'resource_name': 'Hops',
            'end_game_value': 2,
            'base_market_price': 4,
        },
    ]

    for resource_data in resources:
        print(f"\nCreating {resource_data['name']}...")
        result = create_data_asset_with_properties(
            '/Script/TL.ResourceDefinition',
            '/Game/Resources',
            resource_data['name'],
            {
                'ResourceName': resource_data['resource_name'],
                'EndGameValue': resource_data['end_game_value'],
                'BaseMarketPrice': resource_data['base_market_price'],
            }
        )
        print(f"Result: {result.get('success')}")


if __name__ == '__main__':
    generate_resource_data_assets()
