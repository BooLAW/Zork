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

	String action1;
	String item_name;
	String action2;
	String item_location;
	
	world->CreateWorld();
	printf(">>Hi survivor, before the adventure can i know your name?\n");
	scanf_s("%s", world->player->name);
	printf(">>Okay %s have, fun :) .\n", world->player->name);
	printf(">>Here i will give you some tips, and remember if you need to see it again just input <help> command ;)\n");
	
	
	while (gameloop == true)
	{
		while (gameloop)
		{	
			//i have to fix the first enter because i start with incorrect input
			//due to the fact that the \n of the printf it's stored as the first input_command
			gets_s(input_command,50);  
		
			player_input = input_command;
			
			//break the string into key words
			action1 = player_input.GetWordFromString(1);
			item_name = player_input.GetWordFromString(2);
			action2 = player_input.GetWordFromString(3);
			item_location = player_input.GetWordFromString(4);
			

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
			}
			else if (player_input.stringcomparison("go up") || player_input.stringcomparison("u"))
			{
				if (world->player->Move_Player("up"))

					world->player->food -= 5;
					world->player->water -= 5;
					world->Look();
				break;
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
			else if (player_input.stringcomparison("open door"))
			{
				printf(">>Which is the direction of the door to open ? \n");
			
					scanf_s("%s", &direction);
					world->player->Open_Exit(direction);
					break;
			}
				
			//----------------CLOSE---------------------
			else if (player_input.stringcomparison("close door"))
			{
					
					printf(">>Which is the direction of the door to close?\n");
					scanf_s("%s", &direction);
					world->player->Close_Exit(direction);
					break;
				}
				
			//-------------------TAKE & PICK--------------------
			else if ((action1.stringcomparison("pick")))
			{
				world->player->Pick1_Item(item_name);
			}

			//------------------TAKE FROM---------------------
			else if ((action1.stringcomparison("pick")) && (action2.stringcomparison("from")))
			{
				
				world->player->Pick2_Item(item_name, item_location);

			}
			//---------------------------DROP-------------------

			else if (action1.stringcomparison("drop"))
			{
				world->player->Drop_Item(item_name);
			}

			//--------------------INVENTORY----------------------
			else if ((player_input.stringcomparison("inventory") || player_input.stringcomparison("i")))
			{
				printf("\n>>Inventory:\n");
				for (int i = 0; i < MAX_ITEMS; i++)
					if (world->item[i]->current_place.stringcomparison("inventory"))
						printf("%s\n", world->item[i]->name.Cstr());			
			}
			
			//-----------------STATS-----------------------

			else if (player_input.stringcomparison("stats"))
				{
					world->player->User_Status();
				}

			//-----------------HELP-----------------(TODO)
			else if (player_input.stringcomparison("help"))
				printf(">> help lines\n");

			//------------------EAT-----------------
			else if (player_input.stringcomparison("eat apples")){
				if (*player_pos == 10)//appletree
				{
					world->player->food = 100;
					printf("mmmm tasty\n");
				}
				else
					printf("There is nothing to eat here\n");
				}
				
				
			//------------DRINK-------------------
			else if (player_input.stringcomparison("drink water")){
				if (*player_pos == 9)//waterfall
					world->player->water = 100;
				else
					printf("There is no drinking water around\n");
					
				
					
			}
				
			//INVALID COMMAND
			else 
				printf(">>>Incorrect Input\n");

			
			

		}

		
	
	}

	
	return 0;
}