#include <rtthread.h>

#ifdef PKG_PAINTERENGINE_USING_FILESYSTEM

#include <dfs_posix.h>
#include "px_file.h"

int PX_SaveDataToFile(void *buffer,int size,const char path[])
{
    int fd=open(path, O_WRONLY | O_CREAT);
    if (fd >= 0)
    {
        write(fd, buffer, size);
        close(fd);
        return 1;
    }
    return 0;
}


PX_IO_Data PX_LoadFileToIOData(const char path[])
{
        int ret;
        struct stat buf;
        PX_IO_Data io;
        io.size = 0;
        int size;
        int fd = open(path, O_RDONLY);
        int filesize;
        if (fd < 0)
        {
            return io;
        }
        ret = stat(path, &buf);
        filesize = buf.st_size;

        io.buffer=(unsigned char *)rt_malloc(filesize+1);
        if (!io.buffer)
        {
            goto _ERROR;
        }

        size = read(fd, io.buffer, filesize);
        close(fd);
        if (size < 0)
        {
            goto _ERROR;
        }

        io.buffer[filesize]='\0';
        io.size=filesize;
        return io;
        _ERROR:
        if(io.buffer != RT_NULL)
        {
            rt_free(io.buffer);
            io.buffer = 0;
        }
        io.size = 0;
        return io;
}

void PX_FreeIOData(PX_IO_Data *io)
{
    if (io->size&&io->buffer)
    {
        rt_free(io->buffer);
        io->size=0;
        io->buffer=0;
    }
}

#endif

