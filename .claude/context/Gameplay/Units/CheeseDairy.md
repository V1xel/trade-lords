# Cheese Dairy

## Overview

Cheese Dairy is a processing building that converts Milk into Cheese. Essential for dairy production chains.

## Properties

**Type**: Processing Building (Factory)
**Cost**: £6
**Terrain**: Grassland only
**Processing**: 1 Milk → 1 Cheese per Production Phase

## Placement

### Requirements
- Grassland terrain hex
- Adjacent to owned unit OR shipping range
- Pay £6 (unit) + terrain cost

### Examples
- Cheese Dairy on £2 grassland = £8 total
- Cheese Dairy on £5 mixed = £11 total

## Processing

### Production Phase Processing
- Requires 1 Milk in stock
- Converts 1 Milk → 1 Cheese
- Cheese added to stock
- Can process multiple if have multiple Dairies

### Optional Processing
- Processing is optional
- Can keep Milk instead of converting
- Flexible resource management

### Multiple Dairies
- Each Dairy processes 1 Milk → 1 Cheese
- 3 Dairies + 3 Milk = 3 Cheese

## Strategic Use

### Dairy Chain
```
Cow → Milk → Cheese Dairy → Cheese
```

Complete chain requires:
- Cows (produce Milk)
- Cheese Dairies (process Milk)
- Adjacent grassland for both

### Value Proposition
- Cheese worth more than Milk
- Higher contract rewards
- Better victory point conversion

## Lord Synergies

### Sir Bertram (Strong)
- 1st Cheese Dairy: £3 discount (£3 total)
- 2nd Cheese Dairy: £4 discount (£2 total)
- 3rd Cheese Dairy: £4 discount (£2 total)
- Can build cheap dairy empire

### Dame Elspeth
- Starts with 1 Cheese Dairy
- Dairy specialist
- Can balance Cheese vs Milk sales

### Starting Resources
- **Dame Elspeth**: Starts with 1 Cheese Dairy + 2 Cows
- **Sir Bertram**: Starts with 1 Cheese Dairy + 1 Cow

## Processing Buildings Comparison

| Building | Input | Output | Specialists |
|----------|-------|--------|-------------|
| Cheese Dairy | Milk | Cheese | Elspeth, Bertram |
| Bakery | Grain | Bread | Bertram |
| Distillery | Grain | Whisky | Godwyn, Bertram |
| Brewery | Grain | Beer | Oswald, Bertram |

## Game States

### Unit State
- Owner
- Location (hex)
- Type: Cheese Dairy

### Per Production Phase
- Check Milk in stock
- If Milk available: Convert 1 Milk → 1 Cheese
- If no Milk: No production

### Processing Limit
- 1 Dairy processes max 1 Milk per round
- Need multiple Dairies for multiple Milk

## Common Patterns

### Balanced Dairy (1:1 ratio)
- 2 Cows + 2 Cheese Dairies
- 2 Milk produced
- 2 Milk → 2 Cheese converted
- Efficient chain

### Milk Surplus
- 4 Cows + 2 Cheese Dairies
- 4 Milk produced
- 2 Milk → Cheese, 2 Milk kept/sold
- Flexible allocation

### Dairy Surplus
- 2 Cows + 4 Cheese Dairies
- 2 Milk produced
- Only 2 of 4 Dairies used
- Inefficient (over-investment)

## Economic Calculation

**Dairy Investment**:
- £6 (Dairy) + £3 (terrain) = £9
- Requires Milk input
- Produces 1 Cheese per round (if have Milk)

**Full Chain**:
- 1 Cow (£8) + 1 Dairy (£9) = £17 total
- Produces 1 Cheese per round
- Cheese contract value: High

**Multiple Dairies** (Sir Bertram):
- 1st Dairy: £6 - £3 = £3
- 2nd Dairy: £6 - £4 = £2
- 3rd Dairy: £6 - £4 = £2
- Total for 3: £7 (vs £18 standard)
- Massive savings

## Strategy Decisions

### When to Build Cheese Dairies
- Have Cows producing Milk
- Cheese contracts available
- Want higher value than Milk
- Sir Bertram (cheap dairies)

### How Many to Build
- Match to Cow count (1:1 ratio ideal)
- Slightly fewer if selling some Milk
- Sir Bertram can overbuild cheaply

### When to Skip
- No Cows
- Dame Elspeth selling Milk for £8
- Limited grassland
- Focus on other chains

## Processing Priority

**Cheese vs Selling Milk** (Dame Elspeth):

**Sell Milk**:
- Immediate £8 per Milk
- No factory investment
- Simple economics

**Process to Cheese**:
- Requires Dairy investment
- Higher contract value
- Better for victory points
- Delayed payoff

**Optimal Strategy**:
- Early game: Sell Milk for £8 (need gold)
- Mid game: Build Dairies, process to Cheese
- Late game: Cheese for contracts/VPs

## Terrain Efficiency

**Dairy + Cow Adjacency**:
- Place Cow and Dairy on adjacent grassland
- Efficient territory use
- Compact dairy farm

**Example Layout**:
```
[Cow] - [Cow]
  |       |
[Dairy] - [Dairy]
```
4 hexes = 2 Cheese per round
