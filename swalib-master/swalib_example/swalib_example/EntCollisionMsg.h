#pragma once
#include "CollisionMsg.h"

class Entity;
class EntCollisionMsg : public CollisionMsg
{
public:
    EntCollisionMsg(){}
    ~EntCollisionMsg(){}
    vec2 Vel;
    Entity* otherEnt;
};
