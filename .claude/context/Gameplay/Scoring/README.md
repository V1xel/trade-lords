# Scoring System

## Victory Points Sources

### 1. Contracts
- Contract rewards: 3-8 VP
- Main VP source

### 2. Goods (End Game)
- Basic goods: 1 VP each
- Processed goods: 2 VP each
- Import goods: 3-5 VP each

### 3. Gold (End Game)
- £10 = 1 VP

### 4. Glory
- From round scoring
- 1 glory = 1 VP

### 5. Territory (TBD)
- Connected territories
- Settlement bonuses
- If implemented

## Round Scoring

Each round has scoring tile with criteria:
- "Most Whisky"
- "Most contracts fulfilled"
- "Most workers"
- "Largest territory"

Awards:
- 1st: +3 glory
- 2nd: +2 glory
- 3rd: +1 glory

## Final Scoring

```
Total VP = Contract VP
         + Goods VP
         + (Gold ÷ 10)
         + Glory
         + Territory VP
```

## Tiebreaker

1. Most gold
2. Most goods
3. Turn order position

## Victory Condition

Highest VP after Round 5 wins

## Scoring State

```
{
  contract_vp: number,
  goods_vp: number,
  gold_vp: number,
  glory: number,
  territory_vp: number,
  total_vp: number
}
```
