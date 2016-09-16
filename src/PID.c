//-----------------------------------------------------------------------------
// PID.c
//-----------------------------------------------------------------------------
// Copyright 2016, Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Created on: Sept 2016
//     Author: Claudio Filho
//
// PID controller for EFM8
//
//-----------------------------------------------------------------------------

#include <SI_EFM8BB3_Register_Enums.h>
#include "PID.h"


//Constants for the PID Controller

//Error Limits
#define errorlimitH 50
#define errorlimitL -50

//PID Output Limit
#define PIDOutlimitH 4095

//System Set point
#define OutputSetPoint	4096

//PID Multiplying Factors
#define Kp 0x0003
#define Ki 0x00101
#define Kd 0x01000


//Static Variables

static xdata int16_t Error;
static xdata int16_t Error_Integral;
static xdata int16_t Error_Derivative;
static xdata  int16_t Previous_Error =0;
static xdata  int16_t P_term;
static xdata  int16_t I_term;
static xdata  int16_t D_term;
static xdata  int16_t PIDresult;

static xdata uint16_t ADCResult;
static xdata uint16_t OutputResult;



uint16_t CalculatePID(uint16_t current_ADC)
{
	//Scale goes from 0 to 4095


	Error = OutputSetPoint - current_ADC;


	Error_Integral = Error_Integral + Error;

	if(Error_Integral > errorlimitH)
			{
				Error_Integral = errorlimitH;
			}

	else if(Error_Integral < errorlimitL)
		{
			Error_Integral = errorlimitL;
		}

	Error_Derivative = Error - Previous_Error;
	Previous_Error = Error;

	PIDresult = (Kp*Error) + (Ki*Error_Integral) + (Kd*Error_Derivative);


	PIDresult = PIDresult>>2;

	if(PIDresult >= PIDOutlimitH)
	{
		PIDresult = PIDOutlimitH;
	}

	if(PIDresult < 0) {PIDresult = 0;}

	//PIDresult = ADCResult;

	return PIDresult;
}

void SetDACOutput(uint16_t value)
{

	SFRPAGE = 0x30;
	DAC0H = value >>8;
	DAC0L= (char) value;
}

void GetADC(uint16_t value)
{
	ADCResult = value>>4; //Dividing by 16 to get the averaged value
}

void PIDHandler()
{

	OutputResult = CalculatePID(ADCResult);

}


void DACOutputHandler()
{
	SetDACOutput(OutputResult);
	//SetDACOutput(ADCResult);
}


