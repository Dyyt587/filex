from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = []
src += Glob('/common/src/*.c')
# if GetDepend(['PKG_USING_FILEX_DEMO']):
#     src += Glob("flexible_button_demo.c")


path    = [cwd + '/common/inc']


group = DefineGroup('filex', src, depend = ['PKG_USING_FILEX'], CPPPATH = path)

Return('group')
