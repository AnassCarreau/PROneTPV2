#include "ScoreManager.h"



ScoreManager::ScoreManager() :
	Component(ecs::ScoreManager), //
	playing(true),
	pausado(true),//
	score_(0),
	ganar(false)
{
}

ScoreManager::~ScoreManager() {
}

