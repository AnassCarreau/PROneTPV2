#pragma once
#include "Component.h"
#include "checkML.h"
// incluye el n�mero de generaciones del asteroid
struct AsteroidLifeTime : Component {
	AsteroidLifeTime() :
		generaciones_(0)
	{
	}

	unsigned int generaciones_;
};