# Test_Lord_Aldric_DualContracts

**Purpose:** Verify Aldric can hold 2 contracts and take 2 in one action.

## Initial State

**Game State:**
- Round: 2
- Phase: Action
- Contract Cost: £4
- Available Contracts:
  - Contract A: Requires {Wool: 3}
  - Contract B: Requires {Cheese: 2}
  - Contract C: Requires {Bread: 1}

**Player State (Aldric):**
- Lord: Aldric the Negotiator
- Gold: £20
- Resources: {}
- Active Contracts: []
- Max Contracts: 2 (Aldric special)

## Events

### Event 1: Take 2 Contracts in One Action (Aldric Special)

**Action:** Aldric uses special ability to take Contract A and Contract B in one action

**State Changes:**
- Player Gold: £20 → £16 (paid £4 once, not twice!)
- Player Active Contracts: [] → [Contract A, Contract B]

**Expected State:**
- Player Gold: £16
- Active Contracts: 2
- Only paid contract cost once

### Event 2: Attempt to Take Third Contract (Invalid)

**Action:** Aldric attempts to take Contract C but already at max (2)

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £16 (unchanged)
- Active Contracts: [Contract A, Contract B] (unchanged)
- Error: "Cannot take contract - already have maximum contracts (2)"

### Event 3: Fulfill Contract A

**Action:** Aldric fulfills Contract A (after getting Wool)

**State Changes:**
- Player Active Contracts: [Contract A, Contract B] → [Contract B]

**Expected State:**
- Active Contracts: 1 (slot freed)

### Event 4: Take Contract C Normally

**Action:** Aldric takes Contract C (one contract, normal action)

**State Changes:**
- Player Gold: £16 → £12 (paid £4)
- Player Active Contracts: [Contract B] → [Contract B, Contract C]

**Expected State:**
- Player Gold: £12
- Active Contracts: 2 (back to max)

## Final State Verification

**Aldric Ability:**
- Can hold 2 contracts (vs 1 for others)
- Can take 2 contracts in one action
- When taking 2, pays cost once (not twice)
- Normal contract limit rules still apply

**Assertions:**
- Max contracts: 2
- Dual contract action: pays once
- Single contract action: normal cost
- Cannot exceed 2 contracts
