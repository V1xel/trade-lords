# Cheese

## Overview

Cheese is a processed good created from Milk via Cheese Dairy. Higher value than Milk with better contract rewards and VPs.

## Properties

**Type**: Processed Good
**Created From**: Milk (via Cheese Dairy)
**End Game Value**: 2 VP per Cheese

## Production

### Processing (Production Phase)
- Requires: 1 Milk in stock
- Process: Cheese Dairy converts 1 Milk → 1 Cheese
- Output: Cheese added to player's stock

### Requirements
1. Cow(s) producing Milk
2. Cheese Dairy building
3. Milk in stock to convert

## Uses

### Export Contracts
- Cheese contracts offer higher rewards
- Processed goods worth more than basic
- Premium contract requirements

### Market Trading
- Sell for higher gold than Milk
- Buy if needed for contracts (expensive)

### End Game
- 2 VP per Cheese (vs 1 VP for Milk)
- Double value!

## Strategic Value

### Higher Value
- 2 VP vs 1 VP (Milk)
- Better contract rewards
- Premium processed good

### Investment Required
- Need Cow (£6) + Cheese Dairy (£6)
- Total: ~£15-£18 investment
- Delayed payoff
- Multi-round ROI

## Game States

### Player Stock
- `cheese: number` (count in stock)

### Per Production Phase
- Check Milk availability
- Cheese Dairies convert Milk → Cheese
- Add Cheese to stock

## Common Patterns

### Cheese Production Chain
```
2 Cows → 2 Milk → 2 Dairies → 2 Cheese per round
```

### Mixed Dairy Strategy
```
4 Cows → 4 Milk
2 Dairies → 2 Cheese
2 Milk sold/used directly
```

## Economic Value

**Full Chain Investment**:
- 1 Cow: £8
- 1 Cheese Dairy: £9
- Total: £17 for 1 Cheese/round

**Cheese Contract Value**: High (processed good)

**Cheese End Value**: 2 VP

**vs Milk**:
- Milk: 1 VP, simpler
- Cheese: 2 VP, requires Dairy
- Cheese better if can afford investment

## Comparison

| Good | Source | End VP | Contract Value |
|------|--------|--------|----------------|
| Milk | Cow | 1 | Standard |
| Cheese | Milk + Dairy | 2 | High |
| Bread | Grain + Bakery | 2 | High |
| Whisky | Grain + Distillery | 2 | Premium |

**Cheese Position**:
- Standard processed good
- 2 VP (same as Bread/Whisky)
- Dairy chain specialty

## Strategy Decisions

### When to Produce Cheese
- Have Cows producing Milk
- Can afford Cheese Dairies
- Want higher VPs
- Cheese contracts available

### Cheese vs Direct Milk (Dame Elspeth)

**Sell Milk (£8)**:
- Immediate gold
- 1 VP end value
- No Dairy needed

**Process to Cheese**:
- Higher VPs (2 vs 1)
- Better contracts
- Requires Dairy investment

**Optimal (Elspeth)**:
- Early: Sell Milk (need gold)
- Mid: Build Dairies
- Late: Full Cheese production (VPs)

## Lord Synergies

### Sir Bertram (Strong)
**Cheap Cheese Dairies**:
- 1st Dairy: £3 (vs £9)
- 2nd Dairy: £2 (vs £9)
- 3rd Dairy: £2 (vs £9)
- Can build many cheap Dairies
- Efficient Cheese production

### Dame Elspeth (Moderate)
**Dairy Specialist**:
- Starts with 2 Cows + 1 Dairy
- Can sell Milk OR process to Cheese
- Flexible strategy
- Cheese good for late game VPs

## Market Dynamics

### Cheese Price
- Higher than Milk
- Fluctuates with trading
- Premium processed good value

### Supply
- Less Cheese than Milk (requires Dairies)
- Scarcity increases value
- Strategic production

## Contracts

**Cheese Contracts** (common):
- "Deliver 2 Cheese" → High reward
- "Deliver 1 Cheese + 2 Bread" → Premium
- Mix of processed goods

**Cheese Value**: High in contracts
- Processed goods preferred
- Better rewards than basic goods

## End Game Value

**Cheese Worth 2 VP**:
- 5 Cheese = 10 VP
- vs 5 Milk = 5 VP
- **Double value!**

**Conversion Priority**:
- Late game: Convert ALL Milk to Cheese
- Maximize VPs
- 2 VP > 1 VP

## Dairy Chain Efficiency

### 1:1 Ratio (Optimal)
```
2 Cows + 2 Dairies
→ 2 Milk produced
→ 2 Milk converted to Cheese
→ 2 Cheese per round
```
Efficient, no waste

### Surplus Cows
```
4 Cows + 2 Dairies
→ 4 Milk produced
→ 2 converted to Cheese
→ 2 Milk remain (sell or stockpile)
```
Flexible, can sell extra Milk

### Surplus Dairies
```
2 Cows + 4 Dairies
→ 2 Milk produced
→ Only 2 Dairies used
→ 2 Dairies wasted
```
Inefficient, over-investment

## Sir Bertram Cheese Strategy

**Bertram Advantage**:
- Cheap Dairies (£2-£3 each)
- Can build many
- Cheese production focus

**Strategy**:
- Build 4-6 Cows
- Build 4-6 Cheese Dairies (cheap!)
- High Cheese output
- Cheese contracts + VPs

**Investment** (Bertram 3 Dairies):
- Standard: £27 (3 × £9)
- Bertram: £7 (£3 + £2 + £2)
- **Savings: £20!**

## Cheese vs Bread vs Whisky

All processed goods worth 2 VP, but:

**Cheese**:
- From Milk (Cow £6)
- Requires Cheese Dairy
- Moderate availability

**Bread**:
- From Grain (Field £4)
- Requires Bakery
- Standard option

**Whisky**:
- From Grain (Field £4)
- Requires Distillery
- Godwyn bonuses (premium)

**Generally**: Whisky ≥ Cheese > Bread
(Whisky best if Godwyn, otherwise similar)

## Late Game Cheese Focus

**Rounds 4-5** (end game approaching):
- Stop selling Milk
- Process ALL Milk to Cheese
- Accumulate Cheese for 2 VP each
- Maximize end-game VPs

**Example**:
- Have 6 Milk in stock
- Build 3 Cheese Dairies (if don't have)
- Convert 6 Milk → 6 Cheese
- 12 VP (vs 6 VP if kept as Milk)
