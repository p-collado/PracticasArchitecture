//#include "stdafx.h"
#include "..\swalib_example\swalib_example\Time.h"
#include "sys.h"
#include "..\swalib_example\swalib_example\CGame.h"
#include "..\swalib_example\swalib_example\CGameRender.h"
#include "..\swalib_example\swalib_example\EntityManager.h"


char text[100];
char text2[100];
char text3[100];
char text4[100];

//-----------------------------------------------------------------------------
int Main(void)
{
	Time time;
	CGame game;
	CGameRender* renderref = CGameRender::getInstance();
	EntityManager* EntityMref = EntityManager::getInstance();

	renderref->RenderInit();
	game.GameInit();
	
	time.setTimeStart();
	time.setTimeEndTime();
	time.setTimeFreq();

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

			time.LogicSlotInit();
			while (time.processSlot())
			{
				game.GameUpdate(time.getFixedTick());
			}

			time.CalculateFPS();
			renderref->Draw();

			sprintf(text, "FPS: %.2f", time.getFps());
			sprintf(text2, "TIEMPO DE REAL: %.2f", time.getTiempoTranscurrido());
			sprintf(text3, "TIEMPO DE LOGICA: %.2f", time.getTiempoLogica());
			sprintf(text4, "MULTIPLICADOR DE TIEMPO: X%.2f", time.getMultiplier());
		}

		//SYS_Pump();	// Process Windows messages.
		//SYS_Sleep(17);	// To force 60 fps

	renderref->RenderEnd();
	return 0;
}