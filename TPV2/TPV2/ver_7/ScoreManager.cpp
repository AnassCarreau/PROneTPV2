#include "ScoreManager.h"



ScoreManager::ScoreManager() :
	Component(ecs::ScoreManager), //
	jugando(false),
	pausado(true),//
	score_(0),
	finJuego(false)//
{
}

ScoreManager::~ScoreManager() {
}

