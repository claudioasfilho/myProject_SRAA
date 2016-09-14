/*
 * PID.h
 *
 *  Created on: Sep 13, 2016
 *      Author: clfilho
 */

#ifndef PID_H_
#define PID_H_

void SetDACOutput(uint16_t value);

void GetADC(uint16_t value);

void PIDHandler();

void DACOutputHandler();

#endif /* PID_H_ */
