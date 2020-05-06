#pragma once
#include "Component.h"
#include "Texture.h"
struct Clip : Component {
	Clip() :
		clip(nullptr)
	{
	}

	SDL_Rect* clip;
};