#ifndef __PLAYER_H__
#define __PLAYER_H_
#define uint unsigned int 
#include "Entity.h"


class Enemy : public Entity{
public:
	int position_num;//integer used for accessing the rooms
	int health_points;
	int damage;
	int armor;
public:
	Enemy();
	bool Move_Enemy(const String& destination);
	void Drop_Item_enemy(const String& item)const;
	void UpdateStats();
	//attack same as player


};

#endif 