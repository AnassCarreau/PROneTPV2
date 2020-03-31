#include "AsteroidPool.h"

AsteroidPool::AsteroidPool() : asteroids_([](AsteroidEntity* asteroid) { return asteroid->inUse(); }), Component(ecs::AsteroidPool) {
}

AsteroidPool::~AsteroidPool() {
	for (auto a : asteroids_.getPool()) {
		delete a; a = nullptr;
	}
}

void AsteroidPool::generateAsteroids(int n) {
	numOfAsteroids = n;
	int i = 0;
	Vector2D auxPos;
	Vector2D auxVel;
	int auxGen;
	while (i < n) {
		//int dx = 1 - 2 * r->nextInt(0, 2); // 1 or -1
		//int dy = 1 - 2 * r->nextInt(0, 2); // 1 or -1
		//Vector2D v(dx * r->nextInt(6, 7), // 2 to 6
		//dy * r->nextInt(2, 7) // 2 to 6
		//		);
		//ballTR_->setVel(v.normalize() * 5);

		AsteroidEntity* newAsteroid = asteroids_.getPool()[i];

		//Cálculo de la posición
		if (rand() % 2 == 0) auxPos = Vector2D(0, rand() % game_->getWindowHeight()); //x = 0, y aleatoria
		else auxPos = Vector2D(rand() % game_->getWindowWidth(), 0); //x aleatoria, y = 0

		//Cáculo de la velocidad
		Vector2D c = Vector2D(game_->getWindowWidth() / 2 + rand() % 50 - 50, game_->getWindowHeight() / 2 + rand() % 50 - 50);
		auxVel = (c - auxPos).normalize()*((rand() % 10 + 1) / 10.0);

		//Cálculo de las generaciones
		auxGen = rand() % 3 + 1;

		newAsteroid->setAsteroid(auxPos, auxVel, auxGen);
		i++;
	}
}

void AsteroidPool::disablAll() {
	for (AsteroidEntity* asteroid : asteroids_.getPool()) {
		asteroid->setInvisible();
	}
}

void AsteroidPool::onCollision(AsteroidEntity* a) {
	a->setInvisible();
	int newGen = a->getGeneration() - 1;
	if (newGen > 0) {
		int contAst = 0;
		numOfAsteroids++;
		for (int i = 0; i < numOfAsteroids && contAst < 2; i++) {
			if (!asteroids_.getPool()[i]->inUse()) {
				Vector2D newVel = a->getVel().rotate(i * 45);
				Vector2D newPos = a->getPos() + newVel.normalize();
				asteroids_.getPool()[i]->setAsteroid(newPos, newVel, newGen);
				contAst++;
			}

		}
	}
	else {  
  		numOfAsteroids--;
	}
}