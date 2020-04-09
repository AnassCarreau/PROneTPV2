#pragma once
#include "Component.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Bullet.h"
#include "Entity.h"
#include "SDL_macros.h"
#include <SDL_rect.h>
#include "BulletsPool.h"
#include "checkML.h"
#include "Transform.h"

class BulletsViewer: public Component
{
private:
	BulletsPool* bull;
	Texture* bala;
public:
	BulletsViewer() : Component(ecs::BulletsViewer),bala(nullptr) {

	};
	virtual ~BulletsViewer() { delete bull; bull = nullptr;};
	void init()override
	{
		bull = GETCMP1_(BulletsPool);
		bala = game_->getTextureMngr()->getTexture(Resources::Bullet);
	};
	void draw() override
	{
		for (auto& o : bull->getPool())
		{
			if (o->isInUse())
			{
				SDL_Rect rect;
				rect.x = o->getPos().getX();
				rect.y = o->getPos().getY();
				rect.w = o->getW();
				rect.h = o->getH();


				bala->render(rect, o->getRot());
			}
		}
	}
	;
};

