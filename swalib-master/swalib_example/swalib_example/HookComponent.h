#pragma once

#include "Componente.h"

class HookComponent: public Componente
{
public:
  HookComponent(Entity* _Eowner);

  virtual void Update(float _elapsedTime) override;
  virtual void RecieveMessage(Message* message) override;

  void disableShot();
};

