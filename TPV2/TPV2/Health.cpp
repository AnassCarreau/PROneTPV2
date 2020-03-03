#include "Health.h"

bool Health::RestaVida() {

		if (vidas > 1) {
			vidas--;
			return true;
		}
		else
		{
			return false;
		}
}

Health::~Health() {
	//no se sabe que hara xd
}

void Health::draw() {
	int x = 15;
	for (int i = 0; i < vidas; i++) {
		
		
		life->render(x,10);
		x += 30;
	}
}