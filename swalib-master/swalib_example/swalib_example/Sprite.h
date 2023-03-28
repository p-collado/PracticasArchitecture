#pragma once
#include "Componente.h"
#include "../../common/vector2d.h"

class Entity;
class CTexture;
class Sprite : public Componente
{
    CTexture* texture;
    vec2 pos;
    vec2 size;
    Entity* owner;
  
public:
    Sprite(Entity* Owner, const char* texturePath, bool Alpha);
    void setSize(vec2& _size);
    inline vec2 getSize() const {return size;}
    void setPos(vec2& pos);
    inline vec2 getPos() const {return pos;}
    CTexture* getTexture();
    void setTexture(CTexture* _ref);
    void LoadTexture(const char* filename, bool _alpha);
    virtual void draw();
    void free();
    virtual void Update(float elapsed) override;

};

