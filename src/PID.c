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


//Constants

#define errorlimitH 0x00
#define errorlimitL 0x00

#define setPoint	0x00

#define Kp 0x0003
#define Ki 0x0000
#define Kd 0x0000


//Static Variables


static int8_t error;
static int8_t n1_error =0;
static int8_t P_term;
static int8_t I_term;
static int8_t D_term;
static int16_t PIDresult;

static xdata uint16_t ADCResult;


uint16_t CalculatePID(uint16_t current_error)
{
	//Scale goes from 0 to 4095


	error = setPoint - current_error;

	if(error>errorlimitH)
	{
		error = errorlimitH;
	}

	if(error<errorlimitL)
	{
		error = errorlimitL;
	}

	P_term = (error*Kp)>>8;

	I_term += (error*Ki)>>8; //This I term may have to be desaturated (anti - windup).

	D_term = (n1_error *Kd)>>8;

	PIDresult = P_term + I_term + D_term;

	return PIDresult;
}

void SetDACOutput(uint16_t value)
{
	SFRPAGE = 0x30;

	DAC0L = value;
	DAC0H= value >>8;
}

void GetADC(uint16_t value)
{
	ADCResult = value>>4; //Dividing by 16 to get the averaged value
}

void PIDHandler()
{

}


void DACOutputHandler()
{

}


