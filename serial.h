/*
 * =====================================================================================
 *
 *       Filename:  serial.h
 *
 *    Description:  header file for serial.c
 *
 *        Changed:  2015-9-12
 *
 *         Author:  C. Addison Irvin (cirvinfox)
 *
 * =====================================================================================
 */

#ifndef _SERIAL
#define _SERIAL

/* Function Prototypes */
void initSerial(void)
int putc(char c);
char getc(void);
int gets(char * str, int count);
int puts(char * str, int count);




/* Definitions */


/* general bit manipulations */
#define _toggleBit(reg,bit) reg ^= bit  
#define _setBit(reg,bit) reg |= bit
#define _clearBit(reg,bit) reg &= ~##bit
#endif
