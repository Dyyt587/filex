#!/bin/bash

cd $(dirname $0)

# if threadx repo does not exist, clone it
[ -d threadx ] || git clone https://github.com/eclipse-threadx/threadx.git --depth 1
[ -f .run.sh ] || ln -sf threadx/scripts/cmake_bootstrap.sh .run.sh
./.run.sh $*