#pragma once

#include "Component.h"
#include "Entity.h"
#include "SDL_macros.h"
#include "Transform.h"

const int HEART_W_H = 20;

class Heart : public Component
{
private:
	int hearts = 3;
	Texture* image_;

public:
	Heart(Texture* image);
	virtual ~Heart();
	virtual void init();
	virtual void draw();
	void loseHeart(); //Resta vida
	void resetHeart(); //Resetea las vidas
	int getHearts() { return hearts; }
};

