#ifndef __PLAYER_H__
#define __PLAYER_H_
#define uint unsigned int 
#include "Entity.h"


class Player: public Entity{	
public:
	int position_num;//integer used for accessing the rooms
	int health_points;
	int player_damage;
	int player_armor;
	int food;
	int water;
	int day;
public:	
	Player();
	bool Move_Player(const String& destination);
	void Open_Exit(const String& direction)const;
	void Close_Exit(const String& direction)const;
	void Pick1_Item(const String& item)const;
	void Pick2_Item(const String& something, const String& somewhere)const;//take something from somewhere(inventory)
	void Drop_Item(const String& item)const;
	void User_Status();//shows current status(life food, water,...)
	void UpdateStats();
	void Equip(const String& item);
	void UnEquip(const String& item);
	void Time();


};

#endif 