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
#define OutputSetPoint	4000

//PID Multiplying Factors
#define Kp 0x0003
#define Ki 0x00101
#define Kd 0x01000


//Static Variables for PID Control

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

//Static Variables for PID Control

static xdata uint16_t DimmerCount;
static xdata uint16_t Previous_DimmerCount;


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
	ADCResult = value>>4; //Dividing by 16 to get the averaged value from the 16 reads
}




void PIDHandler()
{

	OutputResult = CalculatePID(ADCResult);

}

void DACOutputHandler()
{
	SetDACOutput(OutputResult);
}


void DimmerCounterHandler()
{
	//Un comment if this is called from another interrupt vector that is not timer 0

	//SFRPAGE = 0x00;

	TCON &= 0xBF;	//Stop Timer 1 count

	DimmerCount = TH1<<8;
	DimmerCount += TL1;

	if (DimmerCount>1)
	{
			ToogleTest1();

		//It Resets Timer 1 count because something was captured
		TL1=0;
		TH1=0;
		Previous_DimmerCount = DimmerCount;

	}

	TCON |= 0x40;//Timer 1 Run
}

