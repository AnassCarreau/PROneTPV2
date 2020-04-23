#pragma once

#include "Component.h"
#include "Texture.h"

struct Health : Component {
	Health() :
		vidas_(0) //
	{
	}
	bool RestaVida();
	void draw();
	unsigned int vidas_;
	Texture* life;
};

