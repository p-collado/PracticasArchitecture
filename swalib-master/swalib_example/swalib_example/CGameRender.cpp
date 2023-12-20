#include "CGameRender.h"
#include <ctime>
#include "CGame.h"
#include "../../common/font.h"
#include "../../common/sys.h"
#include "../../common/stdafx.h"
#include "SpriteComponent.h"
#include "CTexture.h"

CGameRender* CGameRender::instance = nullptr;

CGameRender::CGameRender()
{
	
}

void CGameRender::GetTiempos(float fps, float tt, float tl)
{
	FPS = fps;
	tiempotranscurrido = tt;
	Tiempologica = tl;
}

void CGameRender::DrawMenu()
{
	glClear(GL_COLOR_BUFFER_BIT);
	FONT_DrawString(vec2(120, SCR_HEIGHT/2), "PULSA ENTER PARA EMPEZAR");
	SYS_Show();
}

void CGameRender::DrawTexts()
{
	char fps[100];
	char tt[100];
	char tl[100];
	char lives[20];
	sprintf(tt, "TIME: %.2f", tiempotranscurrido);
	sprintf(lives, "LIVES: %d", CGame::getInstance()->get_lives());
	//sprintf(fps, "FPS: %.2f", FPS);
	
	FONT_DrawString(vec2(0, 50), lives);
	FONT_DrawString(vec2(0, 25), tt);
}

void CGameRender::RenderInit()
{
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
		
		// Render balls
		for (int i = 0; i < spritesref.size(); i++) {
			if (spritesref[i]->GetEnable())
			{
				spritesref[i]->draw();
			}
		}
	
	DrawTexts();
		// Exchanges the front and back buffers
	SYS_Show();
}

 void CGameRender::RenderEnd()
 {
	 // End app.
 // Unload textures.

	 for (int i = 0; i < spritesref.size(); i++) {
		 spritesref[i]->free();
	 }

	 spritesref.clear();
	 maptexture.clear();
	 FONT_End();
 }

void CGameRender::DrawGameOverMenu()
{
	glClear(GL_COLOR_BUFFER_BIT);
	FONT_DrawString(vec2(SCR_WIDTH/2 - 75, SCR_HEIGHT/2), "GAME OVER");
	SYS_Show();
}

void CGameRender::PushText(char* string)
{
	 char temp [100];
	 sprintf_s(temp, string);
	 texts.push_back(temp);
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

CTexture* CGameRender::getTexture(const char* filename)
{
	return maptexture[filename];
}

SpriteComponent* CGameRender::getSpriteinPos(int i)
{
	return spritesref[i];
}

void CGameRender::PushSprite( SpriteComponent& ref)
{
	spritesref.push_back(&ref);
}

void CGameRender::DrawWinMenu()
{
	glClear(GL_COLOR_BUFFER_BIT);
	FONT_DrawString(vec2(SCR_WIDTH/2 - 75, SCR_HEIGHT/2), "YOU WIN");
	SYS_Show();
}


