# Test_Lord_Godwyn_WhiskyAging

**Purpose:** Verify Godwyn's whisky aging cellar mechanics.

## Initial State

**Game State:**
- Round: 1
- Phase: Production

**Player State (Godwyn):**
- Lord: Master Godwyn the Distiller
- Gold: £10
- Resources: {Grain: 2}
- Units: [Distillery × 2]
- Aging Cellar: {Slot1: empty, Slot2: empty}

## Events

### Event 1: Produce 2 Whisky + Bonus

**Action:** Distilleries produce 2 Whisky, Godwyn gets £3 per whisky

**State Changes:**
- Player Resources Whisky: 0 → 2
- Player Gold: £10 → £16 (gained £3 × 2)

**Expected State:**
- Resources: {Whisky: 2}
- Gold: £16
- Production bonus applied

### Event 2: Move 1 Whisky to Cellar Slot 1

**Action:** Godwyn moves 1 Whisky from stock to aging cellar Slot 1

**State Changes:**
- Player Resources Whisky: 2 → 1
- Aging Cellar Slot1: empty → {Whisky: 1, Age: 0}

**Expected State:**
- Resources: {Whisky: 1}
- Cellar Slot1: 1 Whisky (age 0)

### Event 3: Round 2 - Age Whisky

**Action:** Round progresses, whisky ages

**State Changes:**
- Round: 1 → 2
- Aging Cellar Slot1: {Whisky: 1, Age: 0} → Slot2: {Whisky: 1, Age: 1}
- Aging Cellar Slot2: empty → {Whisky: 1, Age: 1}
- Aging Cellar Slot1: becomes empty

**Expected State:**
- Cellar Slot1: empty
- Cellar Slot2: 1 Whisky (age 1)

### Event 4: Take 1-Year Whisky (£7 Bonus)

**Action:** Godwyn moves 1-year whisky from Slot 2 to stock

**State Changes:**
- Player Gold: (current) → (current + £15) [2-year bonus]
- Aging Cellar Slot2: {Whisky: 1, Age: 1} → empty
- Player Resources Whisky: (current) → (current + 1)

**Note:** If taken from Slot 1 after 1 year: £7 bonus
**Note:** If taken from Slot 2 after 2 years: £15 bonus

**Expected State:**
- Gold increased by £15 (if 2-year)
- Cellar slot emptied
- Whisky back in stock

## Final State Verification

**Godwyn Aging Mechanics:**
- Production: +£3 per whisky produced
- Cellar Slot 1: 1-year aging
- Cellar Slot 2: 2-year aging
- 1-year whisky: +£7 when moved to stock
- 2-year whisky: +£15 when moved to stock

**Assertions:**
- Production bonus applied immediately
- Whisky can be aged or sold fresh
- Aging progresses each round
- Gold bonus only when moving to stock
- Player chooses when to cash out
