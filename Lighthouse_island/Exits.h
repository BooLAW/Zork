#ifndef __EXITS_H__
#define __EXITS_H__
#include"Entity.h"

class Exits:public Entity{
public:
	String source;
	String destination;
	String direction;
	bool open;
	bool openable;
	void Look()const;


};
#endif