# Lord Caspian the Steward

## Identity

**Name**: Lord Caspian the Steward
**Title**: Master of Guilds
**House Colors**: Multi-colored Guild Badges
**Archetype**: Versatile Specialist

## Appearance

Clever-faced nobleman wearing guild badges from multiple trades, ring of keys to various workshops, practical attire.

## Background

Controls multiple trade guilds through political maneuvering. Master of no single craft, but controls them all through influence and cunning.

## Ability: "Guild Mastery"

### Mechanics

**Flexible Workers**:
- Workers can function as Woodcutters, Miners, OR Fishermen
- Player chooses role when placing worker
- Role is permanent once placed

**Worker Standardization**:
- All workers cost £6 (standard: Miner £6, Woodcutter £5)
- All workers provide £4 income (standard: Miner £6, Woodcutter £4)
- Balanced for flexibility

**Fisherman Mechanics** (Unique to Caspian):
- Can be placed on **loch hexes** (water)
- Can be placed on **port bonus tiles**
- **No land cost** when placed on water (only pay £6 worker cost)
- Produces £4 income per Production Phase
- **Cannot be adjacent** to another Fisherman

### Game States Modified

**Player State**:
- `workers: [{type: "woodcutter"|"miner"|"fisherman", location}]`
- Worker type assigned on placement

**Placement Rules**:
- Water hexes become valid for Fishermen
- Adjacency check for Fishermen (cannot be adjacent to each other)

### Examples

**Example 1: Fisherman Placement**
- Loch hex has no land cost (water hex)
- Place Fisherman: Pay £6 (worker cost only)
- Compare: Standard lord placing Miner on £3 Mountain = £6 + £3 = £9
- Fisherman on loch = £6 total
- Savings: £3 (no terrain cost)

**Example 2: Worker Flexibility**
- Setup: Place 2 Workers as Miners (£4 each income)
- Round 2: Build 1 Worker as Fisherman on loch
- Round 3: Build 1 Worker as Woodcutter
- Total: 2 Miners, 1 Fisherman, 1 Woodcutter
- All produce £4 income = £16 per round

**Example 3: Fisherman Restriction**
- Loch has 6 adjacent hexes (standard hex grid)
- Place Fisherman on loch hex A
- Cannot place Fishermen on hexes adjacent to A
- Can place Fishermen on non-adjacent loch hexes
- Creates spacing requirement

**Example 4: Cost Comparison**
| Worker Type | Standard Lord | Caspian |
|-------------|---------------|---------|
| Woodcutter on £2 Forest | £5 + £2 = £7 | £6 + £2 = £8 |
| Miner on £3 Mountain | £6 + £3 = £9 | £6 + £3 = £9 |
| Fisherman on Loch | N/A | £6 + £0 = £6 |

## Strategy

### Strengths
- Ultimate flexibility (adapt to available terrain)
- Access to water hexes (unique)
- No terrain cost on water (significant savings)
- Can place workers anywhere
- Unpredictable expansion

### Weaknesses
- Workers produce only £4 (vs Miners £6)
- Fishermen cannot be adjacent (spacing limits)
- Woodcutters cost £6 (vs standard £5)
- Requires water access for full potential

### Playstyle

**Early Game**:
- Scout for valuable loch positions
- Place Fishermen on premium water locations
- Use flexibility to claim best available terrain
- Block opponents from water access

**Mid Game**:
- Mix worker types based on terrain
- Maximize spacing for Fishermen
- Control water territories
- Leverage unique positioning

**Late Game**:
- Worker network across all terrain types
- Steady £4 per worker income
- Flexible resource generation
- Defensive positioning

### Key Decisions
- **Worker Type**: Woodcutter vs Miner vs Fisherman?
- **Fisherman Placement**: Which loch hexes provide best value?
- **Spacing**: How to maximize Fishermen without adjacency violations?
- **Water vs Land**: When is £6 water placement better than £9+ land?

### Fisherman Strategy

**Optimal Fisherman Placement**:
- Premium loch locations (near multiple territories)
- Port bonus tiles (extra rewards)
- Defensive chokepoints (block opponents)
- Resource-adjacent (support production units)

**Spacing Pattern**:
```
Example loch layout (F = Fisherman, . = empty loch):
  F . F
 . . . .
  F . F
```
Checkerboard pattern maximizes Fishermen on loch

### Synergies
- Benefits from maps with many lochs
- Strong with shipping (access distant water)
- Complements wide expansion strategies
- Pairs well with port bonuses

### Counters
- Maps with few lochs
- Opponents claiming water early
- Limited terrain variety
- Worker income cap (£4 max)

## Starting Resources

- **Gold**: £8
- **Units**:
  - 2 Workers (assign as any type on placement)
  - 1 Sheep
- **Merchants**: 2
- **Shipping**: 0 (none, but benefits from getting it)

## Difficulty

**Complexity**: Advanced
**Reason**: Requires spatial planning, understanding terrain optimization, Fisherman spacing constraints

## Victory Paths

1. **Water Dominance**: Control loch territories, maximize Fishermen
2. **Flexible Expansion**: Adapt to best terrain, opportunistic placement
3. **Defensive Control**: Use workers to block key positions

## Terrain Value Comparison

**When to Place Each Worker Type**:

**Fisherman**:
- Loch hex (£0 terrain cost) = £6 total
- Best on expensive water positions

**Miner**:
- Mountain £3-£4 = £9-£10 total
- Higher income potential if can be upgraded

**Woodcutter**:
- Forest £2-£3 = £8-£9 total
- Standard positioning

**Decision**:
- Loch available? Consider Fisherman (cheapest)
- Expensive Mountain? Consider Fisherman on water instead
- Cheap terrain? Use appropriate land worker

## Fisherman Adjacency Rules

**Cannot Place Fisherman**:
- Adjacent to existing Fisherman (shares edge)
- Example: If Fisherman at hex A, cannot place at any of A's 6 neighbors

**Can Place Fisherman**:
- Non-adjacent loch hexes
- Separated by at least 1 hex

**Maximum Fishermen on Loch**:
- Depends on loch size and shape
- ~50% of loch hexes maximum (due to spacing)
