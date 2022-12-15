#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "..\swalib_example\CGame.h"
#include "..\swalib_example\CGameRender.h"

float GetTime(LARGE_INTEGER _Current ,LARGE_INTEGER _Previous);

//-----------------------------------------------------------------------------
int Main(void)
{
		CGame game;
		CGameRender render;

		render.RenderInit();
		game.GameInit(render.texsmallball);

		LARGE_INTEGER previousTime;
		QueryPerformanceCounter(&previousTime);
		LARGE_INTEGER currentTime;
		float elapsed = 0.f;
		float fixedTick = 1.f / 60.f;

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.
		QueryPerformanceCounter(&currentTime);
		elapsed = GetTime(currentTime,previousTime) /*currentTime - previousTime*/;
		previousTime = currentTime;
		if (elapsed > 0) {

			while (elapsed >= fixedTick) {
				game.GameUpdate();

				elapsed = elapsed - fixedTick;
			}
			render.Draw();
		}
		//SYS_Pump();	// Process Windows messages.
		//SYS_Sleep(17);	// To force 60 fps
	}
	render.RenderEnd();
	return 0;
}


float GetTime(LARGE_INTEGER _Current, LARGE_INTEGER _Time)
{
	LARGE_INTEGER frequency;
	float result;
	QueryPerformanceFrequency(&frequency);
	return	result = (static_cast<double>(_Current.QuadPart - _Time.QuadPart)) /static_cast<double>(frequency.QuadPart);

}