# Contract System

## Overview

Export Contracts are objectives players fulfill by delivering specific goods. Completing contracts provides rewards: gold, victory points, Import Goods, and upgrades.

## Core Mechanics

### Taking Contracts
- Take Contract action during Action Phase
- Pay round cost (increases each round)
- Take 1 contract (or 2 if Lord Aldric)
- Maximum 1 unfulfilled contract (2 for Aldric)

### Contract Requirements
Contracts specify goods needed:
- "3 Wool + 2 Milk"
- "2 Cheese + 1 Whisky"
- "4 Bread + 2 Hops" (advanced)

### Fulfilling Contracts
- Fulfill Contract action
- Must have all required goods
- Deliver goods (removed from stock)
- Receive rewards immediately

## Contract Rewards

### Gold
- £10-£30 typical
- Immediate economic boost

### Victory Points
- 3-8 VP typical
- Primary scoring method

### Import Goods
- 1-3 Cotton/Tobacco/Sugar Cane/Hops
- High VP value (3-5 VP each)

### Free Expansions
- Place unit without terrain cost
- OR free shipping upgrade
- Expansion boost

### Mixed Rewards
- Combination of above
- "£15 + 2 Cotton + 4 VP"

## Contract State

### Available Contracts
- Pool of available contracts
- Refreshes each round
- Players choose from pool
- First come, first served

### Player Contracts
```
{
  unfulfilled_contracts: [contract1, contract2], // Max 1-2
  fulfilled_contracts: [contracts...], // Completed this game
}
```

### Contract Costs by Round
| Round | Cost to Take Contract |
|-------|-----------------------|
| 1 | £3-£4 |
| 2 | £4-£5 |
| 3 | £5-£6 |
| 4 | £6-£7 |
| 5 | £7-£8 |

Early contracts cheaper to obtain

## Contract Types

### Basic Goods Contracts
- Require Wool, Milk, Grain
- Lower rewards
- Early game accessible
- "3 Wool + 2 Milk" → £12 + 3 VP

### Processed Goods Contracts
- Require Cheese, Bread, Whisky, Beer
- Higher rewards
- Mid-late game
- "2 Whisky + 2 Cheese" → £20 + 6 VP

### Mixed Contracts
- Require basic + processed
- Moderate rewards
- Flexible requirements
- "2 Wool + 1 Bread + 1 Cheese" → £15 + 4 VP

### Import Good Contracts
- Require Import Goods (rare)
- Premium rewards
- Late game only
- "2 Cotton + 3 Whisky" → £25 + 8 VP

## Strategy

### Early Contracts (Rounds 1-2)
- Take cheap contracts (£3-£4 cost)
- Build production for requirements
- Fulfill Round 3-4
- Low risk, moderate reward

### Late Contracts (Rounds 4-5)
- Expensive to take (£6-£8)
- High rewards
- Time-sensitive (game ending)
- Need production already established

### Contract Chaining
- Early contracts → Import Goods
- Late contracts require Import Goods
- Chain rewards for maximum value

## Lord Synergies

### Lord Aldric (Very Strong)
**Dual Contracts**:
- Can hold 2 unfulfilled contracts
- Can take 2 in one action (pay once)
- Flexible strategy
- More contract rewards

### All Lords
- Contracts universal scoring path
- Main VP source
- Economic and strategic

## Contract Competition

### Limited Supply
- Fixed number of contracts available per round
- Players compete for best contracts
- First to take contract removes it from pool

### Blocking
- Take contracts opponents want
- Deny key contracts
- Strategic selection

## Contract Timing

### When to Take Contracts

**Early (Round 1-2)**:
- Low cost to obtain
- Time to build production
- Low pressure

**Mid (Round 2-3)**:
- Production established
- Can fulfill quickly
- Moderate cost

**Late (Round 4-5)**:
- High cost to obtain
- Must fulfill immediately
- High reward pressure

### When to Fulfill

**Immediately**:
- Have all goods
- Need rewards now
- Free up contract slot

**Delay**:
- Gathering goods
- Want to accumulate more
- Strategic timing

## Scoring via Contracts

**Contracts are primary VP source**:
- 3-8 VP per contract
- 3-5 contracts per game typical
- 15-30 VP from contracts
- Plus Import Goods (10-20 VP)

**Total**: 25-50 VP from contracts!

**Comparison**:
- Goods in stock: 5-15 VP
- Gold: 2-5 VP
- Territory: 5-18 VP (if system exists)

**Contracts dominate scoring**

## Contract Examples

**Basic Contract (Round 1)**:
- Requirement: 3 Wool
- Reward: £12 + 3 VP
- Cost to take: £3
- Net: £9 + 3 VP (if fulfill)

**Processed Contract (Round 3)**:
- Requirement: 2 Whisky + 1 Cheese
- Reward: £18 + 2 Cotton + 5 VP
- Cost to take: £5
- Net: £13 + 2 Cotton (6-8 VP) + 5 VP

**Premium Contract (Round 5)**:
- Requirement: 3 Beer + 2 Hops + 2 Bread
- Reward: £30 + 3 Sugar Cane + 8 VP
- Cost to take: £8
- Net: £22 + 3 Sugar Cane (15 VP) + 8 VP

## Contract Balance

**Good Contracts**:
- Achievable requirements
- Fair reward/cost ratio
- Strategic diversity
- Not too easy or hard

**Avoid**:
- Impossible requirements
- Too easy (trivial)
- Unfair rewards
- Required goods too rare
