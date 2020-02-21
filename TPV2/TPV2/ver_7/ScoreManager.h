#pragma once

#include "Component.h"

class ScoreManager: public Component {
public:
	ScoreManager();
	virtual ~ScoreManager();

	

	int getScore() const {
		return Score_;
	}

	void setScore(int score) {
		Score_ = score;
	}

	
	

	bool getRunning() const {
		return running_;
	}

	void setRunning( bool running) {
		running_ = running;
	}
	bool getPausing() const {
		return running_;
	}

	void setPausing(bool Pausing) {
		pausing_ = Pausing;
	}

	void isGameOver(bool ganar) {
		 ganado = ganar ;
	}
	bool getWin() const {
		return ganado;
	}

private:
	bool running_;
	bool pausing_;
	int Score_;
	bool ganado;

};
