#pragma once
#include "Component.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Asteroid.h"
#include "Entity.h"
#include "SDL_macros.h"
#include <SDL_rect.h>
#include "checkML.h"
#include "AsteroidPool.h"
class AsteroidsViewer :public Component
{
private:
	AsteroidPool* ast;
	Texture* asteroide;
public:
	AsteroidsViewer() :Component(ecs::AsteroidsViewer),
	asteroide(nullptr),ast(nullptr){
	};
	virtual ~AsteroidsViewer(){}	
	void init()
	{
		asteroide = game_->getTextureMngr()->getTexture(Resources::Asteroid);
			ast = GETCMP1_(AsteroidPool);
	};
	void draw()
	{
		for (auto& o : ast->getPool())
		{
			if (o->isInUse())
			{
				SDL_Rect rect;
				rect.x = o->getPos().getX();
				rect.y = o->getPos().getY();
				rect.w = o->getW();
				rect.h = o->getH();
				
				asteroide->render(rect,o->getRot());
			}
		}
	}
	;
};