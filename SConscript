from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = Glob('/common/src/*.c')

path    = [cwd + '/common/inc/']

LOCAL_CCFLAGS = ''

group = DefineGroup('filex', src, depend = ['PKG_USING_FILEX'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')