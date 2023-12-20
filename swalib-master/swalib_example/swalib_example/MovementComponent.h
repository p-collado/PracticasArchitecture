#pragma once
#include "Componente.h"
#include "../../common/vector2d.h"

class MovementComponent : public Componente
{
    vec2 Vel;
    vec2 Pos;
    float MAX_BALL_SPEED = 8.f * 20;
    float MaxBounce = 500.f;
    
public:
    MovementComponent(Entity* owner);
    MovementComponent(Entity* owner, vec2 _Pos, vec2 _Vel);
    void Update(float elapsed) override;
    vec2 get_pos() const;
    void set_pos(const vec2& pos);
    vec2 get_vel() const;
    void set_vel(const vec2& vel);
    void RecieveMessage(Message* Msg) override;
    
};
