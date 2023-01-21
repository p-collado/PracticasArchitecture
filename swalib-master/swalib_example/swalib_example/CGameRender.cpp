#include "CGameRender.h"
#include "CGame.h"
#include "../../common/font.h"
#include "../../common/core.h"
#include "../../common/sys.h"
extern const unsigned int NUM_BALLS;
extern tballs balls;

extern char text[100];
extern char text2[100];
extern char text3[100];
extern char text4[100];

void CGameRender::RenderInit()
{
	LoadTexture("data/circle-bkg-128.png", true);
	LoadTexture("data/tyrian_ball.png", false);

  // Load textures
 /* texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);*/
  
	/*for (size_t i = 0; i < EntityManager::getInstance()->getNumBalls(); i++)
	{
		EntityManager::getInstance()->getBalls()[i]->setGFX(texsmallball);
	}*/
	

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
			//CGameRender::RenderDrawSomething(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), texbkg);
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), texbkg);
		}
	}

	// Render balls
	for (int i = 0; i < EntityManager::getInstance()->getNumBalls(); i++) {
		CORE_RenderCenteredSprite(EntityManager::getInstance()->getBalls()[i]->getPos(), vec2(EntityManager::getInstance()->getBalls()[i]->getRadius() * 2.f, EntityManager::getInstance()->getBalls()[i]->getRadius() * 2.f), EntityManager::getInstance()->getBalls()[i]->getGFX());
	}

	// Text
	FONT_DrawString(vec2(450,0), text);
	FONT_DrawString(vec2(0,0), text2);
	FONT_DrawString(vec2(0,50), text3);
	FONT_DrawString(vec2(0,100), text4);

	// Exchanges the front and back buffers
	SYS_Show();
}

void CGameRender::RenderEnd()
{
	// End app.
// Unload textures.
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
	FONT_End();
}

unsigned int CGameRender::LoadTexture(const char* filename, bool _alpha)
{
	if (maptexture.count(filename))
	{
		return maptexture[filename]->getTexture();
	}

	maptexture[filename] = new Sprite();
	maptexture[filename]->LoadTexture(filename, _alpha);
}