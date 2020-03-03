#pragma once

#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include"..//Health.h"
#include "..//AsteroidPool.h"
#include "..//BulletsPool.h"

class GameLogic : public Component {
public:
	GameLogic(Transform* fighter, AsteroidPool* ast, BulletsPool* bala, Health* vida);
	virtual ~GameLogic();
	void init() override;
	void update() override;
private:
	Transform* fighter_;
	AsteroidPool* ast_;
	BulletsPool* bala_;
	Health* vida_;
	ScoreManager* scoreManager_;
};

