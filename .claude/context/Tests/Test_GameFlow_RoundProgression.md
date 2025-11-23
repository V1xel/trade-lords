# Test_GameFlow_RoundProgression

**Purpose:** Verify game rounds progress correctly through phases.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- Current Player: Player 1
- Turn Order: [Player 1, Player 2, Player 3]

**Player 1 State:**
- Actions Taken: 0
- Turn Complete: false

## Events

### Event 1: Player 1 Takes Action

**Action:** Player 1 places a unit

**State Changes:**
- Player 1 Actions Taken: 0 → 1
- Player 1 Turn Complete: false (still)

**Expected State:**
- Still Player 1's turn
- Can take more actions

### Event 2: Player 1 Ends Turn

**Action:** Player 1 ends their turn

**State Changes:**
- Player 1 Turn Complete: false → true
- Current Player: Player 1 → Player 2

**Expected State:**
- Phase: Action (still)
- Current Player: Player 2

### Event 3: Player 2 Ends Turn

**Action:** Player 2 ends their turn

**State Changes:**
- Player 2 Turn Complete: false → true
- Current Player: Player 2 → Player 3

**Expected State:**
- Phase: Action (still)
- Current Player: Player 3

### Event 4: Player 3 Ends Turn (Last Player)

**Action:** Player 3 ends their turn (last player in round)

**State Changes:**
- Player 3 Turn Complete: false → true
- Phase: Action → Production
- All Players Turn Complete reset to false

**Expected State:**
- Phase: Production
- All players' turns reset

### Event 5: Production Phase Executes

**Action:** Production phase processes all units

**State Changes:**
- All production units produce resources
- All workers generate income
- Phase: Production → EndRound

**Expected State:**
- Resources/gold updated
- Phase: EndRound

### Event 6: End Round Phase

**Action:** Round cleanup and progression

**State Changes:**
- Round: 1 → 2
- Phase: EndRound → Action
- Contract cost increases
- Merchants reset
- Current Player: Player 1 (first player again)

**Expected State:**
- Round: 2
- Phase: Action
- Round 2 begins

## Final State Verification

**Phase Cycle:**
1. Action Phase (all players take turns)
2. Production Phase (resources/income generated)
3. EndRound Phase (cleanup)
4. Back to Action Phase (next round)

**Assertions:**
- Players take turns in order
- Last player ending turn triggers Production
- Production phase processes all units
- Round increments at end
- Merchants reset each round
- Contract costs increase by round
