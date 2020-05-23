#pragma once

#include "Entity.h"
#include "System.h"



class RenderSystem: public System {
public:
	RenderSystem();
	void recieve(const msg::Message& msg);
	void update() override;
private:
	char othername_[11] = " ";
	char nameIzq[11] = " ";
	char nameDer[11] = " ";
	void drawImage(Entity* e);
	void drawCtrlMessages();
	void drawScore();
	void drawNames();
};
