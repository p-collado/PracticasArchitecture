#include "MovementComponent.h"

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

void MovementComponent::RecieveMessage(Message* Msg) //TODO: poner elses
{
    NewPosMsg* Msge = dynamic_cast<NewPosMsg*>(Msg);
    
    if (Msge)
    {
        Msge->Pos = Pos;
        Msge->Vel = Vel;
    }

    EntCollisionMsg* EntMsg = dynamic_cast<EntCollisionMsg*>(Msg);
    if(EntMsg)
    {
       Vel *= -1;
    }

    LimitWorldCallMsg* Limit = dynamic_cast<LimitWorldCallMsg*>(Msg);
    if (Limit)
    {
        Limit->Axis ? Vel = vec2(Vel.x, Vel.y * -1.f): Vel = vec2(Vel.x * -1.f ,Vel.y);
    }
}

MovementComponent::MovementComponent(Entity* owner)
{
    Owner = owner;
    Pos = vec2(CORE_FRand(20, SCR_WIDTH - 20), CORE_FRand(20, SCR_HEIGHT - 20));
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
