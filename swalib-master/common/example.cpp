#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "..\swalib_example\CGame.h"
#include "..\swalib_example\CGameRender.h"

double GetTime(LARGE_INTEGER* _Current, LARGE_INTEGER* _Previous, LARGE_INTEGER* _freq);
char text[100];
char text2[100];
char text3[100];
char text4[100];

//-----------------------------------------------------------------------------
int Main(void)
{
	CGame game;
	CGameRender render;

	render.RenderInit();
	game.GameInit(render.texsmallball);

	LARGE_INTEGER StartTime;
	QueryPerformanceCounter(&StartTime);
	LARGE_INTEGER EndTime;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	//LARGE_INTEGER elapsed;
	double elapsed = 0;
	double delapsed = 0.f;
	double fixedTick = 1.f / 60;
	double fps = 0.f;
	double tiempoTranscurrido = 0.f;
	double tiempoLogica = 0.f;
	double timeMultiplier = 1.f;
	int counter = 0;

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

		QueryPerformanceCounter(&EndTime);
		elapsed += GetTime(&EndTime, &StartTime, &frequency);
		elapsed *= timeMultiplier; //2.7 Multiplicador de tiempo

		if (elapsed > 1.f / 15) //2.6 Solucion de la espiral
		{
			elapsed = 1.f / 15;
		}

		delapsed = GetTime(&EndTime, &StartTime, &frequency);
		tiempoTranscurrido += delapsed;
		StartTime = EndTime;
		if (elapsed > 0) {

			while (elapsed >= fixedTick) 
			{
				//SYS_Sleep(17);  //2.5 efectivamente va bajando los FPS progresivamente, espiral de la muerte no solucionado
				game.GameUpdate(fixedTick);
				elapsed = elapsed - fixedTick;
				tiempoLogica += fixedTick;
				++counter;
			}

			fps = counter / tiempoTranscurrido;
			render.Draw();

			sprintf(text, "FPS: %.2f", fps);
			sprintf(text2, "TIEMPO DE REAL: %.2f", tiempoTranscurrido);
			sprintf(text3, "TIEMPO DE LOGICA: %.2f", tiempoLogica);
			sprintf(text4, "MULTIPLICADOR DE TIEMPO: X%.2f", timeMultiplier);
		}

		//SYS_Pump();	// Process Windows messages.
		//SYS_Sleep(17);	// To force 60 fps

	}
	render.RenderEnd();
	return 0;
}


double GetTime(LARGE_INTEGER* _Current, LARGE_INTEGER* _Time, LARGE_INTEGER* _freq)
{
	double result;
	return	result = static_cast<double>(_Current->QuadPart - _Time->QuadPart) / (_freq->QuadPart);

}