import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from generate_hexes import generate_hex_blueprints
from generate_units import generate_unit_blueprints
from generate_resources import generate_resource_data_assets
from generate_lords import generate_lord_data_assets
from generate_contracts import generate_contract_data_assets


def generate_all_content():
    print("=" * 60)
    print("GENERATING ALL CONTENT ASSETS")
    print("=" * 60)

    print("\n" + "=" * 60)
    print("STEP 1: CREATING HEX TILE BLUEPRINTS")
    print("=" * 60)
    generate_hex_blueprints()

    print("\n" + "=" * 60)
    print("STEP 2: CREATING UNIT BLUEPRINTS")
    print("=" * 60)
    generate_unit_blueprints()

    print("\n" + "=" * 60)
    print("STEP 3: CREATING RESOURCE DATA ASSETS")
    print("=" * 60)
    generate_resource_data_assets()

    print("\n" + "=" * 60)
    print("STEP 4: CREATING LORD DATA ASSETS")
    print("=" * 60)
    generate_lord_data_assets()

    print("\n" + "=" * 60)
    print("STEP 5: CREATING CONTRACT DATA ASSETS")
    print("=" * 60)
    generate_contract_data_assets()

    print("\n" + "=" * 60)
    print("ALL CONTENT ASSETS GENERATED SUCCESSFULLY!")
    print("=" * 60)
    print("\nSummary:")
    print("  - 5 Hex Tile Blueprints")
    print("  - 10 Unit Blueprints")
    print("  - 11 Resource Data Assets")
    print("  - 9 Lord Data Assets")
    print("  - 4 Contract Data Assets")
    print("\nTotal: 39 assets created in /Game/ Content Browser")


if __name__ == '__main__':
    generate_all_content()
