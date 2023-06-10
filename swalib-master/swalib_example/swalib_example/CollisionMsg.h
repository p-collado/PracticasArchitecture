#pragma once
#include "Message.h"

class CollisionMsg : public Message
{
public:
    CollisionMsg() = default;
    ~CollisionMsg() override = default;
};
