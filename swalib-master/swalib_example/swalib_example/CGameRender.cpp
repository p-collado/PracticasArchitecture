#include "CGameRender.h"
#include "CGame.h"
#include "../../common/font.h"
#include "../../common/core.h"
#include "../../common/sys.h"

extern const unsigned int NUM_BALLS;
extern tballs balls;

//unsigned int CGameRender::texbkg = 0;
//unsigned int CGameRender::texsmallball = 0;

void CGameRender::RenderInit()
{
  // Load textures
  texbkg = CORE_LoadPNG("..data/circle-bkg-128.png", true);
  texsmallball = CORE_LoadPNG("..data/tyrian_ball.png", false);

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
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), texbkg);
		}
	}

	// Render balls
	for (int i = 0; i < NUM_BALLS; i++) {
		CORE_RenderCenteredSprite(balls[i].pos, vec2(balls[i].radius * 2.f, balls[i].radius * 2.f), balls[i].gfx);
	}

	// Text
	FONT_DrawString(vec2(SCR_WIDTH / 2 - 6 * 16, 16), "HELLO WORLD!");

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
