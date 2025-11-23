# Test_Shipping_UpgradeLevel

**Purpose:** Verify shipping level upgrades cost gold and increase range.

## Initial State

**Game State:**
- Round: 1
- Phase: Action

**Player State:**
- Gold: £20
- Shipping Level: 0
- Shipping Upgrade Costs: [£5, £5, £5, £5, £5] for levels 1-5

## Events

### Event 1: Upgrade Shipping to Level 1

**Action:** Player upgrades shipping from 0 to 1

**State Changes:**
- Player Gold: £20 → £15 (paid £5)
- Player Shipping Level: 0 → 1

**Expected State:**
- Gold: £15
- Shipping Level: 1
- Can place units 1 hex across water

### Event 2: Upgrade Shipping to Level 2

**Action:** Player upgrades shipping from 1 to 2

**State Changes:**
- Player Gold: £15 → £10 (paid £5)
- Player Shipping Level: 1 → 2

**Expected State:**
- Gold: £10
- Shipping Level: 2
- Can place units 2 hexes across water

### Event 3: Upgrade Shipping to Level 3

**Action:** Player upgrades shipping from 2 to 3

**State Changes:**
- Player Gold: £10 → £5 (paid £5)
- Player Shipping Level: 2 → 3

**Expected State:**
- Gold: £5
- Shipping Level: 3
- Can place units 3 hexes across water

## Final State Verification

**Shipping Levels:**
- Level 0: No water crossing
- Level 1: 1 hex across water
- Level 2: 2 hexes across water
- Level 3: 3 hexes across water
- Level 4: 4 hexes across water
- Level 5: 5 hexes across water (max)

**Shipping Upgrade Costs:**
- Each level: £5
- Maximum level: 5

**Assertions:**
- Each upgrade costs £5
- Shipping level increases by 1
- Range increases with level
- Max level is 5
- Cannot upgrade beyond max
