# Production Chain Example

## Scenario: Grain to Whisky (Godwyn)

**Setup**:
- Master Godwyn
- Units: 2 Fields, 1 Distillery
- Aging cellar: Empty
- Resources: 1 Grain

## Production Phase - Round 1

**Production**:
- 2 Fields → 2 Grain
- Total: 3 Grain in stock

**Processing**:
- Distillery: 1 Grain → 1 Whisky
- Godwyn bonus: +£3
- Remaining: 2 Grain, 1 Whisky

**Aging**:
- Move 1 Whisky to cellar Slot 1
- Final: 2 Grain, 0 Whisky in stock, 1 in cellar

## Production Phase - Round 2

**Production**:
- 2 Fields → 2 Grain
- Total: 4 Grain

**Processing**:
- Distillery: 1 Grain → 1 Whisky
- Godwyn bonus: +£3
- State: 3 Grain, 1 Whisky

**Aging**:
- Slot 1 → Slot 2 (1-year aged)
- Move fresh Whisky → Slot 1
- Final: 3 Grain, cellar [Slot 1: fresh, Slot 2: 1-year]

## Production Phase - Round 3

**Production**:
- 2 Fields → 2 Grain
- Total: 5 Grain

**Processing**:
- Distillery: 1 Grain → 1 Whisky
- Godwyn bonus: +£3
- State: 4 Grain, 1 Whisky

**Aging**:
- Slot 2 (2-year) → Stock: +£15 bonus
- Slot 1 → Slot 2
- Fresh Whisky → Slot 1
- Final: 4 Grain, 1 Whisky (2-year aged), cellar continues

**Total earned this round**: £3 (production) + £15 (aged) = £18
