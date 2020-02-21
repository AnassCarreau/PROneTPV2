#include "ScoreManager.h"



ScoreManager::ScoreManager() :
	Component(ecs::ScoreManager), //
	running_(false),
	pausing_(false),//
	score_(0)//
{
}

ScoreManager::~ScoreManager() {
}

