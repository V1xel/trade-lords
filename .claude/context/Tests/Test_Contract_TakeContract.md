# Test_Contract_TakeContract

**Purpose:** Verify taking export contracts costs gold and adds contract to player.

## Initial State

**Game State:**
- Round: 2
- Phase: Action
- Contract Cost (Round 2): £4
- Available Contracts:
  - Contract A: Requires {Wool: 3}, Rewards £8 + Cotton
  - Contract B: Requires {Cheese: 2}, Rewards £12 + Tobacco

**Player State:**
- Gold: £10
- Resources: {Wool: 5}
- Active Contracts: []
- Max Contracts: 1

## Events

### Event 1: Take Contract A

**Action:** Player takes Contract A (Wool export)

**State Changes:**
- Player Gold: £10 → £6 (paid round cost £4)
- Player Active Contracts: [] → [Contract A]

**Expected State:**
- Player Gold: £6
- Active Contracts: [Contract A]
- Contract unfulfilled

### Event 2: Attempt to Take Second Contract (Invalid)

**Action:** Player attempts to take Contract B but already has max contracts (1)

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £6 (unchanged)
- Active Contracts: [Contract A] (unchanged)
- Error: "Cannot take contract - already have maximum contracts"

## Final State Verification

**Player State:**
- Gold: £6
- Active Contracts: 1 (Contract A)
- Resources: {Wool: 5} (not consumed yet)

**Contract State:**
- Contract A: Taken but not fulfilled

**Assertions:**
- Taking contract costs round-based gold
- Contract added to active contracts
- Cannot exceed max contracts (1 for most lords, 2 for Aldric)
- Resources not consumed until fulfillment
- Gold only deducted on valid contract take
