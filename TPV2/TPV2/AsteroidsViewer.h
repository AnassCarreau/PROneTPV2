#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/ObjectPool.h"
#include "Asteroid.h"
#include "ver_7/Entity.h"
class AsteroidsViewer :public Component
{
	ObjectPool<Asteroid, 30>ast;

	Texture* asteroide;
	SDL_Rect clip, destRect;
	AsteroidsViewer();
		virtual ~AsteroidsViewer();
		void draw() override
		{
			for (auto &o :ast.getPool())
			{
				if (o->isInUse())
				{
					 destRect;//= RECT();
					asteroide->render(destRect);
				}

			}

		}
		;
};