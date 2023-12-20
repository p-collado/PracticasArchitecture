#include "..\swalib_example\swalib_example\Time.h"
#include "sys.h"
#include "../swalib_example/swalib_example/EntityManager.h"
#include "..\swalib_example\swalib_example\CGame.h"
#include "..\swalib_example\swalib_example\CGameRender.h"

//-----------------------------------------------------------------------------
int Main(void)
{
	srand(28);
	Time time;
	CGame* game = CGame::getInstance();
	CGameRender* renderref = CGameRender::getInstance();
	EntityManager* EntityRef =  EntityManager::getInstance();
	
	renderref->RenderInit();

	while (!SYS_GottaQuit())
	{
		// Controlling a request to terminate an application.
		if (!game->is_gamestarted())
		{
			game->LoadMainMenu();
			
			if (GetKeyState(' ') & 0x8000)
			{
				game->LoadLevel1();
				game->InitValues();
				game->set_gamestarted(true);
			}
		}
		
		else if (game->get_lives()< 0)
		{
			CGame::getInstance()->LoadGameOverMenu();
			
			if (GetKeyState(' ') & 0x8000)
			{
				game->set_gamestarted(false);
			}
		}
		else if(game->get_currentlevel() == 2 && EntityRef->GetCounterEntity() == 0)
		{
			game->LoadWinMenu();
		}
		else if(EntityRef->GetCounterEntity() == 0)
		{
			game->set_currentlevel(2);
			game->LoadLevel(game->get_currentlevel());
		}
		else
		{
			time.LogicSlotInit();
			while (time.processSlot())
			{
				game->GameUpdate(time.getFixedTick());
			}
			
			time.CalculateFPS();
			renderref->GetTiempos(time.getFps(), time.getTiempoTranscurrido(), time.getTiempoLogica());
			renderref->Draw();
		}
		
		// Process Windows messages.
		SYS_Pump();
	}

	renderref->RenderEnd();
	return 0;
}