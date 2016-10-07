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
#define errorlimitH 800
#define errorlimitL -800
#define errorlimitenable 0
//PID Output Limit
#define PIDOutlimitH 4095

//System Set point
#define OutputSetPoint	2000

//PID Multiplying Factors
#define Kp 1000
#define Ki 2
#define Kd 1000

#define AverageADCEnabled 0
//Static Variables for PID Control

static xdata int16_t Error;
static xdata int16_t Error_Integral;
static xdata int16_t Error_Derivative;
static xdata  int16_t Previous_Error =0;
static xdata  int16_t P_term;
static xdata  int16_t I_term;
static xdata  int16_t D_term;
static xdata  int32_t PIDresult;

#define PIDARRAYSIZE 100
static xdata PIDR PIDread[PIDARRAYSIZE];
static xdata uint8_t PIDcounter=0;

static xdata uint16_t ADCResult=0;
static xdata uint32_t ADCAveragedValue=0;

static xdata uint16_t ADCResultArray[PIDARRAYSIZE]=0;

static xdata uint16_t ADCCounter=1;
static xdata uint16_t OutputResult;

static xdata uint32_t tickcounter=0;

//Static Variables for PID Control

static xdata uint16_t DimmerCount;
static xdata uint16_t Previous_DimmerCount;


uint16_t CalculatePID(uint16_t current_ADC)
{
	//Scale goes from 0 to 4095


	Error = OutputSetPoint - current_ADC;

	PIDread[PIDcounter].ADC = current_ADC;

	Error_Integral = Error_Integral + Error;
#if  errorlimitenable
/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx*/
	if(Error_Integral > errorlimitH)
			{
				Error_Integral = errorlimitH;
			}

	else if(Error_Integral < errorlimitL)
		{
			Error_Integral = errorlimitL;
		}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#endif

	Error_Derivative = Error - Previous_Error;

	Previous_Error = Error;

	//P_term = (Kp*Error);
	P_term = Error/Kp;
	PIDread[PIDcounter].P_term = P_term;

	//I_term = (Ki*Error_Integral);
	I_term = Error_Integral>>Ki;
	PIDread[PIDcounter].I_term= I_term;

	D_term = (Error_Derivative/Kd);
	PIDread[PIDcounter].D_term = D_term;


	PIDresult = P_term + I_term + D_term;

	//PIDread[PIDcounter].Result = PIDresult;



	//PIDresult = PIDresult;

	if(PIDresult >= PIDOutlimitH)
	{
		PIDresult = PIDOutlimitH;
	}

	if(PIDresult < 0) {PIDresult = 0;}

	//PIDresult = ADCResult;

	return PIDresult;
}

void Tick()
{
	if (tickcounter++>=500) tickcounter=500;
}

void SetDACOutput(uint16_t value)
{

	SFRPAGE = 0x30;
	DAC0H = value >>8;
	DAC0L= (char) value;
	PIDread[PIDcounter++].DAC = value;
	if(PIDcounter==PIDARRAYSIZE)

		{
			PIDcounter=0;
		}
/*
	if (  ( (value > (PIDread[PIDcounter-1].DAC + 5)) || (value < (PIDread[PIDcounter-1].DAC - 5)) ) && (tickcounter>500))
	{
		value = value;
	}
*/
}

void GetADC(uint16_t value)
{
#if AverageADCEnabled
	//ADCAveragedValue += value>>4;
	ADCResultArray[ADCCounter] = value;
	ADCAveragedValue += value;
	ADCCounter++;
	if (ADCAveragedValue > 245000)
	{
		NOP();
	}

#else
	ADCResult = value;
#endif
}

void ADCAverageHandler()
{
#if AverageADCEnabled
	ADCResult = ADCAveragedValue / ADCCounter;

	if (ADCResult > 3500)
	{
		//ADCResult = 2000;
		ADCAveragedValue=0;
	}
	ADCAveragedValue=0;
	ADCCounter=0;
#else

#endif
}


void PIDHandler()
{
	//SetTest1();
	OutputResult = CalculatePID(ADCResult);
	//ClearTest1();
}

void DACOutputHandler()
{

	SetDACOutput(OutputResult);
}


void DimmerCounterHandler()
{
	//Un comment if this is called from another interrupt vector that is not timer 0

	SFRPAGE = 0x00;

	TCON &= 0xBF;	//Stop Timer 1 count

	DimmerCount = TH1<<8;
	DimmerCount += TL1;

	if (DimmerCount>10)
	{
		//PCA0CN0 &= 0x70;	//Clears PCA0 interrupt
			//ToogleTest1();

		//It Resets Timer 1 count because something was captured
		TL1=0;
		TH1=0;
		Previous_DimmerCount = DimmerCount;

	}

	TCON |= 0x40;//Timer 1 Run
}

