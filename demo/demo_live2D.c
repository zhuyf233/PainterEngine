#include <rtthread.h>
#include "PX_App.h"
#include "px_file.h"

#ifdef PKG_PAINTERENGINE_USING_DEMO_LIVE2D

PX_LiveFramework liveframework;
px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height)
{
	PX_IO_Data iodata;
	PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
	iodata=PX_LoadFileToIOData("sdcard/release.live");
	if(iodata.size==0)
	{
	    rt_kprintf("Can not load file 'sdcard/release.live'\n");
	    return PX_FALSE;
    }
	PX_LiveFrameworkImport(&pApp->runtime.mp_resources,&liveframework,iodata.buffer,iodata.size);
	PX_FreeIOData(&iodata);
	PX_LiveFrameworkPlayAnimation(&liveframework,0);
	return PX_TRUE;
}

px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elpased)
{
	if(liveframework.status==PX_LIVEFRAMEWORK_STATUS_STOP)PX_LiveFrameworkPlayAnimation(&liveframework,0);
}

px_void PX_ApplicationRender(PX_Application *pApp,px_dword elpased)
{
	px_surface *pRenderSurface=&pApp->runtime.RenderSurface;
	PX_RuntimeRenderClear(&pApp->runtime,PX_COLOR(255,255,255,255));
	PX_LiveRender(pRenderSurface,&liveframework,pRenderSurface->width/2,pRenderSurface->height/2,PX_ALIGN_CENTER,elpased);
}

px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e)
{
	PX_ApplicationEventDefault(&pApp->runtime, e);
}

#endif

