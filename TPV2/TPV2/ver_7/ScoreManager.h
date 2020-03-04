#pragma once

#include "Component.h"

class ScoreManager : public Component {
public:
	ScoreManager();
	virtual ~ScoreManager();



	int getScore() const {
		return score_;
	}

	void setScore(int score) {
		score_ = score;
	}

	bool getPlay() const {
		return jugando;
	}

	void setPlay(bool running) {
		jugando = running;
	}
	bool getPause() const {
		return pausado;
	}

	void setPause(bool Pausing) {
		pausado = Pausing;
	}

	
	void isWin(bool win) {
		ganar = win;
	}
	bool getWin() const {
		return ganar;
	}

private:
	bool jugando;
	bool pausado;
	int score_;
	bool ganar;
};
