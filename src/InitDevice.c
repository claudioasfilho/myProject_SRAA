//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB3_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	WDT_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PORTS_2_enter_DefaultMode_from_RESET();
	PORTS_3_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	ADC_0_enter_DefaultMode_from_RESET();
	CMP_0_enter_DefaultMode_from_RESET();
	DAC_0_enter_DefaultMode_from_RESET();
	DACGCF_0_enter_DefaultMode_from_RESET();
	VREF_0_enter_DefaultMode_from_RESET();
	HFOSC_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER16_2_enter_DefaultMode_from_RESET();
	TIMER16_4_enter_DefaultMode_from_RESET();
	TIMER16_5_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	PCA_0_enter_DefaultMode_from_RESET();
	PCACH_0_enter_DefaultMode_from_RESET();
	PCACH_1_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/*
	 // Weak Pullups enabled 
	 // Crossbar enabled
	 // UART1 I/O unavailable at Port pin
	 // UART1 RTS1 unavailable at Port pin
	 // UART1 CTS1 unavailable at Port pin
	 */
	SFRPAGE = 0x00;
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED
			| XBR2_URT1E__DISABLED | XBR2_URT1RTSE__DISABLED
			| XBR2_URT1CTSE__DISABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

	// $[XBR0 - Port I/O Crossbar 0]
	/*
	 // UART0 I/O unavailable at Port pin
	 // SPI I/O unavailable at Port pins
	 // SMBus 0 I/O unavailable at Port pins
	 // CP0 routed to Port pin
	 // Asynchronous CP0 unavailable at Port pin
	 // CP1 unavailable at Port pin
	 // Asynchronous CP1 unavailable at Port pin
	 // SYSCLK unavailable at Port pin
	 */
	XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__DISABLED
			| XBR0_CP0E__ENABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
			| XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	/*
	 // CEX0 routed to Port pin
	 // ECI unavailable at Port pin
	 // T0 unavailable at Port pin
	 // T1 routed to Port pin
	 // T2 unavailable at Port pin
	 */
	XBR1 = XBR1_PCA0ME__CEX0 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED
			| XBR1_T1E__ENABLED | XBR1_T2E__DISABLED;
	// [XBR1 - Port I/O Crossbar 1]$

}

extern void CMP_0_enter_DefaultMode_from_RESET(void) {
	// $[CMP0MX - Comparator 0 Multiplexer Selection]
	/*
	 // External pin CMP0P.1
	 // External pin CMP0N.15
	 */
	uint8_t delay;

	CMP0MX = CMP0MX_CMXP__CMP0P1 | CMP0MX_CMXN__CMP0N15;
	// Delay to allow the comparator inputs to settle
	for (delay = 0; delay < 0x20; delay++)
		;
	// [CMP0MX - Comparator 0 Multiplexer Selection]$

	// $[CMP0CN1 - Comparator 0 Control 1]
	/*
	 // Internal Comparator DAC Reference Level = 0x1F
	 // The comparator output will always reflect the input conditions
	 */
	SFRPAGE = 0x30;
	CMP0CN1 = (0x1F << CMP0CN1_DACLVL__SHIFT) | CMP0CN1_CPINH__DISABLED;
	// [CMP0CN1 - Comparator 0 Control 1]$

	// $[CMP0MD - Comparator 0 Mode]
	/*
	 // Mode 0 
	 // Connect the CMP- input to the internal DAC output, and CMP+ is
	 //     selected by CMXP. The internal DAC uses the signal specified by CMXN
	 //     as its full-scale reference
	 */
	SFRPAGE = 0x00;
	CMP0MD &= ~CMP0MD_CPMD__FMASK;
	CMP0MD |= CMP0MD_INSL__CMXP_DAC;
	// [CMP0MD - Comparator 0 Mode]$

	// $[CMP0CN0 - Comparator 0 Control 0]
	/*
	 // Comparator enabled
	 */
	CMP0CN0 |= CMP0CN0_CPEN__ENABLED;
	// [CMP0CN0 - Comparator 0 Control 0]$

}

