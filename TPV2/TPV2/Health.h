#pragma once

#include "Component.h"
#include "Texture.h"

struct Health : Component {
	Health() :
		vidas_(0) //
	{
	}
	
	unsigned int vidas_;
};

