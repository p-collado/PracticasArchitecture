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
	game.LoadMainMenu();
	time.setTimeStart();
	//time.setTimeEndTime();
	time.setTimeFreq();

	while (!SYS_GottaQuit())
	{
		// Controlling a request to terminate an application.

		if (GetKeyState(' ') & 0x8000)
		{
			// game.GameInit();
			// time.setTimeStart();
			// time.setTimeEndTime();
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
			//renderref->DrawTexts();

		}
		else
		{
			game.LoadMainMenu();
		}
		// renderref->sprintf(text, "FPS: %.2f", time.getFps());
		// sprintf(text2, "TIEMPO DE REAL: %.2f", time.getTiempoTranscurrido());
		// sprintf(text3, "TIEMPO DE LOGICA: %.2f", time.getTiempoLogica());
		// sprintf(text4, "MULTIPLICADOR DE TIEMPO: X%.2f", time.getMultiplier());
		SYS_Pump();
	}
	// Process Windows messages.

		//SYS_Sleep(17);	// To force 60 fps

	renderref->RenderEnd();
	return 0;
}