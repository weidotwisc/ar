DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
export AR_HOME=$DIR
if  [ x$AR_PLATFORM == "xMAC" ] 
then
     echo "MAC"
     export MPI_HOME=/Users/weiz/install
     export MPICXX=${MPI_HOME}/bin/mpicxx
     export MPI_INCL_DIR=${MPI_HOME}/include
     export MPI_LIB_DIR=${MPI_HOME}/lib
     ##export CXX=/usr/local/Cellar/gcc/7.1.0/bin/g++-7 ## for -fopenmp
     export CXX=g++
elif [ x$AR_PLATFORM == "xdyce" ] 
then
     echo "DYCE"
     export MPI_HOME=/mnt/nfs/nfsshare/user_homes/weiz/install
     export MPICXX=${MPI_HOME}/bin/mpicxx
     export MPI_INCL_DIR=${MPI_HOME}/include
     export MPI_LIB_DIR=${MPI_HOME}/lib
     export CXX=g++
elif [ x$AR_PLATFORM == "xdigits" ] 
then
     echo "digits"
     export MPI_HOME=/raid/weiz/install
     export MPICXX=${MPI_HOME}/bin/mpicxx
     export MPI_INCL_DIR=${MPI_HOME}/include
     export MPI_LIB_DIR=${MPI_HOME}/lib
     export CXX=g++
fi
     