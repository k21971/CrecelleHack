des.level_init({ style = "solidfill", fg = " " });

des.level_flags("mazelevel", "hardfloor", "icedpools", "noflip")

des.level_init({ style="mines", fg=".", bg="C", smoothed=true, joined=true, lit=1, walled=false })

des.map([[
........                        ........
.....     ...................     ......
....    .......................     ....
....   .........................    ....
..  ................................  ..
........................................
..  ................................  ..
....   .........................    ....
....   .........................    ....
.....     ...................     ......
........                        ........
]]);

des.stair("up", 02, 14)
des.stair("down", 20, 05)

des.non_diggable(selection.area(00,00,39,10))
des.region(selection.area(00,00,39,10), "lit")
--
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
des.object()
--
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
des.trap()
--
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster({class = "K", peaceful = 0})
des.monster()
des.monster()