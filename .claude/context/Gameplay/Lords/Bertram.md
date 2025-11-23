# Sir Bertram the Builder

## Identity

**Name**: Sir Bertram the Builder
**Title**: Master of Works
**House Colors**: Grey & Blue
**Archetype**: Factory Efficiency Specialist

## Appearance

Sturdy nobleman with builder's tools at belt, architectural plans under arm, mason's apron over fine blue clothes.

## Background

Renowned architect and engineer who revolutionized factory design. Rose to lordship through innovation and efficiency.

## Ability: "Efficient Construction"

### Mechanics

**Factory Cost Reduction**:
Factories cost less based on how many of that type you've already built:

- **1st factory** of each type: £3 discount
- **2nd factory** of each type: £4 discount
- **3rd factory** of each type: £4 discount
- **4th factory** of each type: £5 discount

**Factory Types** (tracked separately):
- Cheese Dairy
- Bakery
- Distillery
- Brewery (if playing Oswald variant rules)

**Calculation**:
```
Final Cost = (Base Factory Cost + Terrain Cost) - Discount
```

### Game States Modified

**Player State**:
- `cheese_dairies_built: 0`
- `bakeries_built: 0`
- `distilleries_built: 0`
- Track count per factory type

**Factory Placement**:
- Apply discount based on count
- Increment count after placement

### Examples

**Example 1: Building Dairies**
- Cheese Dairy base cost: £6
- 1st Dairy on £2 terrain: (£6 + £2) - £3 = £5 total
- 2nd Dairy on £3 terrain: (£6 + £3) - £4 = £5 total
- 3rd Dairy on £2 terrain: (£6 + £2) - £4 = £4 total
- 4th Dairy on £3 terrain: (£6 + £3) - £5 = £4 total

**Example 2: Mixed Factories**
- 1st Bakery: £3 discount
- 1st Dairy: £3 discount (separate counter)
- 2nd Bakery: £4 discount
- 1st Distillery: £3 discount (separate counter)

**Example 3: Discount Progression**
```
Bakeries Built: 0 → 1 → 2 → 3 → 4
Next Discount:  £3  £4  £4  £5  £5 (stays at £5)
```

### Clarifications

**"Each Type" Means**:
- Counters are separate per factory type
- Building a Bakery doesn't affect Dairy discount
- Each factory type has its own progression

**Maximum Discount**:
- 5th+ factory of same type: £5 discount (caps here)

**Applies To**:
- Only processing buildings (factories)
- Does NOT apply to: Sheep, Cows, Fields, Workers

## Strategy

### Strengths
- Cheap factory expansion
- Multiple factories = high production
- Scales into late game
- Flexible production chains

### Weaknesses
- Needs raw materials (Sheep, Cows, Fields)
- Factory-heavy build is slow start
- Requires diverse terrain
- Initial factories still expensive

### Playstyle

**Early Game**:
- Build 1-2 factories to start discount progression
- Establish raw material production
- Accept slower start for mid-game power

**Mid Game**:
- Aggressive factory building (2nd-4th of each type)
- Massive cost savings kick in
- Out-produce opponents
- Fulfill processing-heavy contracts

**Late Game**:
- Factory empire fully operational
- Cheap factories = easy expansion
- High production volume
- Convert goods to victory points

### Key Decisions
- **Which Factories**: Specialize or diversify?
- **Timing**: When to build 2nd/3rd of same type?
- **Terrain**: Balance cheap terrain vs factory placement

### Build Strategies

**Strategy 1: Specialization**
- Focus on one factory type (e.g., 4 Distilleries)
- Maximum discount efficiency
- Requires lots of one raw material
- Vulnerable to market/contract availability

**Strategy 2: Diversification**
- Build 2 of each factory type
- Balanced production
- Flexible contract fulfillment
- Moderate discount efficiency

**Strategy 3: Hybrid**
- 3-4 of primary factory
- 1-2 of secondary factories
- Balanced power and flexibility

### Synergies
- Benefits from terrain variety
- Strong with grain production (can make Bread OR Whisky)
- Complements contract strategies

### Counters
- Limited grassland access
- Opponents blocking factory placement
- Raw material shortages

## Starting Resources

- **Gold**: £6
- **Units**:
  - 1 Cheese Dairy
  - 1 Cow
  - 1 Worker (Miner)
- **Merchants**: 2
- **Shipping**: 0 (none)

## Difficulty

**Complexity**: Intermediate
**Reason**: Requires planning factory progression, balancing raw materials with processing

## Victory Paths

1. **Factory Empire**: Maximize factories, high production volume
2. **Specialist**: 4+ of one factory type, dominate one processing chain
3. **Balanced Producer**: 2-3 of each type, fulfill diverse contracts

## Cost Savings Table

| Factory # | Discount | Savings vs Standard |
|-----------|----------|---------------------|
| 1st | -£3 | £3 |
| 2nd | -£4 | £7 total |
| 3rd | -£4 | £11 total |
| 4th | -£5 | £16 total |

Building 4 factories of one type saves £16 compared to standard lord!
