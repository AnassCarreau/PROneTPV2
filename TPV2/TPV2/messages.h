#pragma once
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "Transform.h"

namespace msg {

using msgSizeType = uint32_t;

enum MsgId : uint8_t {
	_CONNECTED, //
	_CONNECTION_REFUSED, //
	_CLIENT_DISCONNECTED, //
	_PLAYER_INFO, //
	_AIRPLANE_INFO, //
	_BULLET_INFO, //
	_START_REQ, //
	_START_ROUND, //
	_ON_FIGHTER_DEATH,
	_ON_FIGHTERS_DEATH,
	_PLAYER_INFO_MSG,
	//
	_last_MsgId_
};

#pragma pack(push,1)

struct Message {
	Message(msgSizeType size, MsgId id) :
			size(size), senderClientId(0), id(id) {
	}
	Message(MsgId id) :
			Message(sizeof(Message), id) {
	}
	msgSizeType size;
	uint32_t senderClientId;
	MsgId id;
};

struct ConnectedMsg : Message {
	ConnectedMsg(int clientId) :
		Message(sizeof(ConnectedMsg), _CONNECTED), clientId(clientId) {
	}
	uint32_t clientId;
};

struct ClientDisconnectedMsg : Message {
	ClientDisconnectedMsg(uint32_t clientId) :
		Message(sizeof(ClientDisconnectedMsg), _CLIENT_DISCONNECTED), clientId(
			clientId) {
	}
	uint32_t clientId;
};

struct AirplaneInfoMsg : Message {
	AirplaneInfoMsg(Transform tr) :
		Message(sizeof(AirplaneInfoMsg), _AIRPLANE_INFO), tr(tr) {
	}
	Transform tr;
};
struct BulletInfoMsg : Message {
	BulletInfoMsg(Vector2D p,Vector2D v) :
		Message(sizeof(BulletInfoMsg), _BULLET_INFO), p(p),v(v) {
	}
	Vector2D p;
	Vector2D v;
};
struct PlayerInfoMsg :Message {
	PlayerInfoMsg(string tr) :
		Message(sizeof(AirplaneInfoMsg), _PLAYER_INFO_MSG), tr(tr) {
	}
	string tr;
};


struct OnFighterDeathMsg : Message {
	OnFighterDeathMsg(uint8_t fighterId) :
		Message(sizeof(OnFighterDeathMsg), _ON_FIGHTER_DEATH), fighterId(fighterId) {
	}
	uint8_t fighterId;
};



#pragma pack(pop)

}
