#pragma once

#include "Componente.h"
#include "../../common/vector2d.h"


class BallComponent : public Componente
{
public:
  BallComponent(Entity* _Eowner, int _splits);
  ~BallComponent();

  virtual void Update(float _elapsedTime) override;

  virtual void RecieveMessage(Message* message) override;

private:

  int splits;
  vec2 gravity;
  vec2 pos;
};

