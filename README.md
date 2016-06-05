# Zork-Programming-1
##Instructions:

This game is played by introducing a set of commands that i will explain now:

To move through the rooms you can use:

"go" + "north/south/east/west/up/down" or the shortcuts of them "n/s/e/w/u/d".

To interact with the doors you can use: 

"open" or "close".

To make a deeper vision of every room, you can use the command:

"look".

If you don't remember how does the game work you can use the command:

"help".

If you want to  pick an item or drop it you are going to use the command:

"pick/drop <item>" (e.g. “pick sword”, “drop ring”)

If you want to look into your inventory you are going to use the command:

"inventory/inv/i"

If you want to equip or unequip anything you have to use:

"equip/unequip <item>" (e.g. equip helmet, unequip bow)

If you want to put something into the bag or to get something from it you will have to use

put/get <item> into/from <item>  (e.g. “put arrow in quiver”, “get map from backpack”)

You can look to the hour ( the day has 48 time steps and monsters will appear from 32 to 48):

time

And finally to stop playing the game you can use the command:

"quit".

##Enemies

The enemies only appear during the night and they are placed around the map.

##My Special Feature

My extra feature it's going to be a time counter that will directly affect to the map, for example, during the day some paths are going to be visible and during the night no(the output will be you can't see anything) but the path will be opened, also some items will just be pickable during the day/night, and when we implement the zork 3 with NPCs the game is going to set random NPCs in the opened rooms of the map(everyone except from a house and the lighthouse were you will be safe. Your hitting ratio will be reduced during the night(zork3).

Another "extra feature" is going to be the water and food status, you will start having 100/100 of each resource and in the map there will be 2 places to fill again the status bar(waterfall and appletrees field), so the player is going to be forced of taking care of her actual status while he is solving the puzzles, because every movement will discount 5 of each resource.

Water and apples won't be pickable, because then this implementation will have no sense, i will take care of having an answer of this not pickable issue to don't simply say "apples/water are/is not pickable"


##Link to the github repository:

This version of the classical game It's made by me,Pau Bonet Vall-Llebrera and here is the link of the repositorie of the game:

https://github.com/BooLAW/Zork
