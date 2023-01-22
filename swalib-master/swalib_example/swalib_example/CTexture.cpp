#include "CTexture.h"
#include "../../common/stdafx.h"
#include "../../common/core.h"

void CTexture::LoadTexture(const char* filename, bool _alpha)
{
    id = CORE_LoadPNG(filename, true);
}