# Shipping System

## Overview

Shipping allows players to place units across water (rivers and lochs), expanding their territory beyond adjacent hexes.

## Shipping Levels

### Level 0 (No Shipping)
- Cannot cross rivers
- Cannot cross lochs
- Limited to land adjacency only

### Level 1 (River-Crossing)
- Can cross river edges
- Cannot cross loch hexes
- Unlock: £4

### Level 2 (1-Loch Shipping)
- Can cross rivers
- Can cross 1 loch hex
- Unlock: £4 (£8 total from Level 0)

### Level 3 (2-Loch Shipping)
- Can cross rivers
- Can cross 2 loch hexes
- Unlock: £4 (£12 total from Level 0)

### Levels 4-5+
- Each level: Cross 1 additional loch hex
- Cost: £4 per level
- Diminishing returns

## Shipping Mechanics

### Adjacency Extension
**Without Shipping**:
- Units must be adjacent (share edge)
- Rivers block adjacency
- Lochs block adjacency

**With Shipping**:
- Can "reach" across water
- Distance in water hexes ≤ shipping level
- Land units act as anchor points

### Placement Rules
1. Unit must be within range of owned unit
2. Range = land adjacency OR shipping distance
3. Shipping crosses rivers + lochs
4. Cannot hop across land (must use water path)

## Shipping Examples

**Example 1: River Crossing**
```
[Your Sheep] ~~~river~~~ [Empty Grassland]
```
- Level 0: Cannot place (river blocks)
- Level 1+: CAN place (river-crossing enabled)

**Example 2: Loch Crossing**
```
[Your Unit] - [Loch] - [Land Target]
```
- Level 0-1: Cannot place (need loch shipping)
- Level 2+: CAN place (1-loch shipping)

**Example 3: Multiple Lochs**
```
[Your Unit] - [Loch] - [Loch] - [Land Target]
```
- Level 0-2: Cannot place
- Level 3+: CAN place (2-loch shipping)

## Shipping Costs

### Investment
- Each level: £4
- Total to Level 3: £12

### Value Calculation
- Unlocks new territories
- Access to premium hexes
- Expansion flexibility
- Strategic control

**Worth it**: If valuable territory beyond water

## Lord Synergies

### Baron Roderick (Very Strong)
**Free Shipping**:
- Starts with 2-loch shipping (3-4 players)
- Starts with 1-loch shipping (1-2 players)
- Saves £8-£12
- Immediate wide expansion

### Lady Isolde (Strong)
**Free River-Crossing**:
- Starts with shipping Level 1
- Saves £4
- Early expansion advantage

### Lady Marina
**Indirect Benefit**:
- Deltas near water
- Shipping helps reach distant deltas
- Strategic positioning

### Lord Caspian
**Essential for Fishermen**:
- Fishermen on lochs
- Shipping helps connect territories
- Flexible expansion

## Shipping Strategy

### When to Invest
**Invest in shipping if**:
- Valuable territory across water
- Premium hexes (mountains, deltas)
- Opponents expanding there
- Wide map presence desired

**Skip shipping if**:
- Plenty of adjacent land
- No valuable water territories
- Tight on gold
- Compact strategy

### Shipping Priority
1. **River-Crossing (Level 1)**: Usually essential (£4)
2. **1-Loch (Level 2)**: High value if lochs present (£4 more)
3. **2-Loch (Level 3)**: Situational (£4 more)
4. **3-Loch+**: Rarely needed

## Shipping vs Expansion

**Shipping Investment**:
- £4-£12 total
- Unlocks territories
- One-time cost
- Permanent benefit

**Alternative**:
- Build units on available land
- £6-£10 per unit
- Immediate production
- No new territories

**Trade-off**: Shipping vs more units

## River Deltas and Shipping

**Deltas near water**:
- Often require shipping to reach
- Marina gets discount
- High strategic value
- Worth shipping investment

**Example**:
- Mountain delta across river
- £4 river-crossing unlock
- Access £4 mountain with Marina -£3 = £1 effective cost
- Miner produces £6/round
- ROI: Excellent

## Loch Control

**With Shipping**:
- Reach territories across lochs
- Claim distant hexes
- Prevent opponent expansion

**Caspian Fishermen**:
- Fishermen occupy loch hexes
- Block shipping paths
- Force routing around
- Territorial control

## Map Dependency

### River-Heavy Maps
- Many rivers divide territories
- River-crossing essential (Level 1)
- £4 required for everyone
- Roderick/Isolde advantage

### Loch-Heavy Maps
- Large lochs separate regions
- Loch shipping needed (Level 2-3)
- Higher shipping investment
- Roderick very strong

### Open Maps
- Few water barriers
- Low shipping priority
- Save gold for units
- Compact strategies viable

## Shipping Timing

### Early Shipping (Round 1-2)
- Unlock river-crossing
- Access more territories
- Claim premium spots
- High value

### Mid Shipping (Round 2-3)
- Unlock loch shipping if needed
- Expand to new regions
- Moderate value

### Late Shipping (Round 4-5)
- Usually too late
- Focus on production/contracts
- Skip unless critical

## Free Shipping (Lord Bonuses)

**Roderick 2-Loch Start**:
- Equivalent to £8 saved
- Immediate wide expansion
- Claim best territories
- Massive advantage

**Isolde River-Crossing Start**:
- Equivalent to £4 saved
- Early flexibility
- Good advantage

**Value**: Starting shipping = early expansion = territory control = economic advantage

## Shipping Distance Calculation

**Hex Distance**:
- Count water hexes between owned unit and target
- Must be ≤ shipping level

**Example**:
```
[Your Unit] - [Land] - [Loch] - [Loch] - [Target]
```
- Land adjacency to first land: OK
- 2 lochs to target: Need 2-loch shipping

**Path must be valid water path**

## Shipping Limits

**Cannot Shipping Through**:
- Enemy units (blocks path)
- Occupied hexes
- Caspian's Fishermen (blocks loch hex)

**Must Route Around**:
- Find alternate water path
- Longer distance
- May need higher shipping level
