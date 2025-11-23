"""
Import FBX models from Kenney's hexagon kit to Unreal Engine
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def import_fbx_models():
    """Import all necessary FBX models for hex tiles and units"""

    # Base path to the FBX models
    fbx_base_path = r'C:\Users\vital\Projects\TL\.claude\context\Assets\kenney_hexagon-kit\Models\FBX format'

    # Define models to import for hex tiles - place in /Game/Hexes
    hex_models = {
        'grass.fbx': '/Game/Hexes',
        'grass-forest.fbx': '/Game/Hexes',
        'stone-mountain.fbx': '/Game/Hexes',
        'water.fbx': '/Game/Hexes',
        'river-straight.fbx': '/Game/Hexes',
    }

    # Define models to import for units/buildings - place in /Game/Units
    unit_models = {
        'building-sheep.fbx': '/Game/Units',
        'building-farm.fbx': '/Game/Units',
        'building-mill.fbx': '/Game/Units',
        'building-watermill.fbx': '/Game/Units',
        'building-mine.fbx': '/Game/Units',
        'building-dock.fbx': '/Game/Units',
        'building-market.fbx': '/Game/Units',
        'building-house.fbx': '/Game/Units',
        'building-smelter.fbx': '/Game/Units',
        'building-village.fbx': '/Game/Units',
    }

    all_models = {**hex_models, **unit_models}

    executor = UnrealRemoteExecutor()

    if not executor.connect():
        print("Failed to connect to Unreal Engine")
        return

    print("=" * 60)
    print("IMPORTING FBX MODELS")
    print("=" * 60)

    for fbx_file, destination in all_models.items():
        fbx_path = os.path.join(fbx_base_path, fbx_file)

        if not os.path.exists(fbx_path):
            print(f"\nSkipping {fbx_file} - file not found")
            continue

        print(f"\nImporting {fbx_file} to {destination}...")

        # Import code for Unreal Engine
        code = f"""
import unreal

# Import settings
import_task = unreal.AssetImportTask()
import_task.filename = r'{fbx_path}'
import_task.destination_path = '{destination}'
import_task.automated = True
import_task.save = True
import_task.replace_existing = True

# FBX import options
fbx_options = unreal.FbxImportUI()
fbx_options.import_mesh = True
fbx_options.import_as_skeletal = False
fbx_options.import_materials = True
fbx_options.import_textures = True
fbx_options.static_mesh_import_data.combine_meshes = True

import_task.options = fbx_options

# Execute import
asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
asset_tools.import_asset_tasks([import_task])

print(f'Imported: {fbx_file}')
"""

        result = executor.execute(code)

        if result.get('success'):
            print(f"  [OK] Successfully imported {fbx_file}")
        else:
            print(f"  [FAILED] Failed to import {fbx_file}: {result.get('result')}")

    executor.disconnect()

    print("\n" + "=" * 60)
    print("IMPORT COMPLETE")
    print("=" * 60)


if __name__ == '__main__':
    import_fbx_models()
