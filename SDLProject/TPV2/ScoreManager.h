#pragma once

#include "Component.h"

class ScoreManager: public Component {
private:
	bool running_ = false;
	bool finishGame_ = false;
	bool win_ = false;
	int score_ = 0;
public:
	ScoreManager();
	virtual ~ScoreManager();

	bool isRunning() const { return running_; }
	bool isFinish() { return finishGame_; }
	bool isWin() { return win_; }

	int getScore() { return score_; }
	void addScore() { score_ += 1; }
	void setRunning(bool running) { running_ = running; }
	void setFinishGame(bool finishGame) { finishGame_ = finishGame; }
	void setWin(bool win) { win_ = win; }

	void resetScore() { score_ = 0; }
};