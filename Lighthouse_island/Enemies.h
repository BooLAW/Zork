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
	int health_points;
	int damage;
	int armor;
public:
	Enemy::Enemy(const char* name, const char* description, String location);
	bool Move_Enemy(const String& destination);
	void Drop_Item_enemy(const String& item)const;
	void UpdateStats();
	void Attack(const Player& player)const;
	~Enemy();


};

#endif 