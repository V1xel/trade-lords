# Grain

## Overview

Grain is a basic good produced by Fields. Must be processed into Bread, Whisky, or Beer to be valuable.

## Properties

**Type**: Basic Good
**Produced By**: Fields
**Processing**: Required (Bakery/Distillery/Brewery)
**End Game Value**: 1 VP per Grain (low - should process)

## Production

### Production Phase
- Each Field produces 1 Grain
- Automatic (no input needed)
- Grain added to player's stock

### Processing Required
Grain has limited direct value - must process:
- **Bakery**: 1 Grain → 1 Bread
- **Distillery**: 1 Grain → 1 Whisky
- **Brewery**: 1 Grain → 1 Beer (Oswald)

## Uses

### Processing (Primary Use)
1. **Bread Production**: Standard processed good
2. **Whisky Production**: Premium, Godwyn bonuses
3. **Beer Production**: Oswald specialty

### Direct Use (Rare)
- Grain contracts (uncommon)
- Market trading (low value)
- End game (1 VP - poor value)

**Generally: Always process Grain**

## Strategic Value

### Versatility
- 3 processing options (Bread/Whisky/Beer)
- Flexible allocation
- Adapt to contracts/market
- Strategic depth

### Requires Investment
- Fields cheap (£4)
- But must build processors (£6 each)
- Total investment higher
- Delayed payoff

## Game States

### Player Stock
- `grain: number` (count in stock)

### Per Production Phase
- Count Field units
- Add that many Grain to stock

### Processing Phase
- Allocate Grain to processors
- Bakeries convert → Bread
- Distilleries convert → Whisky
- Breweries convert → Beer

## Common Patterns

### Grain Engine (Godwyn/Oswald)
- 4-6 Fields
- 3-4 Distilleries/Breweries
- High Grain production
- Specialized processing

### Mixed Processing
- 3 Fields
- 1 Bakery + 1 Distillery + 1 Brewery
- 3 Grain allocated flexibly
- Respond to contracts

### Balanced Economy
- 2 Fields + 2 Cows + 2 Sheep
- Diversified resources
- 1-2 processors for Grain

## Economic Value

**Production Cost**:
- Field: £4 + terrain (cheapest producer)
- Produces 1 Grain per round

**Grain Direct Value**: ~£3-£4 (low)

**Processed Value**:
- Bread: £6-£8
- Whisky: £8-£10+
- Beer: £6-£8+

**Must process for value!**

## Comparison

| Resource | Unit Cost | Processing | Options | End VP |
|----------|-----------|------------|---------|--------|
| Wool | £5 | None | 1 | 1 |
| Milk | £6 | Optional | 2 | 1 |
| Grain | £4 | Required | 3 | 1 (or 2 if processed) |

**Grain Advantages**:
- Cheapest producer (£4)
- Most processing options (3)
- Highest versatility

**Grain Disadvantages**:
- MUST process (Grain alone poor)
- Requires factory investment
- Complex logistics

## Strategy Decisions

### Which Processor?

**Bakery (Bread)**:
- Standard option
- Moderate value
- No special bonuses

**Distillery (Whisky)**:
- Higher value
- Godwyn bonus (£3 + aging)
- Premium choice

**Brewery (Beer)**:
- Oswald only
- Special bonuses
- Unique

**Priority**: Distillery > Brewery > Bakery

### Grain Allocation

**Example: 4 Grain, 1 Bakery, 1 Distillery**:
- Option A: 2→Bread, 2→Whisky
- Option B: 1→Bread, 3→Whisky (if Godwyn)
- Option C: 4→Bread (if Bread contracts)

**Flexibility is Grain's strength**

### How Much Grain?

**Match Processors**:
- 3 Fields + 3 processors = efficient
- 4 Fields + 2 processors = surplus (flexible)
- 2 Fields + 4 processors = bottleneck (wasteful)

**Ideal: Slightly more Fields than processors**

## Lord Synergies

### Master Godwyn (Very Strong)
**Grain Specialist**:
- Starts with 2 Fields + 1 Distillery
- Gains £3 per Whisky
- Aging bonuses (£7-£15)
- **Grain → Whisky is core strategy**

### Brewmaster Oswald (Strong)
**Grain Specialist**:
- Starts with 2 Fields + 1 Brewery
- Beer production bonuses
- **Grain → Beer is core strategy**

### Sir Bertram
- Cheap processors (all £3-£5 discount)
- Can build multiple cheap factories
- Efficient Grain processing

## Market Dynamics

### Grain Price
- Low base price (£3-£4)
- Less valuable than processed goods
- Low trading volume (most process internally)

### Processed Goods Prices
- Bread: £6-£8
- Whisky: £8-£12
- Beer: £7-£10

**Processing adds significant value**

## Contracts

**Grain Contracts** (rare):
- "Deliver 4 Grain" → Low reward
- Uncommon (most want processed)

**Processed Contracts** (common):
- "Deliver 3 Whisky" → High reward
- "Deliver 2 Bread + 2 Cheese" → High reward
- **Process Grain for better contracts**

## End Game Value

**Grain in Stock**: 1 VP per Grain (poor)

**Processed in Stock**:
- Bread/Whisky/Beer: 2 VP each
- **Double value!**

**End Game Priority**:
- Process ALL Grain before game ends
- Don't hold raw Grain
- Bread/Whisky/Beer worth 2× VPs

## Processing Decision Matrix

| Situation | Best Processor |
|-----------|----------------|
| Playing Godwyn | Distillery (£3 bonus + aging) |
| Playing Oswald | Brewery (Beer bonuses) |
| Playing Bertram | Any (all cheap) |
| Standard lord | Distillery (higher value) |
| Bread contract | Bakery (specific need) |
| Beer contract (Oswald) | Brewery |
| Late game VPs | Any (all worth 2 VP) |

## Grain Surplus Strategy

**Over-produce Grain**:
- 6 Fields + 3 processors
- 6 Grain produced, 3 processed
- 3 Grain accumulates

**Benefits**:
- Flexibility (allocate as needed)
- Respond to contracts
- Build more processors later

**Downside**:
- Grain in stock low value (1 VP)
- Should process eventually

## Godwyn Grain Focus

**Optimal Godwyn**:
- 4-6 Fields (Grain production)
- 3-4 Distilleries (process to Whisky)
- Aging cellar active
- £12-£18 bonus gold per round
- Plus aged Whisky (+£7-£15)

**Grain is fuel for Godwyn's engine**
