#pragma once

#include "checkML.h"
#include "Component.h"
#include "ScoreManager.h"

class ScoreViewer : public Component {
public:
	ScoreViewer();
	virtual ~ScoreViewer();
	void init() override;
	void draw() override;
private:
	ScoreManager* scoreManager_;
	string texto;

};
