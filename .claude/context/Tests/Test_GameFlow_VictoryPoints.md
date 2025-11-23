# Test_GameFlow_VictoryPoints

**Purpose:** Verify victory point calculation at game end.

## Initial State

**Game State:**
- Round: 8 (final round)
- Phase: EndRound

**Player State:**
- Victory Points: 15 (from contracts)
- Resources:
  - Wool: 3 (basic, 1 VP each)
  - Milk: 2 (basic, 1 VP each)
  - Cheese: 2 (processed, 2 VP each)
  - Whisky: 1 (processed, 2 VP each)
  - Cotton: 2 (import, 3 VP each)
  - Tobacco: 1 (import, 4 VP)
- Gold: £8

## Events

### Event 1: Game Ends

**Action:** Final round ends, game transitions to end state

**State Changes:**
- Phase: EndRound → GameEnd

**Expected State:**
- Phase: GameEnd
- Victory point calculation triggered

### Event 2: Calculate Resource Victory Points

**Action:** Convert resources to victory points

**Basic Goods (1 VP each):**
- Wool: 3 × 1 = 3 VP
- Milk: 2 × 1 = 2 VP
- Total Basic: 5 VP

**Processed Goods (2 VP each):**
- Cheese: 2 × 2 = 4 VP
- Whisky: 1 × 2 = 2 VP
- Total Processed: 6 VP

**Import Goods:**
- Cotton: 2 × 3 = 6 VP
- Tobacco: 1 × 4 = 4 VP
- Total Import: 10 VP

**Total Resource VP:** 5 + 6 + 10 = 21 VP

**State Changes:**
- Resource VP calculated: 21 VP

**Expected State:**
- Resource VP: 21

### Event 3: Calculate Final Victory Points

**Action:** Sum all victory point sources

**Victory Point Sources:**
- Contracts fulfilled: 15 VP
- Resources: 21 VP
- Total: 36 VP

**State Changes:**
- Player Final Victory Points: 15 → 36

**Expected State:**
- Final VP: 36
- Gold not converted (or if it is, £8 = 0-1 VP)

## Final State Verification

**Victory Point Values:**
- Basic goods: 1 VP each
- Processed goods: 2 VP each
- Import goods: 3-5 VP each (varies)
- Contract fulfillment: per contract
- Gold: minimal/no VP

**Assertions:**
- All resources converted to VP
- Resource VP values correct
- Contract VP counted
- Final VP sum correct
- Winner determined by highest VP
