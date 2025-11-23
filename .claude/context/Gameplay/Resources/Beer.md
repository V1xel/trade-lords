# Beer

## Overview

Beer is a unique processed good created from Grain via Brewery. Exclusive to Brewmaster Oswald with special bonuses.

## Properties

**Type**: Processed Good (Unique)
**Created From**: Grain (via Brewery)
**Availability**: Brewmaster Oswald only (or all lords with Brewery, TBD)
**End Game Value**: 2 VP per Beer
**Special**: Oswald bonuses (production bonus/market premium/contracts)

## Production

### Processing (Production Phase)
- Requires: 1 Grain in stock
- Process: Brewery converts 1 Grain → 1 Beer
- Output: Beer added to player's stock

### Oswald Special
**Brewmaster Oswald bonuses** (one or more):
- **Option A**: Gains £1-£2 per Beer produced
- **Option B**: Beer sells for premium market price
- **Option C**: Access to Beer-only contracts
- **Option D**: Combination of above

### Requirements
1. Field(s) producing Grain
2. Brewery building (Oswald only)
3. Grain in stock to convert

## Uses

### Export Contracts
- Beer contracts (possibly Oswald-exclusive)
- Premium rewards
- Unique resource advantage

### Market Trading
- May have premium pricing
- Specialty good value

### End Game
- 2 VP per Beer
- Same as other processed goods

## Strategic Value

### Oswald's Unique Option
- Only Oswald can make Beer
- No competition for Beer niche
- Unique resource control

### Comparable to Whisky
- Similar role to Godwyn's Whisky
- Special production bonuses
- Premium grain processing

## Game States

### Player Stock
- `beer: number` (count in stock)

### Per Production Phase
- Check Grain availability
- Breweries convert Grain → Beer
- Oswald bonuses triggered

## Common Patterns

### Oswald Beer Engine
```
4 Fields → 4 Grain
3 Breweries → 3 Beer
Gain £3-£6 bonus (if Option A)
Beer contracts available
```

### Mixed Oswald Strategy
```
3 Fields → 3 Grain
2 Breweries → 2 Beer
1 Distillery → 1 Whisky
Diversified processing
```

## Economic Value

**Full Chain Investment**:
- 1 Field: £6
- 1 Brewery: £9
- Total: £15 for 1 Beer/round

**Beer Bonuses** (estimated):
- Production: £1-£2 per Beer (if Option A)
- Market premium: £2-£3 higher (if Option B)
- Contracts: Exclusive access (if Option C)

## Comparison

| Processor | Output | Specialist | Bonus Estimate |
|-----------|--------|------------|----------------|
| Bakery | Bread | None | £0 |
| Distillery | Whisky | Godwyn | £3 + £7-£15 aging |
| Brewery | Beer | Oswald | £1-£2 (or other) |

**Beer Position**:
- Oswald's Whisky equivalent
- Unique resource
- Special bonuses

## Strategy Decisions (Oswald)

### When to Build Breweries
- Playing as Oswald (core ability)
- Always high priority
- Unique advantage
- Beer bonuses valuable

### Brewery vs Distillery (Oswald)
**Brewery**:
- Oswald bonuses
- Unique Beer resource
- Exclusive contracts (maybe)

**Distillery**:
- Available to all
- No Oswald bonuses
- Standard Whisky

**Oswald should prefer Brewery** for unique advantage

### How Many Breweries
- Match Field count (1:1)
- Or surplus Fields for flexibility
- 3-4 Breweries typical

## Lord Synergies

### Brewmaster Oswald (Exclusive)
**Beer Specialist**:
- Starts with 2 Fields + 1 Brewery
- Beer production bonuses
- **Brewery/Beer is core strategy**

**Oswald Optimal**:
- 4-6 Fields
- 3-4 Breweries
- High Beer production
- Maximize Beer bonuses
- Pursue Beer contracts

### Sir Bertram
**Hypothetical synergy** (can't occur):
- Only one lord per game
- Either Oswald OR Bertram
- If Oswald has Breweries, Bertram discount would apply
- But impossible in actual game

## Market Dynamics

### Beer Price (if Option B)
- Premium over Bread
- Specialty good
- Limited supply (Oswald only)
- Higher market value

### Beer Scarcity
- Only Oswald produces Beer
- No competition
- Can monopolize Beer market
- Strategic control

## Contracts

### Beer Contracts (if Option C)
**Oswald-Exclusive Contracts**:
- "Deliver 3 Beer" → Premium reward
- Only Oswald can fulfill
- Guaranteed contract access
- Strategic advantage

**Mixed Contracts**:
- "Deliver 2 Beer + 2 Bread" → High reward
- Oswald has unique angle

## Beer Implementation Options

### Option A: Production Bonus
**Mechanic**: Gain £1-£2 per Beer produced
**Similar to**: Godwyn's £3 per Whisky
**Value**: Simpler than aging system

### Option B: Market Premium
**Mechanic**: Beer market price higher/stable
**Similar to**: Premium good value
**Value**: Reliable income

### Option C: Exclusive Contracts
**Mechanic**: Beer contracts only for Oswald
**Similar to**: Unique scoring path
**Value**: Guaranteed contract access

### Option D: Combination (Recommended)
**Mechanic**: Small production bonus (£1-£2) + occasional Beer contracts
**Balance**: Comparable to other lords
**Value**: Multiple benefits, not overpowered

## Oswald Beer Strategy

**Core Build**:
- 4-6 Fields (Grain engine)
- 3-4 Breweries (Beer production)
- Maximize Beer output
- Pursue Beer contracts (if exclusive)

**Income** (Option A):
- 4 Beer per round
- £4-£8 bonus per round
- Comparable to Godwyn (lower ceiling, simpler)

## Beer vs Whisky vs Bread

All worth 2 VP end game:

**Beer**:
- Oswald only
- Special bonuses
- Unique

**Whisky**:
- All lords (prefer for Godwyn)
- Godwyn bonuses huge
- Premium

**Bread**:
- All lords
- No bonuses
- Standard

**For Oswald**: Beer > Whisky > Bread
**For Godwyn**: Whisky > Beer (can't make) / Bread
**For others**: Whisky > Bread, Beer N/A

## Late Game Beer

**Final Rounds (Oswald)**:
- Process all Grain → Beer
- 2 VP per Beer
- Beer bonuses maximize gold
- Use gold for final purchases/contracts

## Beer Balance Considerations

**Beer bonuses should**:
- Match other lords' power level
- Provide unique flavor
- Not exceed Godwyn's Whisky
- Not be underwhelming

**Recommended Balance**:
- Production bonus: £1-£2 (less than Godwyn's £3)
- No aging (simpler than Godwyn)
- Occasional Beer contracts (some exclusivity)
- Total value comparable to other lords

## Beer Uniqueness

**Beer's Role**:
- Makes Oswald distinct
- Alternative to Whisky specialist (Godwyn)
- Simpler than aging mechanics
- Themed around brewing/taverns

**Strategic Niche**:
- Grain processor (like Godwyn)
- But different bonuses
- Unique resource control
- Exclusive contracts

## Oswald Starting Advantage

**Turn 1 (Oswald)**:
- 2 Fields + 1 Brewery + 1 Grain (start)
- Production: 2 Grain total
- Convert 1 Grain → 1 Beer
- Get production bonus
- Early engine start

**Expansion Path**:
- Build more Fields
- Build more Breweries
- Scale Beer production
- Dominate Beer niche
