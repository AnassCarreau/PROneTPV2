#pragma once

#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include"..//Health.h"
#include "..//AsteroidPool.h"
class GameCtrl : public Component {
public:
	GameCtrl(Transform* ballTR);
	virtual ~GameCtrl();
	void init() override;
	void update() override;
	void draw() override;
private:
	Transform* ballTR_;
	ScoreManager* scoreManager_;
	Health* vida_;
	AsteroidPool* ast_;
};

