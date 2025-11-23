# Test_Contract_FulfillContract

**Purpose:** Verify fulfilling contracts consumes resources and grants rewards.

## Initial State

**Game State:**
- Round: 3
- Phase: Action

**Player State:**
- Gold: £5
- Resources: {Wool: 3, Cheese: 1}
- Victory Points: 0
- Active Contracts:
  - Contract A: Requires {Wool: 3}, Rewards £8 + 1 Cotton + 5 VP

## Events

### Event 1: Fulfill Contract A

**Action:** Player fulfills Contract A with 3 Wool

**State Changes:**
- Player Resources Wool: 3 → 0 (consumed)
- Player Gold: £5 → £13 (gained £8)
- Player Resources Cotton: 0 → 1 (import reward)
- Player Victory Points: 0 → 5
- Player Active Contracts: [Contract A] → []

**Expected State:**
- Player Gold: £13
- Resources: {Wool: 0, Cheese: 1, Cotton: 1}
- Victory Points: 5
- Active Contracts: []
- Contract slot freed

## Final State Verification

**Player State:**
- Gold: £13
- Resources: {Cheese: 1, Cotton: 1}
- Victory Points: 5
- Active Contracts: 0 (can take new contract)

**Contract Fulfillment:**
- Required resources consumed
- Gold reward granted
- Import good reward granted
- Victory points awarded
- Contract removed from active
- Contract slot freed

**Assertions:**
- Resources consumed exactly as required
- All rewards granted (gold, import goods, VP)
- Contract slot freed for new contracts
- Cannot fulfill without sufficient resources
