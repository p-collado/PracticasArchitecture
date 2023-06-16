﻿#include "MovementComponent.h"
#include "EntCollisionMsg.h"
#include "Entity.h"
#include "LimitWorldCallMsg.h"
#include "NewPosMsg.h"
#include "../../common/sys.h"

vec2 MovementComponent::get_pos() const
{
    return Pos;
}

void MovementComponent::set_pos(const vec2& pos)
{
    Pos = pos;
}

vec2 MovementComponent::get_vel() const
{
    return Vel;
}

void MovementComponent::set_vel(const vec2& vel)
{
    Vel = vel;
}

void MovementComponent::RecieveMessage(Message* Msg)
{
    EntCollisionMsg* EntMsg = dynamic_cast<EntCollisionMsg*>(Msg);
    if(EntMsg)
    {
       Vel *= -1;
    }

    LimitWorldCallMsg* Limit = dynamic_cast<LimitWorldCallMsg*>(Msg);
    if (Limit)
    {
        Limit->Axis ? Vel = vec2(Vel.x, Vel.y * -1.f): Vel = vec2(Vel.x * -1.f ,Vel.y);
       // Vel = Limit->VelLimit;

    }
}

MovementComponent::MovementComponent(Entity* owner)
{
    Owner = owner;
    Pos = vec2(CORE_FRand(21, SCR_WIDTH - 21), CORE_FRand(21 + 100.f, SCR_HEIGHT - 21));
    Vel = vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED));
}

void MovementComponent::Update(float elapsed)
{
    Pos = Pos + Vel * elapsed;
    NewPosMsg PosMsg;
    PosMsg.Pos = Pos;
    PosMsg.Vel = Vel;
    Owner->SendMsg(&PosMsg);
}
