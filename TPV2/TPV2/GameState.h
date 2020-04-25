#pragma once
#include "Component.h"

struct GameState : Component {
	GameState() :
		estado(Start) //
	{
	}

	enum  State
	{
		Start, Play,Pause,FinishWin,FinishLose
	};
	
	State estado;
};