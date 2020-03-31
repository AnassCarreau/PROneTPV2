#pragma once
#include "AsteroidPool.h"
#include "BulletsPool.h"
#include "Heart.h"
#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"

class GameLogic: public Component {
private:
	Transform* hunterTR_;
	ScoreManager *scoreManager_;
	AsteroidPool* asteroidPool_;
	BulletsPool* bulletsPool_;
	Heart* heart_;
	
public:
	GameLogic(Transform* hunterTR, AsteroidPool* asteroidPool, BulletsPool* bulletsPool, Heart* heart);
	virtual ~GameLogic();
	void init() override;
	void update() override;
};

