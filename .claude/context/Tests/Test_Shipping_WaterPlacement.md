# Test_Shipping_WaterPlacement

**Purpose:** Verify shipping allows unit placement across water.

## Initial State

**Game State:**
- Round: 2
- Phase: Action
- HexGrid:
  - Hex A at (0,0): Grassland, owned by Player (has Sheep)
  - Hex B at (1,0): Loch (water)
  - Hex C at (2,0): Loch (water)
  - Hex D at (3,0): Grassland, unoccupied
  - Path from A to D: crosses 2 water hexes (B and C)

**Player State:**
- Gold: £20
- Shipping Level: 1
- Units: [Sheep at (0,0)]
- Owned Hexes: [Hex A]

## Events

### Event 1: Attempt to Place Across 2 Water Hexes (Invalid)

**Action:** Player attempts to place Cow at Hex D (3,0), which is 2 water hexes away

**State Changes:**
- None (action rejected)

**Expected State:**
- Gold: £20 (unchanged)
- Error: "Shipping level 1 insufficient - target is 2 water hexes away"

### Event 2: Upgrade Shipping to Level 2

**Action:** Player upgrades shipping to level 2

**State Changes:**
- Player Gold: £20 → £15 (£5 upgrade)
- Player Shipping Level: 1 → 2

**Expected State:**
- Gold: £15
- Shipping Level: 2

### Event 3: Place Cow Across 2 Water Hexes (Valid)

**Action:** Player places Cow at Hex D (3,0), now reachable with shipping 2

**State Changes:**
- Player Gold: £15 → £9 (£5 Cow + £1 Grassland)
- Player Units: [Sheep at (0,0)] → [Sheep at (0,0), Cow at (3,0)]
- Player Owned Hexes: [Hex A] → [Hex A, Hex D]
- Hex D OccupyingUnit: null → Cow
- Hex D OwningPlayer: null → Player

**Expected State:**
- Gold: £9
- Units placed successfully across water
- Shipping enabled placement

## Final State Verification

**Shipping Mechanics:**
- Shipping level = max water hexes that can be crossed
- Water hexes = Loch, River (sometimes)
- Adjacency can be through water if shipping sufficient
- Still pay normal unit + terrain cost

**Assertions:**
- Cannot place without sufficient shipping
- Can place with sufficient shipping level
- Shipping level = number of water hexes crossed
- Normal placement costs still apply
- Hex ownership still established
