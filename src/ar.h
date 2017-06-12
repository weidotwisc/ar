/*
 * ar.h
 *
 *  Created on: Jun 7, 2017
 *      Author: weiz
 */

#ifndef AR_H_
#define AR_H_

#ifdef __cplusplus
extern "C" {
#endif
void init();

void allreduce(float *buf, int cnt);

void finalize();
#ifdef __cplusplus
}
#endif

#endif /* AR_H_ */
