#pragma once
#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include "Resources.h"
#include "AsteroidPool.h"
#include "Heart.h"

class GameCtrl: public Component {
private:
	ScoreManager* scoreManager_ ;
	AsteroidPool* asteroidPool_;
	Heart* heart_;
public:
	GameCtrl(AsteroidPool* asteroidPool, Heart* heart);
	virtual ~GameCtrl();
	void init() override;
	void update() override;
	void draw() override;
};

