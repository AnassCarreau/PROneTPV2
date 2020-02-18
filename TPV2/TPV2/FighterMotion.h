#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "ver_7/Entity.h"

class FighterMotion:public Component
{
private:
	Transform *naveDelKibab;
public:
	FighterMotion() : Component(ecs::FighterMotion) {};
	virtual ~FighterMotion() {};
	void update();
	void init();
};

