#pragma once

#include "Component.h"
#include "checkML.h"
// incluye el n�mero de vidas (rondas) que quedan al caza
struct Health : Component {
	Health() :
		vidas_(0) //
	{
	}
	
	 int vidas_;
};

