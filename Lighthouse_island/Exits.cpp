#include "Exits.h"
#include "World.h"
#include "Player.h"


void Exits::Look()const
{
	printf(">>%s", description.Cstr());
	if (openable)
		if (open)
			printf(">>Door already opened.\n");
		else 
			printf(">>Door already closed.\n");
}

