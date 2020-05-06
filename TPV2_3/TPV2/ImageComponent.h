#pragma once

#include "Component.h"
#include "Texture.h"
#include "checkML.h"
// incluye una textura 
struct ImageComponent: Component {
	ImageComponent(Texture* tex) :
			tex_(tex)
	{
	}
	Texture *tex_;
};

