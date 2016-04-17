#include "Items.h"
#include "Player.h"
#include "World.h"
#include <stdio.h>

void Item::Look()
{

	if (current_place.stringcomparison(world->room[world->player->position_num]->name.Cstr()) || current_place.stringcomparison("inventory"))
	{ 
		printf(">>%s\n", description);

	if (num_items > 0)
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (world->item[i]->current_place.stringcomparison(name))
				printf(">>There is a %s inside the inventory.\n", world->item[i]->name.Cstr());
		}
	}
}