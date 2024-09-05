## BaseUnit (abstract class)
- ID
- Type
- Position (x;y)
- Characteristics: UnitCharacteristic[ ... ]
- Actions: Action[ ... ]
- Actions priority (vector)
- Timestamp

Examples:
* Warrior : BaseUnit (class)
* Archer : BaseUnit (class)
* ...

## UnitCharacteristic (enum):
- HP
- Strength
- Range
- Agility

## Action (class)
- Name
- Characteristics (map)

Examples:
* Action "Move"
    * Characteristics:
        * Target point : (1, 2)

* Action "Melee Attack":
    * Characteristics:
        * Radius: 1 

* Action "Range Attack":
    * Characteristics: 
        * Radius: 2
        * Range: 10


## Map (class)
- Height
- Width