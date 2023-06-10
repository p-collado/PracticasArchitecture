#pragma once
#include "CollisionMsg.h"

class LimitWorldCallMsg : public CollisionMsg
{
public:
    LimitWorldCallMsg(){}
    ~LimitWorldCallMsg(){}
    bool Axis; // X = false, Y = true
};
