# 1.0

## Artifacts

### Type Randomization
- Many artifacts have semi-randomized object types.
  - The randomized object type must have a similar damage
    type to the original type of the artifact. For example,
    Sunsword cannot be a mace.
  - The brands are always the same type.

## Commands

### \#trip: Trip a monster.
- Tripping traditionally uses one's lower body, but polearms,
  whips, and flails can be used to trip as well.
- Being tripped puts one into a downed state. Until one moves
  to a different location, AC and to-hit are reduced.
- Select monsters or monsters wielding tripping weapons will
  sometimes attempt to trip the player.

### \#taunt: Taunt nearby monsters.
- Wastes a few turns and wakes up nearby monsters.
- A custom taunt can be defined in the options file. Custom taunts
  are prepended by the word "You" when used in game.

### \#twoweapon
- can be used to attack with both ends of a double-headed
  weapon, such as a quarterstaff, two-bladed sword, or dual axe.

## Floor Coating System
- Room floors can be dirt or stone. 
- Floors can be coated with various substances, such as potions, grass,
  blood, and more.
- All of these coatings can be interacted with in various ways, to
  various effects. Have fun!

## GUI
- MC is displayed on the status line as a percentage.

## Monsters

### General
- Dogs and large dogs now have breed names attached to their names.
- YANI from Riker on the YANI Archive: Werecreatures that transform
  out of sight are disguised as standard creatures of their type.
- Horses and ponies have altered names.
- Tigers are orange.

### Unique Monsters
- Dispater uses the trickster monster spell list, making him likely
  to both disguise himself and summon illusory duplicates.
- Orcus uses the undead monster spell list identical to the one used
  by liches.
- In the course of dungeon exploration, one may encounter unique monsters.
  Further details about these monsters are detailed in uniquefixes.txt.

### Mounts
- The following monster classes are now valid mounts: f, d

### Monster Spells
- Different monsters have different spell lists.
- Many existing spells take advantage of the floor coating system.
- Cure self now heals additional hp for high-level monsters.

### New Monster Spells
- Grease
  - Makes the player's hands greasy.
  - Distributes oil on nearby squares.
- Sleep
  - Puts the player to sleep.
- Raise Dead
  - Raises dead monsters in player's inventory.
  - Summons undead.
- Gravity
  - Summons gravity spheres.
- Mirror Image
  - Creates multiple illusions of the caster.
- Teleport
  - Teleports the caster next to the player.
  - If at low hp, warps to stairs as a covetous monster might.

### New Monsters
- Poltergeist ( )
  - Does not approach, collects objects like a nypmph. Throws any and
    all objects it gets its hands on. Permanently invisible.
  - Can generate in morgues or via raising the dead.
- Grotesque (g)
  - Slow, hard to hit, and very high damage. Spawns in groups.
- Mascaron (g)
  - Stunning gaze. Spawns in groups.
  - Peaceful, but turns hostile if alignment is abused.
- Gravitric Sphere (e)
  - Explosion reduces HP by 1/2.
  - Does not generate randomly.
- Illusion ( )
  - Does not generate randomly, unpolymorphable.
  - Appears as another monster.
  - Only appears when summoned by monsters.
- Snow Ant (a)
  - Hails from numerous variants.  Provenance unclear, but likely originated
    with Slash'Em?
- Squonk (q)
  - Leaves a trail of water.
- Skunk Ape (Y)
  - Periodically releases clouds of poison gas.
- Blood Golem (')
  - Leaves behind a trail of blood.
  - Explodes into blood when destroyed.
- Scrolem (')
  - Unique type of golem associated with scrolls.
- Black Hole (v)
  - Teleports upon engulfing.
  - Teleports items when picking them up
- Smilodon (f)
  - Originally from SLASH'EM (sabre-toothed cat).
- Lightcrust (F)
  - Sheds light in a large radius.
  - Generates throughout the dungeon.
- Boulderer (m)
  - Pretend to be boulders, spawn in groups.
  - Very low birth limit.
- Caterwaul
  - Originally from SLASH'EM.
  - Some changes, including ability to caterwail.

## Monster AI

### General
- Incorporated Slash'Em's traitor system, but updated to 3.7.
- Monsters will slather items with cans of grease if the player is
  polymorphed into a relevant form.

### Elberething
- Elves and princes can engrave Elbereth to ward off the player.
  - TODO: Forbid ranged attacks while on Elbereth?
  - TODO: Intentionally break Elbereth when player hp is low?
  - TODO: Elbereth vanishment?

### Pathfinding
- Some monsters will avoid following the player into chokepoints.
- Monsters will only flee from the player if they could conceivably
  outrun them.

## Objects

### General
- Renamed Scroll of Genocide to Scroll of Erasure.
- Quarterstaves can be wielded in dual weapon mode.
- Potions leave behind empty bottles when drunk. These bottles
  can be refilled with water at fountains, sinks, and other
  locations.
- Potions of water are considered inert and do not polymorph.
- Potions of holy water deal much more damage to demons.

### Armor
- MC: Chance of cancelling a special effect.
  - Every piece of armor adds some amount of magic cancellation.
  - Maxes out at 90%.
  - Each point of enchantment reduces the MC of that piece of equipment by 1%.

### Weapons
- Some weapons are "finesse weapons." To-hit bonuses with
  finesse weapons are determined based on strength or
  dexterity, whichever is higher.
- Some weapons have a speed bonus or a speed penalty.
  - Generally, orc weapons are faster, elven weapons deal more damage,
    and dwarvish weapons deal more damage but are slower.

### New Objects
- Potion of blood
  - Function similarly to potions of blood from dnethack, although
    the implementation is different.
- Shepherd's Crook
  - Similar to a quarterstaff.
  - Can be used for tripping purposes.
  - Can be wielded in dual mode.
- Bolas
  - Thrown weapon.
  - Players struck by a bolas are made prone.
- Two-Bladed Sword
- Dual Axe

### Door and Chest Keys
- Unlocking tools now stack and are destroyed after use.
- Lock picks stack.

## Roles and Races

### General
- Roles are not restricted by race, with the exception of
  tourists (always human).

### Knights
- Knights receive a different mount depending on race.
  Orcs: Warg
  Elves: Jaguar

## System Changes

### Attributes
- Dexterity contributes to AC.
- Strength is normally the sole contributor to to-hit.

### Blessing Objects
- Holy water does not bless objects.
- Objects can be blessed by paying a priest between 50 and 200 times
  one's level.

### Reflection
- Reflection does not reflect rays directly back at
  the one that fired them. Instead, the rays bounce off at a ninety degree
  angle. As a consequence, reflection no longer instantly kills Medusa.

### To-Hit Changes
- As in dNetHack, d(1, Luck) is added to your to-hit instead
  of Luck.
- New To-Hit bonuses: Restricted: -2 Unskilled: 0 Basic: +1 Skilled: +2
  Expert +3
- New Damage bonuses: Restricted: -2 Unskilled: 0 Basic: +1 Skilled: +2
  Expert: +3