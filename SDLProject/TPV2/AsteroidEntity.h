#pragma once
#include "Entity.h"


class AsteroidEntity
{
private:
	Vector2D pos_{0, 0};
	Vector2D vel_{0, 0};
	int width_ = 0;
	int height_ = 0;
	double rotation_ = 0;
	double velRot = rand() % 3 + 1;
	int generations_ = 0;
	bool visible = false; //Para mostrar el asteroide por pantalla
	const int ASTEROID_WIDTH = 15;
	const int ASTEROID_HEIGHT = 15;

public:
	AsteroidEntity();
	AsteroidEntity(Vector2D pos, Vector2D vel, double rotation, int generations);
	~AsteroidEntity() {}

	bool inUse() { return visible; } //Para saber si se muestra
	void asteroidMotion() { pos_ = pos_ + vel_; rotation_ += velRot / 5; }

	//Getters y setters
	Vector2D getPos() { return pos_; }
	Vector2D getVel() { return vel_; }
	int getW() { return width_; }
	int getH() { return height_; }
	double getRotation() { return rotation_; }
	int getGeneration() { return generations_; }
	void setInvisible() { visible = false; } //Pone invisibles las balas no usadas
	void setAsteroid(Vector2D pos, Vector2D vel, int generations); //Activa un nuevo asteroide poniéndolo visible
	void setPos(Vector2D pos) { pos_ = pos; }
};