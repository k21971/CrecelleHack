des.room({ type = "ordinary",
           contents = function()
              des.stair("up")
              des.object()
              des.monster({ class = "Y", peaceful=0 })
           end
})

des.room({ type = "ordinary",
           contents = function()
              des.object()
              des.object()
              des.monster({ class = "Y", peaceful=0 })
           end
})

des.room({ type = "ordinary",
           contents = function()
              des.object()
              des.trap()
              des.object()
              des.monster("air elemental")
              des.monster("air elemental")
           end
})

des.room({ type = "ordinary",
           contents = function()
              des.stair("down")
              des.object()
              des.trap()
              des.monster({ class = "Y", peaceful=0 })
              des.monster("vampire bat")
           end
})

des.room({ type = "ordinary",
           contents = function()
              des.object()
              des.object()
              des.trap()
              des.monster({ class = "Y", peaceful=0 })
           end
})

des.room({ type = "ordinary",
           contents = function()
              des.object()
              des.trap()
              des.monster("rope golem")
           end
})

des.random_corridors()