extern void HFOSC_0_enter_DefaultMode_from_RESET(void) {
	// $[HFOCN - High Frequency Oscillator Control]
	/*
	 // Force High Frequency Oscillator 0 to run
	 // Disable High Frequency Oscillator 1 
	 */
	SFRPAGE = 0x10;
	HFOCN = HFOCN_HFO0EN__ENABLED | HFOCN_HFO1EN__DISABLED;
	// [HFOCN - High Frequency Oscillator Control]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	/*
	 // P0.0 is high. Set P0.0 to drive or float high
	 // P0.1 is high. Set P0.1 to drive or float high
	 // P0.2 is high. Set P0.2 to drive or float high
	 // P0.3 is high. Set P0.3 to drive or float high
	 // P0.4 is low. Set P0.4 to drive low
	 // P0.5 is low. Set P0.5 to drive low
	 // P0.6 is high. Set P0.6 to drive or float high
	 // P0.7 is high. Set P0.7 to drive or float high
	 */
	P0 = P0_B0__HIGH | P0_B1__HIGH | P0_B2__HIGH | P0_B3__HIGH | P0_B4__LOW
			| P0_B5__LOW | P0_B6__HIGH | P0_B7__HIGH;
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/*
	 // P0.0 output is open-drain
	 // P0.1 output is push-pull
	 // P0.2 output is open-drain
	 // P0.3 output is push-pull
	 // P0.4 output is open-drain
	 // P0.5 output is open-drain
	 // P0.6 output is open-drain
	 // P0.7 output is open-drain
	 */
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__PUSH_PULL
			| P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__PUSH_PULL
			| P0MDOUT_B4__OPEN_DRAIN | P0MDOUT_B5__OPEN_DRAIN
			| P0MDOUT_B6__OPEN_DRAIN | P0MDOUT_B7__OPEN_DRAIN;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	/*
	 // P0.0 pin is configured for analog mode
	 // P0.1 pin is configured for digital mode
	 // P0.2 pin is configured for analog mode
	 // P0.3 pin is configured for digital mode
	 // P0.4 pin is configured for digital mode
	 // P0.5 pin is configured for digital mode
	 // P0.6 pin is configured for digital mode
	 // P0.7 pin is configured for digital mode
	 */
	P0MDIN = P0MDIN_B0__ANALOG | P0MDIN_B1__DIGITAL | P0MDIN_B2__ANALOG
			| P0MDIN_B3__DIGITAL | P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL
			| P0MDIN_B6__DIGITAL | P0MDIN_B7__DIGITAL;
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/*
	 // P0.0 pin is skipped by the crossbar
	 // P0.1 pin is not skipped by the crossbar
	 // P0.2 pin is skipped by the crossbar
	 // P0.3 pin is not skipped by the crossbar
	 // P0.4 pin is not skipped by the crossbar
	 // P0.5 pin is not skipped by the crossbar
	 // P0.6 pin is not skipped by the crossbar
	 // P0.7 pin is not skipped by the crossbar
	 */
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__NOT_SKIPPED | P0SKIP_B2__SKIPPED
			| P0SKIP_B3__NOT_SKIPPED | P0SKIP_B4__NOT_SKIPPED
			| P0SKIP_B5__NOT_SKIPPED | P0SKIP_B6__NOT_SKIPPED
			| P0SKIP_B7__NOT_SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	/*
	 // P0.0 pin logic value is compared with logic HIGH
	 // P0.1 pin logic value is compared with logic HIGH
	 // P0.2 pin logic value is compared with logic HIGH
	 // P0.3 pin logic value is compared with logic LOW
	 // P0.4 pin logic value is compared with logic LOW
	 // P0.5 pin logic value is compared with logic LOW
	 // P0.6 pin logic value is compared with logic HIGH
	 // P0.7 pin logic value is compared with logic HIGH
	 */
	P0MAT = P0MAT_B0__HIGH | P0MAT_B1__HIGH | P0MAT_B2__HIGH | P0MAT_B3__LOW
			| P0MAT_B4__LOW | P0MAT_B5__LOW | P0MAT_B6__HIGH | P0MAT_B7__HIGH;
	// [P0MAT - Port 0 Match]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[HFOSC1 Setup]
	// [HFOSC1 Setup]$

	// $[CLKSEL - Clock Select]
	/*
	 // Clock derived from the Internal High Frequency Oscillator 0
	 // SYSCLK is equal to selected clock source divided by 1
	 */
	SFRPAGE = 0x00;
	CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
		;
	// [CLKSEL - Clock Select]$

}

extern void CIP51_0_enter_DefaultMode_from_RESET(void) {
	// $[PFE0CN - Prefetch Engine Control]
	/*
	 // SYSCLK < 50 MHz
	 */
	PFE0CN = PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ;
	// [PFE0CN - Prefetch Engine Control]$

}

