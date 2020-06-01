#pragma once
#include "System.h"
#include "SDLGame.h"

class AudioSystem : public System {
public:
	AudioSystem();
	//Un init para empezar la musica como lo hacia en el init de GameCtrl
	void init() override;
	void recieve(const msg::Message& msg)override;	
};

