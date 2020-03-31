#pragma once

#include "Component.h"
#include "Transform.h"
#include "Gun.h"
#include "BulletsPool.h"
class FighterCtrl:public Component
{
public:
	FighterCtrl();
	FighterCtrl(SDL_Keycode up, SDL_Keycode right, SDL_Keycode left);
	virtual ~FighterCtrl() { delete tr_; tr_ = nullptr; };

	void init();
	void update();

private:
	SDL_Keycode up_;
	SDL_Keycode right_;
	SDL_Keycode left_;
	Transform* tr_;
	
};

