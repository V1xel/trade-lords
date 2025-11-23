# Resources Module

## Overview

Resources are goods produced by units, traded on the market, and used to fulfill export contracts. Resources are the core economic element of Trade Lords.

## Resource Categories

### Basic Goods (Produced by Units)
- **Wool** - From Sheep
- **Milk** - From Cows
- **Grain** - From Fields

### Processed Goods (From Processing Buildings)
- **Cheese** - From Milk (Cheese Dairy)
- **Bread** - From Grain (Bakery)
- **Whisky** - From Grain (Distillery)
- **Beer** - From Grain (Brewery, Oswald only)

### Import Goods (From Contracts)
- **Cotton** - From export contracts
- **Tobacco** - From export contracts
- **Sugar Cane** - From export contracts
- **Hops** - From export contracts

## Resource Properties

### Production
- Basic goods: Produced by units each Production Phase
- Processed goods: Converted from basic goods in processing buildings
- Import goods: Rewards from certain export contracts

### Storage
- Players have unlimited storage
- Resources accumulate in player's stock
- Tracked per resource type

### Uses
1. **Market Trading**: Buy/sell for gold
2. **Export Contracts**: Fulfill contract requirements
3. **Processing**: Basic → Processed goods
4. **Victory Points**: Worth VPs at end of game

## File Structure

```
Resources/
├── README.md (this file)
├── Wool.md
├── Milk.md
├── Grain.md
├── Cheese.md
├── Bread.md
├── Whisky.md
├── Beer.md
└── ImportGoods.md
```

## Resource Values

### Contract Value
- Basic goods: 1 VP each (end game)
- Processed goods: 2 VP each (end game)
- Import goods: 3-5 VP each (varies)

### Market Value
- Dynamic (changes based on trading)
- Buying raises price
- Selling lowers price
- See Market module for details

## Game States

### Player Resource Stock
```
{
  wool: number,
  milk: number,
  grain: number,
  cheese: number,
  bread: number,
  whisky: number,
  beer: number,
  cotton: number,
  tobacco: number,
  sugar_cane: number,
  hops: number
}
```

### Per Production Phase
- Units produce basic goods
- Processing buildings convert basic → processed
- Resources added to stock

## Production Chains

### Wool Chain
```
Sheep → Wool (direct use)
```

### Dairy Chain
```
Cow → Milk → Cheese Dairy → Cheese
```

### Grain Chains
```
Field → Grain → Bakery → Bread
Field → Grain → Distillery → Whisky
Field → Grain → Brewery → Beer (Oswald)
```

### Import Chain
```
Export Contract → Import Goods (reward)
```

## Resource Flow

**Production Phase**:
1. Production units create basic goods
2. Processing buildings convert (optional)
3. Resources added to stock

**Action Phase**:
- Trade resources on market
- Use resources for contracts
- Accumulate for end game

**End Game**:
- Convert resources to VPs
- Basic: 1 VP each
- Processed: 2 VP each
- Import: 3-5 VP each
