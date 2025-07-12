
local tut_ctrl_key = nil;
local tut_alt_key = nil;

function tut_key(command)
   local s = nh.eckey(command);
   local m = s:match("^^([A-Z])$"); -- ^X is Ctrl-X
   if (m ~= nil) then
      tut_ctrl_key = m;
      return "Ctrl-" .. m;
   end

   m = s:match("^M%-([A-Z])$"); -- M-X is Alt-X
   if (m ~= nil) then
      tut_alt_key = m;
      return "Alt-" .. m;
   end

   return s;
end

function tut_key_help(x, y)
   if (tut_ctrl_key ~= nil) then
      des.engraving({ coord = { x,y }, type = "engrave", text = "Note: Outside the tutorial, Ctrl-key combinations are shown prefixed with a caret, like '^" .. tut_ctrl_key .. "'", degrade = false });
      tut_ctrl_key = nil;
   end
end

des.level_init({ style = "solidfill", fg = " " });
des.level_flags("mazelevel", "noflip",
                "nomongen", "nodeathdrops", "noautosearch");
des.map([[
---------------------------------------------------------------------------
|...|.......|.............................................................|
|...|.......|.............................................................|
|.---.......|.............----------......................................|
|.|.|.......|.---------...|........|......................................|
|--.---|+|+--.|.|.|.|.|...|........|......................................|
|.....||.|.|---.-.-.-.-----........|-----.................................|
|.....||.|..+..........+................|.................................|
|.....|-+------.-.-.-.-----........|-----.................................|
|.....|...|...|.|.|.|.|...|........|......................................|
|.....|...|...-S-------...|........|......................................|
|--.---...---...|.........----------......................................|
|.|.|.......|...|.........................................................|
|.|.|.......|...|.........................................................|
|.|.|.......|...|.........................................................|
|.|.|--...---...|.........................................................|
|.|...+...|.....|.........................................................|
---------------------------------------------------------------------------
]]);

des.region(selection.area(01,01, 73, 16), "lit");

des.non_diggable();

des.teleport_region({ region = { 3, 8, 3, 8 } });

nh.parse_config("OPTIONS=taunt:do the tutorial shuffle.");

if (u.role == "Knight") then
   des.engraving({ coord = { 12,1 }, type = "engrave", text = "Knights can jump with '" .. tut_key("jump") .. "'", degrade = false });
end

--
des.object({ coord = { 1, 6 }, id = "statue", montype = "blood golem", historic = true });
des.object({ coord = { 5, 6 }, id = "statue", montype = "black hole", historic = true });
des.object({ coord = { 1, 10 }, id = "statue", montype = "illusion", historic = true });
des.object({ coord = { 5, 10 }, id = "statue", montype = "squonk", historic = true });

