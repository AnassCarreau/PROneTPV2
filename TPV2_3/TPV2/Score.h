#pragma once

#include "Component.h"
#include "checkML.h"
// incluye el total de puntos
struct Score: Component {
	Score() :
			points_(0) //
	{
	}

	unsigned int points_;
};

