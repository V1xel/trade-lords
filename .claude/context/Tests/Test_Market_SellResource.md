# Test_Market_SellResource

**Purpose:** Verify selling resources to market adds gold and removes resources.

## Initial State

**Game State:**
- Round: 2
- Phase: Action
- Market Prices: {Wool: £3, Cheese: £5, Whisky: £6}

**Player State:**
- Gold: £5
- Resources: {Wool: 4, Cheese: 2, Whisky: 1}
- Available Merchants: 2
- Used Merchants: 0

## Events

### Event 1: Sell 3 Wool

**Action:** Player sells 3 Wool at £3 each, uses 1 merchant

**State Changes:**
- Player Gold: £5 → £14 (3 × £3 = £9)
- Player Resources Wool: 4 → 1
- Player Used Merchants: 0 → 1
- Player Available Merchants: 2 → 1

**Expected State:**
- Player Gold: £14
- Player Resources: {Wool: 1, Cheese: 2, Whisky: 1}
- Merchants: 1 used, 1 available

### Event 2: Sell 1 Whisky

**Action:** Player sells 1 Whisky at £6, uses 1 merchant

**State Changes:**
- Player Gold: £14 → £20 (1 × £6 = £6)
- Player Resources Whisky: 1 → 0
- Player Used Merchants: 1 → 2
- Player Available Merchants: 1 → 0

**Expected State:**
- Player Gold: £20
- Player Resources: {Wool: 1, Cheese: 2, Whisky: 0}
- Merchants: 2 used, 0 available

### Event 3: Attempt to Sell Without Merchant (Invalid)

**Action:** Player attempts to sell Cheese but has no merchants left

**State Changes:**
- None (action rejected)

**Expected State:**
- Player Gold: £20 (unchanged)
- Error: "No merchants available"

## Final State Verification

**Player State:**
- Gold: £20
- Resources: {Wool: 1, Cheese: 2}
- Merchants: 2 used, 0 available

**Assertions:**
- Selling adds gold (quantity × price)
- Resources removed from stock
- Merchant consumed per sell action
- Cannot sell without merchants
- Cannot sell more resources than owned
