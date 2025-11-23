# Test_Production_WorkerIncome

**Purpose:** Verify worker units generate gold income during production.

## Initial State

**Game State:**
- Round: 1
- Phase: Production

**Player State:**
- Gold: £5
- Resources: {}
- Units:
  - Woodcutter (not upgraded) at Hex A
  - Miner (not upgraded) at Hex B

## Events

### Event 1: Woodcutter Generates Income

**Action:** Woodcutter produces £4 income (not upgraded)

**State Changes:**
- Player Gold: £5 → £9

**Expected State:**
- Player Gold: £9

### Event 2: Miner Generates Income

**Action:** Miner produces £6 income (not upgraded)

**State Changes:**
- Player Gold: £9 → £15

**Expected State:**
- Player Gold: £15

## Final State Verification

**Player State:**
- Gold: £15
- Resources: {} (workers don't produce resources)
- Units: 2 (unchanged)

**Worker Income:**
- Woodcutter (not upgraded): £4
- Woodcutter (upgraded): £6
- Miner (not upgraded): £6
- Miner (upgraded): £8
- Fisherman: £4 (Caspian only)

**Assertions:**
- Workers generate gold during Production phase
- Workers don't produce resources
- Income based on worker type and upgrade status
- Gold added to player total
