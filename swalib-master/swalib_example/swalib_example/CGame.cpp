#include "CGame.h"
#include "EntityManager.h"
#include "CGameRender.h"


CGame* CGame::instance= nullptr;

CGame::CGame()
{
	Lives = 3;
	Currentlevel = 1;
	Gamestarted = false;
	CanRestart = false;
}

bool CGame::is_gamestarted() const
{
	return Gamestarted;
}

void CGame::set_gamestarted(const bool gamestarted)
{
	Gamestarted = gamestarted;
}

bool CGame::is_can_restart() const
{
	return CanRestart;
}

void CGame::set_can_restart(const bool can_restart)
{
	CanRestart = can_restart;
}

int CGame::get_currentlevel() const
{
	return Currentlevel;
}

void CGame::set_currentlevel(const int currentlevel)
{
	Currentlevel = currentlevel;
}

int CGame::get_lives() const
{
	return Lives;
}

void CGame::set_lives(const int lives)
{
	Lives = lives;
}

void CGame::InitValues()
{
	Lives = 3;
	Currentlevel = 1;
	Gamestarted = false;
	CanRestart = false;
}

void CGame::LoadWinMenu()
{
	CGameRender::getInstance()->DrawWinMenu();
}

CGame* CGame::getInstance()
{
	if (instance)
	{
		return instance;
	}
	return instance = new CGame();
}

void CGame::SetCanRestart(bool value)
{
	CanRestart = value;
}

void CGame::GameInit()
{
	EntityManager::getInstance()->LoadLevel1();
}

void CGame::GameUpdate(double _elapsed)
{
	if (CanRestart)
	{
		LoadLevel(Currentlevel);
		CanRestart = false;
	}
	EntityManager::getInstance()->Slot(_elapsed);
}

void CGame::GameEnd()
{

}

void CGame::LoadMainMenu()
{
	CGameRender::getInstance()->DrawMenu();
}

void CGame::LoadLevel1()
{
	EntityManager::getInstance()->LoadLevel1();
}

void CGame::LoadLevel2()
{
	EntityManager::getInstance()->LoadLevel2();
}

void CGame::LoadLevel(int level)
{
	switch (level)
	{
	case 1:
		{
			LoadLevel1();
		}
		break;
	case 2:
		{
			LoadLevel2();
		}
		break;
	default: ;
	}
}

void CGame::LoadGameOverMenu()
{
	CGameRender::getInstance()->DrawGameOverMenu();
}
