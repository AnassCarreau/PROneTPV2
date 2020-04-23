#include "Health.h"

bool Health::RestaVida() {

		if (vidas_ > 1) {
			vidas_--;
			return true;
		}
		else
		{
			return false;
		}
}


void Health::draw() {
	int x = 15;
	for (int i = 0; i < vidas_; i++) {
		
		
		life->render(x,10);
		x += 30;
	}
}