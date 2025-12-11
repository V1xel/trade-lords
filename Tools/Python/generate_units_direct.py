"""
Direct unit generation - bypasses remote execution, run this IN the Unreal Editor Python console
"""

import unreal

def generate_units_from_json():
    import json
    import os

    # Load units JSON
    json_path = r'C:\Users\vital\Projects\TL\.claude\context\Gameplay\Units\units.json'
    with open(json_path, 'r') as f:
        data = json.load(f)

    meta = data['_meta']
    items = data['items']

    print(f"Generating {len(items)} units...")

    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    editor_asset_lib = unreal.EditorAssetLibrary()

    # Ensure output directory exists
    if not editor_asset_lib.does_directory_exist(meta['output_path']):
        editor_asset_lib.make_directory(meta['output_path'])

    for item in items:
        name = item['name']
        print(f"\nCreating {name}...")

        # Create Blueprint factory
        factory = unreal.BlueprintFactory()
        factory.set_editor_property('parent_class', unreal.load_class(None, meta['parent_class']))

        # Create the Blueprint
        asset = asset_tools.create_asset(name, meta['output_path'], unreal.Blueprint, factory)

        if asset:
            print(f"  Created {name}")

            # Get CDO and set properties
            bp_class = asset.generated_class()
            if bp_class:
                cdo = unreal.get_default_object(bp_class)

                # Set UnitType
                if item['display_name'] in meta['enums']['UnitType']['mapping']:
                    unit_type_value = meta['enums']['UnitType']['mapping'][item['display_name']]
                    cdo.set_editor_property('unit_type', unreal.load_enum('/Script/TL.EUnitType')[unit_type_value])

                # Set UnitCost
                cdo.set_editor_property('unit_cost', item['unit_cost'])

                # Set RequiredTerrain
                if item['terrain_type'] in meta['enums']['RequiredTerrain']['mapping']:
                    terrain_value = meta['enums']['RequiredTerrain']['mapping'][item['terrain_type']]
                    cdo.set_editor_property('required_terrain', unreal.load_enum('/Script/TL.ETerrainType')[terrain_value])

                # Set ProducesResource
                if item.get('produces_resource') and item['produces_resource'] in meta['enums']['ProducesResource']['mapping']:
                    resource_value = meta['enums']['ProducesResource']['mapping'][item['produces_resource']]
                    cdo.set_editor_property('produces_resource', unreal.load_enum('/Script/TL.EResourceType')[resource_value])

                # Set ConsumesResource
                if item.get('consumes_resource') and item['consumes_resource'] in meta['enums']['ConsumesResource']['mapping']:
                    resource_value = meta['enums']['ConsumesResource']['mapping'][item['consumes_resource']]
                    cdo.set_editor_property('consumes_resource', unreal.load_enum('/Script/TL.EResourceType')[resource_value])

                # Set GeneratesIncome
                cdo.set_editor_property('generates_income', item.get('generates_income', 0))

                print(f"  Configured properties for {name}")

            # Save
            editor_asset_lib.save_loaded_asset(asset)
            print(f"  [OK] {name} complete")
        else:
            print(f"  [FAILED] Could not create {name}")

    print("\n" + "="*60)
    print("Unit generation complete!")

# Run it
generate_units_from_json()
