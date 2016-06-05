#include "World.h"
#include "Player.h"

Player::Player(){
	name="auxiliar name";
	position_num = 12;
	health_points = 15;
	player_damage = 3;
	player_armor = 2;
	food = 100;
	water = 100;
	day = 48;
}

bool Player::Move_Player(const String& destination)
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

void Player::Open_Exit(const String& direction)const
{
	int i;
	for (i = 0; i < MAX_EXITS;i++)
		if ((world->exit[i]->source.stringcomparison(world->room[position_num]->name.Cstr())) && (world->exit[i]->direction.stringcomparison(direction)))
		{	
			if (world->exit[i]->openable == false)
				printf("There's no door on that direction.\n");

			else if (world->exit[i]->open)
				printf("The door is already opened.\n");

			else if (world->exit[i]->open == false)
			{ 
				printf("Door opened succesfully.\n");
				world->exit[i]->open = true;
			}	
			break;
		}

		

}	

void Player::Close_Exit(const String& direction)const
{
	int i;
	for (i = 0; i < MAX_EXITS; i++)
		if (world->exit[i]->source.stringcomparison(world->room[position_num]->name.Cstr())
			&& world->exit[i]->direction.stringcomparison(direction))
		{
			if (world->exit[i]->openable == false)
				printf("There's no door on that direction.\n");

			else if (world->exit[i]->open==false)
				printf("The door is already closed.\n");

			else if (world->exit[i]->open)
			{
				printf("You close the door at %s.\n", direction.Cstr());
				world->exit[i]->open = false;
			}
			break;
		}
}

void Player::Pick1_Item(const String& item_name)const
{
	int i;

	for ( i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.stringcomparison(item_name.Cstr()) && world->item[i]->current_place.stringcomparison(world->room[position_num]->name.Cstr()))
		{
			
			printf("You picked the %s.\n", world->item[i]->name.Cstr());
			world->item[i]->current_place = "Inventory";
			break;
		}
	}
	if (i == MAX_ITEMS) 
		printf("There's nothing like that here.\n");
}

void Player::Pick2_Item(const String& something, const String& somewhere)const
{
	int i, j;

	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.stringcomparison(something) && (world->item[i]->current_place.stringcomparison(world->room[position_num]->name.Cstr()) || world->item[i]->current_place.stringcomparison("inventory")))
		{
			if (world->item[i]->capacity == 0)
				printf("Unable action.\n");

			else if (world->item[i]->num_items == 0)
				printf("The %s is empty.\n", world->item[i]->name.Cstr());

			else for (j = 0; j < MAX_ITEMS;j++)
			{ 
			
				if (world->item[j]->current_place.stringcomparison(something) && world->item[j]->name.stringcomparison(somewhere))
				{
					printf("You picked a %s.\n", world->item[j]->name.Cstr());
					world->item[j]->current_place = "Inventory";
					world->item[i]->num_items--;
					break;
				}
			}
			
			break;
		}

	}

	if (i == MAX_ITEMS) printf("There's nothing like that here.\n");
}

void Player::Drop_Item(const String& item_name)const
{
	int i;
	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->current_place.stringcomparison("Inventory") && world->item[i]->name.stringcomparison(item_name.Cstr()))
		{
			world->item[i]->current_place = world->room[position_num]->name.Cstr();
			printf("You dropped the %s.\n", world->item[i]->name.Cstr());
			break;
		}
		if (MAX_ITEMS == i)
			printf("you don't have a %s in your inventory.\n", item_name.Cstr());
	}
}

void Player::User_Status()
{	
	printf(">> %s , you have %d health points left\n",name.buffer, health_points);
	printf(">> %s Attack: %d\n>> %s Armor:%d\n", name.buffer,player_damage,name.buffer, player_armor); // it crashes i don't know why
	printf(">> You have %d / 100 food and %d / 100 water currently\n", food, water);
}
void Player::Equip(const String& item){

}

void Player::Time()
{
	printf("%d\n", day % 48 );
}