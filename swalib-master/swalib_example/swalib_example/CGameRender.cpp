#include "CGameRender.h"
#include "../../common/font.h"
#include "../../common/sys.h"
#include "../../common/stdafx.h"
#include "../../common/core.h"
#include "EntityManager.h"
#include "Sprite.h"
#include "CTexture.h"

extern char text[100];
extern char text2[100];
extern char text3[100];
extern char text4[100];

CGameRender* CGameRender::instance = nullptr;

CGameRender::CGameRender()
{
	
}

void CGameRender::RenderInit()
{
	LoadTexture("data/circle-bkg-128.png", true);
	LoadTexture("data/tyrian_ball.png", false);


	spritesref.push_back(new Sprite);
	spritesref.back()->setTexture(maptexture["data/circle-bkg-128.png"]);
	
	for (int i = 0; i < EntityManager::getInstance()->getNumBalls();  i++)
	{
		spritesref.push_back(new Sprite);
		spritesref[i+1]->setTexture(maptexture["data/tyrian_ball.png"]);
	}


	
	FONT_Init();
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.
}


void CGameRender::Draw()
{
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2( spritesref[0]->getPos().x + (i * 128.f + 64.f), spritesref[0]->getPos().y + (j * 128.f + 64.f)), vec2(128.f, 128.f), spritesref[0]->getTexture()->getTextureId());
		}
	}

	// Render balls
	for (int i = 0; i < EntityManager::getInstance()->getNumBalls(); i++) {
		CORE_RenderCenteredSprite(spritesref[i+1]->getPos(), spritesref[i+1]->getSize() * 2, spritesref[i+1]->getTexture()->getTextureId());
	}

	// Text
	FONT_DrawString(vec2(450, 0), text);
	FONT_DrawString(vec2(0, 0), text2);
	FONT_DrawString(vec2(0, 50), text3);
	FONT_DrawString(vec2(0, 100), text4);

	// Exchanges the front and back buffers
	SYS_Show();
}

 void CGameRender::RenderEnd()
 {
	 // End app.
 // Unload textures.

	 for (const std::pair<const char*, CTexture*> var : maptexture)
	 {
		 CORE_UnloadPNG(var.second->getTextureId());
		 delete var.second;
	 }
	 for (const Sprite* var : spritesref)
	 {
		 delete var;
	 }
	 maptexture.clear();
	 FONT_End();
 }

CTexture* CGameRender::LoadTexture(const char* filename, bool _alpha)
{
	if (maptexture.count(filename))
	{
		return maptexture[filename];
	}
	maptexture[filename] = new CTexture;
	maptexture[filename]->LoadTexture(filename, _alpha);
	return maptexture[filename];
}

Sprite* CGameRender::getSpriteinPos(int i)
{
	return spritesref[i];
}