#include "CGame.h"
#include "EntityManager.h"
#include "CGameRender.h"

void CGame::GameInit()
{
	EntityManager::getInstance()->Init();
}

void CGame::GameUpdate(double _elapsed)
{
	EntityManager::getInstance()->Slot(_elapsed);
}

void CGame::GameEnd()
{

}

void CGame::LoadMainMenu()
{
	CGameRender::getInstance()->DrawMenu();
}
