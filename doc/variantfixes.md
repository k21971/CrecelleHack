# 1.2

## Dungeon Changes
- New minetown variants: Zootown and Lavender Town.
  - Lavender Town originates with me in Splice. I fixed a few issues
    with this one and also added a bit of variance to it.
  - Zootown is from Spork, modified by K2 for EvilHack, then ported
    to Lua by me in Splice.
- Bazaar Town has a 10% chance of generating as a cold level
  filled with frost.
- Swamps generate with mud in addition to fungus. This impacts
  juiblex's level.
- The Castle has increased variance from game to game. The following
  effects are possible:
  - Front of the castle has walls partially replaced by iron bars.
  - A storeroom contains potions.
  - Mimics mimic chests in some towers (idea from RGRN).
  - Surrounded by swamp instead of maze.
  - Monster and terrain variance based on temperature.
- Birds, rather than zombies, can appear in the castle courtyard.
- Castle maze extends closer to the backdoor of the castle.
- Add xNetHack's oracle level variants.

## Traps
- Sleeping gas traps actually create clouds of sleep gas.
- Sleeping gas traps in Gehennom may emit other types of gas.

## Items
- Winter Hat
  - Worn by mercenaries such as soldiers when generated on a
    level that is cold.

# 1.1

## Commands
- Add the #shout command. Present in many variants, but this uses
  the 3.7-compatible code written by aosdict/Phol En Wodan.

## Harmony System
- Complete rework of the harmony system.
  - Harmonic weapons now work differently depending on the type
    of harmony. Full details about this system can be found
    in doc/variantprops.md.
- Made harmonic objects rarer.
- Harmonic objects do not need to be identified to determine
  what they harmonize with.
- Dangerous monsters have a chance to spawn with harmonic objects
  related to their abilities.
- Reading a scroll of harmonize armor while wearing a skull
  corresponding to a monster now not only transforms the skull
  into a skull helm, but harmonizes that helm with the monster's
  associated harmonies.
- Remove obscure ordering system for determining whether a harmony
  is active.
- Disable monster double damage harmonization while reworking
  the system to be more interesting.

## Monsters
- Slightly increase chance of random spawns of unique monsters.
- Yellow dragons leave behind a trail of acid.
- More types of monsters spread fire when they move.
- Monsters can spawn with and throw potions of hazardous waste.
- Monsters can intentionally throw potions to trigger alchemical
  blasts.
- Monsters can seek out and put on eyewear.
- Monsters can wear amulets of change in order to change genders.
- Monsters that hatch from eggs are considered to be babies, and
  their names reflect this. This has no impact on gameplay.
- Implemented the monster max HP changes from xNetHack (originally
  from EvilHack, by way of SporkHack).
- Monsters considered "roguish" can spawn with poisoned items or
  potions of sickness.
- Monsters can dip items into potions.
- Ported EvilHack and Spork's covetous monster behavior tweaks.
- Ported EvilHack's ability for monsters to break boulders.
- Made some fixes to defsym.h to clarify monsters.
- Reduced nightcrust light emission range.
- Water elementals soak enemies with water on hit.
- Greater variance in the weapons that monsters spawn with.
- Crimson deaths create a massive cloud of bloody mist upon death.
- Change name of wargs to dire wolves.

## New Monsters
- Salt Golem
- Mustelid
- Giant Mustelid

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
- Wands of polymorph leave behind random potion coatings when
  zapped and remove all existing coatings.
- Wands of cancellation cancel potion coatings.
- Wands of make invisible change existing potion coatings into
  potions of invisibility.
- Lower damage and raise volatility of potions of hazardous
  waste.
- Allow acid spilled by acid beams to alchemize.
- Tools can become eroded.
- All blades are considered poisonable.
- All players recognize water.
- Added ice as a material, which is used for icicles and for a
  new randomized wand appearance. It can both shatter and be
  melted, making it extremely delicate.
- Significantly increased wand of teleportation rarity.

