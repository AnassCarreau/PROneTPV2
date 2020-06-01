#include "AudioSystem.h"

AudioSystem::AudioSystem() :
	System(ecs::_sys_Sound) { //
}
void AudioSystem::init()
{
	//Al ejecutar el programa suena la intro 
	game_->getAudioMngr()->playMusic(Resources::PacMan_Intro);

}
void AudioSystem::recieve(const msg::Message& msg)
{
	switch (msg.id) {
	case msg::_GAME_START:
		//Si la partida empieza se silencia la musica
		game_->getAudioMngr()->haltMusic();
		break;
	case msg::_GAME_OVER:
		//Si se termina la partida vuelve a sonar la intro
		game_->getAudioMngr()->playMusic(Resources::PacMan_Intro);
		break;
	case msg::_EAT_CHERRY:
		//Suena un sonido al comerse una cereza
		game_->getAudioMngr()->playChannel(Resources::PacMan_Eat, 0);
		break;
	case msg::_COLLISION:
		//Cuando se produce una colision con el fantasma suena un sonido de perder
		game_->getAudioMngr()->haltMusic();
		game_->getAudioMngr()->playChannel(Resources::PacMan_Death, 0);
		break;
	case msg::_NO_CHERRY:
		//Cuando se produce una colision con la ultima cereza suena un sonido de ganar
		game_->getAudioMngr()->haltMusic();
		game_->getAudioMngr()->playChannel(Resources::PacMan_Won, 0);
		break;
	default:
		break;
	}
}