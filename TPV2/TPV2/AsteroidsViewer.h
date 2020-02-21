#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/ObjectPool.h"
#include "Asteroid.h"
#include "ver_7/Entity.h"
class AsteroidsViewer :public Component
{
private:
	ObjectPool<Asteroid, 30>ast;

	Texture* asteroide;
	SDL_Rect destRect;
public:
	AsteroidsViewer(ObjectPool<Asteroid, 30>ast_) :Component(ecs::AsteroidsViewer),
		ast(ast_) {

	};
	virtual ~AsteroidsViewer();
	void init()
	{
		asteroide = game_->getTextureMngr()->getTexture(Resources::Asteroid);
	};
	void draw() override
	{
		for (auto& o : ast.getPool())
		{
			if (o->isInUse())
			{
				SDL_Rect rect;
				rect.x = o->getPos().getX();
				rect.y = o->getPos().getY();
				rect.w = o->getW();
				rect.h = o->getH();


				asteroide->render(destRect, o->getRot());
			}
		}
	}
	;
};