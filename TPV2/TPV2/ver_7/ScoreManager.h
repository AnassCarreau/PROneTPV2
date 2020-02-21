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




	bool getRunning() const {
		return running_;
	}

	void setRunning(bool running) {
		running_ = running;
	}
	bool getPausing() const {
		return running_;
	}

	void setPausing(bool Pausing) {
		pausing_ = Pausing;
	}

	void isGameOver(bool ganar) {
		ganado = ganar;
	}
	bool getGameOver() const {
		return ganado;
	}

private:
	bool running_;
	bool pausing_;
	int score_;
	bool ganado;

};
