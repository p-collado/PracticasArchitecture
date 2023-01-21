#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "..\swalib_example\CGame.h"
#include "..\swalib_example\CGameRender.h"
#include "..\swalib_example\EntityManager.h"
#include "..\swalib_example\Time.h"

double GetTime(LARGE_INTEGER* _Current, LARGE_INTEGER* _Previous, LARGE_INTEGER* _freq);
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
	EntityManager* ref = EntityManager::getInstance();
	ref->Init();

	renderref->RenderInit();
	game.GameInit();

	//LARGE_INTEGER StartTime;
	//QueryPerformanceCounter(&StartTime);
	time.setTimeStart();


	//LARGE_INTEGER EndTime;
	time.setTimeEndTime();
	//LARGE_INTEGER frequency;
//	QueryPerformanceFrequency(&frequency);
	time.setTimeFreq();
	//double elapsed = 0;
	//double delapsed = 0.f;
	//double fixedTick = 1.f / 60;
	//double fps = 0.f;
	//double tiempoTranscurrido = 0.f;
	//double tiempoLogica = 0.f;
	//double timeMultiplier = 1.f;
	//int counter = 0;

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

		//QueryPerformanceCounter(&EndTime);
		//elapsed += GetTime(&EndTime, &StartTime, &frequency);
		//elapsed *= timeMultiplier;

		//if (elapsed > 1.f / 15) //2.6 Solucion de la espiral
		//{
		//	elapsed = 1.f / 15;
		//}
		
		//delapsed = GetTime(&EndTime, &StartTime, &frequency);
		//tiempoTranscurrido += delapsed;
		//StartTime = EndTime;

			//while (elapsed >= fixedTick) 
			//{
			//	//SYS_Sleep(17);  //2.5 efectivamente va bajando los FPS progresivamente, espiral de la muerte no solucionado
			//	counter += 1;
			//	game.GameUpdate(fixedTick);
			//	elapsed = elapsed - fixedTick;
			//	tiempoLogica += fixedTick;
			//}

			time.LogicSlotInit();
			while (time.processSlot())
			{
				game.GameUpdate(time.getFixedTick());
			}

			time.setFPS();
		
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


double GetTime(LARGE_INTEGER* _Current, LARGE_INTEGER* _Time, LARGE_INTEGER* _freq)
{
	double result;
	return	result = static_cast<double>(_Current->QuadPart - _Time->QuadPart) / (_freq->QuadPart);

}