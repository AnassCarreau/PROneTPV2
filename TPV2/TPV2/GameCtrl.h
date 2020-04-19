#pragma once

#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include "Health.h"
#include "AsteroidPool.h"
class GameCtrl : public Component {
public:
	GameCtrl(Health* fighterTR, AsteroidPool* ast);
	virtual ~GameCtrl() { delete scoreManager_; scoreManager_ = nullptr; };
	//void init() override;
	//void update() override;
	//void draw() override;
private:
	ScoreManager* scoreManager_;
	Health* vida_;
	AsteroidPool* ast_;
};

