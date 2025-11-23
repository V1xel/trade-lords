# Brewmaster Oswald the Bold

## Identity

**Name**: Brewmaster Oswald the Bold
**Title**: Lord of the Brewhouses
**House Colors**: Gold & Hops Green
**Archetype**: Beer Production Specialist

## Appearance

Jovial stout nobleman with ale-stained vest, hop garland crown, carries ceremonial brewing paddle.

## Background

Turned his family's humble brewery into a noble house through exceptional quality and innovation. Claims ale is more important than wine at any feast.

## Ability: "Master Brewer"

### Mechanics

**Beer Production**:
- Has access to **Brewery** building (unique to Oswald)
- Brewery: Grain → Beer (processing building)
- Beer is an alternative to Bread/Whisky from Grain

**Brewery Properties**:
- Cost: £6 (same as other factories)
- Placement: Grassland terrain (like other factories)
- Production: 1 Grain → 1 Beer per Production Phase

**Beer Advantages** (one or more):

**Option A: Enhanced Market Value**
- Beer sells for higher base price than Bread
- Market demand for Beer is higher
- Beer price more stable (less volatility)

**Option B: Production Bonus**
- Gains £2 per Beer produced during Production Phase
- Similar to Godwyn's Whisky bonus

**Option C: Special Contracts**
- Unique contracts requiring Beer (unavailable to other lords)
- Beer contracts offer premium rewards
- Beer worth more VP in contracts than Bread

**Option D: Combination**
- Mix of above bonuses (balanced)

### Game States Modified

**Player State**:
- `breweries_count: number`
- `beer_in_stock: number`

**Production Phase**:
- Breweries produce Beer from Grain
- Apply production bonus if applicable

**Market**:
- Beer as tradeable resource
- Separate from Bread/Whisky

**Contracts**:
- Beer contracts available (Oswald only or all players)

### Examples

**Example 1: Basic Beer Production**
- Own 1 Brewery + 2 Fields
- Production Phase:
  - Fields produce 2 Grain
  - Brewery converts 1 Grain → 1 Beer
  - Remaining: 1 Grain, 1 Beer

**Example 2: Production Bonus (Option B)**
- Own 2 Breweries, produce 2 Beer
- Gain £4 bonus (£2 × 2 Beer)
- Similar to Godwyn's Whisky mechanic

**Example 3: Grain Allocation**
- Have 3 Grain
- Options:
  - 3 Grain → 3 Beer (Breweries)
  - 2 Grain → 2 Bread (Bakery) + 1 Grain → 1 Beer (Brewery)
  - 3 Grain → 3 Whisky (Distilleries)
- Oswald has Beer option, others don't

**Example 4: Contract Fulfillment**
- Beer contract: "Deliver 3 Beer, reward: £15 + 5 VP"
- Oswald can fulfill
- Other lords cannot (no Beer access)
- Exclusive scoring opportunity

## Strategy

### Strengths
- Unique resource (Beer) provides niche
- Grain versatility (Beer OR Bread/Whisky)
- Potential exclusive contracts
- Production bonus if Option B
- Market advantage if Option A

### Weaknesses
- Requires Grain infrastructure
- Brewery investment needed
- Grain competition with other uses
- Ability value depends on Beer implementation

### Playstyle

**Early Game**:
- Build Fields for Grain production
- Establish 1-2 Breweries
- Start Beer production
- Evaluate Beer market/contracts

**Mid Game**:
- Expand Brewery network
- Balance Beer vs Bread/Whisky production
- Pursue Beer contracts if available
- Leverage production bonuses

**Late Game**:
- Maximize Beer production
- Fulfill Beer contracts
- Convert Beer to victory points
- Maintain production advantage

### Key Decisions
- **Grain Allocation**: Beer vs Bread vs Whisky?
- **Brewery Count**: How many Breweries to build?
- **Market Timing**: When to sell Beer?
- **Contract Priority**: Beer contracts vs other contracts?

### Grain Production Chain

**Oswald's Options**:
```
Grain → Brewery → Beer (Oswald special)
Grain → Bakery → Bread (standard)
Grain → Distillery → Whisky (standard)
```

**Strategic Flexibility**:
- Can pivot between Beer/Bread/Whisky
- Adapt to market demand
- Respond to contract availability
- Cover multiple production niches

### Synergies
- Benefits from Grain production (Fields)
- Strong with Bertram (cheap Breweries)
- Complements contract strategies
- Pairs with market trading

### Counters
- Limited Grassland access
- Opponents blocking Field placement
- Grain scarcity
- Beer market/contract unavailability

## Starting Resources

- **Gold**: £9
- **Units**:
  - 1 Brewery
  - 2 Fields
- **Resources**: 1 Grain
- **Merchants**: 2
- **Shipping**: 0 (none)

## Difficulty

**Complexity**: Intermediate
**Reason**: Requires understanding Beer vs Bread/Whisky trade-offs, Grain management, contract evaluation

## Victory Paths

1. **Beer Empire**: Maximize Breweries, dominate Beer production, fulfill Beer contracts
2. **Grain Versatility**: Balance Beer/Bread/Whisky, adapt to demand
3. **Production Bonus**: High-volume Beer production for bonus gold (if Option B)

## Beer vs Other Processed Goods

**Comparison** (assuming Option A: Market Advantage):
| Good | Base Value | Market Volatility | Contract Demand |
|------|-----------|-------------------|-----------------|
| Bread | Standard | Medium | Common |
| Whisky | High | Medium | Common |
| Beer | High | Low | Special (Oswald) |

**Comparison** (assuming Option B: Production Bonus):
| Good | Production Bonus |
|------|------------------|
| Bread | £0 |
| Whisky | £3 (Godwyn only) |
| Beer | £2 (Oswald only) |

**Comparison** (assuming Option C: Contract Focus):
- Beer contracts: Oswald exclusive, premium rewards
- Standard contracts: Available to all
- Oswald has access to both

## Design Notes

**Beer Implementation** depends on game balance:
- **Conservative**: Beer = Bread equivalent, Oswald just has theme variety
- **Moderate**: Beer has minor advantages (£2 bonus or +1 market value)
- **Strong**: Beer has exclusive contracts + production bonus

**Recommended Balance**:
- Option D (Combination):
  - Small production bonus (£1-£2 per Beer)
  - Occasional Beer-specific contracts
  - Slightly better market stability
  - Total advantage similar to other lords' bonuses

## Production Calculation

**Per Round** (with 2 Breweries, 2 Fields):
- Produce 2 Grain (Fields)
- Convert 2 Grain → 2 Beer (Breweries)
- Bonus: £4 (if Option B, £2 × 2)
- Market/Contract value: Variable

**Scaling** (4 Breweries, 4 Fields):
- Produce 4 Grain
- Convert 4 Grain → 4 Beer
- Bonus: £8 per round
- High production volume

**Compared to Godwyn** (Whisky specialist):
- Godwyn: £3 per Whisky + aging bonuses (£7-£15)
- Oswald: £2 per Beer (if Option B)
- Godwyn higher ceiling, Oswald more stable
