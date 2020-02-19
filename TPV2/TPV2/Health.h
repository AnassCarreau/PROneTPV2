#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"

class Health: public Component
{
private:
	int vidas;
	Texture* life;
public:
	Health(int vidas_) :Component(ecs::Health) { vidas = vidas_; life = game_->getTextureMngr()->getTexture(Resources::Health);};
	virtual ~Health();
	void RestaVida();
	void ResetVidas() {
		vidas = 3;
	};
	void draw() override;
};
