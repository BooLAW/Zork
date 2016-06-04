#include "World.h"
#include "Player.h"


World::World()
{
	player = new Player;

}

World::~World()
{
	delete player; //is not a vector
}

void World::Look()const{

	printf("%s%s", room[player->position_num]->name.Cstr(),room[player->position_num]->description.Cstr());
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (item[i]->current_place.stringcomparison(room[player->position_num]->name.Cstr()))
			printf("Wow there is a / are %s in the floor.\n", item[i]->name.Cstr());
	
	}
}

void World::CreateWorld()
{
	
	//----------ITEMS--------------
	//name-description-location-number-armor-bonus
	item.PushBack(new Item("axe", "A big weapon that seems to be useful to deal with some problems.\n", "Sawmill", 1,false,5));
	item.PushBack(new Item("gloves", "A pair of gloves that can avoid recoil.\n", "Forest", 1,true,3));
	item.PushBack(new Item("key", "Better keep it safe, keys use to be useful to.\n", "Appletrees", 1,false,0));
	item.PushBack(new Item("tools kit", "a set of tools that a good electrician man would have.\n", "Abandoned House", 2,false,0));
	item.PushBack(new Item("helmet", "this will protect your head.\n", "Beach", 2, true,5));
	item.PushBack(new Item("sword", "this will protect your head.\n", "Machine", 2, false, 5));
	item.PushBack(new Item("life potion", "this will protect your head.\n", "Machine", 1, false, 5));
	item.PushBack(new Item("energy potion", "this will protect your head.\n", "Machine", 1, false, 0));
	item.PushBack(new Item("bazooka", "this will protect your head.\n", "Machine", 3, false, 20));

	//------------ROOMS---------------
	
	room.PushBack(new Room("Solar Panels", " : There is a green energy power station that seems to be supplying the energy to the Lighthouse.\n"));
	room.PushBack(new Room("Nest", " : Near the road there is a big plane full of bones of animals and some kind of human skulls.\n"));
	room.PushBack(new Room("Sawmill", " : A few trees are settled near the road.\n"));
	room.PushBack(new Room("LightHouse Entrance", ": The door is locked so you must find something to open it.\n"));
	room.PushBack(new Room("LightHouse Top", " : There is a bulb that needs to be fixed but, wait, the wires have current and had been cut, so now someone has to fix that with some complex tools.\n"));
	room.PushBack(new Room("Abandoned House", " : You are in a house full of scratches in the walls and a door in the east of it.\n "));
	room.PushBack(new Room("Locked Room", " : You are inside the rocket room and a huge animal stands in front of you, the only escape is to go back or to jump behind the animal to what it seems to be a hole.\n"));
	room.PushBack(new Room("Cliff", " : You are in front of a cliff with a very old wood bridge crossing it, the only way to cross it is through the bridge or by getting back and looking for any other route\n"));
	room.PushBack(new Room("Foggy Valley", " : You are in the foggy valley, you hear some sounds, but the only way to cross it is by keep walking to the north or to the south\n"));
	room.PushBack(new Room("Waterfall", " : You are in a waterfall, the only place of the isle with drinkable water, there is no exit except from getting back, but maybe if you explore...\n"));
	room.PushBack(new Room("Appletrees", " : You are surrounded of AppleTrees with sweet apples that seem to be tasty, there is no more path than the one that you came from\n"));
	room.PushBack(new Room("Forest", " : You are surrounded by big oaks and a two dogs are sleeping in the bottom of one of the trees, there are exits in every direction\n" ));
	room.PushBack(new Room("Beach", " : You are in the beggining of your adventure, there is nothing else but sand and water except from a hidden path with a road inside of it at the north\n"));

	//--------------------EXITS-------------------------
	//source-destination-direction-description-open-openable
	exit.PushBack(new Exits("Solar Panels", "Nest","east","you only see  a long path and the silouethe of a big building",true,false));
	exit.PushBack(new Exits("Nest", "Solar Panels", "west", "you see some solar pannels in that direction", true, false));
	exit.PushBack(new Exits("Nest", "Sawmill", "east", "you see a set of trees and the silouethe of a lighthouse at the end of the path", true, false));
	exit.PushBack(new Exits("Sawmill", "Nest", "west", "you see a long path", true, false));
	exit.PushBack(new Exits("Sawmill", "LightHouse Entrance", "east", "a big Lighthouse stands in front of you, there is a door in front of you", true, false));
	exit.PushBack(new Exits("LightHouse Entrance", "Sawmill", "west", "you can see a set of trees near the road", false, true));
	exit.PushBack(new Exits("LightHouse Entrance", "Lighthouse Top", "up", "there is a ladder in front of you that goes up", true, true));
	exit.PushBack(new Exits("Lighthouse Top", "LightHouse Entrance", "down", "you can see a ladder going down", true, true));
	exit.PushBack(new Exits("Nest", "Locked Room", "down", "there is a hole down the nest", true, false));
	exit.PushBack(new Exits("Locked Room", "Nest", "down", "you can see a tunnel with light in the end", true, false));
	exit.PushBack(new Exits("Sawmill", "Foggy Valley", "south", "you see a path that vanishes into a foggy valley", true, false));
	exit.PushBack(new Exits("Foggy Valley", "Sawmill", "north", "you see a set of trees at the end of the path", true, false));
	exit.PushBack(new Exits("Foggy Valley", "Waterfall", "south", "there is a path that ends inside a cave that emanates some water souds", true, false));
	exit.PushBack(new Exits("Waterfall", "Foggy Valley", "north", "you see are inside a cave with a single path", true, false));
	exit.PushBack(new Exits("Waterfall", "Forest", "west", "you see a deep forest in the end of the path", true, false));
	exit.PushBack(new Exits("Forest", "Waterfall", "east", "you see a waterfall at the end of the path", true, false));
	exit.PushBack(new Exits("Appletrees", "Forest", "south", "you see a deep forest at the end of the path", true, false));
	exit.PushBack(new Exits("Forest", "Beach", "south", "you see a beach at the end of the path", true, false));
	exit.PushBack(new Exits("Beach", "Forest", "north", "you see a deep forest at the end of the path", true, false));
	exit.PushBack(new Exits("Cliff", "Forest", "east", "you see a deep forest at the end of the path", true, false));
	exit.PushBack(new Exits("Cliff", "Abandoned House", "north", "a house that seems to be abandoned is at the end of this path", true, false));
	exit.PushBack(new Exits("Abandoned House", "Cliff", "south", "at the end of the path there is a bridge that crosses a cliff", true, false));
	exit.PushBack(new Exits("Forest", "Cliff", "west", "you see a cliff with a bridge that crosses it", true, false));
	exit.PushBack(new Exits("Forest", "Appletrees", "north", "you see some different trees in the end of the path", true, false));
	exit.PushBack(new Exits("Abandoned House", "Locked Room", "east", "at the end of the corridor there is a locked room", false, true));
	exit.PushBack(new Exits("Locked Room", "Abandoned House", "west", "there is a door in front of you", true, true));
	
	enemy.PushBack(new Enemy("Zombie", "A zombie that has a sailor jacket", "Foggy Valley"));
	enemy.PushBack(new Enemy("Wolf", "A zombie that has a sailor jacket", "Nest"));
	enemy.PushBack(new Enemy("Dog", "A zombie that has a sailor jacket", "Forest"));
	enemy.PushBack(new Enemy("Mutant Shark", "A big shark with legs that can walk", "Beach"));

}

