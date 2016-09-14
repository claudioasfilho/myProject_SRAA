//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB3_Register_Enums.h>
#include "PID.h"

SI_SBIT (TEST1,SFR_P3, 3);			   //Test LED
#define ToogleTest1() TEST1^=1;

//-----------------------------------------------------------------------------
// TIMER0_ISR
//-----------------------------------------------------------------------------
//
// TIMER0 ISR Content goes here. Remember to clear flag bits:
// TCON::TF0 (Timer 0 Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
	SFRPAGE = 0x00;

	TCON &= 0xdf; //Clear the interrupt Flag

	TCON |= 0x40;//Timer 1 Run


	//ToogleTest1();

	if (TL1>10)
	{
		//	ToogleTest1();
		TL1=0;
		TH1=0;
	}

//	TL1=0;
//	TH1=0;

}

//-----------------------------------------------------------------------------
// ADC0EOC_ISR
//-----------------------------------------------------------------------------
//
// ADC0EOC ISR Content goes here. Remember to clear flag bits:

//
//-----------------------------------------------------------------------------
SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
{

	SFRPAGE = 0x00;

	ADC0CN0 &= 0xDF;			//It clears the ADC interrupt Flag

	GetADC(ADC0);

	ADC0=0;

	ToogleTest1();

}

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{
	SFRPAGE = 0x00;

	TMR2CN0 &= 0x3F;			//It clears the Timer 2 interrupt Flags



}

