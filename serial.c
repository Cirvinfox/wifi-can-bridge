/*
 * =====================================================================================
 *
 *       Filename:  serial.c
 *
 *    Description: 
 *
 *        Changed: 2015-9-12
 *		
 *      Author(s):  C. Addison Irvin (cirvinfox)
 *
 * =====================================================================================
 */

#include <serial.h>
#include <msp430.h>
#include <signal.h>
#include <inttypes.h>

void initSerial(void)
{
	/* set the reset bit to put the hardware into reset */
	UCA0CTL1 |= UCSWRST;

	/* Initialize the serial hardware */

	/* Configure the ports to enable RX and TX */

	/* clear reset bit to make the thingy go */
	USCA0CTL1 &= ~UCSWRST;

	/* Turn on the interrupts */

	return;
}
