#pragma once
#include "Componente.h"
#include "../../common/vector2d.h"

class CollisionComponent : public Componente
{
    vec2 Pos;
    float Radius;
    
public:
    CollisionComponent(Entity* owner, float radius);
    vec2 get_pos() const;
    void set_pos(const vec2& pos);
    float get_radius() const;
    void set_radius(const float radius);
    void Update(float elapsed) override;
    void RecieveMessage(Message* Msg) override;
};
