#pragma once

#include "Component.h"
#include "Transform.h"

class PaddleKBCtrl: public Component {
public:
	PaddleKBCtrl();
	PaddleKBCtrl(SDL_Keycode up, SDL_Keycode right , SDL_Keycode left, SDL_Keycode space);
	virtual ~PaddleKBCtrl();

	inline void setCtrlKeys(SDL_Keycode up, SDL_Keycode right,
			SDL_Keycode left,SDL_Keycode space) {
		up_ = up;
		right_ = right;
		left_ = left;
		space_ = space;
		
	}

	void init() override;
	void update() override;

private:
	SDL_Keycode up_;
	SDL_Keycode right_;
	SDL_Keycode left_;
	SDL_Keycode space_;
	Transform *tr_;
};

