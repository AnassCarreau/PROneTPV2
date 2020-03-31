#pragma once
#include "Component.h"
#include "AsteroidPool.h"

class AsteroidsMotion : public Component
{
private:
	AsteroidPool* pool_;
public:
	AsteroidsMotion();
	virtual ~AsteroidsMotion() {}
	void init() override;
	void update() override;
};

