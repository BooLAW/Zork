#include "World.h"
#include "Player.h"


World::World()
{
	for (int i = 0; i < 26; i++)
		exit.PushBack(new Exits);
		//the properties will be defined later on

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
			printf("Wow there is a %s in the floor.\n", item[i]->name.Cstr());
	
	}
}

void World::CreateWorld()
{
	
	//----------ITEMS--------------

	item.PushBack(new Item("axe", "A big weapon that seems to be useful to deal with some problems.\n", "Sawmill", 1,false,5));
	item.PushBack(new Item("gloves", "A pair of gloves that can avoid recoil.\n", "Forest", 1,true,3));
	item.PushBack(new Item("key locked room", "Better keep it safe, keys use to be useful to.\n", "Appletrees", 1,false,0));
	item.PushBack(new Item("Key lighthouse", "Better keep it safe, keys use to be useful to.\n", "Nest", 1,false,0));
	item.PushBack(new Item("tools kit", "a set of tools that a good electrician man would have.\n", "Abandoned House", 2,false,0));
	item.PushBack(new Item("helmet", "this will protect your head.\n", "Beach", 2, true,5));

	//------------ROOMS---------------
	
	room.PushBack(new Room("Solar Panels", " : There is a green energy power station that seems to be supplying the energy to the Lighthouse.\n"));
	room.PushBack(new Room("Nest", " : Near the road there is a big plane full of bones of animals and some kind of human skulls.\n"));
	room.PushBack(new Room("Sawmill", " : A few of trees are settled near the road.\n"));
	room.PushBack(new Room("LightHouse Entrance", ": The door is locked so you must find something to open it.\n"));
	room.PushBack(new Room("LightHouse Top", " : There is a bulb that needs to be fixed but, wait, the wires have current and had been cut, so now someone has to fix that with some complex tools.\n"));
	room.PushBack(new Room("Abandoned House", " : You are in a house full of scratches in the walls and a closed room in the west of it.\n "));
	room.PushBack(new Room("Locked Room", " : You are inside the rocket room and a huge animal stands in front of you, the only escape is to go back or to jump behind the animal to what it seems to be a hole.\n"));
	room.PushBack(new Room("Cliff", " : You are in front of a cliff with a very old wood bridge crossing it, the only way to cross it is through the bridge or by getting back and looking for any other route\n"));
	room.PushBack(new Room("Foggy Valley", " : You are in the foggy valley, you hear some sounds, but the only way to cross it is by keep walking to the north or to the south\n"));
	room.PushBack(new Room("Waterfall", " : You are in a waterfall, the only place of the isle with drinkable water, there is no exit except from getting back, but maybe if you explore...\n"));
	room.PushBack(new Room("Appletrees", " : You are surrounded of AppleTrees with sweet apples that seem to be tasty, there is no more path than the one that you came from\n"));
	room.PushBack(new Room("Forest", " : You are surrounded by big oaks and a two dogs are sleeping in the bottom of one of the trees, there are exits in every direction\n" ));
	room.PushBack(new Room("Beach", " : You are in the beggining of your adventure, there is nothing else but sand and water except from a hidden path with a road inside of it at the north\n"));

	//--------------------EXITS-------------------------
	exit[0]->source = "Solar Panels";
	exit[0]->destination = "Nest";
	exit[0]->direction = "east";
	exit[0]->description = "you only see  a long path and the silouethe of a big building";
	exit[0]->open = true;
	exit[0]->openable = false;

	
	exit[1]->source = "Nest";
	exit[1]->destination = "Solar Panels";
	exit[1]->direction = "west";
	exit[1]->description = "you see some solar pannels in that direction";
	exit[1]->open = true;
	exit[1]->openable = false;

	
	exit[2]->source = "Nest";
	exit[2]->destination = "Sawmill";
	exit[2]->direction = "east";
	exit[2]->description = "you see a set of trees and the silouethe of a lighthouse at the end of the path";
	exit[2]->open = true;
	exit[2]->openable = false;


	exit[3]->source = "Sawmill";
	exit[3]->destination = "Nest";
	exit[3]->direction = "west";
	exit[3]->description = "you see a long path ";
	exit[3]->open = true;
	exit[3]->openable = false;


	exit[4]->source = "Sawmill";
	exit[4]->destination = "LightHouse Entrance";
	exit[4]->direction = "east";
	exit[4]->description = "a big Lighthouse stands in front of you, there is a door in front of you";
	exit[4]->open = true;
	exit[4]->openable = false;


	exit[5]->source = "LightHouse Entrance";
	exit[5]->destination = "Sawmill";
	exit[5]->direction = "west";
	exit[5]->description = "you can see a set of trees near the road";
	exit[5]->open = false;
	exit[5]->openable = false;


	exit[6]->source = "LightHouse Entrance";
	exit[6]->destination = "Lighthouse Top";
	exit[6]->direction = "up";
	exit[6]->description = "there is a ladder in front of you that goes up";
	exit[6]->open = true;
	exit[6]->openable = true;



	exit[7]->source = "Lighthouse Top";
	exit[7]->destination = "LightHouse Entrance";
	exit[7]->direction = "down";
	exit[7]->description = "you can see a ladder going down";
	exit[7]->open = true;
	exit[7]->openable = true;


	exit[8]->source = "Nest";
	exit[8]->destination = "Locked Room";
	exit[8]->direction = "down";
	exit[8]->description = "there is a hole down the nest";
	exit[8]->open = true;
	exit[8]->openable = false;




	exit[9]->source = "Locked Room";
	exit[9]->destination = "Nest";
	exit[9]->direction = "down";
	exit[9]->description = "you can see a tunnel with light in the end";
	exit[9]->open = true;
	exit[9]->openable = false;


	exit[10]->source = "Sawmill";
	exit[10]->destination = "Foggy Valley";
	exit[10]->direction = "south";
	exit[10]->description = "you see a path that vanishes into a foggy valley";
	exit[10]->open = true;
	exit[10]->openable = false;



	exit[11]->source = "Foggy Valley";
	exit[11]->destination = "Sawmill";
	exit[11]->direction = "north";
	exit[11]->description = "you see a set of trees at the end of the path";
	exit[11]->open = true;
	exit[11]->openable = false;



	exit[12]->source = "Foggy Valley";
	exit[12]->destination = "Waterfall";
	exit[12]->direction = "south";
	exit[12]->description = "there is a path that ends inside a cave that emanates some water souds";
	exit[12]->open = true;
	exit[12]->openable = false;



	exit[13]->source = "Waterfall";
	exit[13]->destination = "Foggy Valley";
	exit[13]->direction = "north";
	exit[13]->description = "you see are inside a cave with a single path";
	exit[13]->open = true;
	exit[13]->openable = false;



	exit[14]->source = "Waterfall";
	exit[14]->destination = "Forest";
	exit[14]->direction = "west";
	exit[14]->description = "you see a deep forest in the end of the path";
	exit[14]->open = true;
	exit[14]->openable = false;


	exit[15]->source = "Forest";
	exit[15]->destination = "Waterfall";
	exit[15]->direction = "east";
	exit[15]->description = "you see a waterfall at the end of the path";
	exit[15]->open = true;
	exit[15]->openable = false;


	exit[16]->source = "Appletrees";
	exit[16]->destination = "Forest";
	exit[16]->direction = "south";
	exit[16]->description = "you see a deep forest at the end of the path";
	exit[16]->open = true;
	exit[16]->openable = false;


	exit[17]->source = "Forest";
	exit[17]->destination = "Beach";
	exit[17]->direction = "south";
	exit[17]->description = "you see a beach at the end of the path";
	exit[17]->open = true;
	exit[17]->openable = false;


	exit[18]->source = "Beach";
	exit[18]->destination = "Forest";
	exit[18]->direction = "north";
	exit[18]->description = "you see a deep forest at the end of the path";
	exit[18]->open = true;
	exit[18]->openable = false;


	exit[19]->source = "Cliff";
	exit[19]->destination = "Forest";
	exit[19]->direction = "east";
	exit[19]->description = "you see a deep forest at the end of the path";
	exit[19]->open = true;
	exit[19]->openable = false;

	exit[20]->source = "Cliff";
	exit[20]->destination = "Abandoned House";
	exit[20]->direction = "north";
	exit[20]->description = "a house that seems to be abandoned is at the end of this path";
	exit[20]->open = true;
	exit[20]->openable = false;


	exit[21]->source = "Abandoned House";
	exit[21]->destination = "Cliff";
	exit[21]->direction = "south";
	exit[21]->description = "at the end of the path there is a bridge that crosses a cliff";
	exit[21]->open = true;
	exit[21]->openable = false;


	exit[22]->source = "Forest";
	exit[22]->destination = "Cliff";
	exit[22]->direction = "west";
	exit[22]->description = "you see a cliff with a bridge that crosses it";
	exit[22]->open = true;
	exit[22]->openable = false;


	exit[23]->source = "Forest";
	exit[23]->destination = "Appletrees";
	exit[23]->direction = "north";
	exit[23]->description = "you see some different trees in the end of the path";
	exit[23]->open = true;
	exit[23]->openable = false;


	
	exit[24]->source = "Abandoned House";
	exit[24]->destination = "Locked Room";
	exit[24]->direction = "east";
	exit[24]->description = "at the end of the corridor there is a locked room";
	exit[24]->open = false;
	exit[24]->openable = true;


	exit[25]->source = "Locked Room";
	exit[25]->destination = "Abandoned House";
	exit[25]->direction = "west";
	exit[25]->description = "there is a door in front of you";
	exit[25]->open = false;
	exit[25]->openable = true;
}

