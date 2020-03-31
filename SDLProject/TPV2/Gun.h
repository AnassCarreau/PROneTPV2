#pragma once
#include "Component.h"
#include "Transform.h"
#include "Entity.h"
#include "BulletsPool.h"

const int BULLET_W = 5;
const int BULLET_H = 10;
class Gun : public Component
{
private:
	SDL_Keycode space_;
	Transform* tr_;
	BulletsPool* bulletsPool_;

	//Cadencia
	double tick = SDL_GetTicks();
	double timeShoot_ = 250;

public:
	Gun(SDL_Keycode space, BulletsPool* bulletsPool);
	~Gun() {};
	virtual void init();
	virtual void update();
};

