#pragma once

#include "Component.h"
#include "checkML.h"

struct Health : Component {
	Health() :
		vidas_(0) //
	{
	}
	
	 int vidas_;
};

