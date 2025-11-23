# Test_Market_BuyResource

**Purpose:** Verify buying resources from market deducts gold and adds resources.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- Market Prices: {Wool: £3, Milk: £3, Grain: £2}

**Player State:**
- Gold: £20
- Resources: {}
- Available Merchants: 2
- Used Merchants: 0

## Events

### Event 1: Buy 2 Wool

**Action:** Player buys 2 Wool at £3 each, uses 1 merchant

**State Changes:**
- Player Gold: £20 → £14 (2 × £3 = £6)
- Player Resources Wool: 0 → 2
- Player Used Merchants: 0 → 1
- Player Available Merchants: 2 → 1

**Expected State:**
- Player Gold: £14
- Player Resources: {Wool: 2}
- Merchants: 1 used, 1 available

### Event 2: Buy 3 Grain

**Action:** Player buys 3 Grain at £2 each, uses 1 merchant

**State Changes:**
- Player Gold: £14 → £8 (3 × £2 = £6)
- Player Resources Grain: 0 → 3
- Player Used Merchants: 1 → 2
- Player Available Merchants: 1 → 0

**Expected State:**
- Player Gold: £8
- Player Resources: {Wool: 2, Grain: 3}
- Merchants: 2 used, 0 available

### Event 3: Attempt to Buy Without Merchant (Invalid)

**Action:** Player attempts to buy Milk but has no merchants left

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £8 (unchanged)
- Player Resources: {Wool: 2, Grain: 3} (unchanged)
- Error: "No merchants available"

## Final State Verification

**Player State:**
- Gold: £8
- Resources: {Wool: 2, Grain: 3}
- Merchants: 2 used, 0 available

**Assertions:**
- Buying costs gold (quantity × price)
- Resources added to stock
- Merchant consumed per buy action
- Cannot buy without merchants
- Gold and merchants only deducted on valid purchase
