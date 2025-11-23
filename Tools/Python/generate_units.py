import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties


def generate_unit_blueprints():
    units = [
        {
            'name': 'BP_Unit_Sheep',
            'unit_cost': 4,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Cow',
            'unit_cost': 5,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Field',
            'unit_cost': 4,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Woodcutter',
            'unit_cost': 3,
            'generates_income': 2,
        },
        {
            'name': 'BP_Unit_Miner',
            'unit_cost': 4,
            'generates_income': 3,
        },
        {
            'name': 'BP_Unit_Fisherman',
            'unit_cost': 3,
            'generates_income': 2,
        },
        {
            'name': 'BP_Unit_CheeseDairy',
            'unit_cost': 5,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Bakery',
            'unit_cost': 5,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Distillery',
            'unit_cost': 6,
            'generates_income': 0,
        },
        {
            'name': 'BP_Unit_Brewery',
            'unit_cost': 6,
            'generates_income': 0,
        },
    ]

    for unit_data in units:
        print(f"\nCreating {unit_data['name']}...")
        result = create_blueprint_with_properties(
            '/Script/TL.Unit',
            '/Game/Units',
            unit_data['name'],
            {
                'UnitCost': unit_data['unit_cost'],
                'GeneratesIncome': unit_data['generates_income'],
            }
        )
        print(f"Result: {result.get('success')}")


if __name__ == '__main__':
    generate_unit_blueprints()
