# Woodcutter

## Overview

Woodcutter is a worker unit that generates passive gold income. Placed on Forest terrain.

## Properties

**Type**: Worker (Income Generator)
**Cost**: £5
**Terrain**: Forest only
**Income**: £4 per Production Phase (£6 when upgraded)

## Placement

### Requirements
- Forest terrain hex
- Adjacent to owned unit OR shipping range
- Pay £5 (unit) + terrain cost

### Examples
- Woodcutter on £3 forest = £8 total
- Woodcutter on £4 mixed forest/grassland = £9 total

## Production

### Production Phase Income
- Generates £4 gold
- Automatic (no input needed)
- Added to player's gold

### Upgrade
- Can be upgraded
- Upgraded income: £6 per round
- Upgrade cost: ~£4 (game system dependent)

## Strategic Use

### Passive Income
- No resource input required
- Simple economy
- Reliable gold generation

### Early Game Economy
- Provides steady income
- Supports expansion
- Funds unit purchases

## Lord Synergies

### Baron Roderick (Strong)
- Starts with 3 workers (can be Woodcutters)
- 3 Woodcutters = £12 per round
- Or mix Woodcutters + Miners

### Lord Caspian (Moderate)
- Workers can be Woodcutters
- All Caspian workers: £6 cost, £4 income
- Woodcutter one option among three

### Starting Resources
- **Lord Aldric**: Starts with 1 Worker (can be Woodcutter)

## Comparison

| Worker | Cost | Terrain | Base Income | Upgraded Income |
|--------|------|---------|-------------|-----------------|
| Woodcutter | £5 | Forest | £4 | £6 |
| Miner | £6 | Mountain | £6 | £8 |
| Fisherman* | £6 | Loch | £4 | TBD |

*Caspian only

**Woodcutter Position**:
- Mid-tier income (£4 < £6 Miner)
- Cheaper than Miner (£5 vs £6)
- Easier terrain (Forest more common than Mountain)

## Game States

### Unit State
- Owner
- Location (hex)
- Type: Woodcutter
- Upgraded: boolean

### Per Production Phase
- Generate £4 (base) or £6 (upgraded)
- Add to owner's gold
- No other effects

## Common Patterns

### Worker Income Focus
- 3-4 Woodcutters
- £12-£16 per round (base)
- £18-£24 per round (upgraded)
- Passive income engine

### Mixed Workers
- 2 Woodcutters + 2 Miners
- £8 + £12 = £20 per round (base)
- Diverse terrain coverage

### Supplement Strategy
- 1-2 Woodcutters alongside production
- Extra income supports expansion
- Low maintenance

## Economic Calculation

**Woodcutter Investment**:
- £5 (Woodcutter) + £3 (forest) = £8 total
- Income: £4 per round
- Break-even: 2 rounds
- Rounds 3+: Profit

**Upgraded Woodcutter**:
- Upgrade cost: ~£4
- New income: £6 per round (+£2)
- Upgrade pays for itself in 2 rounds

**Comparison to Miner**:
- Miner: £6 unit + £4 terrain = £10 total, £6 income
- Woodcutter: £5 unit + £3 terrain = £8 total, £4 income
- Miner: Better income (£6 vs £4)
- Woodcutter: Cheaper (£8 vs £10)

## Strategy Decisions

### When to Build Woodcutters
- Forest available
- Need passive income
- Early game economy
- Simpler than production chains

### Woodcutter vs Miner
**Choose Miner If**:
- Mountain available
- Want max income (£6 > £4)
- Have extra £2

**Choose Woodcutter If**:
- Only forest available
- Saving gold (£5 < £6)
- Forest terrain cheaper

### Woodcutter vs Production Units
**Woodcutter (£4 income)**:
- Guaranteed gold
- No resource management
- Simple

**Production Units** (Sheep/Cow/Field):
- Produce resources
- Resources → contracts/VPs
- More complex
- Higher value potential

**Usually production > workers** late game

## Upgrade Priority

**Upgrade Value**:
- Cost: ~£4
- Benefit: +£2 per round
- Payoff: 2 rounds

**Priority**:
- Low priority (Miner upgrades better: +£2 from £6 base)
- Upgrade if excess gold
- Focus on Miners first

## Terrain Considerations

### Pure Forest
- £2-£3 cost
- Woodcutter only option
- Good value

### Mixed Forest/Grassland
- £3-£4 cost
- Can place Woodcutter OR agricultural unit
- Decision: Income vs production

**Usually prefer production** on mixed terrain
**Use Woodcutter on pure forest**

## Roderick Woodcutter Strategy

**Baron Roderick Start**:
- 3 Workers (can be all Woodcutters)
- 3 Woodcutters = £12 per round
- Cheaper than Miners (£5 vs £6)
- But less income (£12 vs £18)

**Roderick Decision**:
- **All Miners**: Max income (£18), requires 3 mountains
- **All Woodcutters**: Good income (£12), easier terrain
- **Mixed**: 2 Miners + 1 Woodcutter (£16), balanced

**Usually prefer Miners** if mountains available

## Caspian Woodcutter

**Lord Caspian Workers**:
- All workers cost £6, produce £4
- Woodcutter: £6 (vs standard £5)
- More expensive!

**Caspian Woodcutter**:
- £6 unit + £3 terrain = £9 total
- Income: £4 per round
- Worse than standard Woodcutter (£8 total)

**Caspian should prefer**:
- Miners if mountains available (same £6 cost, £4 income)
- Fishermen if lochs available (£6 cost, £4 income, no terrain cost)
- Woodcutter only if forest is only option
