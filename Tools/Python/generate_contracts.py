import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties


def generate_contract_data_assets():
    contracts = [
        {
            'name': 'DA_Contract_WoolExport_Small',
            'contract_name': 'Wool Export (Small)',
            'gold_reward': 8,
            'import_good_amount': 1,
            'victory_points': 5,
        },
        {
            'name': 'DA_Contract_WoolExport_Large',
            'contract_name': 'Wool Export (Large)',
            'gold_reward': 15,
            'import_good_amount': 2,
            'victory_points': 10,
        },
        {
            'name': 'DA_Contract_WhiskyExport_Small',
            'contract_name': 'Whisky Export (Small)',
            'gold_reward': 12,
            'import_good_amount': 1,
            'victory_points': 8,
        },
        {
            'name': 'DA_Contract_MixedGoods_1',
            'contract_name': 'Mixed Goods Export',
            'gold_reward': 18,
            'import_good_amount': 2,
            'victory_points': 12,
        },
    ]

    for contract_data in contracts:
        print(f"\nCreating {contract_data['name']}...")
        result = create_data_asset_with_properties(
            '/Script/TL.ContractDefinition',
            '/Game/Contracts',
            contract_data['name'],
            {
                'ContractName': contract_data['contract_name'],
                'GoldReward': contract_data['gold_reward'],
                'ImportGoodAmount': contract_data['import_good_amount'],
                'VictoryPoints': contract_data['victory_points'],
            }
        )
        print(f"Result: {result.get('success')}")


if __name__ == '__main__':
    generate_contract_data_assets()
