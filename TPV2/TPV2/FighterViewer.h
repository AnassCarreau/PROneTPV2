#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/Transform.h"
#include "ver_7/SDL_macros.h"
#include "ver_7/Entity.h"
#include <SDL_rect.h>

class FighterViewer:public Component
{
private:
	Transform *tr_;
	Texture* fighter;
	SDL_Rect clip, destRect;
public:
	FighterViewer(Texture* fig);
	virtual ~FighterViewer();
	void draw() override;
	void init();
};

