#pragma once

#include "Component.h"
#include "checkML.h"
#include "Transform.h"
#include "Entity.h"
class FighterMotion:public Component
{
private:
	Transform *nave;
public:
	FighterMotion() : Component(ecs::FighterMotion), nave(nullptr) {};
	virtual ~FighterMotion() { delete nave; nave = nullptr; };
	void update()override;
	void init()override;
};

