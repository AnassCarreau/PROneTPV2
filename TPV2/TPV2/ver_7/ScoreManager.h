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

	void isGameOver(bool fin) {
		finJuego = fin;
	}
	bool getGameOver() const {
		return finJuego;
	}

private:
	bool jugando;
	bool pausado;
	int score_;
	bool finJuego;
};
