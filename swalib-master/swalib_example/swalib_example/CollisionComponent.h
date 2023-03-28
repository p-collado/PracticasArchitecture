#pragma once
#include "Componente.h"
#include "../../common/vector2d.h"

class CollisionComponent : public Componente
{
    vec2 Pos;
    float Radius;
    vec2 Vel;

public:
    CollisionComponent(Entity* owner);
    vec2 get_pos() const;
    void set_pos(const vec2& pos);
    float get_radius() const;
    void set_radius(const float radius);
    vec2 get_vel() const;
    void set_vel(const vec2& vel);
    virtual void Update(float elapsed) override;
};
