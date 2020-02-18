#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "Bullet.h"
#include "ver_7/Entity.h"

	class BulletsMotion :public Component
	{
	private:
		Transform* balKibab;
	public:
		BulletsMotion() : Component(ecs::FighterMotion) { balKibab = GETCMP1_(Transform); };
		virtual ~BulletsMotion() {};
		void update();
	
};

