#pragma once
#include "Vector2D.h"
class Asteroid
{
	int generaciones_ = 0;
	int use = 0;
public :
	Asteroid() {};
	
	virtual ~Asteroid() {};
	void setGenerations(int generaciones) {
		generaciones_ = generaciones;
	}
	int getGenerations() {
		return generaciones_;
	}
	void isUse(bool usado)
	{
		use = usado;
	}
	bool isInUse()
	{
		return use;
	}

};

