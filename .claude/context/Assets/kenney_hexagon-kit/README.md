# Kenney Hexagon Kit Assets

## Overview

Hex-based 3D models for Trade Lords game board and units.

## Model Categories

### Terrain Hexes (Core)
- **grass.fbx**: Grassland (£1-£2, supports agricultural units)
- **grass-forest.fbx**: Forest (£2-£3, supports Woodcutters)
- **grass-hill.fbx**: Grassland elevation variation
- **stone-mountain.fbx**: Mountain (£3-£4, supports Miners)
- **stone.fbx**, **stone-hill.fbx**: Mountain variations
- **water.fbx**: Loch/lake (impassable except Caspian Fishermen)
- **water-island.fbx**, **water-rocks.fbx**: Loch variations

### Production Units (Core)
- **building-farm.fbx**: Field (produces Grain)
- **building-sheep.fbx**: Sheep (produces Wool)
- **building-cabin.fbx**: Cow (produces Milk)
- **unit-tree.fbx**: Woodcutter (£4 income)
- **building-mine.fbx**: Miner (£6 income)
- **unit-ship.fbx**: Fisherman - Caspian only (£4 income)

### Processing Buildings (Core)
- **building-house.fbx**: Cheese Dairy (Milk→Cheese)
- **building-mill.fbx**: Bakery/Distillery (Grain→Bread/Whisky)
- **building-watermill.fbx**: Brewery - Oswald only (Grain→Beer)
- **building-smelter.fbx**: Distillery alternative visual
- **unit-mill.fbx**: Bakery alternative visual

### River Features (Core)
- **river-straight.fbx**, **river-corner.fbx**, etc.: River edge pieces
- See _RIVER_PIECES.md for complete list
- **bridge.fbx**: River crossing visual indicator

### Cosmetic/UI
- **building-castle.fbx**: Lord headquarters
- **building-wizard-tower.fbx**: Lord with special abilities (Godwyn/Oswald)
- **building-village.fbx**: Settlement marker
- **building-market.fbx**: Market UI indicator
- **building-port.fbx**: Port bonus tile, shipping visual
- **building-dock.fbx**: Fisherman location (Caspian)
- **unit-house.fbx**, **unit-mansion.fbx**: Settlement visuals

### Not Used
- **building-archery.fbx**, **building-tower.fbx**, **building-wall.fbx**: Combat buildings (no combat mechanic)
- **path-*.fbx**: Roads (no road mechanic) - See _PATH_PIECES.md
- **sand*.fbx**, **dirt*.fbx**: Alternative terrains (not in game)
- **unit-ship-large.fbx**, **unit-tower.fbx**, **unit-wall-tower.fbx**: Not used

## Model Mapping to Game Units

| Game Unit | Primary Model | Alternative |
|-----------|---------------|-------------|
| Sheep | building-sheep.fbx | - |
| Cow | building-cabin.fbx | - |
| Field | building-farm.fbx | - |
| Cheese Dairy | building-house.fbx | - |
| Bakery | building-mill.fbx | unit-mill.fbx |
| Distillery | building-mill.fbx | building-smelter.fbx |
| Brewery | building-watermill.fbx | - |
| Woodcutter | unit-tree.fbx | - |
| Miner | building-mine.fbx | - |
| Fisherman | unit-ship.fbx | - |

## Terrain Mapping

| Terrain Type | Primary Model | Variations |
|--------------|---------------|------------|
| Grassland | grass.fbx | grass-hill.fbx |
| Forest | grass-forest.fbx | - |
| Mountain | stone-mountain.fbx | stone.fbx, stone-hill.fbx |
| Loch | water.fbx | water-island.fbx, water-rocks.fbx |
| River | river-*.fbx | Multiple edge pieces |

## Usage Notes

- Each .fbx has matching .md file with game mechanics
- Batch descriptions in _*.md files for similar pieces
- Models designed for hexagonal grid layout
- Preview images available in ../Previews/ folder
