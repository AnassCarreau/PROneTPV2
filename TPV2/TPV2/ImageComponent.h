#pragma once

#include "Component.h"
#include "Texture.h"
#include "checkML.h"

struct ImageComponent: Component {
	ImageComponent(Texture* tex) :
			tex_(tex)
	{
	}
	Texture *tex_;
};

