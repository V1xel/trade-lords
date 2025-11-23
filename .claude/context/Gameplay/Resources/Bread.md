# Bread

## Overview

Bread is a processed good created from Grain via Bakery. Standard grain processing option.

## Properties

**Type**: Processed Good
**Created From**: Grain (via Bakery)
**End Game Value**: 2 VP per Bread

## Production

### Processing (Production Phase)
- Requires: 1 Grain in stock
- Process: Bakery converts 1 Grain → 1 Bread
- Output: Bread added to player's stock

### Requirements
1. Field(s) producing Grain
2. Bakery building
3. Grain in stock to convert

## Uses

### Export Contracts
- Bread contracts common
- Processed good value
- Standard rewards

### Market Trading
- Sell for gold
- Higher value than Grain

### End Game
- 2 VP per Bread
- Same as other processed goods

## Strategic Value

### Standard Processor
- Default Grain processing option
- No special bonuses (unlike Whisky/Beer)
- Reliable, moderate value

### Lower Priority
- Distillery (Whisky) usually better
- Brewery (Beer) better for Oswald
- Bakery is fallback option

## Game States

### Player Stock
- `bread: number` (count in stock)

### Per Production Phase
- Check Grain availability
- Bakeries convert Grain → Bread
- Add Bread to stock

## Common Patterns

### Bread Production
```
2 Fields → 2 Grain → 2 Bakeries → 2 Bread per round
```

### Mixed Grain Processing
```
4 Fields → 4 Grain
1 Bakery → 1 Bread
1 Distillery → 1 Whisky
2 Grain stockpiled
```

## Economic Value

**Full Chain Investment**:
- 1 Field: £6
- 1 Bakery: £9
- Total: £15 for 1 Bread/round

**Bread Contract Value**: Standard processed good

**Bread End Value**: 2 VP

## Comparison

| Processor | Input | Output | Special Bonus | End VP |
|-----------|-------|--------|---------------|--------|
| Bakery | Grain | Bread | None | 2 |
| Distillery | Grain | Whisky | Godwyn £3 + aging | 2 |
| Brewery | Grain | Beer | Oswald bonuses | 2 |

**Bread Position**:
- Standard option
- No specialist
- Moderate value
- Safe choice

## Strategy Decisions

### When to Build Bakeries
- Bread contracts available
- No Distillery access yet
- Playing Bertram (cheap factories)
- Need processed Grain

### Bakery vs Distillery

**Bakery**:
- Standard value
- No bonuses
- Available to all

**Distillery**:
- Same end VP (2)
- Godwyn bonuses (£3 + aging)
- Higher market value

**Usually prefer Distillery** unless:
- Bertram discount makes Bakery cheaper
- Bread-specific contracts
- Distillery not available

## Lord Synergies

### Sir Bertram (Strong)
**Cheap Bakeries**:
- 1st Bakery: £3 (vs £9)
- 2nd Bakery: £2 (vs £9)
- 3rd Bakery: £2 (vs £9)
- Can build many cheap
- Bread production viable

**Bertram Strategy**:
- Build 3-4 cheap Bakeries
- 4 Fields + 3 Bakeries
- 3-4 Bread per round
- Efficient with discount

### No Special Bonuses
- No lord specializes in Bread
- Universal option
- No unique mechanics

## Market Dynamics

### Bread Price
- Moderate (higher than Grain)
- Processed good value
- Standard volatility

### Comparison
- Bread: £6-£8
- Whisky: £8-£12 (higher)
- Beer: £7-£10

**Whisky usually higher market value**

## Contracts

**Bread Contracts** (common):
- "Deliver 3 Bread" → Reward
- "Deliver 2 Bread + 2 Cheese" → Higher reward
- Standard processed good contracts

**Bread Value**: Standard in contracts
- Not premium (like Whisky)
- Not unique (like Beer)
- Reliable option

## End Game Value

**Bread Worth 2 VP**:
- 5 Bread = 10 VP
- Same as Whisky/Cheese/Beer

**No end-game advantage over other processed goods**

## Grain Allocation Priority

**If have multiple processors**:
1. Brewery (if Oswald, unique bonuses)
2. Distillery (higher value, Godwyn bonus)
3. Bakery (standard fallback)

**Bakery is lowest priority for Grain**

**Exception**: Bread-specific contracts make Bakery priority

## Bread vs Cheese vs Whisky

All worth 2 VP, differences:

**Bread**:
- From Grain (Field £4)
- Standard processor (Bakery)
- No bonuses

**Cheese**:
- From Milk (Cow £6)
- Bertram specialty
- Elspeth synergy

**Whisky**:
- From Grain (Field £4)
- Godwyn specialty (£3 + aging)
- Premium option

**Ranking**: Whisky > Cheese ≥ Bread
(Whisky best, Bread is fallback)

## Sir Bertram Bread Focus

**Why Bertram + Bread works**:
- Cheap Bakeries (£2-£3 vs £9)
- Can build many
- Bread production at low cost

**Investment Comparison**:
- Standard: 3 Bakeries = £27
- Bertram: 3 Bakeries = £7
- **Savings: £20**

**Bertram Bread Strategy**:
- 4-6 Fields (Grain)
- 3-4 Bakeries (cheap!)
- High Bread output
- Bread contracts + VPs

## When Bread is Best Option

1. **Playing Bertram**: Cheap Bakeries
2. **Bread Contracts**: Specific requirement
3. **No Godwyn in game**: Whisky less valuable
4. **Oswald not playing**: No Beer option
5. **Early game**: Bakery available, Distillery not yet

**Otherwise prefer Distillery/Whisky**

## Late Game Bread Management

**Final Rounds**:
- Process ALL Grain to Bread (or Whisky/Beer)
- Don't hold raw Grain (1 VP)
- Bread worth 2 VP (double value)
- Any processed good better than Grain

**Bread is acceptable end-game**:
- 2 VP same as Whisky/Cheese
- No disadvantage in final scoring