extern void TIMER16_2_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR2CN0_TR2_save;
	TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
	// Stop Timer
	TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
	// [Timer Initialization]$

	// $[TMR2CN1 - Timer 2 Control 1]
	// [TMR2CN1 - Timer 2 Control 1]$

	// $[TMR2CN0 - Timer 2 Control]
	// [TMR2CN0 - Timer 2 Control]$

	// $[TMR2H - Timer 2 High Byte]
	// [TMR2H - Timer 2 High Byte]$

	// $[TMR2L - Timer 2 Low Byte]
	// [TMR2L - Timer 2 Low Byte]$

	// $[TMR2RLH - Timer 2 Reload High Byte]
	/*
	 // Timer 2 Reload High Byte = 0xFC
	 */
	TMR2RLH = (0xFC << TMR2RLH_TMR2RLH__SHIFT);
	// [TMR2RLH - Timer 2 Reload High Byte]$

	// $[TMR2RLL - Timer 2 Reload Low Byte]
	/*
	 // Timer 2 Reload Low Byte = 0x03
	 */
	TMR2RLL = (0x03 << TMR2RLL_TMR2RLL__SHIFT);
	// [TMR2RLL - Timer 2 Reload Low Byte]$

	// $[TMR2CN0]
	/*
	 // Start Timer 2 running
	 */
	TMR2CN0 |= TMR2CN0_TR2__RUN;
	// [TMR2CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR2CN0 |= TMR2CN0_TR2_save;
	// [Timer Restoration]$

}

extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	/*
	 // Enable interrupt requests generated by the ADINT flag
	 // Disable ADC0 Window Comparison interrupt
	 // Disable CP0 interrupts
	 // Disable CP1 interrupts
	 // Disable all Port Match interrupts
	 // Disable all PCA0 interrupts
	 // Disable all SMB0 interrupts
	 // Disable Timer 3 interrupts
	 */
	EIE1 = EIE1_EADC0__ENABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
			| EIE1_ECP1__DISABLED | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
			| EIE1_ESMB0__DISABLED | EIE1_ET3__DISABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIE2 - Extended Interrupt Enable 2]
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP1H - Extended Interrupt Priority 1 High]
	// [EIP1H - Extended Interrupt Priority 1 High]$

	// $[EIP1 - Extended Interrupt Priority 1 Low]
	// [EIP1 - Extended Interrupt Priority 1 Low]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$

	// $[EIP2H - Extended Interrupt Priority 2 High]
	// [EIP2H - Extended Interrupt Priority 2 High]$

	// $[IE - Interrupt Enable]
	/*
	 // Enable each interrupt according to its individual mask setting
	 // Disable external interrupt 0
	 // Disable external interrupt 1
	 // Disable all SPI0 interrupts
	 // Enable interrupt requests generated by the TF0 flag
	 // Disable all Timer 1 interrupt
	 // Enable interrupt requests generated by the TF2L or TF2H flags
	 // Disable UART0 interrupt
	 */
	IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
			| IE_ESPI0__DISABLED | IE_ET0__ENABLED | IE_ET1__DISABLED
			| IE_ET2__ENABLED | IE_ES0__DISABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[IPH - Interrupt Priority High]
	/*
	 // External Interrupt 0 priority MSB set to low
	 // External Interrupt 1 priority MSB set to low
	 // SPI0 interrupt priority MSB set to low
	 // Timer 0 interrupt priority MSB set to high
	 // Timer 1 interrupt priority MSB set to low
	 // Timer 2 interrupt priority MSB set to low
	 // UART0 interrupt priority MSB set to low
	 */
	SFRPAGE = 0x10;
	IPH = IPH_PHX0__LOW | IPH_PHX1__LOW | IPH_PHSPI0__LOW | IPH_PHT0__HIGH
			| IPH_PHT1__LOW | IPH_PHT2__LOW | IPH_PHS0__LOW;
	// [IPH - Interrupt Priority High]$

}

