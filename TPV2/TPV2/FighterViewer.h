#pragma once
#include "Component.h"
#include "Texture.h"
#include "Transform.h"
#include "SDL_macros.h"
#include "Entity.h"
#include <SDL_rect.h>
class FighterViewer:public Component
{
private:
	Transform *tr_;
	Texture* fighter;
	SDL_Rect clip, destRect;
public:
	FighterViewer();
	virtual ~FighterViewer() { delete tr_; tr_ = nullptr; delete fighter; fighter = nullptr; };
	/*void draw() override;
	void init();*/
};

