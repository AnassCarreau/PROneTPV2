#include "Asteroid.h"

Asteroid::Asteroid(Vector2D pos, Vector2D vel, double width, double height, double rotation) : position_(pos),
velocity_(vel), width_(width), height_(height), rotation_(rotation) {
	use = 0;
	generaciones_ = 0;
}