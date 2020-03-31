#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL_macros.h"
#include "Transform.h"

class FighterViewer : public Component {
private:
	Texture* image_;
	Transform* tr_; 
	
public:
	FighterViewer(Texture* image);
	virtual ~FighterViewer() {}
	virtual void init();
	virtual void draw();
};

