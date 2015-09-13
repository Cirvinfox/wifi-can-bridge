/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: 
 *
 *        Changed: 2015-9-12
 *		
 *      Author(s):  Corbin Irvin (cirvinfox)
 *
 * =====================================================================================
 */

/* 
 * (c) 2011 Corbin Irvin 
 *
 * Please see LICENSE for License details.
 *
 */

#include <msp430.h>
#include <signal.h>
#include <inttypes.h>
#include "main.h"

/* global vars */
volatile uint32_t   regTimer = 0;	 /* timer register, starts at 0 on startup, 500uS steps */
volatile uint8_t	keyRegOld;
volatile uint8_t	keyReg;          /* register that holds key state */
volatile uint8_t	keyPulse;

volatile int		tapState =0;
volatile int		heartbeatState;
volatile uint32_t   delayTime = 500; /* delay time in  milliseconds */
volatile uint32_t	heartbeatStartTime;
volatile uint32_t	oldTime;
volatile int		tapFlag = 0;

volatile uint8_t	programArray[MAXSTEPS] = { 0x01, 0x02, 0x04, 0x08};
volatile int		programStep = 0;
volatile int		programLength = 4;
volatile uint8_t	programState = 0;
volatile uint32_t	programCycleStartTime;

volatile int 		programmingState =0;

volatile int 		mode = 0; /* 0 is normal, 1 is programming */

int main(void)
{
	/* watchdog timer */
	WDTCTL = WDTPW | WDTHOLD;	/* WDT disabled */			
  	
	/* configure the internal oscillator */
	BCSCTL1 = RSEL3 + RSEL2 + RSEL1 + RSEL0;	/* set up for 15.25MHz internal oscillator */
	DCOCTL = DCO2 + DCO1 + DCO0;

	/* set up inputs and outputs */
	initIO();

	/* configure timerA0 for 1ms interrupt rate */
	TA0CTL = TASSEL_2 + MC_1 + TACLR ; /* SMCLK source, no division, up to TACCR0, interrupts on */
	TACCTL0 = CCIE;	/* enable the interrupt on compare */
	CCR0 = 15250 - 1;	/* count requried for a 1ms interrupt rate */


	/* enable interrupts */
	/* dint(); */ /* opposite is  */
	eint();
	
	/* switch to low power mode, act on interrupts */
	/* LPM0; */			
	
	while(1)
	{
		delayMs(500);
		P2OUT = 0xff;
		delayMs(500);
		P2OUT= 0x00;
	
	}
}

/* 	
	this interrupt fires at 1KHz and does the pwm routine
*/
interrupt(TIMERA0_VECTOR) TimerA0_interrupt(void)
{   

	return;
} 



/* initalizes the io ports */
void initIO(void)
{
	
	/* configure IO ports */
			
	P1SEL = 0x00;		/* disable any special functions */
	P2SEL = 0x00;
	
	P1DIR = 0x00;		/* set up the port directions */
	P1REN = 0x00;		/* enable internal resistors */
	P1OUT = 0x00;		/* set resistors to pullup */
	
	P2DIR = 0xFF;		/* set up port directions */
	P2REN = 0x00;		/* enable internal resistors */
	//P2OUT = BIT7;		/* set resistors to pullup */
	
	return;
}


static void __inline__ brief_pause(register unsigned int n)
{
	 __asm__ __volatile__ (
	 "1: \n"
	 " dec	%[n] \n"
	 " jne	1b \n"
	 : [n] "+r"(n));
}
	

void delayMs(uint32_t delay)
{
	uint32_t i ;
	i = regTimer + delay;
	while( regTimer < i ) nop();
	return;
}

/* vim: set noet :*/
