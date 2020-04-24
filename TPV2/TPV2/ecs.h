#pragma once

#include <ctime>
#include "mpl.h"

// ** Components
//
// They must match the names of your components.
//
struct Transform;
struct ImageComponent;
struct Rotation;
struct Score;
struct AsteroidLifeTime;
struct Health;
struct GameState;

using ComponentsList =
mpl::TypeList<Transform, ImageComponent, Rotation, Score, AsteroidLifeTime, Health, GameState>;

// ** Groups
//
// start them with _grp_ to avoid conflicts (or make a name space)
//
struct _grp_Asteroid;
struct _grp_Bullet;

using GroupsList =
mpl::TypeList<_grp_Asteroid, _grp_Bullet>;

// ** handlers
//
// start them with _grp_ to avoid conflicts (or make a name space)
//
struct _hdlr_Fighter;
struct _hdlr_GameState;

using HandlersList =
mpl::TypeList<_hdlr_Fighter, _hdlr_GameState>;

// ** Systems
//
// they must match the name of the systems classes

class GameCtrlSystem; // sistema de control del juego (para empezar el juego, etc.)
class AsteroidsSystem; // sistema de los asteroids (para mover los asteroides)
class BulletsSystem; // sistema de las balas (para mover las balas)
class FighterSystem; // sistema del caza (para gestionar el movimiento del caza)
class FighterGunSystem; // sistema del arma (para disparar -- arma para el caza)
class CollisionSystem; // sistema de colisiones (para comprobar todas las colisiones)
class RenderSystem; // sistema de rendering (para dibujar las entidades, etc.)


//class _sys_GameCtrl; // sistema de control del juego (para empezar el juego, etc.)
//	class _sys_Asteroids; // sistema de los asteroids (para mover los asteroides)
//	class _sys_Bullets; // sistema de las balas (para mover las balas)
//	class _sys_Fighter; // sistema del caza (para gestionar el movimiento del caza)
//	class _sys_FighterGun; // sistema del arma (para disparar -- arma para el caza)
//	class _sys_Collisions; // sistema de colisiones (para comprobar todas las colisiones)
//	class _sys_Render; // sistema de rendering (para dibujar las entidades, etc.)

using SystemsList =
mpl::TypeList<GameCtrlSystem, AsteroidsSystem, BulletsSystem, FighterSystem, FighterGunSystem, CollisionSystem, RenderSystem>;
/*using SystemsList =
mpl::TypeList<_sys_GameCtrl, _sys_Asteroids, _sys_Bullets, _sys_Fighter, _sys_FighterGun, _sys_Collisions, _sys_Render>;*/

constexpr std::size_t maxComponents = ComponentsList::size;
constexpr std::size_t maxGroups = GroupsList::size;
constexpr std::size_t maxHandlers = HandlersList::size;
constexpr std::size_t maxSystems = SystemsList::size;


// These macros are obselete ... you can ucomment them if needed,
// but better use getComponent directly

/*
// these two should be used to get a component via the field
// entity_
#define GETCMP2_(id,type)  GETCMP2(entity_,type)
#define GETCMP1_(type)     GETCMP2(entity_,type)

// these two should be used to get a component via an
// entity e provided as a parameter
#define GETCMP2(e,type) e->getComponent<type>()
#define GETCMP3(e,id,type) e->getComponent<type>()
*/

