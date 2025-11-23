# Contract Fulfillment

## Scenario: Multi-Good Contract

**Player**: Standard lord
**Resources**: 2 Wool, 3 Milk, 1 Cheese, 2 Grain
**Contract**: "2 Wool + 2 Cheese + 1 Bread → £20 + 2 Cotton + 5 VP"

## Analysis

**Have**:
- 2 Wool ✓
- 1 Cheese (need 2) ✗
- 0 Bread (need 1) ✗

**Missing**:
- 1 more Cheese
- 1 Bread

## Action Sequence

**Option 1: Produce Missing Goods**

Wait for Production Phase:
- Have Cheese Dairy → 1 Milk → 1 Cheese (now 2 total)
- Have Bakery → 1 Grain → 1 Bread (now 1 total)
- Next turn: Fulfill contract

**Option 2: Trade for Missing Goods**

Action Phase trades:
- Buy 1 Cheese (market price £10, use merchant)
- Buy 1 Bread (market price £8, use merchant)
- Same turn: Fulfill contract

**Option 3: Mixed**

Production Phase:
- Cheese Dairy: 1 Milk → 1 Cheese ✓
- Keep Grain

Action Phase:
- Buy 1 Bread for £8 ✓
- Fulfill contract

## Fulfillment

**Deliver**:
- 2 Wool (removed from stock)
- 2 Cheese (removed)
- 1 Bread (removed)

**Receive**:
- £20 gold
- 2 Cotton (import goods, 3-4 VP each)
- 5 VP immediate

**Total Value**: £20 + 6-8 VP (cotton) + 5 VP = £20 + 11-13 VP