### New Objects
- Bestiary
  - Reading it allows the player to learn information about
    a monster, so that they can fully view that monster's
    stats when using the farlook command.
- Scroll of Control Weather
  - Blessed: Direct control over the current weather.
  - Uncursed: Swaps current weather from rain to shine.
  - Cursed: Causes bizarre inclement weather.
  - Confused and not cursed: Summons a tame tornado.
- Scroll of Maze
  - Allows you to send a monster to a randomly generated maze.
    This does not affect Riders, but it bypasses all forms of
    magic resistance.
- Mirrored Glasses
  - Provide reflection.
- Tinker Goggles
  - Block flash effects, as sunglasses do.
  - Protects from alchemic blasts when performing alchemy.
- Skeleton
  - Found on the ground of the dungeon, and occasionally
    created through other situations, such as by zapping
    a wand of death or being struck by lightning.
- Duct Tape
  - You can do all sorts of fun things with duct tape...
    - TODO: Breaking a taped-up wand should cause many explosions?
- Banana Peel
  - Replaces bolas.
- Acoustic Guitar
  - Tonal instrument.
- Electric Guitar
  - Fires bolts of electricity, as a fire or frost horn would.
- Wand of water
  - Does damage as a wand of striking, but cannot be resisted.
  - Coats things in water.
- Potion of teleportitis
  - Non-cursed potions teleport the drinker.
  - Gas released from the potion teleports those that breathe it.

## Floor Coating System
- Added frost and mud as a floor coatings.
  - Frost causes those walking over it to slip, as walking over ice.
  - Mud costs additional movement points to move through. Additionally,
    many monsters can hide themselves in the mud in order to ambush
    the player.
- Floor coatings can be added in level generation lua. Maps
  have been updated to reflect this.
- Allow blood golems to be created while polypiling.
- Remove cockatrice blood once it petrifies something.
- Only healers recognize the origin of pools of blood.
- Monsters and players can now drip with potions, spreading them
  across the level. You stop dripping after a short time, but can
  hasten the process using a towel.
- You can #tip potions onto yourself to douse yourself in a liquid.
- You can clean liquids off yourself by using #wipe.
- Towels can now be used to wipe the floor by engraving with them, rather
  than by using #rub.
- New messages for hurtling across coatings.
- Fire traps now evaporate potion puddles.
- Drain life destroys fungal and grass coatings.
- Can now use #name to name potions on the floor.

## Dungeon Changes
- Allow fountains to become frozen. Frozen fountains cannot be
  dipped into or quaffed from.
- New special room: Laboratory
- Fixed many special rooms having grass inside.

## GUI
- Farlook a monster with (:) to see a summary of a monster's stats,
  including attacks and harmonies.
- Examining an item in one's inventory allows one to view the item's
  stats.
- You can learn more about monsters' attacks by getting hit by them,
  chatting with them, using a stethoscope, or a wand of probing.
- Default to 3 status lines.
- Add code to windowports to support botl handling of many more statuses.
- Switch riding to opt_in on botl and being held to opt_out.

## Roles and Races
- Rewrote the wrestler role entirely.
  - Wrestlers are now known as grapplers.
  - Attacking a monster as a grappler now initiates a grap instead of an attack.
  - The direction one moves while holding a grabbed monster determines the kind
    of attack one performs against it.
  - Using #grapple while holding a monster releases that monster instead of
    executing a special move.

## Skills
- New Skill: Improvised Weaponry
  - Improvised weaponry allows players to improve their to-hit with
    abnormally wielded objects.
  - Grappler damage for improvised weapons caps at 1d20 instead of 1d6.

## Misc
- Bonfires no longer block sight.
- Potions destroyed in chests now splatter everywhere and create clouds of
  gas.
- Potion vapors are tracked and displayed as poison gas and mist would be,
  and can impact both players and monsters in new ways.
- Trapped chests that create gas clouds actually create clouds of gas.

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