# Units Module

## Overview

Units are placed on hexes to produce resources, generate income, or process goods. Each unit type has specific terrain requirements and gameplay functions.

## Unit Categories

### Production Units (Basic Goods)
- **Sheep** - Produces Wool
- **Cow** - Produces Milk
- **Field** - Produces Grain

### Workers (Income)
- **Woodcutter** - Generates £4/£6 income
- **Miner** - Generates £6/£8 income
- **Fisherman** - Generates £4 income (Caspian only)

### Processing Buildings (Processed Goods)
- **Cheese Dairy** - Milk → Cheese
- **Bakery** - Grain → Bread
- **Distillery** - Grain → Whisky
- **Brewery** - Grain → Beer (Oswald only)

## Common Unit Properties

### Placement
- Terrain requirement
- Unit cost (£4-£6)
- Terrain cost (£1-£6)
- Adjacency to owned units OR shipping range

### Production
- Produces during Production Phase
- 1 unit → 1 resource per round (standard)
- Workers produce income instead

### Ownership
- Owned by placing player
- Permanent (cannot be removed/captured)
- Marks territory control

## File Structure

```
Units/
├── README.md (this file)
├── Sheep.md
├── Cow.md
├── Field.md
├── CheeseDairy.md
├── Bakery.md
├── Distillery.md
├── Brewery.md
├── Woodcutter.md
├── Miner.md
└── Fisherman.md
```

## Unit States

### Placement State
- Unit type
- Owner
- Hex location
- Terrain matched

### Production State
- Produced resource (if production unit)
- Income generated (if worker)
- Input resource consumed (if processing building)

## Placement Rules

**Total Cost Calculation**:
```
Total = Unit Cost + Terrain Cost - Lord Discounts
```

**Adjacency Requirement**:
- Must be adjacent to owned unit
- OR within shipping range across water
- Cannot place in isolation

**Terrain Matching**:
- Grassland units → Grassland terrain
- Forest units → Forest terrain
- Mountain units → Mountain terrain
- Loch units → Loch terrain (Caspian only)
- Mixed terrain → Any matching type

## Production Chains

### Wool Chain
```
Sheep → Wool (used directly for contracts/trading)
```

### Dairy Chain
```
Cow → Milk → Cheese Dairy → Cheese
```

### Grain Chains
```
Field → Grain → Bakery → Bread
Field → Grain → Distillery → Whisky
Field → Grain → Brewery → Beer (Oswald)
```

### Worker Income
```
Woodcutter → £4 per round (£6 upgraded)
Miner → £6 per round (£8 upgraded)
Fisherman → £4 per round (Caspian)
```
