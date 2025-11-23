# Test_Production_Processing

**Purpose:** Verify processing buildings convert basic goods to processed goods.

## Initial State

**Game State:**
- Round: 2
- Phase: Production

**Player State:**
- Gold: £15
- Resources: {Milk: 2, Grain: 3}
- Units:
  - Cow at Hex A
  - Field at Hex B
  - CheeseDairy at Hex C
  - Bakery at Hex D

## Events

### Event 1: Cow Produces Milk

**Action:** Cow produces Milk during production

**State Changes:**
- Player Resources Milk: 2 → 3

**Expected State:**
- Player Resources: {Milk: 3, Grain: 3}

### Event 2: Field Produces Grain

**Action:** Field produces Grain during production

**State Changes:**
- Player Resources Grain: 3 → 4

**Expected State:**
- Player Resources: {Milk: 3, Grain: 4}

### Event 3: CheeseDairy Converts Milk to Cheese

**Action:** CheeseDairy consumes 1 Milk, produces 1 Cheese

**State Changes:**
- Player Resources Milk: 3 → 2
- Player Resources Cheese: 0 → 1

**Expected State:**
- Player Resources: {Milk: 2, Grain: 4, Cheese: 1}

### Event 4: Bakery Converts Grain to Bread

**Action:** Bakery consumes 1 Grain, produces 1 Bread

**State Changes:**
- Player Resources Grain: 4 → 3
- Player Resources Bread: 0 → 1

**Expected State:**
- Player Resources: {Milk: 2, Grain: 3, Cheese: 1, Bread: 1}

## Final State Verification

**Player State:**
- Gold: £15 (unchanged)
- Resources: {Milk: 2, Grain: 3, Cheese: 1, Bread: 1}

**Processing:**
- CheeseDairy: Milk → Cheese (1:1)
- Bakery: Grain → Bread (1:1)
- Distillery: Grain → Whisky (1:1)
- Brewery: Grain → Beer (1:1)

**Assertions:**
- Processing buildings consume input resource
- Processing buildings produce output resource
- Conversion ratio is 1:1
- Processing happens during Production phase
- Both basic production and processing can occur same round
