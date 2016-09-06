//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$
uint8_t delay;
//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void) {
	// Call hardware initialization routine

#if 0
	//All Pins are digital except P02
	P0MDIN = 0xfb;
	//P00 latched to 1
	P0 = 0x01;
	//P00 is a Push Pull
	P0MDOUT = 0x01;

	//PBCFG_0_enter_DefaultMode_from_RESET();

	//Comparator 0 Setup
	CMP0CN0 = 0xc0;
	CMP0MD = 0x0c;
	CMP0MX = 0xf2;
	CMP0CN1 = 0x1f;//Half Scale on the DAC
#endif

	enter_DefaultMode_from_RESET();


		while (1) {
// $[Generated Run-time code]
// [Generated Run-time code]$
		}
}

