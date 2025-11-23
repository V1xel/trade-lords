# Hex Grid System

## Map Construction

### Modular System
- 4 double-sided modules (A, B, C, D)
- Each module has 2 sides (side 1, side 2)
- Creates 16 different configurations (2^4)

### Module Selection
1. Randomly choose side for each module (1 or 2)
2. Arrange modules with letters in alphabetical order
3. Modules placed clockwise

## Hex Properties

### Geometry
- Regular hexagon (6 sides)
- Each hex has 6 adjacent hexes (edge neighbors)
- No diagonal adjacency (corner touching ≠ adjacent)

### Adjacency Pattern
```
    [A]
 [B] [X] [C]
    [D]
```
Hex X is adjacent to A, B, C, D (shares edges)

## Hex Features

### Terrain Content
Each hex contains 1-3 terrain types:
- Single: Grassland, Forest, Mountain, or Loch
- Mixed: 2-3 terrain types combined

### Placement Cost
- Single terrain: £1-£3
- Mixed terrain: £4-£6
- Printed on hex tile

### Hex State Properties
- Occupant (unit placed here)
- Owner (player)
- Terrain types (list)
- Cost (£1-£6)
- Is river delta (boolean)

## Adjacency Rules

### Direct Adjacency
- Units adjacent to owned units
- Adjacent = shares hex edge
- Used for expansion without shipping

### Shipping Adjacency
- Can place across water hexes
- Requires shipping level
- Distance measured in hex steps

### Isolation
- Cannot place in isolated hexes
- Must maintain connection to owned territory

## River System

### River as Edge Feature
- Rivers run along hex edges (not through centers)
- Creates natural boundaries

### River Crossing
- Without shipping: Cannot cross rivers
- With river-crossing shipping: Can cross rivers

### River Deltas
**Definition**: Hex adjacent to both river and loch

**Identification**:
- Land hex
- Has river edge
- Adjacent to loch hex

**Game Effect**:
- Marina gets £2-£3 discount

## Loch (Lake) Hexes

### Properties
- Water hexes
- Impassable (except Caspian's Fishermen)
- Require shipping to cross
- Create spatial barriers

## Special Hex Types

### Mixed Terrain Hex
- Contains 2-3 terrain types
- Allows multiple unit types
- Higher placement cost (£4-£6)
- Flexible strategic value

## Map Setup

### Game Setup Sequence
1. Randomly select module sides
2. Assemble map in alphabetical order
3. Identify river deltas
4. Determine starting positions

### Starting Positions
- Each player chooses starting area
- Different map quadrants
- Selection in reverse turn order

## Expansion Patterns

### Compact
- Build in tight cluster
- Low shipping need
- Limited terrain variety

### Linear
- Follow terrain band
- Specialized production

### Hub
- Central position with branches
- Balanced approach

### Wide
- Span map
- Requires shipping
- Diverse terrain access

## Distance

### Hex Distance
- Measured in hex steps
- Minimum hexes to traverse
- Used for shipping range

### Calculation
Distance = minimum hex steps between two hexes
