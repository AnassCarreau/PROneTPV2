#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"

class Health: public Component
{
private:
	int vidas;
	Texture* life;
	SDL_Rect  dest;

	
	;
public:
	Health(int vidas_) :Component(ecs::Health),
		vidas(vidas_)
	{
		dest.y = 10;
		dest.w = 50;
		dest.h = 50;
	};
	void init() {
		life = game_->getTextureMngr()->getTexture(Resources::Health);
	}
	virtual ~Health();
	bool RestaVida();
	void ResetVidas() {
		vidas = 3;
	};
	void draw() override;
};

