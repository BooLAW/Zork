#include "World.h"
#include "Player.h"

World* world = nullptr;

int main(){
	
	world = new World;
	

	bool gameloop = true;
	int *player_pos = &world->player->position_num;
	char input_command[50];
	String player_input;
	char* direction;

	String word1;
	String word2;
	String word3;
	String word4;
	
	world->CreateWorld();
	printf(">>Hi survivor, before the adventure can i know your name?\n");
	scanf_s("%s", world->player->name);
	printf(">>Okay %s have, fun :) .\n", world->player->name);
	printf(">>Here i will give you some tips, and remember if you need to see it again just input <help> command ;)\n");
	printf("\n>> Quit the game: (quit)\n>> Look current room: (look)\n>> Move: (n/s/e/w/u/d) or (go) + (north/south/west/east/up/down)\n>> Stats:(stats)\n>> Pick/Drop: (pick/drop item_name)\n>> Long Pick/Drop: (pick/drop item_name from item_location)\n>> Inventory: (inventory) or (i)\n>> Open/Close: (open/close direction)\n>> Eat:(eat apples)\n>> Drink:(drink water)\n\n");

	while (gameloop){
		while (gameloop)
		{
			//i have to fix the first enter because i start with incorrect input
			//due to the fact that the \n of the printf it's stored as the first input_command
			int aux = 0;
			gets_s(input_command, 50);

			player_input = input_command;

			//break the string into key words
			word1 = player_input.GetWordFromString(1);
			word2 = player_input.GetWordFromString(2);
			word3 = player_input.GetWordFromString(3);
			word4 = player_input.GetWordFromString(4);
			//... new strings for the attack commands


			//-------------------QUIT---------------------
			if (player_input.stringcomparison("quit")){
				gameloop = false;
				break;
			}

			//-----------------MOVE(move using long direction)-----------------------
			else if (player_input.stringcomparison("go north") || player_input.stringcomparison("n"))
			{
				if (world->player->Move_Player("north")){
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}

				if (world->player->day % 48 > 32)//night
				{
					for (int i = 0; i < MAX_ENEMIES; i++)
					{
						world->enemy[i]->enemy_randmove();
					}
				}
			}
			else if (player_input.stringcomparison("go south") || player_input.stringcomparison("s"))
			{
				if (world->player->Move_Player("south"))
				{
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}
				if (world->player->day % 48 > 32)//night
				{
					for (int i = 0; i < MAX_ENEMIES; i++)
					{
						world->enemy[i]->enemy_randmove();
					}
				}

			}
			else if (player_input.stringcomparison("go east") || player_input.stringcomparison("e"))
			{
				if (world->player->Move_Player("east"))
				{
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}
				if (world->player->day % 48 > 32)//night
				{
					for (int i = 0; i < MAX_ENEMIES; i++)
					{
						world->enemy[i]->enemy_randmove();
					}
				}
			}
			else if (player_input.stringcomparison("go west") || player_input.stringcomparison("w"))
			{
				if (world->player->Move_Player("west"))
				{
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}
				if (world->player->day % 48 > 32)//night
				{
					for (int i = 0; i < MAX_ENEMIES; i++)
					{
						world->enemy[i]->enemy_randmove();
					}
				}
			}
			else if (player_input.stringcomparison("go up") || player_input.stringcomparison("u"))
			{
				if (world->player->Move_Player("up"))
				{
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}
					
				if (world->player->day % 48 > 32)//night
				{
					for (int i = 0; i < MAX_ENEMIES; i++)
					{
						world->enemy[i]->enemy_randmove();
					}
				}
			}
			else if (player_input.stringcomparison("go down") || player_input.stringcomparison("d"))
			{
				if (world->player->Move_Player("down")){
					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
					break;
				}


			}
			//------------------LOOK(Rooms)------------------------
			else if (player_input.stringcomparison("look")){
				world->Look();
				break;
			}
			//--------------------OPEN---------------------------
			else if (word1.stringcomparison("open"))
			{
				world->player->Open_Exit(word2);
				world->player->day++;
				break;
			}

			//----------------CLOSE---------------------
			else if (word1.stringcomparison("close"))
			{
				
				world->player->Close_Exit(word2);
				world->player->day++;
				break;
			}

			//-------------------TAKE & PICK--------------------
			else if ((word1.stringcomparison("pick")))
			{
				world->player->Pick1_Item(word2);
				world->player->day++;
				break;
			}

			//------------------TAKE FROM---------------------
			else if ((word1.stringcomparison("pick")) && (word3.stringcomparison("from")))
			{

				world->player->Pick2_Item(word2, word4);
				world->player->day++;
				break;

			}
			//--------------------DROP-------------------

			else if (word1.stringcomparison("drop"))
			{
				world->player->Drop_Item(word2);
				world->player->day++;
				break;
			}

			//-------------PUT ITEM INSIDE BAG---------

			//--------------------INVENTORY----------------------
			else if ((word1.stringcomparison("inventory") || word1.stringcomparison("i")))
			{
				printf("\n>>Inventory:\n");
				for (int i = 0; i < MAX_ITEMS; i++)
				{
					if (world->item[i]->current_place.stringcomparison("Inventory"))
						printf(">> %s\n", world->item[i]->name.Cstr());
				}
				
			}

			//-----------------STATS-----------------------

			else if (word1.stringcomparison("stats"))
			{
				world->player->User_Status();
				//enemy
			}

			//-----------------HELP-----------------(TODO)
			else if (word1.stringcomparison("help"))
			{
				printf("\n>> Quit the game: (quit)\n>> Look current room: (look)\n>> Move: (n/s/e/w/u/d) or (go) + (north/south/west/east/up/down)\n>> Stats:(stats)\n>> Pick/Drop: (pick/drop item_name)\n>> Long Pick/Drop: (pick/drop item_name from item_location)\n>> Inventory: (inventory) or (i)\n>> Open/Close: (open/close direction)\n>> Eat:(eat apples)\n>> Drink:(drink water)\n\n");
				//enemy
			}

			//------------------EAT-----------------
			else if (word1.stringcomparison("eat apples"))
			{
				if (*player_pos == 10)//appletree
				{
					world->player->food = 100;
					printf(">>Mmmm tasty\n");
				}
				else
					printf(">>There is nothing to eat here\n");
			
				//enemy
			}


			//------------DRINK-------------------
			else if (word1.stringcomparison("drink water")){
				if (*player_pos == 9)//waterfall
				{
					world->player->water = 100;
					world->player->day++;
				}
				else
					printf(">>There is no drinking water around\n");


				//enemy

			}
			else if (word1.stringcomparison("time")){
				world->player->Time();

				//enemy

			}
			//INVALID COMMAND
			else if (aux++)
				printf(">>Incorrect Input\n");

		
		}
	}
	return 0;
}