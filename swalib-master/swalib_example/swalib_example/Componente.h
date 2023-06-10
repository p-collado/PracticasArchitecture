#pragma once

#include "../../common/stdafx.h"
#include "../../common/core.h"

class Message;
class Entity;
class Componente
{
protected:
    Entity* Owner = nullptr;
public:
    virtual void Update(float elapsed) = 0;
    virtual void RecieveMessage(Message* Msg) = 0;
};
