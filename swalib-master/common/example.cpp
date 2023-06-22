#include "..\swalib_example\swalib_example\Time.h"
#include "sys.h"
#include "..\swalib_example\swalib_example\CGame.h"
#include "..\swalib_example\swalib_example\CGameRender.h"
#include "..\swalib_example\swalib_example\EntityManager.h"

//-----------------------------------------------------------------------------
int Main(void)
{
	srand(28);
	Time time;
	CGame game;
	CGameRender* renderref = CGameRender::getInstance();
	EntityManager* EntityMref = EntityManager::getInstance();

	renderref->RenderInit();
	game.GameInit();
	//time.setTimeStart();
	//time.setTimeEndTime();
	//time.setTimeFreq();

	while (!SYS_GottaQuit())
	{
		// Controlling a request to terminate an application.

		if (GetKeyState(' ') & 0x8000)
		{
			game.Gamestarted = true;
		}
		
		if (game.Gamestarted)
		{
			time.LogicSlotInit();
			while (time.processSlot())
			{
				game.GameUpdate(time.getFixedTick());
			}
			
			time.CalculateFPS();
			renderref->GetTiempos(time.getFps(), time.getTiempoTranscurrido(), time.getTiempoLogica());
			renderref->Draw();
		}
		else
		{
			game.LoadMainMenu();
		}
		
		SYS_Pump();
	}
	// Process Windows messages.

		//SYS_Sleep(17);	// To force 60 fps

	renderref->RenderEnd();
	return 0;
}