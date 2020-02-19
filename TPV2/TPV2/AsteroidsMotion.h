#pragma once
#include "ver_7/Component.h"
#include "ver_7/ObjectPool.h"
#include "Asteroid.h"
#include "ver_7/Entity.h"
class AsteroidsMotion : public Component {

	ObjectPool<Asteroid, 30>ast;

	Texture* asteroide;
	SDL_Rect clip, destRect;
	void update()override
	{
		for (auto& o : ast.getPool())
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