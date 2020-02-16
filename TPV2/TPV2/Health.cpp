#include "Health.h"

void Health::RestaVida() {
	if (vidas > 0) {
		vidas--;
	}
	else {
		//llama a perder partida imagino
	}
}

Health::~Health() {
	//no se sabe que hara xd
}