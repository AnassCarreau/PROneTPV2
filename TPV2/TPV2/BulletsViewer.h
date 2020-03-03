#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/ObjectPool.h"
#include "Bullet.h"
#include "ver_7/Entity.h"
#include "ver_7/SDL_macros.h"
#include <SDL_rect.h>
#include "BulletsPool.h"
#include "ver_7/Transform.h"


class BulletsViewer: public Component
{
private:
	BulletsPool* bull;
	Texture* bala;
public:
	BulletsViewer(BulletsPool* bull_) : Component(ecs::BulletsViewer),
		bull(bull_), bala(nullptr) {

	};
	virtual ~BulletsViewer() {};
	void init()
	{
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

