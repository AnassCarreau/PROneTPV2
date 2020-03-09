#pragma once

#include <vector>

#include "Manager.h"
#include "SDLGame.h"
#include "GameCtrl.h"
#include "GameLogic.h"
#include "InputHandler.h"
#include "ScoreManager.h"
#include "ScoreViewer.h"
#include "Transform.h"
#include "SDLGame.h"
#include "FighterCtrl.h"
#include "FighterViewer.h"
#include "FighterMotion.h"
#include "Health.h"
#include "ObjectPool.h"
#include "AsteroidPool.h"
#include "Asteroid.h"
#include "AsteroidsViewer.h"
#include "AsteroidsMotion.h"
#include "BulletsMotion.h"
#include "BulletsPool.h"
#include "BulletsViewer.h"
#include "Bullet.h"

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
	void handleInput();
	void update();
	void render();

	SDLGame* game_;
	EntityManager* entityManager_;
	Entity* asteroid;
	Entity* bullet;
	Entity* fighter;
	Entity* gameManager;
	AsteroidPool* ast;
	BulletsPool* bull;
	Transform* fighterTR;
	Health* vida;

	bool exit_;

	const static int _WINDOW_WIDTH_ = 640;
	const static int _WINDOW_HEIGHT_ = 480;

};
