#pragma once

class Entity;
class Componente
{
protected:
    Entity* Owner = nullptr;
public:
    virtual void Update(float elapsed) = 0;
};
