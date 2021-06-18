#include <rtthread.h>
#include <rtdevice.h>
#include "PX_App.h"
#include "px_display.h"

static rt_device_t lcd;
static struct rt_device_graphic_info info;

static rt_uint16_t ARGB8888ToRGB565(px_color c) {
    rt_uint16_t blue  = c._argb.b >> 3;
    rt_uint16_t green = c._argb.g >> 2;
    rt_uint16_t red   = c._argb.r >> 3;

    return (red << 11) | (green << 5) | (blue);
}

void px_display_device_init(int *width, int *height)
{
    lcd = rt_device_find(PKG_PAINTERENGINE_DISPLAY_DEVICE_NAME);
    rt_device_control(lcd, RTGRAPHIC_CTRL_GET_INFO, &info);
    *width = info.width;
    *height = info.height;
}

void px_display_device_update(px_surface surface)
{
    if (info.pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB565)
    {
        for (int y = 0; y < info.height; y++)
            for (int x = 0; x < info.width; x++)
                ((rt_uint16_t *)info.framebuffer)[x + info.width * y] = ARGB8888ToRGB565(surface.surfaceBuffer[x + info.width * y]);
    }
    else if(info.pixel_format == RTGRAPHIC_PIXEL_FORMAT_RGB888)
    {
        for (int i = 0; i < (info.height * info.width); i++)
        {
            info.framebuffer[3 * i] = surface.surfaceBuffer[i]._argb.b;
            info.framebuffer[3 * i + 1] = surface.surfaceBuffer[i]._argb.g;
            info.framebuffer[3 * i + 2] = surface.surfaceBuffer[i]._argb.r;
        }
    }
    rt_device_control(lcd, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
}

