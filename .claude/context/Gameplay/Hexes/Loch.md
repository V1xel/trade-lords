# Loch (Lake) Terrain

## Overview

Lochs are water hexes that create barriers, require shipping to cross, and provide unique strategic opportunities (especially for Caspian).

## Visual

- Color: Deep blue
- Texture: Water, waves
- Moderate presence (15-20% of map)

## Loch Properties

### Water Hexes
- Full hex terrain (not edge feature like rivers)
- Impassable for standard units
- Require shipping to cross
- Special placement rules for Fishermen

### No Placement Cost
- Lochs have no terrain cost
- Cannot build on loch (except Fishermen)
- Pure barrier for most lords

## Gameplay Effects

### Spatial Barriers
- Block land-based expansion
- Force shipping investment
- Create map divisions
- Strategic positioning

### Shipping Requirement

**Crossing Lochs**:
- **0-loch shipping**: Cannot cross loch hexes
- **1-loch shipping**: Can cross 1 loch hex
- **2-loch shipping**: Can cross 2 loch hexes
- **3-loch shipping**: Can cross 3 loch hexes
- Etc.

**Distance Measured in Hexes**:
```
[Land] - [Loch] - [Loch] - [Land]
```
Requires 2-loch shipping to reach opposite land

## Fishermen (Caspian Only)

### Lord Caspian's Unique Ability
- Can place Fishermen on loch hexes
- Fishermen produce £4 income per Production Phase

### Fisherman Placement Rules
**Can Place On**:
- Any empty loch hex
- Port bonus hexes (special loch locations)

**Cost**:
- £6 (Fisherman unit cost)
- £0 (no terrain cost on water)
- Total: £6

**Restriction**:
- Cannot be adjacent to another Fisherman
- Spacing requirement (one hex minimum between Fishermen)

### Fisherman Adjacency
```
[Loch F] - [Loch] - [Loch F]  ✓ Valid (not adjacent)
[Loch F] - [Loch F]            ✗ Invalid (adjacent)
```

## Strategic Considerations

### For Standard Lords

**Barriers**:
- Lochs divide territory
- Shipping needed for expansion
- Limit early-game options

**Shipping Investment**:
- £4 per shipping level
- 1-loch: £4
- 2-loch: £8 total
- 3-loch: £12 total

**Value Decision**:
- Is territory beyond loch worth shipping cost?
- What terrain is accessible?
- Can opponents block access?

### For Lord Caspian

**Unique Territory**:
- Exclusive access to loch hexes
- No competition for water territories
- Cheap placement (£6 vs £9-£10 for land workers)

**Income Generation**:
- Fishermen: £4 per round
- Multiple lochs = multiple Fishermen
- Passive income engine

**Spacing Strategy**:
- Maximize Fishermen while maintaining spacing
- Checkerboard pattern on large lochs
- ~50% of loch hexes usable

## Loch States

### Hex Properties
- Terrain type: Loch (water)
- Placement cost: N/A
- Occupant: None (or Fisherman if Caspian)
- Adjacent to: Land hexes, other loch hexes, river deltas

### Loch Configuration
- Single large loch
- Multiple small lochs
- Loch chains (connected)
- Isolated lochs

## Lord Synergies

### Strong with Lochs
- **Lord Caspian**: Direct synergy
  - Fishermen on lochs
  - Exclusive territory
  - Unique income source
  - More lochs = more power

- **Baron Roderick**: Free shipping
  - Starts 2-loch shipping (3-4p)
  - Loch barriers minimized
  - Wide expansion enabled

- **Lady Isolde**: Free river-crossing
  - Starts shipping level 1
  - Partial loch advantage
  - Early mobility

### Moderate Impact
- **Lady Marina**: Lochs adjacent to rivers
  - River deltas next to lochs
  - Strategic positioning

### Neutral
- Other lords: Lochs are barriers equally
- Shipping investment required

## Loch Patterns

### Central Loch
- Large loch in map center
- Divides map into regions
- High shipping value

### Peripheral Lochs
- Small lochs at map edges
- Lower strategic impact
- May contain premium terrain beyond

### Loch Chain
- Connected loch hexes
- Long water barriers
- Require high shipping levels

## Shipping Economics

**Example: Reaching Territory Beyond 2 Loch Hexes**
- Shipping cost: £8 (2 levels × £4)
- Accessible: Mountains, forests, or premium grassland
- Value: If 2-3 premium hexes, worth investment
- If only 1 hex or low-value terrain, skip

**Caspian Alternative**:
- No shipping needed for loch placement
- Can claim loch hexes directly
- Blocks shipping routes (Fishermen occupy hexes)

## Loch + River Interactions

### River Deltas
- Where rivers flow into lochs
- Land hex adjacent to both
- Marina's specialty (£3 discount)
- Premium strategic positions

### Delta Patterns
```
[River] ~~~ [DELTA Land] --- [Loch]
                |
            [Loch]
```
Delta adjacent to loch, has river edge

## Placement Examples

**Example 1: Standard Lord Crossing Loch**
- Starting hex: [Land A]
- Target hex: [Land B], 2 loch hexes away
- Need: 2-loch shipping (£8 investment)
- Then can place units on Land B

**Example 2: Caspian Fisherman**
- Loch hex available
- Place Fisherman: £6 (no terrain cost)
- Income: £4 per round
- Break-even: 1.5 rounds
- Cheap income

**Example 3: Caspian Spacing**
```
Large Loch (7 hexes):
[F] [.] [F] [.]
   [.] [F] [.]

F = Fisherman, . = empty
Maximum 4 Fishermen on 7-hex loch due to spacing
```

## Strategic Decisions

### For All Lords
**Shipping Investment**:
- Evaluate terrain beyond lochs
- Calculate shipping ROI
- Consider opponent access
- Timing of investment

**Loch Positioning**:
- Use lochs as defensive barriers
- Control loch-adjacent chokepoints
- Block opponent expansion

### For Caspian
**Fisherman Placement**:
- Which lochs to claim first?
- Spacing optimization
- Income vs expansion balance

**Loch Monopoly**:
- Claim all major lochs
- Deny shipping value to opponents
- Passive income dominance

## Loch Distribution Effects

### Many Lochs Map
- Shipping critical for all
- Caspian very strong
- Territorial fragmentation
- Complex expansion paths

### Few Lochs Map
- Lower shipping priority
- Caspian weaker (fewer Fishermen)
- Open expansion
- Simpler strategies

### Typical Distribution
- 10-15% of map hexes
- 2-3 major lochs
- 8-15 loch hexes total
- 4-7 potential Fisherman locations (Caspian)

## Loch Control

**Caspian's Advantage**:
- Fishermen occupy loch hexes
- Blocks shipping paths through occupied hexes
- Forces opponents to route around
- Territorial control via water

**Defensive Value**:
- Lochs protect flanks
- Reduce attack vectors
- Create safe production zones
- Limit opponent options
