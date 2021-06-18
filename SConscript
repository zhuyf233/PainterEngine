
from building import *
import rtconfig

cwd = GetCurrentDir()
src = []
src = src + Glob('./*.c')
src = src + Glob('./architecture/*.c')
src = src + Glob('./core/*.c')
src = src + Glob('./kernel/*.c')
src = src + Glob('./platform/rtthread/*.c')
src = src + Glob('./demo/*.c')

inc = []
inc = inc + Glob(cwd)
inc = inc + Glob('./architecture')
inc = inc + Glob('./core')
inc = inc + Glob('./kernel')
inc = inc + Glob('./platform/rtthread')
inc = inc + Glob('./platform/modules')
inc = inc + Glob('./demo')

LOCAL_CCFLAGS = ''

group = DefineGroup('PainterEngine', src, depend = ['PKG_USING_PAINTERENGINE'], CPPPATH = inc, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
