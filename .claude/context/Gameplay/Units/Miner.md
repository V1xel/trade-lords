# Miner

## Overview

Miner is a worker unit that generates the highest passive gold income. Placed on Mountain terrain.

## Properties

**Type**: Worker (Income Generator)
**Cost**: £6
**Terrain**: Mountain only
**Income**: £6 per Production Phase (£8 when upgraded)

## Placement

### Requirements
- Mountain terrain hex
- Adjacent to owned unit OR shipping range
- Pay £6 (unit) + terrain cost

### Examples
- Miner on £4 mountain = £10 total
- Miner on £5 mixed mountain/grassland = £11 total

## Production

### Production Phase Income
- Generates £6 gold
- Automatic (no input needed)
- Added to player's gold
- Highest base worker income

### Upgrade
- Can be upgraded
- Upgraded income: £8 per round
- Highest upgraded worker income
- Upgrade cost: ~£4 (game system dependent)

## Strategic Use

### Premium Passive Income
- Highest worker income (£6 base, £8 upgraded)
- No resource input needed
- Most efficient gold generation

### Economic Engine
- Multiple Miners = strong economy
- Supports any strategy
- Gold funds expansion

## Lord Synergies

### Baron Roderick (Very Strong)
- Starts with 3 workers (can be Miners)
- 3 Miners = £18 per round immediately
- Dominant early economy
- Scales to £24 upgraded

### Lord Caspian (Special Case)
- Workers can be Miners
- But Caspian Miners: £6 cost, £4 income (not £6!)
- Worse than standard Miner
- Usually prefer Fishermen instead

### Starting Resources
- **Sir Bertram**: Starts with 1 Miner
- **Lady Marina**: Starts with 1 Miner

## Comparison

| Worker | Cost | Terrain | Base Income | Upgraded | ROI |
|--------|------|---------|-------------|----------|-----|
| Woodcutter | £5 | Forest | £4 | £6 | 2 rounds |
| Miner | £6 | Mountain | £6 | £8 | <2 rounds |
| Fisherman* | £6 | Loch | £4 | TBD | 1.5 rounds |

*Caspian only

**Miner Advantages**:
- Highest income (£6 base, £8 upgraded)
- Best long-term value
- Priority worker

**Miner Disadvantages**:
- Most expensive (£6)
- Requires Mountain (limited terrain)
- High terrain cost (£3-£4)

## Game States

### Unit State
- Owner
- Location (hex)
- Type: Miner
- Upgraded: boolean

### Per Production Phase
- Generate £6 (base) or £8 (upgraded)
- Add to owner's gold

## Common Patterns

### Miner Focus (Roderick)
- 3-4 Miners
- £18-£24 per round (base)
- £24-£32 per round (upgraded)
- Economic dominance

### Mountain Control
- Claim all accessible mountains
- Place Miners
- Block opponents from mountains
- Secure income advantage

### Mixed Worker Strategy
- 2 Miners + 2 Woodcutters
- £12 + £8 = £20 per round
- Terrain diversity

## Economic Calculation

**Miner Investment**:
- £6 (Miner) + £4 (mountain) = £10 total
- Income: £6 per round
- Break-even: <2 rounds
- Best worker ROI

**Upgraded Miner**:
- Upgrade cost: ~£4
- New income: £8 per round (+£2)
- Pays for itself in 2 rounds
- £8 per round is exceptional

**Roderick 3 Miners**:
- Base: £18 per round
- Upgraded: £24 per round
- By Round 3: £54-£72 extra gold vs opponents
- Massive advantage

## Strategy Decisions

### When to Build Miners
- Mountains available (essential)
- Always high priority
- Best passive income
- Early game advantage

### Miner vs Woodcutter
**Always prefer Miner if mountain available**:
- £6 income vs £4 income
- Worth extra £1 cost
- Worth higher terrain cost

**Only choose Woodcutter if**:
- No mountains accessible
- Cannot afford £6 cost

### Miner vs Production Units
**Early Game**: Miners better
- Passive income funds expansion
- Simple economics
- Safe investment

**Late Game**: Production units better
- Resources → contracts → VPs
- Higher scoring potential
- Miners still valuable for income

## Upgrade Priority

**Highest Priority Upgrade**:
- Miners: £6 → £8 (+£2 per round)
- Better than Woodcutter upgrade (£4 → £6)
- Best ROI for workers

**Upgrade Order**:
1. Miners first (highest value)
2. Woodcutters second
3. Other upgrades

## Terrain Considerations

### Pure Mountain
- £3-£4 cost
- Miner only option
- Excellent value

### Mixed Mountain/Grassland
- £4-£5 cost
- Miner OR agricultural unit

**Decision**:
- **Miner**: £6 income per round
- **Cow**: Milk production (value ~£6-£8)
- **Field**: Grain production (requires processing)

**Usually prefer Miner**:
- Guaranteed £6 income
- No processing needed
- Simpler logistics

**Choose Agricultural If**:
- Desperately need production
- Have too many workers already
- Late game (VPs > gold)

## Mountain Scarcity

### Limited Mountains
- High competition
- First player advantage
- Mountain control = economic advantage
- Block opponents

### Mountain Priority
- Claim mountains early
- Before opponents
- Even if distant (use shipping)
- Worth investment

## Marina Mountain Delta

**Lady Marina on Mountain Delta**:
- Mountain terrain: £4
- Marina discount: -£3
- Effective cost: £1

**Miner on Delta (Marina)**:
- £6 (Miner) + £4 (mountain) - £3 (discount) = £7 total
- Income: £6 per round
- Break-even: ~1 round
- Exceptional value

**Marina Priority**:
- Mountain deltas are best deltas
- Claim immediately
- Miner income + discount = huge advantage

## Roderick Miner Dominance

**Baron Roderick Starting Miners**:
```
Round 1: Start with 3 Miners (£18 income)
Round 2: Earned £18
Round 3: Earned £36 total
Round 4: Earned £54 total
Round 5: Earned £72 total
```

By Round 3, Roderick has £36 extra gold:
- Can afford 3-4 extra units
- Massive territorial advantage
- Economic dominance

**Upgrade Path**:
- Round 2-3: Upgrade all Miners
- New income: £24 per round
- Compounds advantage

**Roderick is strongest early game lord** primarily due to Miner income
