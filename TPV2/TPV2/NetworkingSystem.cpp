#include "NetworkingSystem.h"

#include "messages.h"
#include "Manager.h"

NetworkingSystem::NetworkingSystem() :
		System(ecs::_sys_NetWorking) {

}

NetworkingSystem::~NetworkingSystem() {
}

void NetworkingSystem::recieve(const msg::Message &msg) {
	if (msg.senderClientId == mngr_->getClientId()) {
		game_->getNetworking()->send(msg);
	}
}

void NetworkingSystem::update() {
	auto net = game_->getNetworking();
	msg::Message *msg = nullptr;
	while ((msg = net->recieve()) != nullptr) {
		switch (msg->id) {
		case msg::_PLAYER_INFO:
			mngr_->forwardMsg<msg::Message>(msg->senderClientId,
				msg::_PLAYER_INFO);
			break;
		case msg::_CLIENT_DISCONNECTED:
			mngr_->forwardMsg<msg::ClientDisconnectedMsg>(msg->senderClientId,
				static_cast<msg::ClientDisconnectedMsg*>(msg)->clientId);
			break;
		case msg::_AIRPLANE_INFO: 
			mngr_->forwardMsg<msg::AirplaneInfoMsg>(msg->senderClientId,
				static_cast<msg::AirplaneInfoMsg*>(msg)->tr);
			break;
		case msg::_BULLET_INFO: 
			mngr_->forwardMsg<msg::BulletInfoMsg>(msg->senderClientId,
				static_cast<msg::BulletInfoMsg*>(msg)->p, static_cast<msg::BulletInfoMsg*>(msg)->v);
			break;
		case msg::_START_REQ: 
			mngr_->forwardMsg<msg::Message>(msg->senderClientId,
				msg::_START_REQ);
			break;
		case msg::_START_ROUND: 
			mngr_->forwardMsg<msg::Message>(msg->senderClientId,msg::_START_ROUND);
			break;
		case msg::_ON_FIGHTER_DEATH:
			mngr_->forwardMsg<msg::OnFighterDeathMsg>(msg->senderClientId,
				static_cast<msg::OnFighterDeathMsg*>(msg)->fighterId);
			break;
		case msg::_ON_FIGHTERS_DEATH:
			mngr_->forwardMsg<msg::Message>(msg->senderClientId,
				msg::_ON_FIGHTERS_DEATH);	
			break;
		case msg::_PLAYER_NAME_MSG:
			mngr_->forwardMsg<msg::PlayerNameMsg>(msg->senderClientId,
				static_cast<msg::PlayerNameMsg*>(msg)->nombre);
			break;
		default:
			assert(false);
			break;
		}
	}

}
