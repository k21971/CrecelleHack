- Areas with multiple coatings are not properly described when using
(:) to check what is here.
- Fire region code makes an assumption that fire will be 1x1 regions.
For efficiency purposes we may want to modify this in the future.
- Potions should alchemize on the floor when shed by a monster, not
only when a potion splatters. Need to pull out a function.
- inside_bonfire() code needs serious cleanup!
- Special rooms are outlined by a coating due to some type of flag
collision.
- Potions of specific types of blood can only be wished up by wishing
  for "%s blood."
- Messages for getting killed by a potion of blood are a bit wonky.