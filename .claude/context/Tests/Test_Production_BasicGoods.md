# Test_Production_BasicGoods

**Purpose:** Verify basic goods production from production units.

## Initial State

**Game State:**
- Round: 1
- Phase: Action (about to transition to Production)

**Player State:**
- Gold: £10
- Resources: {}
- Units:
  - Sheep at Hex A
  - Cow at Hex B
  - Field at Hex C

## Events

### Event 1: Transition to Production Phase

**Action:** Game phase changes from Action to Production

**State Changes:**
- Phase: Action → Production
- Trigger production for all units

**Expected State:**
- Production phase active

### Event 2: Sheep Produces Wool

**Action:** Sheep unit produces Wool

**State Changes:**
- Player Resources Wool: 0 → 1

**Expected State:**
- Player Resources: {Wool: 1}

### Event 3: Cow Produces Milk

**Action:** Cow unit produces Milk

**State Changes:**
- Player Resources Milk: 0 → 1

**Expected State:**
- Player Resources: {Wool: 1, Milk: 1}

### Event 4: Field Produces Grain

**Action:** Field unit produces Grain

**State Changes:**
- Player Resources Grain: 0 → 1

**Expected State:**
- Player Resources: {Wool: 1, Milk: 1, Grain: 1}

## Final State Verification

**Player State:**
- Gold: £10 (unchanged during production)
- Resources: {Wool: 1, Milk: 1, Grain: 1}
- Units: 3 (unchanged)

**Assertions:**
- Each production unit produces 1 resource per round
- Sheep → Wool
- Cow → Milk
- Field → Grain
- Resources added to player stock
- Production happens during Production phase
