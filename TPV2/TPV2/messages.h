#pragma once
#include <ctime>

class Entity;

namespace msg {

using msgType = std::size_t;

enum MsgId : msgType {
	_GAME_START,//Cuando empieza el juego
	_GAME_OVER,//Cuando acaba el juego
	_COLLISION,// Cuando se produce un choque entre el pacman y un ghost
	_EAT_CHERRY,// Cuando el PacMan come una cereza
	_NO_CHERRY,//Cuando no hay más cerezas

	//
	_last_MsgId_
};

struct Message {
	Message(MsgId id) :
			id(id) {
	}

	MsgId id;
};
//Un mensaje con la entidad que corresponde a la cereza comida 
struct OnEatCherry : Message {
	OnEatCherry(Entity*e) :
		Message(_EAT_CHERRY), e(e) {
	}
	Entity* e;
};


}
