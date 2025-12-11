"""
Generic Asset Generation from JSON

Reads JSON definitions with metadata and creates Unreal Engine assets (Blueprints or DataAssets)
with all properties correctly set from the JSON data.

Usage:
    python generate_from_json.py path/to/definition.json
    python generate_from_json.py --all   # Generate all assets from all JSON files

JSON Schema:
{
    "_meta": {
        "asset_type": "blueprint" | "dataasset",
        "parent_class": "/Script/TL.ClassName",
        "output_path": "/Game/FolderName",
        "enums": {
            "PropertyName": {
                "type": "/Script/TL.EEnumName",
                "mapping": {
                    "json_value": "EnumValue"
                }
            }
        }
    },
    "items": [...]
}
"""

import sys
import os
import json
import glob

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_blueprint import create_blueprint_with_properties
from create_data_asset import create_data_asset_with_properties


def load_json_definition(json_path):
    """Load JSON definition file with metadata"""
    if not os.path.exists(json_path):
        raise FileNotFoundError(f"JSON file not found: {json_path}")

    with open(json_path, 'r') as f:
        data = json.load(f)

    # Validate required metadata
    if '_meta' not in data:
        raise ValueError(f"JSON file must contain '_meta' section: {json_path}")

    meta = data['_meta']
    required_meta = ['asset_type', 'parent_class', 'output_path']
    for key in required_meta:
        if key not in meta:
            raise ValueError(f"_meta must contain '{key}': {json_path}")

    return data


def convert_property_value(value, property_name, meta):
    """
    Convert JSON value to Unreal property value

    Args:
        value: The JSON value
        property_name: Name of the property
        meta: Metadata from JSON _meta section

    Returns:
        Converted value suitable for Unreal Engine
    """
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

    # Handle color arrays [R, G, B, A]
    if isinstance(value, list) and len(value) == 4:
        if all(isinstance(x, (int, float)) for x in value):
            return tuple(value)

    # Handle boolean
    if isinstance(value, bool):
        return value

    # Handle numbers
    if isinstance(value, (int, float)):
        return value

    # Handle strings
    if isinstance(value, str):
        return value

    # Handle null
    if value is None:
        return None

    # Default: return as-is
    return value


def create_asset_properties(item_data, meta):
    """
    Convert JSON item data to asset properties

    Args:
        item_data: Single item from JSON 'items' array
        meta: Metadata from JSON _meta section

    Returns:
        dict: Properties to set on the asset
    """
    properties = {}

    # Get property mappings from meta (if defined)
    property_mapping = meta.get('property_mapping', {})

    for json_key, json_value in item_data.items():
        # Skip special keys
        if json_key in ['name', 'description']:
            continue

        # If property_mapping is defined, only process mapped properties
        if property_mapping:
            if json_key not in property_mapping:
                continue  # Skip unmapped properties
            property_name = property_mapping[json_key]
        else:
            # No mapping defined, convert snake_case to PascalCase
            property_name = ''.join(word.capitalize() for word in json_key.split('_'))

        # Convert the value
        converted_value = convert_property_value(json_value, property_name, meta)

        # Only add non-null properties
        if converted_value is not None:
            properties[property_name] = converted_value

    return properties


def generate_assets_from_json(json_path):
    """
    Generate assets from a single JSON definition file

    Args:
        json_path: Path to JSON definition file
    """
    print(f"\n{'='*60}")
    print(f"Processing: {json_path}")
    print(f"{'='*60}")

    # Load JSON definition
    data = load_json_definition(json_path)
    meta = data['_meta']
    items = data.get('items', [])

    if not items:
        print("No items found in JSON")
        return

    print(f"Loaded {len(items)} item definitions")
    print(f"Asset Type: {meta['asset_type']}")
    print(f"Parent Class: {meta['parent_class']}")
    print(f"Output Path: {meta['output_path']}\n")

    # Choose creation function based on asset type
    if meta['asset_type'] == 'blueprint':
        create_func = create_blueprint_with_properties
    elif meta['asset_type'] == 'dataasset':
        create_func = create_data_asset_with_properties
    else:
        raise ValueError(f"Unknown asset_type: {meta['asset_type']}")

    # Generate each asset
    success_count = 0
    fail_count = 0

    for item_data in items:
        asset_name = item_data.get('name')
        if not asset_name:
            print("WARNING: Item missing 'name' field, skipping")
            continue

        print(f"\nCreating {asset_name}...")

        # Show some key properties
        for key, value in item_data.items():
            if key not in ['name', 'description'] and not key.startswith('_'):
                print(f"  {key}: {value}")

        # Convert to asset properties
        properties = create_asset_properties(item_data, meta)

        # Create the asset
        result = create_func(
            meta['parent_class'],
            meta['output_path'],
            asset_name,
            properties
        )

        if result.get('success'):
            print(f"  [OK] Successfully created {asset_name}")
            success_count += 1
        else:
            print(f"  [FAILED] Failed to create {asset_name}")
            print(f"    Error: {result.get('result', 'Unknown error')}")
            fail_count += 1

    print(f"\n{'='*60}")
    print(f"Summary: {success_count} succeeded, {fail_count} failed")
    print(f"{'='*60}\n")


def find_all_json_definitions():
    """Find all JSON definition files in .claude/context"""
    project_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    context_path = os.path.join(project_root, '.claude', 'context')

    # Find all .json files recursively
    json_files = []
    for root, dirs, files in os.walk(context_path):
        for file in files:
            if file.endswith('.json'):
                json_files.append(os.path.join(root, file))

    return json_files


def main():
    if len(sys.argv) < 2:
        print("Usage:")
        print("  python generate_from_json.py <json_file_path>")
        print("  python generate_from_json.py --all")
        sys.exit(1)

    if sys.argv[1] == '--all':
        # Generate from all JSON files
        json_files = find_all_json_definitions()
        print(f"Found {len(json_files)} JSON definition files\n")

        for json_file in json_files:
            try:
                generate_assets_from_json(json_file)
            except Exception as e:
                print(f"ERROR processing {json_file}: {e}")
                continue
    else:
        # Generate from single JSON file
        json_path = sys.argv[1]

        # If relative path, resolve it
        if not os.path.isabs(json_path):
            project_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
            json_path = os.path.join(project_root, json_path)

        generate_assets_from_json(json_path)


if __name__ == '__main__':
    main()
