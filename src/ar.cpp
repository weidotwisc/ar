/*
 * ar.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: weiz
 */
#include "ar.h"

#include<mpi.h>
//#include <cuda.h>
//#include <cuda_runtime_api.h>
#ifdef __cplusplus
extern "C"{
#endif
void init(){
	MPI_Init(NULL, NULL);
}


void allreduce(float *buf, int count){
	MPI_Allreduce(MPI_IN_PLACE, buf, count, MPI_FLOAT, MPI_SUM,MPI_COMM_WORLD);
}

void finalize(){
	MPI_Finalize();
}
#ifdef __cplusplus
}
#endif


