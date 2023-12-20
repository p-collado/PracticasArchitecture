#pragma once

#include "Componente.h"
#include "../../common/vector2d.h"

class entity;

class PlayerComponent: public Componente
{
public:
  PlayerComponent(Entity* _Eowner, int _lives);
  virtual void Update(float _elapsedTime) override;
  virtual void RecieveMessage(Message* message) override;

  void removeLife();

private:
  char InputMoveLeft = 'A';
  char InputMoveRight = 'D';
  char InputShoot = 'S';

  bool ResetInput;
  Entity* Shot;
  vec2 Pos;

};

