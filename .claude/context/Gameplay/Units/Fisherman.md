# Fisherman

## Overview

Fisherman is a special worker unit unique to Lord Caspian. Placed on Loch (water) hexes, generates income with no terrain cost.

## Properties

**Type**: Worker (Income Generator)
**Cost**: £6
**Terrain**: Loch (water) only
**Income**: £4 per Production Phase
**Availability**: Lord Caspian only

## Placement

### Requirements
- Loch (water) terrain hex
- Adjacent to owned unit OR shipping range
- Pay £6 (unit cost only)
- **No terrain cost** (water is free)
- Cannot be adjacent to another Fisherman

### Spacing Rule
**Fishermen cannot be adjacent**:
```
[Loch F] - [Loch] - [Loch F]  ✓ Valid
[Loch F] - [Loch F]            ✗ Invalid (adjacent)
```

### Examples
- Fisherman on loch = £6 total (no terrain cost!)
- Compare to Miner: £6 + £4 = £10
- Savings: £4 per Fisherman

## Production

### Production Phase Income
- Generates £4 gold
- Automatic (no input needed)
- Added to player's gold

### No Upgrade (TBD)
- Currently unclear if Fishermen can upgrade
- Assume £4 income permanent

## Strategic Use

### Caspian's Unique Advantage
- Exclusive access to loch hexes
- No competition (other lords can't place here)
- Cheap placement (no terrain cost)
- Extra territory

### Spacing Strategy
- Cannot place adjacent Fishermen
- Checkerboard pattern on large lochs
- ~50% of loch hexes usable

**Example Loch Pattern**:
```
  F . F .
 . . . . .
  F . F .
```
F = Fisherman, . = empty loch

## Lord Synergies

### Lord Caspian (Exclusive)
**Core Ability**: "Guild Mastery"

**Worker Rules**:
- All workers cost £6
- All workers produce £4
- Can be: Woodcutter, Miner, OR Fisherman

**Fisherman Advantages**:
- £6 cost, £4 income (same as other Caspian workers)
- **No terrain cost** (unique!)
- Exclusive territory (no competition)

**Fisherman Best Option for Caspian**:
- Woodcutter: £6 + £3 terrain = £9 total
- Miner: £6 + £4 terrain = £10 total
- Fisherman: £6 + £0 terrain = £6 total ✓ Best

## Comparison

**Caspian's Worker Options**:
| Worker Type | Unit Cost | Terrain Cost | Total | Income |
|-------------|-----------|--------------|-------|--------|
| Woodcutter | £6 | £3 | £9 | £4 |
| Miner | £6 | £4 | £10 | £4 |
| Fisherman | £6 | £0 | £6 | £4 |

**Fisherman is cheapest Caspian worker**:
- Same income as others (£4)
- Lowest total cost (£6)
- Best ROI

**Fisherman vs Standard Workers** (other lords):
| Worker | Cost (standard) | Cost (Caspian) | Income |
|--------|-----------------|----------------|--------|
| Woodcutter | £5 | £6 | £4 |
| Miner | £6 | £6 (but £4 income!) | £6 (£4 for Caspian) |
| Fisherman | N/A | £6 | £4 |

**Caspian's workers are worse income-wise**:
- Standard Miner: £6 income
- Caspian Miner: £4 income
- But Fisherman compensates with no terrain cost

## Game States

### Unit State
- Owner: Lord Caspian only
- Location: Loch hex
- Type: Fisherman

### Per Production Phase
- Generate £4 gold
- Add to Caspian's gold

### Spacing State
- Track adjacent Fishermen
- Prevent adjacent placement
- Enforce spacing rule

## Common Patterns

### Loch Control (Caspian)
- Claim all major lochs
- Fishermen on non-adjacent hexes
- Maximize coverage with spacing

**Example: 8-hex Loch**:
```
Maximum Fishermen: 4 (50% due to spacing)
Income: £16 per round
Investment: £24 total (4 × £6)
```

### Mixed Worker Strategy (Caspian)
- 2 Fishermen (lochs)
- 1 Miner (mountain)
- 1 Woodcutter (forest)
- Total: £16 per round
- Diverse terrain coverage

## Economic Calculation

**Fisherman Investment**:
- £6 (Fisherman only)
- No terrain cost
- Income: £4 per round
- Break-even: 1.5 rounds
- Best ROI for Caspian

**Multiple Fishermen** (4 on large loch):
- £6 × 4 = £24 investment
- £4 × 4 = £16 per round income
- Break-even: 1.5 rounds
- Cheap income engine

**Comparison to Land Workers**:
- 4 Miners (other lord): £10 × 4 = £40, income £24/round
- 4 Fishermen (Caspian): £6 × 4 = £24, income £16/round
- Fishermen: Less income but much cheaper

## Strategy Decisions

### When to Build Fishermen (Caspian)
- Lochs available (essential)
- Always high priority (cheapest worker)
- No terrain cost advantage
- Exclusive territory

### How Many Fishermen
- Based on loch size
- ~50% of loch hexes (spacing rule)
- Claim all major lochs

**Typical Map**:
- 8-12 loch hexes total
- 4-6 Fishermen possible
- £16-£24 per round income

### Fisherman vs Other Workers (Caspian)
**Fisherman Advantages**:
- Cheapest (£6 total vs £9-£10)
- Exclusive territory
- No competition

**Land Worker Advantages**:
- More locations available
- Can claim premium spots (deltas, etc.)

**Caspian Strategy**:
- Fishermen on all accessible lochs (priority)
- Land workers for remaining territories
- Maximize cheap Fishermen first

## Terrain Blockage

**Fishermen Block Shipping**:
- Fisherman occupies loch hex
- Other players cannot cross that hex (even with shipping)
- Forces routing around Fishermen
- Territorial control via water

**Strategic Placement**:
- Fishermen on key loch positions
- Block opponent shipping routes
- Control water access
- Defensive positioning

## Loch Distribution Impact

### Many Lochs Map
- Caspian very strong
- 8-10 Fishermen possible
- £32-£40 per round
- Dominates water

### Few Lochs Map
- Caspian weaker
- 2-4 Fishermen only
- Must rely on land workers
- Less unique advantage

**Caspian power scales with loch presence**

## Spacing Optimization

**Maximizing Fishermen on Loch**:

**Small Loch (4 hexes)**:
```
 F .
. . F
```
2 Fishermen maximum

**Medium Loch (7 hexes)**:
```
  F .
 . F .
  . F
```
3-4 Fishermen maximum

**Large Loch (12+ hexes)**:
```
 F . F . F
. . . . . .
 F . F . F
```
6 Fishermen maximum

**Generally ~50% coverage due to spacing**

## Caspian Income Comparison

**Caspian Starting Strategy**:
- 2 Workers (start) + expand
- Best allocation: 2 Fishermen (if lochs available)
- £6 × 2 = £12 investment
- £4 × 2 = £8 per round

**vs Roderick**:
- Roderick: 3 Miners = £18 per round (but £30 investment)
- Caspian: Could build 5 Fishermen for same £30 = £20 per round
- Caspian catches up if enough lochs

**Caspian's advantage is cost efficiency, not raw income**