extern void PCA_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA Off]
	PCA0CN0_CR = PCA0CN0_CR__STOP;
	// [PCA Off]$

	// $[PCA0MD - PCA Mode]
	/*
	 // PCA continues to function normally while the system controller is in
	 //     Idle Mode
	 // Disable the CF interrupt
	 // System clock
	 */
	PCA0MD = PCA0MD_CIDL__NORMAL | PCA0MD_ECF__OVF_INT_DISABLED
			| PCA0MD_CPS__SYSCLK;
	// [PCA0MD - PCA Mode]$

	// $[PCA0CENT - PCA Center Alignment Enable]
	// [PCA0CENT - PCA Center Alignment Enable]$

	// $[PCA0CLR - PCA Comparator Clear Control]
	/*
	 // PCA channel
	 // Comparator 0 will be used for the comparator clear function
	 // Enable the comparator clear function on PCA channel 0
	 // Disable the comparator clear function on PCA channel 1
	 // Disable the comparator clear function on PCA channel 2
	 // Disable the comparator clear function on PCA channel 3
	 // Disable the comparator clear function on PCA channel 4
	 // Disable the comparator clear function on PCA channel 5
	 */
	PCA0CLR = PCA0CLR_CPCPOL__HIGH | PCA0CLR_CPCSEL__CMP_0
			| PCA0CLR_CPCE0__ENABLED | PCA0CLR_CPCE1__DISABLED
			| PCA0CLR_CPCE2__DISABLED | PCA0CLR_CPCE3__DISABLED
			| PCA0CLR_CPCE4__DISABLED | PCA0CLR_CPCE5__DISABLED;
	// [PCA0CLR - PCA Comparator Clear Control]$

	// $[PCA0L - PCA Counter/Timer Low Byte]
	/*
	 // PCA Counter/Timer Low Byte = 0xE8
	 */
	PCA0L = (0xE8 << PCA0L_PCA0L__SHIFT);
	// [PCA0L - PCA Counter/Timer Low Byte]$

	// $[PCA0H - PCA Counter/Timer High Byte]
	/*
	 // PCA Counter/Timer High Byte = 0x03
	 */
	PCA0H = (0x03 << PCA0H_PCA0H__SHIFT);
	// [PCA0H - PCA Counter/Timer High Byte]$

	// $[PCA0POL - PCA Output Polarity]
	// [PCA0POL - PCA Output Polarity]$

	// $[PCA0PWM - PCA PWM Configuration]
	/*
	 // 11 bits
	 */
	PCA0PWM &= ~PCA0PWM_CLSEL__FMASK;
	PCA0PWM |= PCA0PWM_CLSEL__11_BITS;
	// [PCA0PWM - PCA PWM Configuration]$

	// $[PCA On]
	PCA0CN0_CR = PCA0CN0_CR__RUN;
	// [PCA On]$

}

extern void PCACH_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
	/*
	 // Disable negative edge capture
	 // Disable CCF0 interrupts
	 // Enable match function
	 // 8 to 11-bit PWM selected
	 // Disable positive edge capture
	 // Enable comparator function
	 // Enable PWM function
	 // Disable toggle function
	 */
	PCA0CPM0 = PCA0CPM0_CAPN__DISABLED | PCA0CPM0_ECCF__DISABLED
			| PCA0CPM0_MAT__ENABLED | PCA0CPM0_PWM16__8_BIT
			| PCA0CPM0_CAPP__DISABLED | PCA0CPM0_ECOM__ENABLED
			| PCA0CPM0_PWM__ENABLED | PCA0CPM0_TOG__DISABLED;
	// [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

	// $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
	/*
	 // PCA Channel 0 Capture Module Low Byte = 0xFF
	 */
	PCA0CPL0 = (0xFF << PCA0CPL0_PCA0CPL0__SHIFT);
	// [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

	// $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
	/*
	 // PCA Channel 0 Capture Module High Byte = 0x03
	 */
	PCA0CPH0 = (0x03 << PCA0CPH0_PCA0CPH0__SHIFT);
	// [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$

	// $[Auto-reload]
	PCA0PWM |= PCA0PWM_ARSEL__AUTORELOAD;
	/*
	 // PCA Channel 0 Capture Module Low Byte = 0xFF
	 */
	PCA0CPL0 = (0xFF << PCA0CPL0_PCA0CPL0__SHIFT);

	/*
	 // PCA Channel 0 Capture Module High Byte = 0x03
	 */
	PCA0CPH0 = (0x03 << PCA0CPH0_PCA0CPH0__SHIFT);

	PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

extern void WDT_0_enter_DefaultMode_from_RESET(void) {
	// $[WDTCN - Watchdog Timer Control]
	SFRPAGE = 0x00;
	//Disable Watchdog with key sequence
	WDTCN = 0xDE; //First key
	WDTCN = 0xAD; //Second key
	// [WDTCN - Watchdog Timer Control]$

}

extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {
	// $[CKCON0 - Clock Control 0]
	/*
	 // System clock divided by 4
	 // Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 // Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
	 // Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
	 // Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
	 // Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
	 // Timer 1 uses the clock defined by the prescale field, SCA
	 */
	SFRPAGE = 0x00;
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T0M__PRESCALE
			| CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
			| CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
			| CKCON0_T1M__PRESCALE;
	// [CKCON0 - Clock Control 0]$

	// $[CKCON1 - Clock Control 1]
	// [CKCON1 - Clock Control 1]$

	// $[TMOD - Timer 0/1 Mode]
	/*
	 // Mode 1, 16-bit Counter/Timer
	 // Mode 1, 16-bit Counter/Timer
	 // Timer Mode. Timer 0 increments on the clock defined by T0M in the
	 //     CKCON0 register
	 // Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
	 // Counter Mode. Timer 1 increments on high-to-low transitions of an
	 //     external pin
	 // Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
	 */
	TMOD = TMOD_T0M__MODE1 | TMOD_T1M__MODE1 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__COUNTER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/*
	 // Start Timer 0 running
	 */
	TCON |= TCON_TR0__RUN;
	// [TCON - Timer 0/1 Control]$

}

extern void PORTS_3_enter_DefaultMode_from_RESET(void) {
	// $[P3 - Port 3 Pin Latch]
	// [P3 - Port 3 Pin Latch]$

	// $[P3MDOUT - Port 3 Output Mode]
	/*
	 // P3.0 output is open-drain
	 // P3.1 output is open-drain
	 // P3.2 output is open-drain
	 // P3.3 output is push-pull
	 // P3.4 output is open-drain
	 // P3.7 output is open-drain
	 */
	SFRPAGE = 0x20;
	P3MDOUT = P3MDOUT_B0__OPEN_DRAIN | P3MDOUT_B1__OPEN_DRAIN
			| P3MDOUT_B2__OPEN_DRAIN | P3MDOUT_B3__PUSH_PULL
			| P3MDOUT_B4__OPEN_DRAIN | P3MDOUT_B7__OPEN_DRAIN;
	// [P3MDOUT - Port 3 Output Mode]$

	// $[P3MDIN - Port 3 Input Mode]
	/*
	 // P3.0 pin is configured for analog mode
	 // P3.1 pin is configured for digital mode
	 // P3.2 pin is configured for digital mode
	 // P3.3 pin is configured for digital mode
	 // P3.4 pin is configured for digital mode
	 // P3.7 pin is configured for digital mode
	 */
	P3MDIN = P3MDIN_B0__ANALOG | P3MDIN_B1__DIGITAL | P3MDIN_B2__DIGITAL
			| P3MDIN_B3__DIGITAL | P3MDIN_B4__DIGITAL | P3MDIN_B7__DIGITAL;
	// [P3MDIN - Port 3 Input Mode]$

}

extern void TIMER16_4_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR4CN0_TR4_save;
	SFRPAGE = 0x10;
	TMR4CN0_TR4_save = TMR4CN0 & TMR4CN0_TR4__BMASK;
	// Stop Timer
	TMR4CN0 &= ~(TMR4CN0_TR4__BMASK);
	// [Timer Initialization]$

	// $[TMR4CN1 - Timer 4 Control 1]
	// [TMR4CN1 - Timer 4 Control 1]$

	// $[TMR4CN0 - Timer 4 Control]
	// [TMR4CN0 - Timer 4 Control]$

	// $[TMR4H - Timer 4 High Byte]
	// [TMR4H - Timer 4 High Byte]$

	// $[TMR4L - Timer 4 Low Byte]
	// [TMR4L - Timer 4 Low Byte]$

	// $[TMR4RLH - Timer 4 Reload High Byte]
	/*
	 // Timer 4 Reload High Byte = 0xF8
	 */
	TMR4RLH = (0xF8 << TMR4RLH_TMR4RLH__SHIFT);
	// [TMR4RLH - Timer 4 Reload High Byte]$

	// $[TMR4RLL - Timer 4 Reload Low Byte]
	/*
	 // Timer 4 Reload Low Byte = 0x07
	 */
	TMR4RLL = (0x07 << TMR4RLL_TMR4RLL__SHIFT);
	// [TMR4RLL - Timer 4 Reload Low Byte]$

	// $[TMR4CN0]
	// [TMR4CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR4CN0 |= TMR4CN0_TR4_save;
	// [Timer Restoration]$

}

