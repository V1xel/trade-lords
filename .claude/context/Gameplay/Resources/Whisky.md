# Whisky

## Overview

Whisky is a premium processed good created from Grain via Distillery. Highest value grain processing option, especially for Master Godwyn.

## Properties

**Type**: Processed Good
**Created From**: Grain (via Distillery)
**End Game Value**: 2 VP per Whisky
**Special**: Godwyn bonuses (£3 + aging)

## Production

### Processing (Production Phase)
- Requires: 1 Grain in stock
- Process: Distillery converts 1 Grain → 1 Whisky
- Output: Whisky added to player's stock

### Godwyn Special
**Master Godwyn bonuses**:
- Gains £3 per Whisky produced
- Can age Whisky in cellar:
  - 1-year aged: +£7 when moved to stock
  - 2-year aged: +£15 when moved to stock

### Requirements
1. Field(s) producing Grain
2. Distillery building
3. Grain in stock to convert

## Uses

### Export Contracts
- Whisky contracts high value
- Premium processed good
- Better rewards than Bread

### Market Trading
- Higher market value than Bread
- Premium pricing
- Good gold generation

### Godwyn Aging
- Age for massive bonuses (£7-£15)
- Strategic timing
- Late game payoff

### End Game
- 2 VP per Whisky
- Same as other processed goods

## Strategic Value

### Premium Processor
- Highest value Grain option
- Godwyn synergy (core ability)
- Better than Bakery (standard)

### Godwyn Dominance
- £3 immediate bonus
- Aging: +£7 or +£15
- Total value: +£18 per aged Whisky!
- Economic engine

## Game States

### Player Stock
- `whisky: number` (count in stock)

### Godwyn Aging Cellar
- Slot 1: Whisky aging (1 year)
- Slot 2: Whisky aging (2 years)
- Ages each Production Phase

### Per Production Phase
- Check Grain availability
- Distilleries convert Grain → Whisky
- Godwyn gains £3 per Whisky
- Aging cellar advances (Godwyn)

## Common Patterns

### Standard Whisky Production
```
2 Fields → 2 Grain → 2 Distilleries → 2 Whisky per round
```

### Godwyn Whisky Engine
```
4 Fields → 4 Grain
3 Distilleries → 3 Whisky
Gain £9 (3 × £3)
Age 1-2 Whisky per round
Harvest aged Whisky: +£15
```

## Economic Value

**Full Chain Investment**:
- 1 Field: £6
- 1 Distillery: £9
- Total: £15 for 1 Whisky/round

**Whisky Market Value**: £8-£12 (premium)

**Godwyn Value** (2-year aged):
- £3 production bonus
- +£15 aging bonus
- Total: £18 extra per aged Whisky!

## Comparison

| Processor | Input | Output | Specialist | Bonus |
|-----------|-------|--------|------------|-------|
| Bakery | Grain | Bread | None | £0 |
| Distillery | Grain | Whisky | Godwyn | £3 + £7-£15 |
| Brewery | Grain | Beer | Oswald | £1-£2 (est) |

**Whisky Advantages**:
- Highest market value
- Godwyn massive bonuses
- Premium contracts

**Best Grain processor** (especially for Godwyn)

## Strategy Decisions

### When to Build Distilleries
- Always preferred over Bakery
- Playing as Godwyn (essential)
- Premium Grain processing
- Whisky contracts available

### Distillery Priority
**All lords**: Distillery > Bakery
**Godwyn**: Distillery is #1 priority

**Only skip Distillery if**:
- Playing Oswald (Brewery better)
- Bread-specific contracts
- Bertram discount makes Bakery very cheap

## Lord Synergies

### Master Godwyn (Core Ability)
**Whisky Specialist**:
- Starts with 2 Fields + 1 Distillery
- Gains £3 per Whisky
- Aging cellar (2 slots)
- **Whisky is Godwyn's strategy**

**Godwyn Optimal**:
- 4-6 Fields
- 3-4 Distilleries
- £9-£12 bonus per round
- Plus aged Whisky (£7-£15)
- Total: £15-£30+ per round!

### Sir Bertram
**Cheap Distilleries**:
- 1st: £3 (vs £9)
- 2nd: £2 (vs £9)
- 3rd: £2 (vs £9)
- Efficient Whisky production
- Good even without Godwyn bonuses

## Market Dynamics

### Whisky Price
- Premium processed good
- £8-£12 base (higher than Bread)
- High demand
- Good trading value

### Godwyn Impact
- Godwyn bypasses market for income
- Gets £3 + aging regardless
- Market for others

## Contracts

**Whisky Contracts** (premium):
- "Deliver 3 Whisky" → High reward
- "Deliver 2 Whisky + 1 Bread" → Premium
- Better rewards than Bread contracts

**Whisky highly valued in contracts**

## Godwyn Aging Strategy

### Aging Cellar Mechanics
**Cellar has 2 slots**:
- Slot 1: 1-year aged Whisky
- Slot 2: 2-year aged Whisky

**Each Production Phase**:
- Slot 2 → Slot 1 (ages 1 year)
- Empty Slot 2
- Can add fresh Whisky to Slot 1

### Aging Decision

**Fresh Whisky**:
- Base value + £3
- Immediate use

**1-Year Aged** (Slot 1):
- Base value + £3 + £7 = +£10
- Good value

**2-Year Aged** (Slot 2):
- Base value + £3 + £15 = +£18
- Maximum value!

### When to Age

**Age if**:
- Playing long game
- Don't need Whisky immediately
- Cellar has space
- Want maximum gold

**Sell fresh if**:
- Need Whisky for contract now
- Need immediate gold
- Cellar full
- Late game (no time to age)

## Godwyn Aging Timing

**Example Aging Cycle**:
```
Round 1: Produce 2 Whisky, age 1 (Slot 1), keep 1
Round 2: Produce 2 Whisky, Slot 1→Slot 2, age 1 fresh (Slot 1), keep 1
Round 3: Produce 2 Whisky, harvest Slot 2 (+£15!), Slot 1→Slot 2, age 1, keep 1
Round 4: Harvest Slot 2 (+£15), continue cycle
```

**Steady state**: +£15 every round from aged Whisky!

## Bertram Whisky Strategy

**Sir Bertram + Distilleries**:
- 3 Distilleries: £7 total (vs £27)
- Savings: £20
- Can build many cheap

**Bertram Whisky Focus**:
- 4-6 Fields
- 3-4 Distilleries (cheap!)
- No Godwyn bonuses
- But still premium Grain processing
- High Whisky output for contracts

## Whisky vs Bread

Both worth 2 VP end game, but:

**Whisky**:
- Higher market value (£8-£12 vs £6-£8)
- Better contracts
- Godwyn bonuses (huge)

**Bread**:
- Same end VP
- Lower market value
- No bonuses

**Always prefer Whisky over Bread**
(unless Bread-specific contract)

## Late Game Whisky

**Final Rounds (Godwyn)**:
- Cash out aged Whisky (+£15 each)
- Process remaining Grain → Whisky
- Whisky worth 2 VP end game
- Massive gold for final purchases

**Final Rounds (others)**:
- Process Grain → Whisky
- 2 VP per Whisky
- Better than holding Grain (1 VP)

## Whisky Contracts Focus

**High-value strategy**:
- Build 4+ Distilleries
- Produce 4+ Whisky per round
- Target Whisky contracts (premium rewards)
- Dominate processed goods market

**Whisky contracts typically**:
- Higher rewards than Bread
- Premium VP bonuses
- Worth pursuing
