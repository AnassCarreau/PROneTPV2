#include "Resources.h"
#include "SDL_macros.h"

vector<Resources::FontInfo> Resources::fonts_{
			{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 }, //
			{ ARIAL24, "resources/fonts/ARIAL.ttf", 24 } //
};

vector<Resources::ImageInfo> Resources::images_{
			{ Blank, "resources/images/blank.png" }, //
			{ Heart, "resources/images/heart.png" }, //
			{ KeyBoardIcon, "resources/images/keyboard.png" }, //
			{ MouseIcon, "resources/images/mouse.png" }, //
			{ AIIcon, "resources/images/ai.png" }, //
			{ SpaceShips, "resources/images/spaceships.png" }, //
			{ Airplanes, "resources/images/airplanes.png" }, //
			{ Star, "resources/images/star.png" }, //
			{ Asteroids, "resources/images/astreoid.png" }, //
			{ Bullet, "resources/images/whiterect.png" } //
};

vector<Resources::TextMsgInfo> Resources::messages_{
			{ Score, "SCORE: ", { COLOR(0xaaffffff) }, ARIAL16 }, //
			{ PressAnyKey, "Press Any Key ...", { COLOR(0xaaffbbff) }, ARIAL24 }, //
			{ GameOver, "Game Over!", { COLOR(0xffffbbff) }, ARIAL24 } //
};

vector<Resources::MusicInfo> Resources::musics_{
			{ Beat, "resources/sound/beat.wav" }, //
			{ Cheer, "resources/sound/cheer.wav" }, //
			{ Boooo, "resources/sound/boooo.wav" }, //
			{ Imperial, "resources/sound/imperial_march.wav" }, //
			{ Missed, "resources/sound/missed.wav" } //
};

vector<Resources::SoundInfo> Resources::sounds_{
			{ Wall_Hit, "resources/sound/wall_hit.wav" }, //
			{ Paddle_Hit, "resources/sound/paddle_hit.wav" }, //
			{ Explosion, "resources/sound/explosion.wav" }, //
			{ GunShot, "resources/sound/GunShot.wav" } //
};

