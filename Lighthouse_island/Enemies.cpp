#include "World.h"
#include"Enemies.h"

void Enemy::Drop_Item_enemy(const String& item_name)const
{
	int i;
	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->current_place.stringcomparison("inventory") && world->item[i]->name.stringcomparison(item_name.Cstr()))
		{
			world->item[i]->current_place = world->room[position_num]->name.Cstr();
			printf("You dropped the %s.\n", world->item[i]->name.Cstr());
			break;
		}

	}
}