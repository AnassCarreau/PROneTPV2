#include "AsteroidEntity.h"

AsteroidEntity::AsteroidEntity() {}

AsteroidEntity::AsteroidEntity(Vector2D pos, Vector2D vel, double rotation, int generations) : 
	pos_(pos), vel_(vel), rotation_(rotation), generations_(generations) {}

void AsteroidEntity::setAsteroid(Vector2D pos, Vector2D vel, int generations) {
	pos_ = pos;
	vel_ = vel;
	width_ = ASTEROID_WIDTH * generations;
	height_ = ASTEROID_HEIGHT * generations;
	rotation_ = 0;
	generations_ = generations;
	visible = true;
}
