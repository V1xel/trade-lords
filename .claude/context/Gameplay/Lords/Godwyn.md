# Master Godwyn the Distiller

## Identity

**Name**: Master Godwyn the Distiller
**Title**: Keeper of the Cellars
**House Colors**: Deep Amber & Brown
**Archetype**: Whisky Production Specialist

## Appearance

Portly middle-aged man with well-kept beard, fine merchant clothes in amber tones, carries ornate cellar keys on golden chain.

## Background

Third-generation master distiller from highland estates. His family's secret aging techniques produce the finest whisky in the realm.

## Ability: "Ancient Cellars"

### Mechanics

**Production Bonus**:
- During Production Phase: Gain £3 for each Whisky produced

**Aging Cellar**:
- Has special aging cellar with 2 slots: [Slot 1] [Slot 2]
- Each Production Phase, whisky in cellar ages (moves right one slot)
- When moving whisky from cellar to stock:
  - From Slot 1: Gain £7
  - From Slot 2: Gain £15

**Cellar Management**:
- Player chooses when to move whisky from production to cellar
- Player chooses when to move aged whisky from cellar to stock
- Cellar slots are not mandatory (can sell whisky fresh)

### Game States Modified

**Player State**:
- `aging_cellar: [slot_1, slot_2]`
- Each slot contains: `{whisky_count, age}`
- Special production bonus tracker

**Production Phase**:
- Standard whisky production +£3 per whisky
- Age increment for whisky in cellar
- Option to move whisky to/from cellar

### Detailed Flow

**Production Phase Sequence for Godwyn**:
1. Produce whisky from distilleries (as normal)
2. Gain £3 per whisky produced (ability)
3. Age cellar whisky (move from Slot 1→Slot 2, clear Slot 1)
4. Choose: Move fresh whisky to cellar Slot 1
5. Choose: Move aged whisky from cellar to stock (gain £7 or £15)

### Examples

**Example 1: Basic Aging**
- Production Phase
- Produce 2 Whisky from distilleries
- Gain £6 (£3 × 2)
- Move 1 Whisky to Cellar Slot 1
- Keep 1 Whisky in stock

**Example 2: Aging Cycle**
- Round 1: Place 1 Whisky in Slot 1
- Round 2: Whisky ages to Slot 2, place new Whisky in Slot 1
- Round 3:
  - Slot 2 whisky is 2-year aged
  - Move Slot 2→Stock, gain £15
  - Slot 1→Slot 2
  - Place new in Slot 1

**Example 3: Decision Making**
- Have 1 Whisky in Slot 2 (worth £15 if moved)
- Contract needs Whisky this turn
- Options:
  - Move aged Whisky to stock (gain £15), use for contract
  - Produce fresh Whisky, save aged for later

## Strategy

### Strengths
- Massive late-game gold generation
- Each aged whisky worth £15 + base value
- Compound growth (more distilleries = more aging)
- Flexible timing on cashing out aged whisky

### Weaknesses
- Slow start (need time to age)
- Requires grain production infrastructure
- Distilleries are expensive
- Delayed payoff

### Playstyle

**Early Game**:
- Build distilleries and fields ASAP
- Start aging immediately
- Accept lower early income for late power

**Mid Game**:
- Expand distillery network
- Keep aging pipeline full
- Begin cashing out 1-year aged (£7)

**Late Game**:
- Harvest 2-year aged (£15) repeatedly
- Dominant economy
- Convert gold to victory points

### Key Decisions
- **Sell or Age?**: Fresh whisky for immediate gold vs cellar for future bonus
- **1-year or 2-year?**: Cash out Slot 1 (£7) or wait for Slot 2 (£15)?
- **Contract Timing**: Use aged whisky for contracts or keep aging?

### Synergies
- Grain-producing lords benefit
- Contracts requiring whisky
- Market demand for whisky

### Counters
- Early game aggression
- Limited grassland terrain
- Opponents blocking distillery locations

## Starting Resources

- **Gold**: £8
- **Units**:
  - 1 Distillery
  - 2 Fields
- **Resources**: 1 Grain
- **Merchants**: 2
- **Shipping**: 0 (none)
- **Special**: Aging cellar (2 slots, empty)

## Difficulty

**Complexity**: Advanced
**Reason**: Requires long-term planning, timing decisions, resource pipeline management

## Victory Paths

1. **Aging Engine**: Maximize distilleries, constant aging, economic dominance
2. **Hybrid**: Balance fresh sales with aging for steady income
3. **Contract Focused**: Use aged whisky for high-value whisky contracts

## Timing Table

| Round | Fresh Whisky | 1-Year (Slot 1) | 2-Year (Slot 2) |
|-------|--------------|-----------------|-----------------|
| Value | Base | Base +£7 | Base +£15 |
| Turn 1 | Produce | - | - |
| Turn 2 | Produce | Available | - |
| Turn 3+ | Produce | Available | Available |
