#pragma once

#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include"..//Health.h"
#include "..//AsteroidPool.h"
class GameCtrl : public Component {
public:
	GameCtrl(Transform* fighterTR, AsteroidPool* ast);
	virtual ~GameCtrl();
	void init() override;
	void update() override;
	void draw() override;
private:
	Transform* fighterTR_;
	ScoreManager* scoreManager_;
	Health* vida_;
	AsteroidPool* ast_;
};

