cd $GADEI_HOME/torch/cifar.torch# Compile

    git clone git@github.rtp.raleigh.ibm.com:weiz-us/gadei.git
    cd gadei
    source gadei.profile && make

    cd $GADEI_HOME/user/c && source gadei.user.c.profile && make

    cd $GADEI_HOME/lua
    cmake -E make_directory build && cd build && cmake .. && make

    mkdir -p $GADEI_HOME/lua/gadei
    cp $GADEI_HOME/lua/init.lua $GADEI_HOME/lua/gadei
    cp $GADEI_HOME/lua/build/liblgadei.so $GADEI_HOME/lua/gadei

# cifar.torch

Copy provider.t7 to $GADEI_HOME/torch/cifar.torch

    export LUA_CPATH="$GADEI_HOME/lib/?.so;$GADEI_HOME/lua/gadei/?.so;"$LUA_CPATH
    export LUA_PATH="$GADEI_HOME/lua/?/init.lua;"$LUA_PATH
    export LD_LIBRARY_PATH="$GADEI_HOME/lib/":$LD_LIBRARY_PATH

    cd $GADEI_HOME/torch/cifar.torch
    ./run.sh

==========backup==========


mkdir ../gadei && cd ../gadei
cp ../init.lua .
cp ../build/liblgadei.so .

# Run

export LUA_CPATH='/home/yren/gadei/lib/?.so;/home/yren/gadei/lua/gadei/?.so;'$LUA_CPATH
export LUA_PATH='/home/yren/gadei/lua/?/init.lua;'$LUA_PATH
export LD_LIBRARY_PATH=/home/yren/gadei/lib/:$LD_LIBRARY_PATH

th
require 'liblgadei'

# cifar torch

## Data preprocessing

    OMP_NUM_THREADS=2 th -i provider.lua

    provider = Provider()
    provider:normalize()
    torch.save('provider.t7',provider)

## Start learner

th train.lua --batchSize 128 --epoch_step 13 --model vgg_bn_drop -s logs/vgg2_0 --type float --gadei_conf "/home/yren/gadei/torch/cifar.torch/cifar_ipc.conf" --gadei_lid 0 --gpu_id 1 > lid-0.log 2>&1 &

th train.lua --batchSize 128 --epoch_step 13 --model vgg_bn_drop -s logs/vgg2_1 --type float --gadei_conf "/home/yren/gadei/torch/cifar.torch/cifar_ipc.conf" --gadei_lid 1 --gpu_id 2 > lid-1.log 2>&1 &

# misc
rsync -avL --exclude=.git/ /home/ren/git/gadei yren@digits01.watson.ibm.com:~




On digits machine:

    export NLC_PLATFORM=

    export GADEI_HOME=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
    export TORCH_HOME=/home/yren/torch/install/
    export CUDA_HOME=/usr/local/cuda-7.5/
