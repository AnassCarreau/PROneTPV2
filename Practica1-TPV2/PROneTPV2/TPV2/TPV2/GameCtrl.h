#pragma once

#include "Component.h"
#include "ScoreManager.h"
#include "Transform.h"
#include "checkML.h"
#include "Health.h"
#include "AsteroidPool.h"
class GameCtrl : public Component {
public:
	GameCtrl(Health* fighterTR, AsteroidPool* ast);
	virtual ~GameCtrl() {};
	void init() override;
	void update() override;
	void draw() override;
private:
	ScoreManager* scoreManager_;
	Health* vida_;
	AsteroidPool* ast_;
};