extern void TIMER16_5_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR5CN0_TR5_save;
	TMR5CN0_TR5_save = TMR5CN0 & TMR5CN0_TR5__BMASK;
	// Stop Timer
	TMR5CN0 &= ~(TMR5CN0_TR5__BMASK);
	// [Timer Initialization]$

	// $[TMR5CN1 - Timer 5 Control 1]
	// [TMR5CN1 - Timer 5 Control 1]$

	// $[TMR5CN0 - Timer 5 Control]
	// [TMR5CN0 - Timer 5 Control]$

	// $[TMR5H - Timer 5 High Byte]
	// [TMR5H - Timer 5 High Byte]$

	// $[TMR5L - Timer 5 Low Byte]
	// [TMR5L - Timer 5 Low Byte]$

	// $[TMR5RLH - Timer 5 Reload High Byte]
	/*
	 // Timer 5 Reload High Byte = 0xFC
	 */
	TMR5RLH = (0xFC << TMR5RLH_TMR5RLH__SHIFT);
	// [TMR5RLH - Timer 5 Reload High Byte]$

	// $[TMR5RLL - Timer 5 Reload Low Byte]
	/*
	 // Timer 5 Reload Low Byte = 0x03
	 */
	TMR5RLL = (0x03 << TMR5RLL_TMR5RLL__SHIFT);
	// [TMR5RLL - Timer 5 Reload Low Byte]$

	// $[TMR5CN0]
	// [TMR5CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR5CN0 |= TMR5CN0_TR5_save;
	// [Timer Restoration]$

}

extern void PCACH_1_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]
	// [PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]$

	// $[PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]
	// [PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]$

	// $[PCA0CPH1 - PCA Channel 1 Capture Module High Byte]
	/*
	 // PCA Channel 1 Capture Module High Byte = 0x01
	 */
	PCA0CPH1 = (0x01 << PCA0CPH1_PCA0CPH1__SHIFT);
	// [PCA0CPH1 - PCA Channel 1 Capture Module High Byte]$

	// $[Auto-reload]
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

extern void DAC_0_enter_DefaultMode_from_RESET(void) {
	// $[DAC0CF0 - DAC0 Configuration 0]
	/*
	 // DAC0 is enabled and will drive the output pin
	 // DAC0 output updates occur on every clock cycle
	 // DAC0 input is treated as right-justified
	 // All resets will reset DAC0 and its associated registers
	 */
	SFRPAGE = 0x30;
	DAC0CF0 = DAC0CF0_EN__ENABLE | DAC0CF0_UPDATE__SYSCLK
			| DAC0CF0_LJST__RIGHT_JUSTIFY | DAC0CF0_RSTMD__NORMAL;
	// [DAC0CF0 - DAC0 Configuration 0]$

	// $[DAC0CF1 - DAC0 Configuration 1]
	/*
	 // DAC output gain is 2
	 */
	DAC0CF1 = DAC0CF1_DRVGAIN__GAIN_2P0;
	// [DAC0CF1 - DAC0 Configuration 1]$

}

extern void DACGCF_0_enter_DefaultMode_from_RESET(void) {
	// $[DACGCF0 - DAC Global Configuration 0]
	/*
	 // Select the VREF pin
	 // Select the VDD supply
	 // Input = DAC1H:DAC1L
	 // Input = DAC3H:DAC3L
	 // DAC1 always updates from the data source selected in D1SRC. This mode
	 //     may be used with any trigger source
	 // DAC3 always updates from the data source selected in D3SRC. This mode
	 //     may be used with any trigger source
	 */
	DACGCF0 = DACGCF0_D01REFSL__VREF | DACGCF0_D23REFSL__VDD
			| DACGCF0_D1SRC__DAC1 | DACGCF0_D3SRC__DAC3 | DACGCF0_D1AMEN__NORMAL
			| DACGCF0_D3AMEN__NORMAL;
	// [DACGCF0 - DAC Global Configuration 0]$

	// $[DACGCF2 - DAC Global Configuration 2]
	/*
	 // Selected reference will be attenuated by a factor of 2
	 // Selected reference will be attenuated by a factor of 2.4 
	 */
	DACGCF2 = DACGCF2_D01REFGN__ATTEN_2P0 | DACGCF2_D23REFGN__ATTEN_2P4;
	// [DACGCF2 - DAC Global Configuration 2]$

}

