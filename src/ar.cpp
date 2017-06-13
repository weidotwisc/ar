/*
 * ar.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: weiz
 */
#include "ar.h"
#include <stdlib.h>
#include<mpi.h>
#include <iostream>
//#include <cuda.h>
//#include <cuda_runtime_api.h>
#ifdef __cplusplus
extern "C"{
#endif
void init(){
	int provided, claimed;
	MPI_Init_thread( 0, 0,  MPI_THREAD_MULTIPLE, &provided );// just ask for  MPI_THREAD_MULTIPLE for now
	if(provided < MPI_THREAD_MULTIPLE){
		std::cerr<<" the provided level MPI thread support is "<<provided<<std::endl;
		exit(1);
	}
	std::cout<<"MPI thread support is at level "<<provided<<std::endl;

}


void allreduce(float *buf, int count){

	MPI_Allreduce(MPI_IN_PLACE, buf, count, MPI_FLOAT, MPI_SUM,MPI_COMM_WORLD);
}

int getRank(){
	int rank;
	 MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	 return rank;
}
void finalize(){
	MPI_Finalize();
}
#ifdef __cplusplus
}
#endif


