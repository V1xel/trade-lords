# Hexes Module

## Overview

The hex system forms the game board where lords expand their territories. Hexes have terrain types that determine which units can be placed and the cost to do so.

## Terrain Types

1. **Grassland** - Agricultural production
2. **Forest** - Woodcutter placement
3. **Mountain** - Miner placement
4. **River** - Water boundary feature
5. **Loch** - Water hexes

## Core Concepts

### Hex Grid
- Modular map construction (16 configurations)
- Hexagonal grid (6 neighbors per hex)
- Adjacency-based expansion

### Placement Cost
Each hex has a cost (£1-£6) based on terrain composition:
- Single terrain: £1-£3
- Mixed terrain: £4-£6

### Terrain Requirements
Units require specific terrain types:
- Grassland: Sheep, Cows, Fields, Factories
- Forest: Woodcutters
- Mountain: Miners
- Loch: Fishermen (Caspian only)

### Special Features
- **River Deltas**: Where rivers meet lochs (Marina bonus)
- **Mixed Terrain**: Multiple terrain types in one hex

## File Structure

```
Hexes/
├── README.md (this file)
├── HexGrid.md (grid mechanics, adjacency, map setup)
├── Grassland.md
├── Forest.md
├── Mountain.md
├── River.md
└── Loch.md
```

## Hex State

- Terrain type(s)
- Placement cost (£1-£6)
- Occupying unit (if any)
- Owning player (if occupied)
- Is river delta (boolean)
- Adjacent hexes (6 references)

## Placement Rules

### Basic Placement
1. Unit must match terrain type
2. Hex must be adjacent to owned unit OR within shipping range
3. Pay total cost = unit cost + terrain cost - discounts

### Adjacency
- New units adjacent (share edge) to existing units
- OR connected via shipping
- Cannot place in isolated locations

### Terrain Matching
- Grassland units → Grassland terrain
- Forest units → Forest terrain
- Mountain units → Mountain terrain
- Mixed terrain → Any matching terrain type
