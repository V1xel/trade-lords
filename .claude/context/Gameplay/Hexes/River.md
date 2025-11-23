# River Feature

## Overview

Rivers are edge features (not hex terrain) that create natural boundaries and strategic complexity. Rivers flow along hex edges and require shipping to cross.

## Visual

- Color: Light blue
- Representation: Lines along hex edges
- Flows from source to loch

## River Properties

### Edge Feature
- Runs along hex edges (not through hex centers)
- Multiple edges can have rivers
- Creates boundaries between hexes

### River Path
- Flows from highlands to loch
- Connected water system
- Natural barriers

## Gameplay Effects

### Blocking Adjacency
**Without Shipping**:
- Cannot cross river edges
- Units separated by river are NOT adjacent
- Limits expansion

**With River-Crossing Shipping**:
- Can cross rivers
- Adjacent across river edges
- Unlocks new territories

### Shipping Requirement
- **Level 0** (no shipping): Cannot cross rivers
- **Level 1** (river-crossing): Can cross rivers
- **Level 2+** (loch shipping): Can cross rivers + water hexes

## River Deltas

### Definition
Hex where river meets loch:
- Land hex
- Adjacent to river edge
- Adjacent to loch hex
- River flows into loch at this point

### Identification
```
[Land Hex with River] ~~~river~~~ [Land Hex DELTA] --- [Loch Hex]
```

Delta hex is:
- Adjacent to river
- Adjacent to loch
- Where water meets water

### Marina's Bonus
**Lady Marina of the Estuaries**:
- £3 discount on delta placement (3-4 players)
- £2 discount on delta placement (1-2 players)
- Major strategic advantage

## Strategic Considerations

### Natural Barriers
- Rivers divide map into regions
- Control river crossings strategic
- Defensive positions

### Expansion Routes
- Rivers channel expansion paths
- Force shipping investment
- Create chokepoints

### Delta Premium
- Deltas are strategic positions
- Control waterway junctions
- High value for Marina
- Often mixed terrain (versatile)

## River States

### Map Generation
- River paths pre-determined
- Flow from source to loch
- Multiple rivers possible

### Game State
- River edges marked on hexes
- Immutable (don't change during game)
- Used for adjacency calculations

## River Crossing Examples

**Example 1: No Shipping**
```
[Player's Sheep] ~~~river~~~ [Empty Grassland]
```
- Cannot place unit on grassland (river blocks adjacency)
- Not adjacent without shipping

**Example 2: With River-Crossing Shipping**
```
[Player's Sheep] ~~~river~~~ [Empty Grassland]
```
- CAN place unit on grassland
- Shipping level 1 crosses rivers
- Now adjacent

**Example 3: River Delta (Marina)**
```
[Player unit] ~~~river~~~ [DELTA Grassland] --- [Loch]
```
- Marina places Sheep on delta
- Cost: £5 (Sheep) + £3 (terrain) - £3 (Marina) = £5 total
- Standard lord pays: £8
- Savings: £3

## River Patterns

### Single River
- One main river across map
- Divides map in half
- Major strategic feature

### Multiple Rivers
- Several smaller rivers
- Create multiple regions
- More deltas (good for Marina)

### River Networks
- Rivers branch and merge
- Complex water systems
- Many delta locations

## Lord Synergies

### Strong with Rivers
- **Lady Marina**: Delta specialist
  - Rivers create deltas
  - More rivers = more deltas
  - Direct power scaling

- **Lady Isolde**: Free river-crossing shipping
  - Starts with shipping level 1
  - Can cross rivers immediately
  - Early expansion advantage

- **Baron Roderick**: Free shipping
  - Starts with 2-loch shipping (3-4p)
  - Rivers not a barrier
  - Wide expansion possible

### Moderate Impact
- **Lord Caspian**: Benefits from shipping
  - Fishermen need water access
  - Rivers lead to lochs

### Low Direct Impact
- Other lords affected equally
- Rivers are universal barriers
- Shipping investment needed

## Shipping Investment

### Cost to Cross Rivers
- River-crossing shipping: £4
- Unlocks all river crossings
- One-time investment
- Essential for expansion

### Value Calculation
**Without river-crossing**:
- Limited to one side of river
- ~50% of map inaccessible

**With river-crossing**:
- Full map access
- More terrain options
- Strategic flexibility

**Investment**: £4 for 50%+ more territory = excellent value

## River Control Strategy

### Bridge Positions
- Hexes on both sides of river
- Control crossings
- Block opponent access

### River-Based Defense
- Use rivers as defensive lines
- Opponents need shipping to attack
- Time to prepare

### Delta Monopoly (Marina)
- Claim all deltas early
- Maximum discount value
- Strategic waterway control

## Map Variations

### River-Heavy Maps
- Many rivers, many deltas
- Marina very strong
- Shipping essential for all
- Complex territorial divisions

### River-Light Maps
- Few or no rivers
- Marina weaker
- Less shipping pressure
- Open expansion

### River Distribution
- Typical map: 2-3 rivers
- Each river: 2-4 deltas
- 6-12 delta hexes total

## River + Terrain Interactions

### River + Grassland
- Deltas often grassland
- High value (versatile + Marina bonus)

### River + Mountain
- Mountain deltas rare but premium
- £4 terrain - £3 Marina = £1 effective cost
- Miner + discount = excellent value

### River + Mixed Terrain
- Common delta configuration
- £4-£5 terrain typical
- Marina discount makes affordable
