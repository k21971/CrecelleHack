# 1.1

## Monsters
- Orcs have a chance to spawn with a dual axe.
- Slightly increase chance of random spawns of unique monsters.
- Yellow monsters leave behind a trail of acid.

## New Monsters
- Salt Golem

## Unique Monsters
- Many new unique monsters.
- The deferred Goblin King boss is now a potential unique
  monster spawn.

## Objects
- Dented pots have been renamed to Yendorian Bascinets.
- Add in some additional helmet and cloak appearances to be
  shuffled into the existing ones.
- Yellow dragon scales and yellow dragon scale mail cause you
  to leave behind a trail of acid.

### New Objects
- Bestiary
  - Reading it allows the player to learn information about
    a monster, so that they can fully view that monster's
    stats when using the farlook command.

## Floor Coating System
- Added ice as a floor coating.

## Dungeon Changes
- Allow fountains to become frozen. Frozen fountains cannot be
  dipped into or quaffed from.

## GUI
- Farlook a monster with (:) to see a summary of a monster's stats,
  including attacks and harmonies.
- You can learn more about monsters' attacks by getting hit by them,
  chatting with them, using a stethoscope, or a wand of probing.
- Default to 3 status lines.
- Add code to windowports to support botl handling of many more statuses.
- Switch riding to opt_in on botl and being held to opt_out.

# 1.0

## Artifacts

### Type Randomization
- Many artifacts have semi-randomized object types.
  - The randomized object type must have a similar damage
    type to the original type of the artifact. For example,
    Sunsword cannot be a mace.
  - The brands are always the same type.

## Commands

### \#grapple: Grapple a monster
- Grappling a monster holds that monster in place.
- Trains the grappling skill, which allows you to escape
  and execute grabs more easily.
- Use special techniques by using #grapple when you are
  already grappling an opponent.

### \#trip: Trip a monster.
- Tripping traditionally uses one's lower body, but polearms,
  whips, and flails can be used to trip as well.
- Being tripped puts one into a downed state. Until one moves
  to a different location, AC and to-hit are reduced.
- While in a prone state, all harmonic bonuses are negated. This
  applies to both players and monsters.

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
- These coatings interface with the harmony system.
- All of these coatings can be interacted with in various ways, to
  various effects. Have fun!

## Day-Night Cycle
- Exactly what it sounds like! Watch your vision wax and
  wane over time!

## GUI
- MC is displayed on the status line as a percentage.
- Display level names on status line.

## Harmony System
- Most monsters harmonize on a specific type of terrain. While
  harmonizing, a monster deals double damage.
- Harmonic weapons and armor provide massive bonuses while standing
  on terrain that they harmonize with.
  - Armor grants 3 bonus points of AC while harmonized.
  - Weapons deal double damage when harmonized.

## Monsters

### General
- Dogs and large dogs now have breed names attached to their names.
- YANI from Riker on the YANI Archive: Werecreatures that transform
  out of sight are disguised as standard creatures of their type.
- Horses and ponies have altered names.
- Tigers are orange.
- Monsters can grapple and trip the player.
- Bats and vampires only spawn at night.
- Renamed mordor orcs to fen orcs and uruk-hai to fell orcs.

### Unique Monsters
- Dispater uses the trickster monster spell list, making him likely
  to both disguise himself and summon illusory duplicates.
- Orcus uses the undead monster spell list identical to the one used
  by liches.
- In the course of dungeon exploration, one may encounter unique monsters.
  Further details about these monsters are detailed in uniquefixes.txt.

### Mounts
- The following monster classes are now valid mounts: f, d
- Many monsters now do not spawn in Gehennom.

### Monster Spells
- Different monsters have different spell lists.
- Many existing spells take advantage of the floor coating system.
- Cure self now heals additional hp for high-level monsters.
- See variantspells.md for a full list of new spells.

### New Monsters
- 20 new monsters.
- See variantmonsters.md for a full list of these monsters and mild
  spoilers.

## Monster AI

### General
- Incorporated Slash'Em's traitor system, but updated to 3.7.
- Monsters will slather items with cans of grease if the player is
  polymorphed into a relevant form.

### Pathfinding
- Some monsters will avoid following the player into chokepoints.
- Monsters will only flee from the player if they could conceivably
  outrun them.
- Monsters do not track the player across the entire level, as in
  vanilla.

## New Role: Wrestler
- Use your special wrestling moves and the #grapple command to
  obtain the amulet!

## Objects

### General
- Renamed Scroll of Genocide to Scroll of Erasure.
- Renamed large shield to kite shield and small shield
  to roundshield.
- Quarterstaves can be wielded in dual weapon mode.
- Potions leave behind empty bottles when drunk. These bottles
  can be refilled with water at fountains, sinks, and other
  locations.
- Potions of water are considered inert and do not polymorph.
- Potions of holy water deal much more damage to demons.
- Bags have distinct appearances.
- Non-stacking weapons, armor, and weapon-tools have their
  weight mildly fuzzed.
- All gems shatter when thrown, regardless of their material.
  This opens up an additional route for getting glass onto
  the floor.

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
- Wand of Fecundity
  - Causes grass to grow when zapped.
  - Zapped monsters grow up.
  - Zapped eggs instantly start hatching.
- Skull
  - Derived from a monster.
- Skull Helm
  - Can be obtained by using a non-cursed scroll of enchant armor
    to enchant a worn skull.
  - Provide the same type of resistances possessed by the original
    monster. 
- Potion of blood
  - Function similarly to potions of blood from dnethack, although
    the implementation is different.
- Sunglasses
  - Provide protection against flash-based blindness.
- Shepherd's Crook
  - Similar to a quarterstaff.
  - Can be used for tripping purposes.
  - Can be wielded in dual mode.
- Bolas
  - Thrown weapon.
  - Players struck by a bolas are made prone.
- Heater Shield
- Two-Bladed Sword
- Dual Axe

### Locks and Picks
- Unlocking tools now stack.
- Unlocking tools have a small chance of being destroyed upon use.
  The chance is dependent upon the type of unlocking tool.

## Roles and Races

### New Role: The Wrestler
- Can you wrestle the dungeon into submission?
- TODO: Overwrite placeholder racial wrestling attacks.
- TODO: Improvised weapon usage.

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

### Misc
- Ported Hardfought's HTML Dumps and other tweaks.
- Ported xNetHack's invweight patch. Thanks to aosdict.
- Ported NetHack4's altar identification of items in bags. The code
  is pulled from dNetHack, but is likely identical to NetHack4's.
- Ported DynaHack's Enhanced Enhance menu. Code is pulled from
  some SpliceHack-Rewrite code I wrote a long time ago.

## Weather System
- Experience wind, rain, hail, and more.
- Weather changes dynamically over time, and may impact the gameplay
  in various ways.