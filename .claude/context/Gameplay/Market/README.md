# Market System

## Overview

The Market allows players to buy and sell resources for gold. Prices are dynamic, changing based on player trades.

## Core Mechanics

### Trading
- Use merchants to buy or sell resources
- Each trade uses 1 merchant
- Merchants refresh each round

### Dynamic Pricing
- Buying a resource raises its price
- Selling a resource lowers its price
- Prices adjust immediately after trade

### Merchants
- Players start with 2 merchants
- Can unlock up to 6 total (cost £4 each)
- Lady Isolde starts with 5 merchants
- Used merchants unavailable until next round

## Market State

### Resource Prices
Each resource has a current price:
```
{
  wool: £6,
  milk: £7,
  grain: £4,
  cheese: £10,
  bread: £8,
  whisky: £12,
  beer: £9
}
```

Prices fluctuate based on trading

### Price Movement
- **Buy**: Price increases by 1-2 steps
- **Sell**: Price decreases by 1-2 steps
- Price track: £3 → £4 → £5 → £6 → £7 → £8 → £9 → £10 → £12 → £15

### Player Merchants
```
{
  available_merchants: 2-6,
  used_merchants: 0-6,
  max_merchants: 6
}
```

## Trading Actions

### Buy Resource
1. Select resource to buy
2. Pay current market price
3. Use 1 merchant
4. Receive 1 resource
5. Price increases

### Sell Resource
1. Select resource to sell
2. Have 1 of that resource in stock
3. Use 1 merchant
4. Receive current market price in gold
5. Price decreases

### Trade Limits
- Cannot trade if no merchants available
- Cannot sell if don't have resource
- Cannot buy if cannot afford price

## Special Rules

### Lady Isolde Bonus
- Gains £1 per trade (buy or sell)
- Trade action triggers bonus
- Stacks with trade value

### Dame Elspeth Milk Sales
- Can sell Milk for flat £8
- Does NOT use merchant
- Does NOT use market
- Bypasses market price

### Merchant Restrictions
**Cannot have same player's merchants on both buy and sell in same round**:
- If bought this round, cannot sell (or vice versa)
- Prevents rapid price manipulation
- Anti-exploit rule

## Market Strategy

### Buy Low, Sell High
- Monitor price tracks
- Buy when prices dip
- Sell when prices rise
- Market timing

### Price Manipulation
- Buy to raise price (opponent must pay more)
- Sell to lower price (make buying cheaper later)
- Strategic pricing

### Merchant Management
- Don't waste merchants on poor trades
- Save merchants for critical resources
- Unlock more merchants if trading heavily

## Market vs Production

**Market Trading**:
- Immediate resource access
- Uses merchants
- Price varies
- Flexible but expensive

**Production**:
- Requires units/buildings
- Takes time to build
- Consistent output
- Long-term investment

**Generally: Production > Market trading**
- Market supplements production
- Market fills gaps for contracts
- Market emergency resource access

## Lady Isolde Market Dominance

**Isolde Advantages**:
- 5 merchants (vs 2 standard)
- £1 per trade
- Can trade 5 times per round

**Isolde Strategy**:
- High-volume trading
- £5 bonus per round (5 trades)
- Manipulate prices
- Control market

## Merchant Unlock Cost

**Unlocking Merchants**:
- Cost: £4 per merchant
- Unlock 3rd merchant: £4 (now have 3)
- Unlock 4th merchant: £4 (now have 4)
- Etc. up to 6 total

**Value Calculation**:
- 1 extra trade per round
- Worth it if trading frequently
- Isolde starts with 5 (saves £12)

## Price Track Examples

**Wool Price Track**:
```
£3 → £4 → £5 → £6 → £7 → £8
     ↑ Buy action
          ↓ Sell action
```

**Dynamic Market**:
- Multiple players trading → volatile prices
- Supply/demand simulation
- Strategic depth

## Round Structure

### Start of Round
- All merchants refresh
- Available merchants reset to max
- Prices remain from previous round

### During Round
- Players trade using merchants
- Merchants become used
- Prices fluctuate

### End of Round
- Used merchants don't refresh until next round
- Prices carry over

## Trade Examples

**Example 1: Buy Wool**
- Current Wool price: £6
- Player has £10, 2 merchants
- Buys 1 Wool: Pay £6, use 1 merchant
- Wool price increases to £7
- Player now has: £4, 1 Wool, 1 merchant left

**Example 2: Sell Cheese (Isolde)**
- Current Cheese price: £10
- Isolde has 2 Cheese, 5 merchants
- Sells 1 Cheese: Receive £10 + £1 (Isolde) = £11
- Use 1 merchant
- Cheese price decreases to £9
- Isolde now has: +£11, 1 Cheese, 4 merchants left

**Example 3: Elspeth Milk**
- Elspeth has 3 Milk, 2 merchants
- Sells 3 Milk to Elspeth ability: Receive £24 (3 × £8)
- Uses 0 merchants (special ability)
- Market price unchanged
- Elspeth now has: +£24, 0 Milk, 2 merchants still available

## Market Balance

**Market should**:
- Provide flexibility
- Not replace production
- Create price volatility
- Reward timing

**Market should not**:
- Be primary resource source
- Be exploitable
- Make production worthless
