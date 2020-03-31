#pragma once

#include "Component.h"
#include "checkML.h"
#include "Transform.h"

class Health: public Component
{
private:
	int vidas;
	Texture* life;
public:
	Health(int vidas_) :Component(ecs::Health),
		vidas(vidas_), life(nullptr)
	{
		
	};
	void init() {
		life = game_->getTextureMngr()->getTexture(Resources::Health);
	}
	virtual ~Health() { delete life; life = nullptr; };
	bool RestaVida();
	void ResetVidas() {
		vidas = 3;
	};
	void draw() override;
};

