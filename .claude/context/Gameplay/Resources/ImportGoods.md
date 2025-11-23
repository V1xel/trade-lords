# Import Goods

## Overview

Import Goods are special resources obtained as rewards from certain Export Contracts. Worth high victory points but cannot be produced directly.

## Import Good Types

1. **Cotton**
2. **Tobacco**
3. **Sugar Cane**
4. **Hops**

## Properties

**Type**: Import Goods (Special)
**Produced By**: Cannot be produced (contract rewards only)
**End Game Value**: 3-5 VP each (varies by type)
**Rarity**: Limited availability

## Acquisition

### Export Contract Rewards
- Certain contracts provide Import Goods as rewards
- Instead of or in addition to gold/upgrades
- One-time rewards

**Example Contract**:
- "Deliver 3 Whisky + 2 Cheese"
- Reward: £20 + 2 Cotton + 4 VP

### Cannot Produce
- No production units make Import Goods
- No processing buildings create them
- Only source: Contract rewards

### Cannot Trade (TBD)
- Likely cannot buy/sell on market
- Exclusive to contract rewards
- Accumulate for VPs

## Uses

### End Game Victory Points
**Primary use**:
- Cotton: 3-5 VP each
- Tobacco: 3-5 VP each
- Sugar Cane: 3-5 VP each
- Hops: 3-5 VP each

**Higher than processed goods** (2 VP)

### Contracts (Rare)
- Some advanced contracts may require Import Goods
- "Deliver 2 Cotton + 3 Whisky" → Premium reward
- Creates contract chains

### No Market Use (Likely)
- Cannot sell for gold
- VP-only value
- Hoard for end game

## Strategic Value

### High VP Value
- 3-5 VP vs 2 VP (processed) vs 1 VP (basic)
- Most valuable resources
- Worth pursuing contracts for

### Limited Availability
- Only from contracts
- Can't mass-produce
- Scarcity creates value

### End Game Focus
- Import Goods accumulate
- Convert to VPs at end
- Late-game scoring boost

## Game States

### Player Stock
```
{
  cotton: number,
  tobacco: number,
  sugar_cane: number,
  hops: number
}
```

### No Production Phase
- Import Goods don't produce
- Static until contracts provide more

## Import Good Values (Estimated)

| Import Good | VP Value | Rarity |
|-------------|----------|--------|
| Cotton | 3-4 | Common |
| Tobacco | 3-4 | Common |
| Sugar Cane | 4-5 | Uncommon |
| Hops | 4-5 | Uncommon |

**Variation by rarity**:
- More common → 3 VP
- Less common → 5 VP
- Rewards match difficulty

## Contracts Providing Import Goods

**Early Contracts** (Rounds 1-2):
- Small Import Good rewards (1 Cotton, 1 Tobacco)
- Easier requirements
- Introduce mechanic

**Mid Contracts** (Rounds 2-3):
- Moderate rewards (2 Cotton, 1 Sugar Cane)
- Standard requirements
- Build Import Good stock

**Late Contracts** (Rounds 4-5):
- Large rewards (3 Tobacco, 2 Hops)
- Difficult requirements
- Final VP push

## Strategic Decisions

### Pursue Import Good Contracts
**When to prioritize**:
- Late game (VPs critical)
- Can fulfill requirements easily
- Have production for needed goods
- Import Good reward is high (Sugar Cane, Hops)

**When to skip**:
- Requirements too expensive
- Need gold more than VPs
- Import Good value low (only 1 Cotton)
- Other contracts better

### Import Goods vs Gold
**Import Good Contracts**:
- Lower gold rewards
- Higher VP rewards
- End-game focused

**Gold Contracts**:
- Higher gold rewards
- Lower VP rewards
- Expansion focused

**Early game**: Prefer gold (need expansion)
**Late game**: Prefer Import Goods (need VPs)

## Comparison

**End Game VP Value**:
| Resource Type | VP per Unit | Source |
|---------------|-------------|--------|
| Basic Goods | 1 | Production units |
| Processed Goods | 2 | Processing buildings |
| Import Goods | 3-5 | Contract rewards |

**Import Goods most valuable per unit**

**But limited by**:
- Contract availability
- Ability to fulfill
- Competition from other players

## Lord Synergies

### Lord Aldric (Strong)
**Dual Contracts**:
- Can hold 2 contracts
- More Import Good opportunities
- Double rewards possible
- Higher Import Good accumulation

### All Lords
- Import Goods universal
- No special bonuses
- Equal opportunity

## Contract Chains

**Advanced Strategy**:
- Early contracts → Import Goods
- Later contracts require Import Goods
- Chain rewards

**Example Chain**:
1. Round 2: "Deliver 3 Wool" → Reward: 2 Cotton
2. Round 4: "Deliver 2 Cotton + 3 Whisky" → Reward: £25 + 8 VP
3. Import Goods enable access to premium contracts

## End Game Calculation

**Example Import Good Accumulation**:
- Round 1: Contract → 1 Cotton (3 VP)
- Round 2: Contract → 2 Tobacco (6 VP)
- Round 3: Contract → 1 Sugar Cane (5 VP)
- Round 4: Contract → 2 Hops (10 VP)
- Total: 24 VP from Import Goods alone!

**Significant end-game scoring**

## Import Good Strategy

### Maximize Import Goods (Late Game Focus)
1. Prioritize contracts with Import Good rewards
2. Fulfill multiple Import Good contracts
3. Accumulate 6-10 Import Goods
4. 20-40 VP from Import Goods at end
5. Victory through contracts

### Balanced Strategy
- Mix Import Good and gold contracts
- Don't over-focus on VPs
- Need gold for expansion
- Moderate Import Good accumulation (10-15 VP worth)

## Import Good Scarcity

**Limited Supply**:
- Only from contracts
- Contracts limited per round
- Competition from players
- First to contract gets reward

**Creates urgency**:
- Claim Import Good contracts fast
- Block opponents from high-value contracts
- Strategic contract selection

## Thematic Import Goods

**Cotton**: Textile trade
**Tobacco**: Colonial trade
**Sugar Cane**: Plantation trade
**Hops**: Brewing ingredient (Beer synergy?)

**Thematic fit**: Medieval trade economy

## Hops + Beer Synergy (Potential)

**Thematic Connection**:
- Hops used in brewing
- Oswald (Brewmaster) + Hops connection?

**Possible Mechanic**:
- Oswald bonus for Hops?
- Hops required for premium Beer?
- Thematic but may add complexity

**Likely**: Hops just VP value (keep simple)

## Import Goods in Contracts

**Contracts May Require Import Goods**:
- Advanced contracts (Rounds 4-5)
- "Deliver 2 Cotton + 3 Cheese" → Premium reward
- Creates use for Import Goods beyond end-game VPs
- Adds strategic depth

**Consideration**:
- Most contracts don't require Import Goods
- Only premium/advanced contracts
- Keeps Import Goods as VPs primary use
