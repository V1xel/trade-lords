# Bakery

## Overview

Bakery is a processing building that converts Grain into Bread. Most common grain processing option.

## Properties

**Type**: Processing Building (Factory)
**Cost**: £6
**Terrain**: Grassland only
**Processing**: 1 Grain → 1 Bread per Production Phase

## Placement

### Requirements
- Grassland terrain hex
- Adjacent to owned unit OR shipping range
- Pay £6 (unit) + terrain cost

### Examples
- Bakery on £2 grassland = £8 total
- Bakery on £5 mixed = £11 total

## Processing

### Production Phase Processing
- Requires 1 Grain in stock
- Converts 1 Grain → 1 Bread
- Bread added to stock
- Optional (can keep Grain)

### Multiple Bakeries
- Each Bakery processes 1 Grain
- 2 Bakeries + 2 Grain = 2 Bread

## Strategic Use

### Bread Chain
```
Field → Grain → Bakery → Bread
```

### Grain Allocation
With multiple processors:
- Bakery: Grain → Bread
- Distillery: Grain → Whisky
- Brewery: Grain → Beer (Oswald)

Player chooses allocation each round

## Lord Synergies

### Sir Bertram (Strong)
- 1st Bakery: £3 discount
- 2nd Bakery: £4 discount
- 3rd Bakery: £4 discount
- Cheap factory construction

### All Lords
- Standard processing option
- No special bonuses (unlike Godwyn/Whisky or Oswald/Beer)

## Comparison

| Grain Processor | Output | Specialists | Value |
|-----------------|--------|-------------|-------|
| Bakery | Bread | None | Standard |
| Distillery | Whisky | Godwyn | High |
| Brewery | Beer | Oswald | Special |

**Bakery Position**:
- Default grain processor
- No specialist bonuses
- Moderate contract value
- Reliable option

## Game States

### Unit State
- Owner
- Location (hex)
- Type: Bakery

### Per Production Phase
- Check Grain in stock
- If Grain available: Convert 1 Grain → 1 Bread
- If no Grain: No production

## Common Patterns

### Balanced Grain Production
- 2 Fields + 1 Bakery + 1 Distillery
- 2 Grain produced
- 1 → Bread, 1 → Whisky
- Diversified output

### Bread Focus
- 3 Fields + 3 Bakeries
- 3 Grain → 3 Bread
- Simple, consistent production

### Mixed Processing
- 4 Fields + 1 Bakery + 1 Distillery + 1 Brewery
- 4 Grain allocated based on needs
- Maximum flexibility

## Economic Calculation

**Bakery Investment**:
- £6 (Bakery) + £3 (terrain) = £9
- Requires Grain input
- Produces 1 Bread per round

**Full Chain**:
- 1 Field (£6) + 1 Bakery (£9) = £15 total
- Produces 1 Bread per round
- Bread contract value: Moderate

**Sir Bertram Discount**:
- 1st Bakery: £3 total (vs £9)
- Build cheap Bakery early
- Efficient bread production

## Strategy Decisions

### When to Build Bakeries
- Have Fields producing Grain
- Bread contracts available
- No specialist bonuses elsewhere
- Need reliable processing

### Bakery vs Distillery
**Bakery**:
- Standard value
- No special bonuses
- Safe choice

**Distillery**:
- Higher value (Whisky > Bread)
- Godwyn bonus (£3 per Whisky)
- Premium contracts

**Usually prefer Distillery** unless:
- Bread-specific contracts
- Godwyn not in game
- Bertram discount makes Bakery cheap

### Bakery vs Brewery (if Oswald available)
- Brewery unique to Oswald
- Beer has special bonuses
- Bakery is fallback

## Processing Priority

**Grain Allocation** (with all options):
1. Brewery (if Oswald, special bonuses)
2. Distillery (higher value, Godwyn bonus)
3. Bakery (standard option)

**When Bakery is Best**:
- Bread contracts worth more this round
- Out of other processors
- Bertram discount makes it cheapest

## Terrain Efficiency

**Field + Bakery Layout**:
```
[Field] - [Field]
   |         |
[Bakery] - [Other]
```
Compact grain processing area

## Sir Bertram Bakery Strategy

**Bertram's Advantage**:
- 1st Bakery: £3
- 2nd Bakery: £2
- 3rd Bakery: £2
- Can build 3 Bakeries for £7 total (vs £18)

**Mass Bakery Build**:
- 4 Fields + 3 Bakeries
- 3-4 Bread per round
- Cheap investment
- Bread contract specialist
