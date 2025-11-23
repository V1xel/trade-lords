# Test_Contract_ContractCost

**Purpose:** Verify contract cost increases by round.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- Available Contracts:
  - Contract A: Requires {Wool: 2}

**Player 1 State:**
- Gold: £10
- Active Contracts: []

**Player 2 State:**
- Gold: £10
- Active Contracts: []

## Events

### Event 1: Player 1 Takes Contract in Round 1

**Action:** Player 1 takes Contract A in Round 1

**State Changes:**
- Player 1 Gold: £10 → £7 (Round 1 cost: £3)
- Player 1 Active Contracts: [] → [Contract A]

**Expected State:**
- Player 1 Gold: £7
- Contract cost in Round 1: £3

### Event 2: Progress to Round 2

**Action:** Game advances to Round 2

**State Changes:**
- Round: 1 → 2
- Contract Cost: £3 → £4

**Expected State:**
- Contract cost in Round 2: £4

### Event 3: Player 2 Takes Contract in Round 2

**Action:** Player 2 takes similar contract in Round 2

**State Changes:**
- Player 2 Gold: £10 → £6 (Round 2 cost: £4)
- Player 2 Active Contracts: [] → [Contract B]

**Expected State:**
- Player 2 Gold: £6
- Contract cost in Round 2: £4

### Event 4: Progress to Round 3

**Action:** Game advances to Round 3

**State Changes:**
- Round: 2 → 3
- Contract Cost: £4 → £5

**Expected State:**
- Contract cost in Round 3: £5

## Final State Verification

**Contract Cost by Round:**
- Round 1: £3
- Round 2: £4
- Round 3: £5
- Round 4: £6
- Round 5+: £7 (likely cap)

**Assertions:**
- Contract cost increases each round
- Cost applies when contract is taken
- Cost independent of contract type
- All players pay same cost in same round
