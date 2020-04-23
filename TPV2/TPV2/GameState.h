#pragma once
#include "Component.h"

struct GameState : Component {
	GameState() :
		estado(pausado), //
		win(false) //
	{
	}

	enum State
	{
		pausado,jugando,terminado
	};
	State estado;
	bool win;
};