#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"

class FighterCtrl
{
public:
	FighterCtrl();
	FighterCtrl(SDL_Keycode up, SDL_Keycode right, SDL_Keycode left);
	virtual ~FighterCtrl();

	void init();
	void update();

private:
	SDL_Keycode up_;
	SDL_Keycode right_;
	SDL_Keycode left_;
	Transform* tr_;
};

