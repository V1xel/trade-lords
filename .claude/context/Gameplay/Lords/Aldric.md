# Lord Aldric the Negotiator

## Identity

**Name**: Lord Aldric the Negotiator
**Title**: Master of Writs
**House Colors**: Black & Gold
**Archetype**: Contract Specialist

## Appearance

Distinguished nobleman in black and gold robes, multiple sealed scrolls at belt, quill pen, signet rings on both hands.

## Background

Former royal chancellor who left court politics to build a merchant empire. Expert in trade agreements and legal negotiations.

## Ability: "Dual Contracts"

### Mechanics

**Contract Slots**:
- Has 2 contract slots (instead of standard 1)
- Can hold 2 unfulfilled contracts simultaneously

**Taking Contracts**:
- Can take 1 contract (normal action)
- Can take 2 contracts in a single action
- When taking 2 contracts in one action: pays the round cost only once

**Rules**:
- Exception to the "1 unfulfilled contract" limit
- Each contract must still be fulfilled separately
- Cannot take more than 2 contracts total

### Game States Modified

**Player State**:
- `max_contracts: 2` (default is 1)
- `unfulfilled_contracts: [contract_1, contract_2]`

**Action Options**:
- "Take Contract" (normal)
- "Take 2 Contracts" (special, Aldric only)

### Examples

**Example 1: Taking Two Contracts**
- Round 2, contract cost is £4
- Aldric takes "Take 2 Contracts" action
- Pays £4 once (not £8)
- Now has 2 unfulfilled contracts

**Example 2: Sequential Contracts**
- Aldric has 1 unfulfilled contract
- Takes "Take Contract" action
- Now has 2 unfulfilled contracts
- Cannot take more until one is fulfilled

**Example 3: Fulfilling**
- Aldric has 2 unfulfilled contracts
- Fulfills contract A
- Now has 1 unfulfilled contract
- Can take another contract

## Strategy

### Strengths
- Flexible strategy (pursue multiple production chains)
- Can adapt to available contracts
- High scoring potential from contracts
- Economic efficiency (one cost for two contracts)

### Weaknesses
- Requires diverse production to fulfill multiple contracts
- Resource intensive
- Complex resource management
- High risk if contracts don't align

### Playstyle

**Early Game**:
- Grab two contracts round 1-2 when costs are low
- Build production for both contract types
- Establish diverse economy

**Mid Game**:
- Fulfill first contracts
- Take new contracts to maintain dual pursuit
- Balance production vs fulfillment

**Late Game**:
- Maximize contract completion
- High VP from fulfilled contracts
- Convert remaining resources to contracts

### Synergies
- Benefits from diverse terrain access
- Strong with factory-focused builds
- Pairs well with versatile production units

### Counters
- Limited terrain types hurt flexibility
- Opponents taking desired contracts first
- Resource scarcity from multiple demands

## Starting Resources

- **Gold**: £10
- **Units**:
  - 1 Sheep
  - 1 Field
  - 1 Worker (Woodcutter)
- **Merchants**: 2
- **Shipping**: 0 (none)

## Difficulty

**Complexity**: Advanced
**Reason**: Requires long-term planning, resource juggling, contract evaluation

## Victory Paths

1. **Contract Rush**: Maximize contracts fulfilled (high VP)
2. **Efficient Economy**: Use saved gold from dual contracts for expansion
3. **Opportunistic**: Adapt to contract availability each round
