#include <rtthread.h>
#include "PainterEngine_Startup.h"
#include "PainterEngine_Application.h"
#include "px_file.h"

#ifdef PKG_PAINTERENGINE_USING_DEMO_PARTICAL

PX_Partical_Launcher launcher;
px_texture texture;
px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height)
{
	PX_ParticalLauncher_InitializeInfo ParticalInfo;
	PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
	PX_LoadTextureFromFile(&pApp->runtime.mp_resources, &texture, "sdcard/star.traw");

	PX_ParticalLauncherInitializeDefault(&ParticalInfo);
	ParticalInfo.deviation_rangAngle = 360;
	ParticalInfo.deviation_velocity = 10;
	ParticalInfo.direction = PX_POINT(0, -1, 0);
	ParticalInfo.generateDuration = 100;
	ParticalInfo.launchCount = -1;
	ParticalInfo.maxCount = 100;
	ParticalInfo.position = PX_POINT(pApp->runtime.surface_width / 2.f, pApp->runtime.surface_height / 2.f, 0);
	ParticalInfo.tex = &texture;
	ParticalInfo.velocity = 60;
	ParticalInfo.alive = 5000;
	ParticalInfo.rotation = 180;
	ParticalInfo.deviation_rotation = 90;
	ParticalInfo.atomsize = 0.7f;
	ParticalInfo.deviation_atomsize = 0.3f;
	ParticalInfo.alpha = 0.8f;
	ParticalInfo.deviation_alpha = 0.3f;
	ParticalInfo.deviation_hdrR = 0.5f;
	ParticalInfo.deviation_hdrG = 0.5f;
	ParticalInfo.deviation_hdrB = 0.5f;
	ParticalInfo.alphaincrease = -0.2f;

	PX_ParticalLauncherCreate(&launcher, &pApp->runtime.mp_game, ParticalInfo);
	return PX_TRUE;
}

px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elpased)
{
}

px_void PX_ApplicationRender(PX_Application *pApp,px_dword elpased)
{
	px_surface *pRenderSurface=&pApp->runtime.RenderSurface;
	PX_RuntimeRenderClear(&pApp->runtime,PX_COLOR(255,33,33,33));
	PX_ParticalLauncherSetPosition(&launcher, PX_POINT(pRenderSurface->width / 2.f, pRenderSurface->height / 2.f,0));
	PX_ParticalLauncherRender(pRenderSurface, &launcher, elpased);
}

px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e)
{
	PX_ApplicationEventDefault(&pApp->runtime, e);

}


#endif

