# Test_Market_PriceChange

**Purpose:** Verify market prices change dynamically based on trading.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- Market Prices: {Wool: £3}

**Player State:**
- Gold: £50
- Resources: {Wool: 10}
- Available Merchants: 6

## Events

### Event 1: Buy Wool (Price Increases)

**Action:** Player buys 2 Wool at £3

**State Changes:**
- Player Gold: £50 → £44 (2 × £3)
- Player Resources Wool: 10 → 12
- Market Price Wool: £3 → £4 (buying raises price)

**Expected State:**
- Wool price: £4
- Price increased due to demand

### Event 2: Buy More Wool at New Price

**Action:** Player buys 1 Wool at new price £4

**State Changes:**
- Player Gold: £44 → £40 (1 × £4)
- Player Resources Wool: 12 → 13
- Market Price Wool: £4 → £5

**Expected State:**
- Wool price: £5
- Price continues to increase

### Event 3: Sell Wool (Price Decreases)

**Action:** Player sells 3 Wool at £5

**State Changes:**
- Player Gold: £40 → £55 (3 × £5)
- Player Resources Wool: 13 → 10
- Market Price Wool: £5 → £4 (selling lowers price)

**Expected State:**
- Wool price: £4
- Price decreased due to supply

### Event 4: Sell More Wool

**Action:** Player sells 2 Wool at £4

**State Changes:**
- Player Gold: £55 → £63 (2 × £4)
- Player Resources Wool: 10 → 8
- Market Price Wool: £4 → £3

**Expected State:**
- Wool price: £3 (back to original)
- Price continues to decrease

## Final State Verification

**Market State:**
- Wool price: £3 (returned to base price)

**Price Dynamics:**
- Buying increases price
- Selling decreases price
- Price changes persist across actions

**Assertions:**
- Buying raises market price
- Selling lowers market price
- Price changes affect subsequent trades
- Price bounded by min/max values
