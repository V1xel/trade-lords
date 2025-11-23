# Test_PlaceUnit_Basic

**Purpose:** Verify basic unit placement on valid terrain with sufficient gold.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- HexGrid: Grassland hex at position (0,0) unoccupied

**Player State:**
- Gold: £10
- Resources: {}
- Units: []
- Owned Hexes: []

## Events

### Event 1: Place Sheep on Grassland

**Action:** Player places Sheep unit on Grassland hex at (0,0)

**State Changes:**
- Player Gold: £10 → £5 (Sheep cost £4 + Terrain cost £1)
- Player Units: [] → [Sheep at (0,0)]
- Player Owned Hexes: [] → [Hex (0,0)]
- Hex (0,0) OccupyingUnit: null → Sheep
- Hex (0,0) OwningPlayer: null → Player

**Expected State:**
- Player Gold: £5
- Player Units: [Sheep at (0,0)]
- Hex (0,0) is occupied by Player's Sheep

## Final State Verification

**Player State:**
- Gold: £5
- Units: 1 Sheep
- Owned Hexes: 1

**Hex State:**
- Hex (0,0): Occupied, Owner = Player

**Assertions:**
- Gold reduced by exactly £5 (unit + terrain)
- Sheep unit created and placed
- Hex ownership transferred to player
- Hex marked as occupied
