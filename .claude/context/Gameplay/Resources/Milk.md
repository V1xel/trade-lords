# Milk

## Overview

Milk is a basic good produced by Cows. Can be used directly or processed into Cheese for higher value.

## Properties

**Type**: Basic Good
**Produced By**: Cows
**Processing**: Optional (Cheese Dairy → Cheese)
**End Game Value**: 1 VP per Milk

## Production

### Production Phase
- Each Cow produces 1 Milk
- Automatic (no input needed)
- Milk added to player's stock

### Optional Processing
- Can process: Milk → Cheese Dairy → Cheese
- Or use Milk directly
- Flexible resource management

## Uses

### Direct Use
1. **Export Contracts**: Some contracts require Milk
2. **Market Trading**: Sell for gold
3. **Dame Elspeth Special**: Sell for flat £8 (no merchant)
4. **End Game**: 1 VP per Milk

### Processing to Cheese
- Cheese Dairy: 1 Milk → 1 Cheese
- Cheese worth 2 VP (vs 1 VP for Milk)
- Higher contract rewards
- Better value but requires factory investment

## Strategic Value

### Flexibility
- Can use directly OR process
- Adapt to situation
- Milk shortage: Use directly
- Excess Milk: Process to Cheese

### Dame Elspeth Specialty
- Guaranteed £8 sale price
- No market dependency
- No merchant needed
- Reliable income

## Game States

### Player Stock
- `milk: number` (count in stock)

### Per Production Phase
- Count Cow units
- Add that many Milk to stock

### Processing (optional)
- If have Cheese Dairy
- Convert Milk → Cheese

## Common Patterns

### Direct Milk Sales (Dame Elspeth)
- 3-4 Cows
- Produce 3-4 Milk per round
- Sell to Elspeth for £8 each
- £24-£32 per round income
- Simple, reliable

### Dairy Chain
- 2 Cows + 2 Cheese Dairies
- 2 Milk → 2 Cheese
- Higher value output
- For contracts/VPs

### Mixed Strategy
- 4 Cows + 2 Dairies
- 2 Milk → Cheese
- 2 Milk sold/used directly
- Balanced approach

## Economic Value

**Production Cost**:
- Cow: £6 + terrain
- Produces 1 Milk per round

**Milk Market Value**: ~£6-£8 (varies)

**Elspeth Guaranteed**: £8 flat

**Milk vs Cheese**:
- Milk: 1 VP, £6-£8 value
- Cheese: 2 VP, higher contract value
- Cheese requires Dairy investment

## Comparison

| Resource | Source | Processing | End VP | Special |
|----------|--------|------------|--------|---------|
| Wool | Sheep (£5) | None | 1 | - |
| Milk | Cow (£6) | Optional | 1 | Elspeth £8 |
| Cheese | Milk + Dairy | Required | 2 | - |

**Milk Position**:
- Mid-cost production (£6)
- Optional processing
- Elspeth specialty

## Strategy Decisions

### When to Sell Milk (Elspeth)
- Need gold immediately
- Early game income
- No Cheese Dairies yet
- Guaranteed £8 is good value

### When to Process to Cheese
- Have Cheese Dairies
- Want higher VPs (2 vs 1)
- Cheese contracts available
- Late game (VPs > gold)

### Milk vs Wool
**Milk**:
- More expensive (Cow £6 vs Sheep £5)
- Can process to Cheese (2 VP)
- Elspeth specialty (£8)

**Wool**:
- Cheaper (Sheep £5)
- No processing option
- Simpler

**Usually Milk > Wool** for flexibility

## Lord Synergies

### Dame Elspeth (Strong)
**Milk Specialist**:
- Starts with 2 Cows + 1 Dairy
- Can sell Milk for £8 (guaranteed)
- Dairy production focus

**Elspeth Strategy**:
- Early: Sell Milk for £8 (income)
- Mid: Build Dairies, some Cheese
- Late: Process to Cheese (VPs)

### Sir Bertram
- Cheap Cheese Dairies (discount)
- Good Milk → Cheese efficiency

## Market Dynamics

### Milk Price
- Base: ~£6
- Fluctuates with trading
- Elspeth bypasses market (£8 flat)

### Elspeth Impact
- Doesn't use market for Milk sales
- Keeps merchants free
- Stable income regardless of market

## Contracts

**Milk Contracts** (typical):
- "Deliver 3 Milk" → Reward
- "Deliver 2 Milk + 1 Cheese" → Higher reward
- Mix of Milk and processed goods

**Contract Decision**:
- If have Dairies: Process to Cheese first
- If no Dairies: Use Milk directly

## End Game Value

**Milk in Stock**:
- 1 VP per Milk
- 5 Milk = 5 VP

**Alternative**:
- Process to Cheese: 5 Milk → 5 Cheese = 10 VP
- **Double value!**

**Late Game Priority**:
- Process all Milk to Cheese if possible
- Only keep Milk if no Dairies

## Dame Elspeth Decision Matrix

**Sell Milk (£8)**:
- Pros: Immediate gold, no factory, simple
- Cons: 1 VP only, lower value

**Process to Cheese**:
- Pros: 2 VP, higher contracts
- Cons: Requires Dairy (£9), delayed

**Optimal**:
- Early: Sell for £8 (need gold)
- Late: Process to Cheese (need VPs)
