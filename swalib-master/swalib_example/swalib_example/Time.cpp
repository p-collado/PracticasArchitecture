#include "Time.h"
#include "EntityManager.h"
#include "Entity.h"

double Time::GetTime()
{
  return	static_cast<double>(EndTime.QuadPart - StartTime.QuadPart) / (frequency.QuadPart);
}

void Time::LogicSlotInit()
{

  QueryPerformanceCounter(&EndTime);
  elapsed += GetTime();
  elapsed *= timeMultiplier;

  if (elapsed > 1.f / 15) //2.6 Solucion de la espiral
  {
    elapsed = 1.f / 15;
  }

  delapsed = GetTime();

  tiempoTranscurrido += delapsed;
  StartTime = EndTime;

 
}

void Time::setTimeEndTime()
{
  QueryPerformanceCounter(&EndTime);
}

void Time::setTimeStart()
{
  QueryPerformanceCounter(&StartTime);
}

void Time::setTimeFreq()
{
  QueryPerformanceFrequency(&frequency);
}

void Time::CalculateFPS()
{
  fps = counter / tiempoTranscurrido;
}

void Time::setElapsed(double _elapsed)
{
  elapsed = _elapsed;
}

void Time::setDelapsed(double _delapsed)
{
  delapsed = _delapsed;
}

void Time::setTimeMultiplier(double _Timemul)
{
  timeMultiplier = _Timemul;
}

bool Time::processSlot()
{
  if (elapsed >= fixedTick)
  {
    counter += 1;
    elapsed = elapsed - fixedTick;
    tiempoLogica += fixedTick;
    return true;
  }
  return false;
}
