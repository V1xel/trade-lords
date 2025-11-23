# Test_GameFlow_PhaseTransitions

**Purpose:** Verify correct phase transitions and phase-specific actions.

## Initial State

**Game State:**
- Round: 1
- Phase: Action

**Player State:**
- Gold: £10
- Resources: {Grain: 2}
- Units: [Field]
- Available Merchants: 2

## Events

### Event 1: Valid Action Phase Actions

**Action:** Player places unit (valid in Action phase)

**State Changes:**
- Unit placed successfully

**Expected State:**
- Action phase allows: place unit, trade, take/fulfill contracts, upgrade shipping

### Event 2: Transition to Production Phase

**Action:** All players end turns, phase transitions to Production

**State Changes:**
- Phase: Action → Production

**Expected State:**
- Phase: Production
- Production actions now valid

### Event 3: Production Occurs

**Action:** Production phase processes units

**State Changes:**
- Field produces Grain
- Player Resources Grain: 2 → 3

**Expected State:**
- Resources updated
- Production phase allows: automatic production only

### Event 4: Attempt Action Phase Action in Production (Invalid)

**Action:** Player attempts to place unit during Production

**State Changes:**
- None (action rejected)

**Expected State:**
- Error: "Cannot place unit during Production phase"
- Phase: Production (unchanged)

### Event 5: Production Complete, Transition to EndRound

**Action:** Production finishes, phase transitions

**State Changes:**
- Phase: Production → EndRound

**Expected State:**
- Phase: EndRound

### Event 6: EndRound Cleanup

**Action:** Cleanup tasks execute

**State Changes:**
- Merchants reset
- Used Merchants: (any) → 0
- Available Merchants: (restored to max)
- Round: 1 → 2

**Expected State:**
- Merchants refreshed
- Round incremented

### Event 7: Transition Back to Action

**Action:** EndRound complete, new round starts

**State Changes:**
- Phase: EndRound → Action

**Expected State:**
- Phase: Action
- Round: 2
- Ready for player actions

## Final State Verification

**Phase-Specific Actions:**

**Action Phase:**
- Place units ✓
- Trade (buy/sell) ✓
- Take/fulfill contracts ✓
- Upgrade shipping ✓
- End turn ✓

**Production Phase:**
- Automatic production only
- No player actions

**EndRound Phase:**
- Automatic cleanup only
- Merchant reset
- Round increment

**Assertions:**
- Actions only valid in correct phase
- Invalid actions rejected
- Phase transitions automatic
- Cleanup happens in EndRound
- Cycle repeats each round
