#ifndef __ENEMIES_H__
#define __ENEMIES_H__
#define uint unsigned int 


#include "Entity.h"


class Enemy : public Entity{
public:
	String	name;
	String	description;
	String current_place;
	int position_num;//integer used for accessing the rooms
	int damage;
	int life;
	Enemy(const char* item_name, const char* item_description, String location, int damage, int life)
	{

		this->name = item_name;
		this->description = item_description;
		this->current_place = location;
		this->damage = damage;
		this->life = life;
		
	}
public:
	bool Move_Enemy(const String& destination);
	//void Drop_Item_enemy(const String& item)const;
	void UpdateStats();
	//void Attack(const Player& player)const;
	bool enemy_randmove();
	~Enemy();

	


};

#endif 