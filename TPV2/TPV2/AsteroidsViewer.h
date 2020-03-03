#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/ObjectPool.h"
#include "Asteroid.h"
#include "ver_7/Entity.h"
#include "ver_7/SDL_macros.h"
#include <SDL_rect.h>
#include "AsteroidPool.h"

class AsteroidsViewer :public Component
{
private:
	AsteroidPool* ast;
	Texture* asteroide;
public:
	AsteroidsViewer(AsteroidPool* ast_) :Component(ecs::AsteroidsViewer),
	ast(ast_), asteroide(nullptr){
	};
	virtual ~AsteroidsViewer() {};
	void init() 
	{
		asteroide = game_->getTextureMngr()->getTexture(Resources::Asteroid);
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