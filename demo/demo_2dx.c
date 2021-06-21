#include <rtthread.h>
#include "PainterEngine_Startup.h"
#include "PainterEngine_Application.h"
#include "px_file.h"

#ifdef PKG_PAINTERENGINE_USING_DEMO_2DX

PX_Animationlibrary animationLibrary;
PX_Animation animation;
px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height)
{
    PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
    PX_LoadAnimationLibraryFromFile(&pApp->runtime.mp_resources, &animationLibrary, "sdcard/fox.2dx");
    PX_AnimationCreate(&animation, &animationLibrary);
    PX_AnimationSetCurrentPlayAnimationByName(&animation, "run");
    return PX_TRUE;
}

px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elpased)
{
    PX_AnimationUpdate(&animation, elpased);
}

px_void PX_ApplicationRender(PX_Application *pApp,px_dword elpased)
{
    px_surface *pRenderSurface=&pApp->runtime.RenderSurface;
    PX_RuntimeRenderClear(&pApp->runtime,PX_COLOR_WHITE);
    PX_AnimationRender(pRenderSurface, &animation, pRenderSurface->width / 2, pRenderSurface->height / 2, PX_ALIGN_CENTER, PX_NULL);
}

px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e)
{
    PX_ApplicationEventDefault(&pApp->runtime, e);

}

#endif

