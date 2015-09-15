/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  header file for main.c
 *
 *        Changed: 2015-9-12
 *
 *         Author:  Corbin Irvin (cirvinfox)
 *
 * =====================================================================================
 */

/* Function Prototypes */
void initIO(void);
static void __inline__ brief_pause(register unsigned int n);
void delayMs(uint32_t);

/* Definitions */
#define LED_WIFI BIT2
#define LED_CAN BIT0
#define LED_SYS BIT1

/* port 2 definitions */
/* port 1 definitions */

/* macro to help us toggle bits on ports */
#define _togglePort(port,bit) P##port##OUT^= bit
#define _setPort(port,bit) P##port##OUT |= bit
#define _clearPort(port,bit) P##port##OUT &= ~bit

/* general bit manipulations */
#define _toggleBit(reg,bit) reg ^= bit  
#define _setBit(reg,bit) reg |= bit
#define _clearBit(reg,bit) reg &= ~##bit


typedef enum 
{
	off,
	on,
	slowblink,
	fastblink
}e_LEDState;


