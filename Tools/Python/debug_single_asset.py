"""Debug single asset creation"""

import sys
import os
import json

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from create_data_asset import create_data_asset_with_properties

# Load the resources JSON
json_path = r'C:\Users\vital\Projects\TL\.claude\context\Gameplay\Resources\resources.json'
with open(json_path, 'r') as f:
    data = json.load(f)

# Get first resource (Wool)
meta = data['_meta']
wool_item = data['items'][0]

print("Creating Wool resource...")
print(f"Item data: {wool_item}\n")

# Convert properties manually to see what's being sent
from generate_from_json import create_asset_properties

properties = create_asset_properties(wool_item, meta)

print("Converted properties:")
for key, value in properties.items():
    print(f"  {key}: {value}")
print()

# Try to create
result = create_data_asset_with_properties(
    meta['parent_class'],
    meta['output_path'],
    wool_item['name'],
    properties
)

print("\n" + "="*60)
print("Generated Code:")
print("="*60)
if 'command' in result:
    print(result['command'])
print("\n" + "="*60)
print("Result:")
print("="*60)
print(f"Success: {result.get('success')}")
if 'output' in result:
    for output_item in result['output']:
        print(f"  [{output_item['type']}] {output_item['output']}")