extern void VREF_0_enter_DefaultMode_from_RESET(void) {
	// $[REF0CN - Voltage Reference Control]
	/*
	 // 1.2 V reference output to VREF pin
	 */
	SFRPAGE = 0x00;
	REF0CN = REF0CN_VREFSL__VREF_1P2;
	// [REF0CN - Voltage Reference Control]$

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	/*
	 // P1.0 is low. Set P1.0 to drive low
	 // P1.1 is low. Set P1.1 to drive low
	 // P1.2 is high. Set P1.2 to drive or float high
	 // P1.3 is low. Set P1.3 to drive low
	 // P1.4 is high. Set P1.4 to drive or float high
	 // P1.5 is high. Set P1.5 to drive or float high
	 // P1.6 is high. Set P1.6 to drive or float high
	 // P1.7 is high. Set P1.7 to drive or float high
	 */
	P1 = P1_B0__LOW | P1_B1__LOW | P1_B2__HIGH | P1_B3__LOW | P1_B4__HIGH
			| P1_B5__HIGH | P1_B6__HIGH | P1_B7__HIGH;
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	/*
	 // P1.0 pin is configured for digital mode
	 // P1.1 pin is configured for digital mode
	 // P1.2 pin is configured for digital mode
	 // P1.3 pin is configured for digital mode
	 // P1.4 pin is configured for digital mode
	 // P1.5 pin is configured for digital mode
	 // P1.6 pin is configured for digital mode
	 // P1.7 pin is configured for analog mode
	 */
	P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__DIGITAL | P1MDIN_B2__DIGITAL
			| P1MDIN_B3__DIGITAL | P1MDIN_B4__DIGITAL | P1MDIN_B5__DIGITAL
			| P1MDIN_B6__DIGITAL | P1MDIN_B7__ANALOG;
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/*
	 // P1.0 pin is not skipped by the crossbar
	 // P1.1 pin is not skipped by the crossbar
	 // P1.2 pin is not skipped by the crossbar
	 // P1.3 pin is not skipped by the crossbar
	 // P1.4 pin is not skipped by the crossbar
	 // P1.5 pin is not skipped by the crossbar
	 // P1.6 pin is not skipped by the crossbar
	 // P1.7 pin is skipped by the crossbar
	 */
	P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__NOT_SKIPPED
			| P1SKIP_B2__NOT_SKIPPED | P1SKIP_B3__NOT_SKIPPED
			| P1SKIP_B4__NOT_SKIPPED | P1SKIP_B5__NOT_SKIPPED
			| P1SKIP_B6__NOT_SKIPPED | P1SKIP_B7__SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	/*
	 // P1.0 pin logic value is compared with logic HIGH
	 // P1.1 pin logic value is compared with logic LOW
	 // P1.2 pin logic value is compared with logic HIGH
	 // P1.3 pin logic value is compared with logic LOW
	 // P1.4 pin logic value is compared with logic HIGH
	 // P1.5 pin logic value is compared with logic HIGH
	 // P1.6 pin logic value is compared with logic HIGH
	 // P1.7 pin logic value is compared with logic HIGH
	 */
	P1MAT = P1MAT_B0__HIGH | P1MAT_B1__LOW | P1MAT_B2__HIGH | P1MAT_B3__LOW
			| P1MAT_B4__HIGH | P1MAT_B5__HIGH | P1MAT_B6__HIGH | P1MAT_B7__HIGH;
	// [P1MAT - Port 1 Match]$

}

