#include "World.h"
#include"Enemies.h"
#include<time.h>




Enemy::~Enemy()
{}
bool Enemy::Move_Enemy(const String& destination)
{	
		for (int i = 0; i < MAX_EXITS; i++)
		{

			if (world->exit[i]->direction.stringcomparison(destination.Cstr()) && world->exit[i]->source.stringcomparison(world->room[position_num]->name.Cstr()))
			{
				if ((world->exit[i]->openable) && (world->exit[i]->open == false))
				{
					printf("You can't go on that direction. The door is closed.\n");
					return false;
				}

				if (world->exit[i]->destination.Empty())
				{
					printf("%s", world->exit[i]->description.Cstr());
					return false;
				}


				for (int j = 0; j < MAX_ROOMS; j++)
					if (world->room[j]->name.stringcomparison(world->exit[i]->destination.Cstr()))
					{

						position_num = j;
						return true;
					}
			}
		}
		printf("You can't do that.\n");
		return false;
	}

bool Enemy::enemy_randmove()
{
	int var;
	srand(time(NULL));
	var = rand() % 4;


	switch (var)
	{

	case 0:
		if (Move_Enemy("north"))
		{
			Move_Enemy("north");
			return true;
		}
		break;
	case 1:
		if (Move_Enemy("south"))
		{
			Move_Enemy("south");
			return true;
		}
		break;
	case 2:
		if (Move_Enemy("east"))
		{
			Move_Enemy("east");
			return true;
		}
		break;
	case 3:
		if (Move_Enemy("west"))
		{
			Move_Enemy("west");
			return true;
		}
		break;
	}
	return false;
}




//void Enemy::Drop_Item_enemy(const String& item_name)const
//{
//	int i;
//	for (i = 0; i < MAX_ITEMS; i++)
//	{
//		if (world->item[i]->current_place.stringcomparison("inventory") && world->item[i]->name.stringcomparison(item_name.Cstr()))
//		{
//			world->item[i]->current_place = world->room[position_num]->name.Cstr();
//			printf("You dropped the %s.\n", world->item[i]->name.Cstr());
//			break;
//		}
//
//	}
//}
//
//void Enemy::Attack(const Player& player)const
//{
//	int i;
//	for (i = 0; i < MAX_ENEMIES; i++)
//	{
//		if ()
//		{
//			world->item[i]->current_place = world->room[position_num]->name.Cstr();
//			printf("You dropped the %s.\n", world->item[i]->name.Cstr());
//			break;
//		}
//
//	}
//}