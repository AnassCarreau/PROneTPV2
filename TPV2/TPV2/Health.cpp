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

void Health::draw() {
	int x = 50;
	for (int i = 0; i < vidas; i++) {
		
		dest.x = x;
		
		life->render(dest);
		x += 40;
	}
}