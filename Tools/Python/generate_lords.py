import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties


def generate_lord_data_assets():
    lords = [
        {
            'name': 'DA_Lord_Aldric',
            'lord_name': 'Lord Aldric the Negotiator',
            'lord_title': 'Master of Writs',
            'color_primary': (0.0, 0.0, 0.0, 1.0),
            'color_secondary': (1.0, 0.843, 0.0, 1.0),
            'starting_gold': 10,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Can hold 2 unfulfilled contracts. Can take 2 contracts in one action.',
        },
        {
            'name': 'DA_Lord_Godwyn',
            'lord_name': 'Master Godwyn the Distiller',
            'lord_title': 'Keeper of the Cellars',
            'color_primary': (0.545, 0.271, 0.075, 1.0),
            'color_secondary': (0.4, 0.2, 0.0, 1.0),
            'starting_gold': 8,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Gain £3 per whisky produced. Has 2-slot aging cellar: 1-year whisky +£7, 2-year whisky +£15.',
        },
        {
            'name': 'DA_Lord_Isolde',
            'lord_name': 'Lady Isolde the Merchant Princess',
            'lord_title': 'Queen of Commerce',
            'color_primary': (0.627, 0.125, 0.941, 1.0),
            'color_secondary': (0.753, 0.753, 0.753, 1.0),
            'starting_gold': 12,
            'starting_merchants': 6,
            'starting_shipping': 0,
            'ability_description': 'Buying resources doesn\'t raise prices. Selling resources doesn\'t lower prices.',
        },
        {
            'name': 'DA_Lord_Bertram',
            'lord_name': 'Sir Bertram the Builder',
            'lord_title': 'Master of Industry',
            'color_primary': (0.275, 0.510, 0.706, 1.0),
            'color_secondary': (1.0, 1.0, 1.0, 1.0),
            'starting_gold': 6,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Processing buildings cost £3 instead of £5-£6.',
        },
        {
            'name': 'DA_Lord_Elspeth',
            'lord_name': 'Dame Elspeth the Shepherdess',
            'lord_title': 'Lady of the Pastures',
            'color_primary': (0.961, 0.961, 0.863, 1.0),
            'color_secondary': (0.0, 0.502, 0.0, 1.0),
            'starting_gold': 8,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Can sell milk for £4 each (no merchant needed, no market price change).',
        },
        {
            'name': 'DA_Lord_Roderick',
            'lord_name': 'Baron Roderick the Foreman',
            'lord_title': 'Commander of Labor',
            'color_primary': (0.545, 0.0, 0.0, 1.0),
            'color_secondary': (0.804, 0.498, 0.196, 1.0),
            'starting_gold': 6,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'All workers start upgraded. Workers cost £3 instead of £5-£6.',
        },
        {
            'name': 'DA_Lord_Caspian',
            'lord_name': 'Lord Caspian the Steward',
            'lord_title': 'Lord of All Trades',
            'color_primary': (0.0, 0.0, 0.502, 1.0),
            'color_secondary': (1.0, 0.843, 0.0, 1.0),
            'starting_gold': 10,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Can place workers on any terrain. Has Fisherman unit.',
        },
        {
            'name': 'DA_Lord_Marina',
            'lord_name': 'Lady Marina of the Estuaries',
            'lord_title': 'Mistress of the Waters',
            'color_primary': (0.0, 0.502, 0.502, 1.0),
            'color_secondary': (1.0, 1.0, 1.0, 1.0),
            'starting_gold': 8,
            'starting_merchants': 3,
            'starting_shipping': 2,
            'ability_description': 'Starts with Shipping 2. River delta hexes cost £0.',
        },
        {
            'name': 'DA_Lord_Oswald',
            'lord_name': 'Brewmaster Oswald the Bold',
            'lord_title': 'Master of the Brew',
            'color_primary': (0.333, 0.2, 0.0, 1.0),
            'color_secondary': (1.0, 0.647, 0.0, 1.0),
            'starting_gold': 9,
            'starting_merchants': 2,
            'starting_shipping': 0,
            'ability_description': 'Has Brewery unit. Gain £2 per beer produced.',
        },
    ]

    for lord_data in lords:
        print(f"\nCreating {lord_data['name']}...")
        result = create_data_asset_with_properties(
            '/Script/TL.LordDefinition',
            '/Game/Lords',
            lord_data['name'],
            {
                'LordName': lord_data['lord_name'],
                'LordTitle': lord_data['lord_title'],
                'HouseColorPrimary': lord_data['color_primary'],
                'HouseColorSecondary': lord_data['color_secondary'],
                'StartingGold': lord_data['starting_gold'],
                'StartingMerchants': lord_data['starting_merchants'],
                'StartingShipping': lord_data['starting_shipping'],
                'AbilityDescription': lord_data['ability_description'],
            }
        )
        print(f"Result: {result.get('success')}")


if __name__ == '__main__':
    generate_lord_data_assets()
