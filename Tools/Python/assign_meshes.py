"""
Assign static meshes to Blueprint actors
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from unreal_remote import UnrealRemoteExecutor


def assign_mesh_to_blueprint(blueprint_path, mesh_path):
    """
    Assign a static mesh to a Blueprint's StaticMeshComponent

    Args:
        blueprint_path (str): Path to Blueprint asset (e.g., '/Game/Hexes/BP_HexTile_Grassland')
        mesh_path (str): Path to static mesh asset (e.g., '/Game/Meshes/Hexes/grass')
    """
    executor = UnrealRemoteExecutor()

    if not executor.connect():
        return {"success": False, "result": "Failed to connect to Unreal Engine"}

    code = f"""
import unreal

# Load the Blueprint asset
blueprint = unreal.load_asset('{blueprint_path}')

if blueprint:
    # Get the Blueprint's generated class
    bp_class = blueprint.generated_class()

    if bp_class:
        # Get the CDO (Class Default Object)
        cdo = unreal.get_default_object(bp_class)

        # Try to find TileMesh or UnitMesh component
        mesh_comp = None
        try:
            mesh_comp = cdo.get_editor_property('tile_mesh')
        except:
            try:
                mesh_comp = cdo.get_editor_property('unit_mesh')
            except:
                print(f'Could not find TileMesh or UnitMesh component')

        if mesh_comp:
            # Load the static mesh
            mesh = unreal.load_asset('{mesh_path}')
            if mesh:
                mesh_comp.set_editor_property('static_mesh', mesh)
                print(f'Assigned mesh {{mesh.get_name()}} to {{mesh_comp.get_name()}}')
            else:
                print(f'Failed to load mesh: {mesh_path}')

            # Save the Blueprint
            unreal.EditorAssetLibrary.save_loaded_asset(blueprint)
            print(f'Saved Blueprint: {blueprint_path}')
        else:
            print(f'No mesh component found on: {blueprint_path}')
    else:
        print(f'Failed to get generated class for: {blueprint_path}')
else:
    print(f'Failed to load Blueprint: {blueprint_path}')
"""

    result = executor.execute(code)
    executor.disconnect()

    return result


def assign_all_meshes():
    """Assign meshes to all created Blueprints"""

    print("=" * 60)
    print("ASSIGNING MESHES TO BLUEPRINTS")
    print("=" * 60)

    # Hex Tiles
    hex_assignments = {
        '/Game/Hexes/BP_HexTile_Grassland': '/Game/Hexes/grass',
        '/Game/Hexes/BP_HexTile_Forest': '/Game/Hexes/grass-forest',
        '/Game/Hexes/BP_HexTile_Mountain': '/Game/Hexes/stone-mountain',
        '/Game/Hexes/BP_HexTile_Loch': '/Game/Hexes/water',
        '/Game/Hexes/BP_HexTile_River': '/Game/Hexes/river-straight',
    }

    # Unit Buildings
    unit_assignments = {
        '/Game/Units/BP_Unit_Sheep': '/Game/Units/building-sheep',
        '/Game/Units/BP_Unit_Cow': '/Game/Units/building-farm',  # Cow uses farm
        '/Game/Units/BP_Unit_Field': '/Game/Units/building-farm',
        '/Game/Units/BP_Unit_Woodcutter': '/Game/Units/building-mill',  # Woodcutter uses mill
        '/Game/Units/BP_Unit_Miner': '/Game/Units/building-mine',
        '/Game/Units/BP_Unit_Fisherman': '/Game/Units/building-dock',
        '/Game/Units/BP_Unit_CheeseDairy': '/Game/Units/building-house',  # Dairy uses house
        '/Game/Units/BP_Unit_Bakery': '/Game/Units/building-market',  # Bakery uses market
        '/Game/Units/BP_Unit_Distillery': '/Game/Units/building-smelter',  # Distillery uses smelter
        '/Game/Units/BP_Unit_Brewery': '/Game/Units/building-watermill',  # Brewery uses watermill
    }

    all_assignments = {**hex_assignments, **unit_assignments}

    for blueprint_path, mesh_path in all_assignments.items():
        print(f"\nAssigning mesh to {blueprint_path.split('/')[-1]}...")
        result = assign_mesh_to_blueprint(blueprint_path, mesh_path)

        if result.get('success'):
            print(f"  [OK] Assigned {mesh_path.split('/')[-1]}")
        else:
            print(f"  [FAILED] {result.get('result')}")

    print("\n" + "=" * 60)
    print("MESH ASSIGNMENT COMPLETE")
    print("=" * 60)


if __name__ == '__main__':
    assign_all_meshes()
