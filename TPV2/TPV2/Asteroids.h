#pragma once

#include <vector>
#include "CollisionSystem.h"
#include "GameCtrlSystem.h"
#include "Manager.h"
#include "FighterCtrl.h"
#include "FighterGunSystem.h"
#include "RenderSystem.h"
#include "SDLGame.h"
#include "AsteroidsSystem.h"
#include "BulletsSystem.h"


class Asteroids {

public:
	Asteroids();
	virtual ~Asteroids();

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	

	RenderSystem* renderSystem_;
	AsteroidsSystem* asteroidSystem_;
	BulletsSystem* bulletSystem_;
	FighterSystem* fighterSystem_;
	FighterGunSystem* fighterGunSystem;
	CollisionSystem* collisionSystem_;
	GameCtrlSystem* gameCtrlSystem_;

	SDLGame* game_;
	Manager* mngr_;
	bool exit_;

	const static int _WINDOW_WIDTH_ = 640;
	const static int _WINDOW_HEIGHT_ = 480;

};
