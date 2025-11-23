# Market Trading Flow

## Scenario: Price Manipulation

**Initial Market Prices**:
- Wool: £6
- Whisky: £10

**Player A** (Lady Isolde, 5 merchants):

**Trade 1 - Sell Wool**:
- Sell 1 Wool at £6
- Receive £6 + £1 (Isolde bonus) = £7
- Wool price drops to £5
- Merchants: 4 left

**Trade 2 - Sell Wool**:
- Sell 1 Wool at £5
- Receive £5 + £1 = £6
- Wool price drops to £4
- Merchants: 3 left

**Trade 3 - Buy Whisky**:
- Buy 1 Whisky at £10
- Pay £10, receive £1 (Isolde) = £9 net
- Whisky price rises to £11
- Merchants: 2 left

**Player B** (Standard, 2 merchants):

**Trade 1 - Buy Wool**:
- Buy 1 Wool at £4 (benefiting from Isolde's price drop)
- Pay £4
- Wool price rises to £5
- Merchants: 1 left

**Trade 2 - Sell Whisky**:
- Sell 1 Whisky at £11 (price raised by Isolde)
- Receive £11
- Whisky price drops to £10
- Merchants: 0 left

---

## Scenario: Merchant Limits

**Player** has 2 merchants, needs 3 goods

**Round N Actions**:
- Buy Wool (1 merchant used)
- Buy Cheese (2 merchants used)
- Cannot buy Bread (no merchants left)

**Options**:
1. Wait until next round (merchants refresh)
2. Produce Bread instead of buying
3. Unlock 3rd merchant (£4) then trade

**Round N+1**:
- Merchants refresh to 2 (or 3 if unlocked)
- Can buy Bread now
