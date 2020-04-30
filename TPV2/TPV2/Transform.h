#pragma once

#include "Vector2D.h"
#include "Component.h"
#include "checkML.h"
//Incluye las propiedades de un objeto
struct Transform: Component {
	Transform(Vector2D pos, Vector2D vel, double width, double height,
			double rotation) :
			position_(pos), //
			velocity_(vel), //
			width_(width), //
			height_(height), //
			rotation_(rotation) //
	{
	}

	Transform() :
			position_(), //
			velocity_(), //
			width_(), //
			height_(), //
			rotation_() //
	{
	}

	Vector2D position_;
	Vector2D velocity_;
	double width_;
	double height_;
	double rotation_;
};

