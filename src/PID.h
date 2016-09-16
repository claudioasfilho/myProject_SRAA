/*
 * PID.h
 *
 *  Created on: Sep 13, 2016
 *      Author: clfilho
 */

#ifndef PID_H_
#define PID_H_

SI_SBIT (TEST1,SFR_P3, 3);			   //Test LED
#define ToogleTest1() TEST1^=1;


void SetDACOutput(uint16_t value);

void GetADC(uint16_t value);

void PIDHandler();

void DACOutputHandler();

void DimmerCounterHandler();

#endif /* PID_H_ */
