/*
 * test.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: weiz
 */
#include "ar.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	init();
	float a[10] = {1};
	for(int i = 0 ; i < 10; ++i){
			a[i] = 1;
		}
	allreduce(a, 10);
	for(int i = 0 ; i < 10; ++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	finalize();
}



