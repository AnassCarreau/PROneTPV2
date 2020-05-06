#pragma once
#include "Component.h"
#include "checkML.h"
// incluye el estado del juego (parado, terminado, etc.) y el ganador
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