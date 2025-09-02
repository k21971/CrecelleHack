des.level_init({ style = "solidfill", fg = " " });

des.level_flags("mazelevel");

des.map([[
----------------
|..............|
|.FFFFFFFFFFFF.|
|.F}........}F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F..........F.|
|.F}........}F.|
|.FFFFFFFFFFFF.|
|..............|
----------------
]]);

-- Dungeon Description
des.region(selection.area(00,00,15,15), "lit")
-- Stairs
des.stair("up", 08,10)
-- Non diggable walls
des.non_diggable(selection.area(00,00,15,15))
-- Objects
des.object({ id = "amulet of life saving", x=07, y=03, buc="blessed", spe=0, name="The Belt of Champions" })
des.object()
des.object()
des.object()
-- Random traps
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
-- Our nemesis
des.monster("Heel", 07, 03)
-- Spectators!
des.monster({ class = "@", x=01, y=01, peaceful=1 })
des.monster({ id = "rogue", x=14, y=14, peaceful=0 })
des.monster({ class = "@", x=01, y=14, peaceful=1 })
des.monster({ class = "@", x=14, y=01, peaceful=1 })
des.monster({ class = "@", x=01, y=03, peaceful=1 })
des.monster({ class = "@", x=14, y=01, peaceful=1 })
des.monster({ class = "@", x=01, y=12, peaceful=1 })
des.monster({ class = "K", x=14, y=12, peaceful=1 })