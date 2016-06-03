#ifndef __WORLD_H__
#define __WORLD_H__

#define MAX_ITEMS 4
#define MAX_ROOMS 13
#define MAX_EXITS 26

#include <string.h>
#include <iostream>

#include "String.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"
#include "Items.h"

class Player;//we need the declaration to declare the player*

class World{

public:
	World();
	void CreateWorld();
	void Look()const;
	~World();

public:
	Player* player;
	Vector <Enemy*> enemy;
	Vector <Room*> room;
	Vector <Exits*> exit;
	Vector <Item*> item;
	
};

extern World* world;

#endif
	



