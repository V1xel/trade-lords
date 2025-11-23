# Lady Marina of the Estuaries

## Identity

**Name**: Lady Marina of the Estuaries
**Title**: Duchess of the Deltas
**House Colors**: Blue & White
**Archetype**: River Delta Specialist

## Appearance

Noble in blue and silver with river motifs embroidered on clothing, carries navigation charts and compass.

## Background

Controls all major river delta territories through ancient hereditary rights. Expert in waterway commerce and river navigation.

## Ability: "Delta Rights"

### Mechanics

**River Delta Discount**:
When placing a unit in a **river delta** hex:
- **3-4 Player Games**: £3 discount off total placement cost
- **1-2 Player Games**: £2 discount off total placement cost

**River Delta Definition**:
A hex space that is:
1. Adjacent to a river (river runs along hex edge)
2. Adjacent to a loch (lake hex)
3. Where the river flows into the loch

**Applies To**:
- Any unit placement (production units, workers, factories)
- Includes initial worker placement during setup

**Cost Calculation**:
```
Total Cost = (Unit Cost + Terrain Cost) - Delta Discount
Minimum: £0 (cannot go negative)
```

### Game States Modified

**Hex Properties**:
- `is_river_delta: boolean`
- Pre-calculated during map generation

**Placement Cost**:
- If placing on delta hex, apply discount

### Examples

**Example 1: Basic Delta Placement**
- Sheep (£5) on £2 grassland delta
- 3-4 Players: (£5 + £2) - £3 = £4 total
- Standard lord would pay: £7
- Savings: £3

**Example 2: Expensive Delta**
- Cheese Dairy (£6) on £5 mixed terrain delta
- 3-4 Players: (£6 + £5) - £3 = £8 total
- Standard lord would pay: £11
- Savings: £3

**Example 3: Premium Delta Location**
- Miner (£6) on £4 mountain delta
- 3-4 Players: (£6 + £4) - £3 = £7 total
- Standard lord would pay: £10
- Savings: £3

**Example 4: Initial Worker**
- Setup Phase: Place starting Worker
- Place on £3 forest delta
- 3-4 Players: (Worker cost) + £3 - £3 = Worker cost only
- Free terrain cost on delta

**Example 5: 1-2 Player Game**
- Cow (£6) on £3 grassland delta
- 1-2 Players: (£6 + £3) - £2 = £7 total
- 3-4 Players would be: £6
- Discount reduced for smaller games

## Strategy

### Strengths
- Significant cost savings on premium locations
- Deltas often have mixed terrain (versatile)
- Deltas are strategic positions (control waterways)
- Scales with number of delta placements
- Works with any unit type

### Weaknesses
- Requires map with river deltas
- Limited delta availability
- Opponents can contest deltas
- Doesn't help with non-delta placement
- Map-dependent power level

### Playstyle

**Early Game**:
- Identify all delta hexes on map
- Claim highest-value deltas first
- Use starting worker on delta for free terrain
- Prioritize expensive delta hexes

**Mid Game**:
- Fill delta territories
- Use savings for rapid expansion
- Control key waterways
- Block opponents from deltas

**Late Game**:
- Delta advantage maintains lead
- Savings accumulate to significant gold
- Use gold for contracts/upgrades
- Territory control advantage

### Key Decisions
- **Which Deltas**: Prioritize expensive terrain or strategic position?
- **Unit Type**: What to place on each delta?
- **Timing**: Claim deltas early or wait for better units?
- **Competition**: Which deltas are worth contesting?

### Delta Evaluation

**High-Value Deltas** (prioritize):
- £4+ terrain cost (maximize discount)
- Mixed terrain (versatile placement options)
- Central position (control trade routes)
- Adjacent to multiple territories

**Medium-Value Deltas**:
- £2-£3 terrain cost
- Single terrain type
- Moderate strategic position

**Low-Value Deltas**:
- £1 terrain cost (minimal savings)
- Poor strategic position
- Limited adjacency

### Map Analysis

**Marina Power Level by Map**:
- **Many deltas**: Strong (multiple £3 savings)
- **Few deltas**: Moderate (limited scope)
- **No deltas**: Weak (ability unused)

**Delta Distribution**:
- Typical map: 4-8 delta hexes
- Strategic map: 8-12 delta hexes
- Marina should evaluate map before selection

### Synergies
- Benefits from shipping (reach distant deltas)
- Strong with expensive unit strategies (maximize savings)
- Complements expansion strategies
- Pairs well with diverse production

### Counters
- Maps with few/no deltas
- Opponents claiming deltas first
- Concentrated delta positioning (easy to block)
- Early game aggression (before deltas claimed)

## Starting Resources

- **Gold**: £10
- **Units**:
  - 1 Field
  - 1 Sheep
  - 1 Worker (Miner)
- **Merchants**: 2
- **Shipping**: 0 (none, but benefits from getting it)

## Difficulty

**Complexity**: Intermediate
**Reason**: Requires map reading, delta identification, prioritization, spatial planning

## Victory Paths

1. **Delta Control**: Claim all valuable deltas, maximize savings
2. **Waterway Dominance**: Control river/loch territories strategically
3. **Economic Efficiency**: Use savings for rapid expansion, out-economy opponents

## Savings Calculation

**Per Delta Placement**:
- £3 saved (3-4 players)
- £2 saved (1-2 players)

**Multiple Deltas**:
- 5 deltas claimed = £15 saved (3-4 players)
- 8 deltas claimed = £24 saved (3-4 players)
- Equivalent to 3-4 free units

**Cumulative Advantage**:
By mid-game (Round 3):
- Marina with 6 delta placements: £18 saved
- Can place ~2-3 extra units with savings
- Significant territorial advantage

## Delta Identification

**Visual Indicators**:
- River (blue line) along hex edge
- Loch (blue hex) adjacent
- River flows toward loch

**Hex Requirements**:
```
[Grassland/Delta Hex] - (river edge) - [Loch Hex]
```

**Common Delta Patterns**:
- River mouth (1 hex at end of river)
- River fork (2+ hexes where river branches to loch)
- Estuary (wide river delta area)

## Comparison with Other Lords

**Marina vs Standard**:
| Placement | Standard | Marina (3-4p) | Savings |
|-----------|----------|---------------|---------|
| Sheep on £2 delta | £7 | £4 | £3 |
| Dairy on £5 delta | £11 | £8 | £3 |
| Miner on £4 delta | £10 | £7 | £3 |

**Marina vs Roderick**:
- Roderick: Front-loaded (early workers)
- Marina: Scaling (savings per delta)
- Both strong early-mid game

**Marina vs Bertram**:
- Bertram: Factory specialist
- Marina: Territory specialist
- Complementary (don't compete for same advantage)
