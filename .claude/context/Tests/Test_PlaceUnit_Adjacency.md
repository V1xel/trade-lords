# Test_PlaceUnit_Adjacency

**Purpose:** Verify adjacency requirement for unit placement.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- HexGrid:
  - Hex A at (0,0): Grassland, occupied by Player's Sheep
  - Hex B at (1,0): Grassland, adjacent to A, unoccupied
  - Hex C at (5,5): Grassland, not adjacent to A, unoccupied

**Player State:**
- Gold: £20
- Resources: {}
- Units: [Sheep at (0,0)]
- Owned Hexes: [Hex A (0,0)]

## Events

### Event 1: Place Cow on Adjacent Hex (Valid)

**Action:** Player places Cow unit on Hex B (1,0) adjacent to owned Hex A

**State Changes:**
- Player Gold: £20 → £14 (Cow cost £5 + Terrain cost £1)
- Player Units: [Sheep at (0,0)] → [Sheep at (0,0), Cow at (1,0)]
- Player Owned Hexes: [Hex A] → [Hex A, Hex B]
- Hex B OccupyingUnit: null → Cow
- Hex B OwningPlayer: null → Player

**Expected State:**
- Player Gold: £14
- Player Units: [Sheep at (0,0), Cow at (1,0)]
- Hex B occupied

### Event 2: Attempt to Place Field on Non-Adjacent Hex (Invalid)

**Action:** Player attempts to place Field unit on Hex C (5,5) not adjacent to owned hexes

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £14 (unchanged)
- Player Units: [Sheep at (0,0), Cow at (1,0)] (unchanged)
- Hex C: still unoccupied
- Error: "Cannot place unit - not adjacent to owned units"

## Final State Verification

**Player State:**
- Gold: £14
- Units: 2 (Sheep, Cow)
- Owned Hexes: 2 (Hex A, Hex B)

**Hex States:**
- Hex A (0,0): Occupied by Sheep
- Hex B (1,0): Occupied by Cow
- Hex C (5,5): Unoccupied

**Assertions:**
- Adjacent placement succeeds
- Non-adjacent placement fails
- Gold only deducted for valid placement
- Game state unchanged after failed placement
