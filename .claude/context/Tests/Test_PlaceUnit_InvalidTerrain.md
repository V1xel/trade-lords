# Test_PlaceUnit_InvalidTerrain

**Purpose:** Verify terrain requirement validation for unit placement.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- HexGrid:
  - Hex A at (0,0): Grassland, occupied by Player's Sheep
  - Hex B at (1,0): Forest, adjacent to A, unoccupied
  - Hex C at (2,0): Mountain, adjacent to B, unoccupied

**Player State:**
- Gold: £20
- Resources: {}
- Units: [Sheep at (0,0)]
- Owned Hexes: [Hex A (0,0)]

## Events

### Event 1: Attempt to Place Sheep on Forest (Invalid)

**Action:** Player attempts to place Sheep (requires Grassland) on Forest hex

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £20 (unchanged)
- Player Units: [Sheep at (0,0)] (unchanged)
- Hex B: still unoccupied
- Error: "Terrain mismatch - Sheep requires Grassland"

### Event 2: Place Woodcutter on Forest (Valid)

**Action:** Player places Woodcutter (requires Forest) on Forest hex

**State Changes:**
- Player Gold: £20 → £13 (£5 Woodcutter + £2 Forest)
- Player Units: [Sheep] → [Sheep, Woodcutter at (1,0)]
- Player Owned Hexes: [Hex A] → [Hex A, Hex B]

**Expected State:**
- Player Gold: £13
- Woodcutter placed successfully

### Event 3: Attempt to Place Woodcutter on Mountain (Invalid)

**Action:** Player attempts to place Woodcutter (requires Forest) on Mountain hex

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £13 (unchanged)
- Hex C: still unoccupied
- Error: "Terrain mismatch - Woodcutter requires Forest"

## Final State Verification

**Player State:**
- Gold: £13
- Units: 2 (Sheep, Woodcutter)
- Owned Hexes: 2 (Hex A, Hex B)

**Terrain Validation:**
- Grassland units: Sheep, Cow, Field, Factories
- Forest units: Woodcutter only
- Mountain units: Miner only

**Assertions:**
- Invalid terrain placement rejected
- Valid terrain placement succeeds
- No gold deducted for invalid placements
- Clear error messages for terrain mismatches