des.engraving({ coord = { 3, 5 }, type = "engrave", text = "You can leave the tutorial via the magic portal", degrade = false });
des.trap({ type = "magic portal", coord = { 3, 4 }, seen = true });
--
des.engraving({ coord = { 3, 11 }, type = "engrave", text = "Welcome to the CrecelleHack Tutorial", degrade = false });
des.engraving({ coord = { 3, 13 }, type = "engrave", text = "This tutorial will walk you through a few key differences between this variant and vanilla", degrade = false });
des.engraving({ coord = { 3, 15 }, type = "engrave", text = "If you have not played NetHack before, please familiarize yourself with NetHack 3.7 first", degrade = false });
des.engraving({ coord = { 5, 16 }, type = "engrave", text = "Let's start with the floor coating system", degrade = false });
des.door({ coord = { 6, 16 }, state = "closed" });
--
des.door({ coord = { 8, 8 }, state = "closed" });
des.engraving({ coord = { 8, 13 }, type = "engrave", text = "Try throwing this tonic at something", degrade = false });
des.object({ id = "tonic of acid", spe = 0, buc = "not-cursed", coord = { 8, 13} });
des.engraving({ coord = { 8, 7 }, type = "engrave", text = "Notice how the tonic splattered all over the floor", degrade = false });
des.engraving({ coord = { 8, 6 }, type = "engrave", text = "The dungeon in CrecelleHack can become coated in all sorts of things, including tonics, grass, and more", degrade = false });
des.door({ coord = { 8, 5 }, state = "closed" });
--
des.replace_terrain({ region={05,00, 04,11}, fromterrain=".", toterrain=".", coat="grass" })
des.door({ coord = { 10, 5 }, state = "closed" });
des.engraving({ coord = { 8, 3 }, type = "engrave", text = "Try standing on that altar and zapping this wand of fire south", degrade = false });
des.altar({ x = 8, y = 1, align="chaos", type="shrine" });
des.object({ coord = { 8, 3 }, id = "wand of fire", buc = "blessed" });
des.engraving({ coord = { 10, 7 }, type = "engrave", text = "There are many coating interactions to discover in your adventure", degrade = false });
des.door({ coord = { 12, 7 }, state = "closed" });
--
des.engraving({ coord = { 13, 7 }, type = "engrave", text = "Welcome to the hall of rule changes!", degrade = false });
des.engraving({ coord = { 14, 7 }, type = "engrave", text = "This hall covers the most critical rule changes to be aware of", degrade = false });
-- Niche
des.engraving({ coord = { 15, 6 }, type = "engrave", text = "Magic Cancellation is displayed on the status line", degrade = false });
des.object({ id = "cloak of protection", spe = 0, buc = "not-cursed", coord = { 15, 5 }})
-- Niche
des.engraving({ coord = { 17, 6 }, type = "engrave", text = "Dexterity contributes to AC instead of to-hit", degrade = false });
des.object({ coord = { 17, 5 }, id = "tonic of gain ability", buc = "blessed", quantity = math.random(3, 5) });
-- Niche
des.engraving({ coord = { 19, 6 }, type = "engrave", text = "Scrolls of Genocide have been renamed to Scrolls of Erasure", degrade = false });
des.object({ coord = { 19, 5 }, id = "scroll of light", buc = "not-cursed", name = "(Not a Real SoE)" });
-- Niche
des.engraving({ coord = { 15, 8 }, type = "engrave", text = "Unlocking items are discarded after a single use", degrade = false });
des.object({ coord = { 15, 9 }, id = "skeleton key", buc = "not-cursed" });
des.door({ coord = { 15, 10 }, state = "locked"});
-- Secret Room
des.engraving({ coord = { 15, 13 }, type = "engrave", text = "Use the #taunt command to taunt", degrade = false });
des.engraving({ coord = { 11, 16 }, type = "engrave", text = "A custom taunt can be defined in your config file", degrade = false });
des.monster({ coord = { 11, 9 }, id = "mountain nymph", peaceful = 1, asleep = 1 });


des.engraving({ coord = { 22, 7 }, type = "engrave", text = "Please note that this is not a comprehensive list of changes, merely a few salient ones.", degrade = false });
des.door({ coord = { 23, 7 }, state = "closed" });
----------------
des.engraving({ coord = { 24, 7 }, type = "engrave", text = "Welcome to the final area of the tutorial.", degrade = false });
des.engraving({ coord = { 25, 7 }, type = "engrave", text = "Sometimes, monsters may become extra powerful if standing on terrain they favor.", degrade = false });
des.engraving({ coord = { 26, 7 }, type = "engrave", text = "For example, elves get stronger on grass.", degrade = false});
des.engraving({ coord = { 27, 7 }, type = "engrave", text = "This is called harmonizing.", degrade = false});
des.monster({ coord = { 28, 7 }, id = "wolf", peaceful = 1 });
des.monster({ coord = { 29, 7 }, id = "wolf", peaceful = 1 });
-- This should be harmonic?
des.object({ id = "dagger", spe = 0, coord = { 38, 7 } });
des.engraving({ coord = { 38, 7 }, type = "engrave", text = "Some objects allow you to harmonize with specific types of terrain. Find them all!", degrade = false});
des.engraving({ coord = { 39, 7 }, type = "engrave", text = "So ends the CrecelleHack tutorial. Go forth!", degrade = false});

-- entering and leaving tutorial _branch_ now handled by core
-- // nh.callback("cmd_before", "tutorial_cmd_before");
-- // nh.callback("level_enter", "tutorial_enter");
-- // nh.callback("level_leave", "tutorial_leave");
-- // nh.callback("end_turn", "tutorial_turn");

----------------

-- temporary stuff here
-- des.trap({ type = "magic portal", coord = { 9,5 }, seen = true });
-- des.trap({ type = "magic portal", coord = { 9,1 }, seen = true });
-- des.object({ id = "leather armor", spe = 0, coord = { 9,2} });

