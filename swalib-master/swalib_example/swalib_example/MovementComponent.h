#pragma once
#include "Componente.h"
#include "../../common/vector2d.h"

class MovementComponent : public Componente
{
    vec2 Vel;
    vec2 Pos;
    
public:
    MovementComponent(Entity* owner);
    void Update(float elapsed) override;
    vec2 get_pos() const;
    void set_pos(const vec2& pos);
    vec2 get_vel() const;
    void set_vel(const vec2& vel);
    
};
