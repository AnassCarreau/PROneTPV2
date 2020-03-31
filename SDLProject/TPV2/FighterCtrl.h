#pragma once

#include "Component.h"
#include "Transform.h"

class FighterCtrl: public Component {
public:
	FighterCtrl();
	FighterCtrl(SDL_Keycode up, SDL_Keycode left, SDL_Keycode right);
	virtual ~FighterCtrl();

	inline void setCtrlKeys(SDL_Keycode up, SDL_Keycode left, SDL_Keycode right) {
		up_ = up;
		left_ = left;
		right_ = right;
	}

	void init() override;
	void update() override;

private:
	SDL_Keycode up_;
	SDL_Keycode left_;
	SDL_Keycode right_;
	Transform *tr_;
	Vector2D speedLimit = Vector2D(150, 150);
};

