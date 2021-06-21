#include <rtthread.h>
#include <rtdevice.h>
#include "PainterEngine_Application.h"
#include "px_display.h"

PX_Application App;

static rt_thread_t tid1 = RT_NULL;

static void px_thread(void* parameter)
{
    int w, h;
    rt_tick_t ticknow, tickold, elpased;
    px_display_device_init(&w, &h);
    PX_ApplicationInitialize(&App, w, h);
    tickold = rt_tick_get();
    while(1)
    {
        ticknow = rt_tick_get();
        if(ticknow >= tickold)
        {
            elpased = ticknow - tickold;
        }
        else
        {
            elpased = RT_TICK_MAX - tickold + ticknow;
        }
        tickold = ticknow;

        PX_ApplicationUpdate(&App, elpased);
        PX_ApplicationRender(&App, elpased);
        px_display_device_update(App.runtime.RenderSurface);

        rt_thread_mdelay(5);
    }
}

void init_px_thread(void)
{
    tid1 = rt_thread_create("px",
            px_thread, RT_NULL,
            4096,
            28, 10);

    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);
}
