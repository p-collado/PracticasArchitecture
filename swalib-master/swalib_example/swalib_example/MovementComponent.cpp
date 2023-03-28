#include "MovementComponent.h"

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

MovementComponent::MovementComponent(Entity* owner)
{
    Owner = owner;
}

void MovementComponent::Update(float elapsed)
{
    vec2 newpos = Pos + Vel * elapsed;
}
