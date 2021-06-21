#ifndef _PX_APP_H_
#define _PX_APP_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "PainterEngine_Startup.h"
#ifdef __cplusplus
}
#endif

typedef struct
{
    PX_Runtime runtime;
}PX_Application;

extern PX_Application App;

px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height);
px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elpased);
px_void PX_ApplicationRender(PX_Application *pApp,px_dword elpased);
px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e);

void init_px_thread(void);

#endif
