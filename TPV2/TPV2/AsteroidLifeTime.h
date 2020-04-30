#pragma once
#include "Component.h"
#include "checkML.h"
struct AsteroidLifeTime : Component {
	AsteroidLifeTime() :
		generaciones_(0)
	{
	}

	unsigned int generaciones_;
};