#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
#include "ver_7/Transform.h"
#include "ver_7/Entity.h"
class FighterViewer:public Component
{
private:
	Transform *tr_;
	Texture* fighter;
	SDL_Rect clip, destRect;
public:
	FighterViewer();
	virtual ~FighterViewer();
	void draw() override;
};

