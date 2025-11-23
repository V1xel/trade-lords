# Test_Lord_Isolde_MarketTrading

**Purpose:** Verify Isolde's trading doesn't affect market prices.

## Initial State

**Game State:**
- Round: 1
- Phase: Action
- Market Prices: {Wool: £3}

**Player State (Isolde):**
- Lord: Lady Isolde the Merchant Princess
- Gold: £30
- Resources: {Wool: 10}
- Available Merchants: 6 (Isolde special)

## Events

### Event 1: Isolde Buys Wool (Price Unchanged)

**Action:** Isolde buys 3 Wool at £3 each

**State Changes:**
- Player Gold: £30 → £21 (3 × £3)
- Player Resources Wool: 10 → 13
- Market Price Wool: £3 → £3 (UNCHANGED - Isolde ability)

**Expected State:**
- Gold: £21
- Resources: {Wool: 13}
- Market price still £3 (not increased)

### Event 2: Isolde Sells Wool (Price Unchanged)

**Action:** Isolde sells 5 Wool at £3 each

**State Changes:**
- Player Gold: £21 → £36 (5 × £3)
- Player Resources Wool: 13 → 8
- Market Price Wool: £3 → £3 (UNCHANGED - Isolde ability)

**Expected State:**
- Gold: £36
- Resources: {Wool: 8}
- Market price still £3 (not decreased)

### Event 3: Normal Player Buys Wool (Price Changes)

**Action:** Different player (not Isolde) buys 2 Wool

**State Changes:**
- Market Price Wool: £3 → £4 (CHANGED - normal trading)

**Expected State:**
- Market price: £4 (normal price change)

### Event 4: Isolde Buys at New Price (Price Still Unchanged)

**Action:** Isolde buys 2 more Wool at £4 each

**State Changes:**
- Player Gold: £36 → £28 (2 × £4)
- Player Resources Wool: 8 → 10
- Market Price Wool: £4 → £4 (UNCHANGED by Isolde)

**Expected State:**
- Gold: £28
- Market price still £4

## Final State Verification

**Isolde Trading Ability:**
- Has 6 merchants (vs 2 for most lords)
- Buying doesn't raise prices
- Selling doesn't lower prices
- Other players' trading still affects prices
- Isolde pays/receives current market price

**Assertions:**
- Isolde's trades don't change market prices
- Other players' trades do change prices
- Isolde still pays current market price
- 6 merchants allow more trading
