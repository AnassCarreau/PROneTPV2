#pragma once
#include "ver_7/Component.h"
#include "ver_7/Texture.h"
class FighterViewer:public Component
{
private:
	Texture* fighter;
public:
	FighterViewer();
	virtual ~FighterViewer();
	void draw() override;
};

