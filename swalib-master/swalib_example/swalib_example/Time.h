#pragma once
#include "..\..\common\stdafx.h"
class Time
{
	LARGE_INTEGER StartTime;
	LARGE_INTEGER EndTime;
	LARGE_INTEGER frequency;
	double elapsed = 0;
	double delapsed = 0.f;
	double fixedTick = 1.f / 60;
	double fps = 0.f;
	double tiempoTranscurrido = 0.f;
	double tiempoLogica = 0.f;
	double timeMultiplier = 1.f;
	double counter = 0.f;
public:
	double GetTime();
	void LogicSlotInit();
	void setTimeEndTime();
	void setTimeStart();
	void setTimeFreq();
	void CalculateFPS();
	void setElapsed(double _elapsed);
	void setDelapsed(double _delapsed);
	void setTimeMultiplier(double _Timemul);
	double inline getFps() { return fps; };
	double inline getElapsed() { return elapsed; };
	double inline getDelapsed() { return delapsed; };
	double inline getTiempoTranscurrido() { return tiempoTranscurrido; };
	double inline getTiempoLogica() { return tiempoLogica; };
	double inline getMultiplier() { return timeMultiplier; };
	double inline getFixedTick() { return fixedTick; };
	bool processSlot();


};