extern void ADC_0_enter_DefaultMode_from_RESET(void) {
	// $[ADC0CN2 - ADC0 Control 2]
	/*
	 // ADC0 conversion initiated on overflow of Timer 2
	 // The ADC accumulator is over-written with the results of any conversion
	 */
	ADC0CN2 = ADC0CN2_ADCM__TIMER2 | ADC0CN2_PACEN__PAC_DISABLED;
	// [ADC0CN2 - ADC0 Control 2]$

	// $[ADC0CN1 - ADC0 Control 1]
	// [ADC0CN1 - ADC0 Control 1]$

	// $[ADC0MX - ADC0 Multiplexer Selection]
	/*
	 // Select ADC0.17
	 */
	ADC0MX = ADC0MX_ADC0MX__ADC0P17;
	// [ADC0MX - ADC0 Multiplexer Selection]$

	// $[ADC0CF2 - ADC0 Power Control]
	/*
	 // The ADC0 ground reference is the GND pin
	 // The ADC0 voltage reference is the VREF pin 
	 // Power Up Delay Time = 0x1F
	 */
	ADC0CF2 = ADC0CF2_GNDSL__GND_PIN | ADC0CF2_REFSL__VREF_PIN
			| (0x1F << ADC0CF2_ADPWR__SHIFT);
	// [ADC0CF2 - ADC0 Power Control]$

	// $[ADC0CF0 - ADC0 Configuration]
	/*
	 // ADCCLK = SYSCLK
	 // SAR Clock Divider = 0x03
	 */
	ADC0CF0 = ADC0CF0_ADCLKSEL__SYSCLK | (0x03 << ADC0CF0_ADSC__SHIFT);
	// [ADC0CF0 - ADC0 Configuration]$

	// $[ADC0CF1 - ADC0 Configuration]
	/*
	 // Enable low power mode
	 // Conversion Tracking Time = 0x0A
	 */
	ADC0CF1 = ADC0CF1_ADLPM__LP_ENABLED | (0x0A << ADC0CF1_ADTK__SHIFT);
	// [ADC0CF1 - ADC0 Configuration]$

	// $[ADC0ASAL - ADC0 Autoscan Start Address Low Byte]
	/*
	 // ADC results in XRAM are stored in little-endian order. This will
	 //     result in the most significant byte stored in the odd-numbered address
	 */
	SFRPAGE = 0x30;
	ADC0ASAL |= ADC0ASAL_ENDIAN__LITTLE_ENDIAN;
	// [ADC0ASAL - ADC0 Autoscan Start Address Low Byte]$

	// $[ADC0GTH - ADC0 Greater-Than High Byte]
	// [ADC0GTH - ADC0 Greater-Than High Byte]$

	// $[ADC0GTL - ADC0 Greater-Than Low Byte]
	// [ADC0GTL - ADC0 Greater-Than Low Byte]$

	// $[ADC0LTH - ADC0 Less-Than High Byte]
	// [ADC0LTH - ADC0 Less-Than High Byte]$

	// $[ADC0LTL - ADC0 Less-Than Low Byte]
	// [ADC0LTL - ADC0 Less-Than Low Byte]$

	// $[ADC0ASCF - ADC0 Autoscan Configuration]
	/*
	 // The selected conversion trigger source will begin each scan cycle. All
	 //     conversions within a scan cycle are performed automatically when the
	 //     previous conversion is complete
	 */
	ADC0ASCF |= ADC0ASCF_STEN__SINGLE_TRIGGER;
	// [ADC0ASCF - ADC0 Autoscan Configuration]$

	// $[ADC0CN0 - ADC0 Control 0]
	/*
	 // Enable ADC0 
	 */
	SFRPAGE = 0x00;
	ADC0CN0 |= ADC0CN0_ADEN__ENABLED;
	// [ADC0CN0 - ADC0 Control 0]$

}

extern void PORTS_2_enter_DefaultMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	/*
	 // P2.0 output is open-drain
	 // P2.1 output is open-drain
	 // P2.2 output is open-drain
	 // P2.3 output is open-drain
	 // P2.4 output is open-drain
	 // P2.5 output is push-pull
	 // P2.6 output is open-drain
	 */
	P2MDOUT = P2MDOUT_B0__OPEN_DRAIN | P2MDOUT_B1__OPEN_DRAIN
			| P2MDOUT_B2__OPEN_DRAIN | P2MDOUT_B3__OPEN_DRAIN
			| P2MDOUT_B4__OPEN_DRAIN | P2MDOUT_B5__PUSH_PULL
			| P2MDOUT_B6__OPEN_DRAIN;
	// [P2MDOUT - Port 2 Output Mode]$

	// $[P2MDIN - Port 2 Input Mode]
	// [P2MDIN - Port 2 Input Mode]$

	// $[P2SKIP - Port 2 Skip]
	// [P2SKIP - Port 2 Skip]$

	// $[P2MASK - Port 2 Mask]
	// [P2MASK - Port 2 Mask]$

	// $[P2MAT - Port 2 Match]
	// [P2MAT - Port 2 Match]$

}

extern void CLU_0_enter_DefaultMode_from_RESET(void) {

}

extern void CLU_3_enter_DefaultMode_from_RESET(void) {

}

extern void CL_0_enter_DefaultMode_from_RESET(void) {

}

