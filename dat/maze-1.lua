des.level_init({ style = "solidfill", fg = " ", lit = 0 });
des.level_flags("mazelevel", "noteleport", "nodeathdrops", "nommap")
des.level_init({ style = "maze", corrwid = 1, wallthick = 1, deadends = false });

des.map([[
]])

des.levregion({ region = {00,00,74,19}, type="branch" });
des.teleport_region({ region = {00,00,74,19}, dir="up" })
des.teleport_region({ region = {00,00,74,19}, dir="down" })
des.trap({ type = "magic portal", seen = false });
des.non_diggable(selection.area(00,00,74,19))
des.non_passwall(selection.area(00,00,74,19))