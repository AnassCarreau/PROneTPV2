#pragma once

#include "Component.h"
#include "checkML.h"

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

	bool isPlay() const {
		return playing;
	}

	void setPlay(bool running) {
		playing = running;
	}
	bool isPause() const {
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
	bool playing;
	bool pausado;
	int score_;
	bool ganar;
};
