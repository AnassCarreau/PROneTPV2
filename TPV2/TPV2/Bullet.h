#pragma once
#include "ver_7/Vector2D.h"
class Bullet
{
protected:
	Vector2D pos;
	Vector2D vel;
	double width;
	double height;
	double rotation;
	Bullet(Vector2D pos,
		Vector2D vel,
		double width,
		double height,
		double rotation);


};

