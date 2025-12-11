"""
Generate Contract DataAssets from JSON definition file
"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_contract import create_contract_with_properties


def load_contracts_data():
    """Load contract definitions from JSON file"""
    json_path = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))),
        '.claude',
        'context',
        'Gameplay',
        'Contracts',
        'contracts.json'
    )

    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Contracts data file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    return data


def convert_property_value(value, property_name, meta):
    """Convert JSON value to Unreal property value"""
    # Check if this property has enum mapping
    if 'enums' in meta and property_name in meta['enums']:
        enum_config = meta['enums'][property_name]
        enum_type = enum_config['type']
        mapping = enum_config['mapping']

        if value in mapping:
            return {
                'enum': enum_type,
                'value': mapping[value]
            }
        else:
            print(f"WARNING: No enum mapping for {property_name}={value}")
            return value

    return value


def generate_contract_data_assets():
    """Load contract data from JSON and generate DataAsset assets"""

    print("Loading contracts data from JSON...")
    data = load_contracts_data()
    meta = data['_meta']
    items = data['items']

    print(f"Loaded {len(items)} contract definitions\n")

    property_mapping = meta.get('property_mapping', {})

    success_count = 0
    fail_count = 0

    for contract_data in items:
        print(f"\nCreating {contract_data['name']}...")
        print(f"  Name: {contract_data['contract_name']}")
        print(f"  Gold Reward: £{contract_data['gold_reward']}")
        print(f"  Required Resources: {contract_data['required_resources']}")
        print(f"  Import Good: {contract_data['import_good_reward']} x{contract_data['import_good_amount']}")
        print(f"  Victory Points: {contract_data['victory_points']}")

        # Build properties dictionary (excluding required_resources which is handled separately)
        properties = {}
        for json_key, json_value in contract_data.items():
            # Skip special keys
            if json_key in ['name', 'description', 'required_resources']:
                continue

            # Get the Unreal property name
            if json_key in property_mapping:
                property_name = property_mapping[json_key]
            else:
                # Convert snake_case to PascalCase
                property_name = ''.join(word.capitalize() for word in json_key.split('_'))

            # Convert the value
            converted_value = convert_property_value(json_value, property_name, meta)

            # Only add non-null properties
            if converted_value is not None:
                properties[property_name] = converted_value

        # Get required resources
        required_resources = contract_data.get('required_resources', {})

        # Create the contract
        result = create_contract_with_properties(
            meta['parent_class'],
            meta['output_path'],
            contract_data['name'],
            properties,
            required_resources
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {contract_data['name']}")
            success_count += 1
        else:
            print(f"  [FAILED] Failed to create {contract_data['name']}")
            print(f"    Error: {result.get('result', 'Unknown error')}")
            fail_count += 1

    print(f"\n{'='*60}")
    print(f"Summary: {success_count} succeeded, {fail_count} failed")
    print(f"{'='*60}\n")


if __name__ == '__main__':
    generate_contract_data_assets()
