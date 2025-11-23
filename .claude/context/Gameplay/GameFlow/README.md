# Game Flow

## Game Structure

**5 Rounds Total**

Each round has 3 phases:
1. Action Phase
2. Production Phase
3. Scoring Phase

## Setup Phase

1. Assemble map (4 modules, random sides)
2. Determine turn order (random)
3. Lord selection (reverse turn order, choose from player_count + 1 lords)
4. Place starting units
5. Receive starting resources per lord

## Action Phase

### Turn Order
- Players take turns in established order
- One action per turn
- Continue until all players pass

### Actions
- **Expand**: Place unit, pay unit cost + terrain cost - discounts
- **Trade**: Buy/sell resource, uses 1 merchant
- **Take Contract**: Pay round cost, take contract from pool
- **Fulfill Contract**: Deliver goods, receive rewards
- **Upgrade Shipping**: Pay £4, +1 shipping level
- **Upgrade**: Upgrade worker/factory
- **Pass**: Exit phase, receive passing bonus

### Passing
- Cannot act after passing
- Passing bonus awarded (gold or resources)
- First to pass may receive better bonus

### Merchant State
- Available merchants: 2-6
- Used merchants unavailable until next round
- Refresh at round start

## Production Phase

### Production Sequence
1. Production units generate resources
2. Workers generate income
3. Processing buildings convert (optional)
4. Lord abilities trigger

### Production Units
- Sheep → 1 Wool
- Cow → 1 Milk
- Field → 1 Grain

### Workers
- Woodcutter → £4 (£6 upgraded)
- Miner → £6 (£8 upgraded)
- Fisherman → £4 (Caspian)

### Processing (Optional)
- Cheese Dairy: 1 Milk → 1 Cheese
- Bakery: 1 Grain → 1 Bread
- Distillery: 1 Grain → 1 Whisky
- Brewery: 1 Grain → 1 Beer (Oswald)

### Lord Triggers
- Godwyn: £3 per Whisky, aging advances
- Oswald: Beer bonuses
- Isolde: £1 per trade (action phase)

## Scoring Phase

Round-specific scoring tile:
- Criteria varies (most Whisky, most contracts, etc.)
- Award glory points: 1st=3, 2nd=2, 3rd=1
- Glory = VP

## Round Transition

1. Refresh merchants
2. Increment round counter
3. Update contract costs
4. Begin next round

## End Game

After Round 5 Scoring Phase:
1. Calculate final VP
2. Determine winner

## Game State

```
{
  round: 1-5,
  phase: "action" | "production" | "scoring",
  turn_order: [player_ids],
  active_player: player_id,
  passed_players: [player_ids],
  contract_cost: £3-£8
}
```
