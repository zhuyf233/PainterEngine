#include "PX_Typedef.h"
#include <rtthread.h>

void PX_ASSERT(void)
{
#ifdef PX_DEBUG_MODE
*(char *)(0)=1;
#endif
}

void PX_ERROR(px_char fmt[])
{
    rt_kprintf(fmt);
	PX_ASSERT();
}


px_char * PX_GETLOG(void)
{
	return "";
}

void PX_LOG(px_char fmt[])
{
    rt_kprintf(fmt);
	//while(1);
}
