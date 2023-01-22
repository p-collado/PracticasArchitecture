#pragma once

class CTexture
{

    unsigned int id;

public:
    inline unsigned int getTextureId() const
    {
        return id;
    }
    void LoadTexture(const char* filename, bool _alpha);
};
