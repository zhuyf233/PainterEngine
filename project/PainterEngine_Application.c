#include <rtthread.h>
#include "PainterEngine_Application.h"

static PX_Object *root, *msgbox;

RT_WEAK px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height)
{
    PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
    root = PX_ObjectCreate(&pApp->runtime.mp_ui , PX_NULL, 0, 0, 0, 0, 0, 0);
    msgbox = PX_Object_MessageBoxCreate (&pApp->runtime.mp_ui , root, PX_NULL);
    PX_Object_MessageBoxAlert(msgbox, "Hello PainterEngine!");
    return PX_TRUE;
}

RT_WEAK px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elpased)
{

}

RT_WEAK px_void PX_ApplicationRender(PX_Application *pApp,px_dword elpased)
{
    px_surface *pRenderSurface=&pApp->runtime.RenderSurface;
    PX_RuntimeRenderClear(&pApp->runtime,PX_OBJECT_UI_DEFAULT_BACKGROUNDCOLOR);

    PX_ObjectRender(pRenderSurface, root, elpased);
}

RT_WEAK px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e)
{
    PX_ApplicationEventDefault(&pApp->runtime, e);
}
