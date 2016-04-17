#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "String.h"
#include "Vector.h"

class Entity{
public:
	//basic properties of all child classes
	String name;
	String description;
	
	//for making the inventory
	int capacity;
	int num_items;
	bool armor;
	int bonus;
	
	void Look(){};
	

};


#endif