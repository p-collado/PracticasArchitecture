#pragma once
#include "Message.h"

class NewPosMsg : public Message
{
public:
    NewPosMsg(){}
    ~NewPosMsg(){}
    vec2 Pos;
    vec2 Vel;
};
