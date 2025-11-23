# Test_PlaceUnit_TerrainCost

**Purpose:** Verify correct calculation of total placement cost (unit + terrain).

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- HexGrid:
  - Hex A at (0,0): Grassland (£1), occupied by Player's Sheep
  - Hex B at (1,0): Forest (£2), adjacent to A, unoccupied
  - Hex C at (2,0): Mountain (£3), adjacent to B, unoccupied

**Player State:**
- Gold: £20
- Resources: {}
- Units: [Sheep at (0,0)]
- Owned Hexes: [Hex A (0,0)]

## Events

### Event 1: Place Woodcutter on Forest (£5 unit + £2 terrain = £7)

**Action:** Player places Woodcutter on Hex B (Forest)

**State Changes:**
- Player Gold: £20 → £13 (£5 Woodcutter + £2 Forest terrain)
- Player Units: [Sheep] → [Sheep, Woodcutter at (1,0)]
- Player Owned Hexes: [Hex A] → [Hex A, Hex B]

**Expected State:**
- Player Gold: £13
- Total cost deducted: £7

### Event 2: Place Miner on Mountain (£6 unit + £3 terrain = £9)

**Action:** Player places Miner on Hex C (Mountain)

**State Changes:**
- Player Gold: £13 → £4 (£6 Miner + £3 Mountain terrain)
- Player Units: [Sheep, Woodcutter] → [Sheep, Woodcutter, Miner at (2,0)]
- Player Owned Hexes: [Hex A, Hex B] → [Hex A, Hex B, Hex C]

**Expected State:**
- Player Gold: £4
- Total cost deducted: £9

## Final State Verification

**Player State:**
- Gold: £4
- Units: 3 (Sheep, Woodcutter, Miner)
- Owned Hexes: 3

**Assertions:**
- Total cost = unit cost + terrain cost
- Grassland: £1 terrain
- Forest: £2 terrain
- Mountain: £3 terrain
- Correct gold deduction for each placement
