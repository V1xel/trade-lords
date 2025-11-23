# Content Documentation

Asset definitions for the TL board game project.

## Overview

This folder contains documentation for all Unreal Engine content assets including Blueprints, models, materials, data assets, textures, and UI widgets.

## Structure

- **Hexes/** - Hex tile Blueprints, models, and materials
- **Units/** - Unit Blueprints and models
- **Lords/** - Lord data assets and portraits
- **Resources/** - Resource data assets and icons
- **Contracts/** - Contract data assets
- **UI/** - Widget Blueprints and UI elements

## Asset Types

### Blueprints (BP_)
Blueprint classes derived from C++ base classes. Configured with specific data.

**Examples:**
- BP_HexTile_Grassland (extends AHexTile)
- BP_Unit_Sheep (extends AUnit)

### Static Meshes (SM_)
3D models for game entities.

**Examples:**
- SM_HexTile_Grassland
- SM_Unit_Sheep

### Materials (M_)
Materials applied to static meshes.

**Examples:**
- M_HexTile_Grassland
- M_HexTile_Forest

### Data Assets (DA_)
Pure data configurations (no visual representation).

**Examples:**
- DA_Lord_Aldric (ULordDefinition)
- DA_Resource_Wool (UResourceDefinition)
- DA_Contract_WoolExport_Small (UContractDefinition)

### Textures (T_)
2D images for UI, portraits, and icons.

**Examples:**
- T_Lord_Aldric_Portrait
- T_Icon_Wool
- T_UI_Background

### Widget Blueprints (WBP_)
UI elements and interfaces.

**Examples:**
- WBP_MainHUD
- WBP_MarketPanel
- WBP_ContractCard

## Module Breakdown

### Hexes (15 files)
- 5 Blueprint classes (one per terrain type)
- 5 Static meshes
- 5 Materials

### Units (21 files)
- 10 Blueprint classes (Sheep, Cow, Field, Woodcutter, Miner, Fisherman, CheeseDairy, Bakery, Distillery, Brewery)
- 10 Static meshes
- 1 README

### Lords (19 files)
- 9 Data assets (one per lord)
- 9 Portrait textures
- 1 README

### Resources (23 files)
- 11 Data assets (Wool, Milk, Grain, Cheese, Bread, Whisky, Beer, Cotton, Tobacco, SugarCane, Hops)
- 11 Icon textures
- 1 README

### Contracts (5 files)
- 4 Example contract data assets
- 1 README
- (Expand with more contracts as needed)

### UI (13 files)
- 12 Widget Blueprints
- 1 README

## Related Documentation

- **Development/** - C++ class definitions for base classes
- **Gameplay/** - Game mechanics that use these assets
- **Scenarios/** - How assets work together in gameplay

## Asset Creation Workflow

1. Check **Development/** for C++ base class definition
2. Check **Gameplay/** for gameplay mechanics
3. Create asset in Unreal Engine Content Browser
4. Configure properties per documentation
5. Update documentation if adding new assets
