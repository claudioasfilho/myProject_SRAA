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
#define SetTest1() TEST1=1;
#define ClearTest1() TEST1=0;

typedef struct
{
    int16_t P_term;
    int16_t I_term;
    int16_t D_term;
    uint16_t ADC;
    uint16_t DAC;
   // int32_t Result;

} PIDR;


void SetDACOutput(uint16_t value);

void GetADC(uint16_t value);

void PIDHandler();

void DACOutputHandler();

void DimmerCounterHandler();

void ADCAverageHandler();

void Tick();

#endif /* PID_H_ */
