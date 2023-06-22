#include "HookComponent.h"
#include "entity.h"
#include "LimitWorldCallMsg.h"
#include "MovementComponent.h"

HookComponent::HookComponent(Entity* _Eowner)
{
  Owner = _Eowner;
}

void HookComponent::Update(float _elapsedTime)
{
}

void HookComponent::RecieveMessage(Message* message)
{
  LimitWorldCallMsg* collMsg = dynamic_cast<LimitWorldCallMsg*>(message);
  if (collMsg)
  {
    disableShot();
  }
}

void HookComponent::disableShot()
{
  Owner->FindComponent<MovementComponent>()->set_pos(vec2(-100, -100));
  Owner->Enabled = 0;
}
