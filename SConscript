from building import *
import rtconfig
import os

cwd = GetCurrentDir()
src = []
src = src + Glob('./*.c')
src = src + Glob('./architecture/*.c')
src = src + Glob('./core/*.c')
src = src + Glob('./kernel/*.c')
src = src + Glob('./project/*.c')
src = src + Glob('./platform/rtthread/*.c')

inc = []
inc = inc + [cwd]
inc = inc + [cwd + '/architecture']
inc = inc + [cwd + '/core']
inc = inc + [cwd + '/kernel']
inc = inc + [cwd + '/project']
inc = inc + [cwd + '/platform/rtthread']
inc = inc + [cwd + '/platform/modules']

if GetDepend('PKG_PAINTERENGINE_USING_DEMO'):
	src = src + Glob('./demo/*.c')
	inc = inc + [cwd + '/demo']

LOCAL_CCFLAGS = ''

group = DefineGroup('painterengine', src, depend = ['PKG_USING_PAINTERENGINE'], CPPPATH = inc, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
