#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL_macros.h"
#include "BulletsPool.h"

class BulletsViewer : public Component {
private:
	Texture* image_;
	BulletsPool* pool_;

public:
	BulletsViewer(Texture* image);
	virtual ~BulletsViewer();
	void init() override;
	void draw() override;
};

