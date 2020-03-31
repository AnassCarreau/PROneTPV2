#pragma once
#include "Component.h"
#include "Entity.h"
#include "SDL_macros.h"
#include "AsteroidPool.h"
class AsteroidsViewer : public Component
{
private:
	Texture* image_ = nullptr;
	AsteroidPool* pool_;

public:
	AsteroidsViewer(Texture* image);
	virtual ~AsteroidsViewer();
	void init() override;
	void draw() override;
};