#include "AsteroidsSystem.h"
#include "GameCtrlSystem.h"
//Metodo para evitar dependencias circulares 
void  AsteroidsSystem::SinAsteroides()
{
	mngr_->getSystem<GameCtrlSystem>()->onAsteroidsExtenction();

}