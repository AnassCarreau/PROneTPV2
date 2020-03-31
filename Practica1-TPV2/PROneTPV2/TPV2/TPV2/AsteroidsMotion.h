#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include "Asteroid.h"
#include "Entity.h"
#include "AsteroidPool.h"
class AsteroidsMotion : public Component {
private:
	AsteroidPool* ast;

public:
	AsteroidsMotion() : Component(ecs::AsteroidsMotion),ast(nullptr){};

	virtual ~AsteroidsMotion()
	{
		delete ast;
		ast = nullptr;
	}
	void init()override
	{
		ast = GETCMP1_(AsteroidPool);
	}
	void update()override
	{
		for (auto& o : ast->getPool())
		{
			o->setPos(o->getPos() + o->getVel());
			o->setRot(o->getRot() + 0.5);
			if (o->getPos().getX() > game_->getWindowWidth())
			{
				o->setPosX(0);
			}
			else  if (o->getPos().getY() > game_->getWindowHeight())
			{
				o->setPosY(0);
			}
			else if (o->getPos().getX() <0)
			{
				o->setPosX(game_->getWindowWidth());
			}
			else  if (o->getPos().getY() <0)
			{
				o->setPosY(game_->getWindowHeight());
			}
		}
	};

};