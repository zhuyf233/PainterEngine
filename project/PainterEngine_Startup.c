#include <rtthread.h>
#include "PainterEngine_Startup.h"
#include "px_file.h"

static px_byte *PX_ApplicationRuntime = RT_NULL;
px_bool PX_ApplicationInitializeDefault(PX_Runtime *runtime, px_int screen_width, px_int screen_height)
{
    rt_uint32_t runtime_mem_size = PX_APPLICATION_MEMORYPOOL_UI_SIZE+PX_APPLICATION_MEMORYPOOL_RESOURCES_SIZE+PX_APPLICATION_MEMORYPOOL_GAME_SIZE+PX_APPLICATION_MEMORYPOOL_SPACE_SIZE;

    PX_ApplicationRuntime = rt_malloc(runtime_mem_size);
    if(PX_ApplicationRuntime == RT_NULL)
    {
        rt_kprintf("No memory for PainterEngine runtime!\n");
        return PX_FALSE;
    }
    if(!PX_RuntimeInitialize(runtime,
            screen_width,
            screen_height,
            screen_width,
            screen_height,
            PX_ApplicationRuntime,
            runtime_mem_size,
            PX_APPLICATION_MEMORYPOOL_UI_SIZE,
            PX_APPLICATION_MEMORYPOOL_RESOURCES_SIZE,
            PX_APPLICATION_MEMORYPOOL_GAME_SIZE))
        return PX_FALSE;
    return PX_TRUE;
}

px_void PX_ApplicationEventDefault(PX_Runtime *runtime,PX_Object_Event e)
{

}

px_bool PX_LoadTextureFromFile(px_memorypool *mp,px_texture *tex,const px_char path[])
{
    PX_IO_Data io;

    for(rt_uint8_t i = 0; i < 5; i++)
    {
        io=PX_LoadFileToIOData(path);
        if(io.size > 0)
        {
            break;
        }
        else if(i == 4)
        {
            rt_kprintf("Can not load file %s\n", path);
            return PX_FALSE;
        }
        rt_thread_mdelay(500);
    }
    if (PX_TextureCreateFromMemory(mp,io.buffer,io.size,tex))
    {
        PX_FreeIOData(&io);
        return PX_TRUE;
    }
    PX_FreeIOData(&io);
    return PX_FALSE;
}

px_bool PX_LoadAnimationLibraryFromFile(px_memorypool *mp,PX_Animationlibrary *lib,const px_char path[])
{
    PX_IO_Data io;
    for(rt_uint8_t i = 0; i < 5; i++)
    {
        io=PX_LoadFileToIOData(path);
        if(io.size > 0)
        {
            break;
        }
        else if(i == 4)
        {
            rt_kprintf("Can not load file %s\n", path);
            return PX_FALSE;
        }
        rt_thread_mdelay(500);
    }
    if (PX_AnimationLibraryCreateFromMemory(mp,lib,io.buffer,io.size))
    {
        PX_FreeIOData(&io);
        return PX_TRUE;
    }
    PX_FreeIOData(&io);
    return PX_FALSE;

}

