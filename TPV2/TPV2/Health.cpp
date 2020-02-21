#include "Health.h"

bool Health::RestaVida() {

	if (vidas > 0) {
		vidas--;
		return true;
	}
	else {
		return false;
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