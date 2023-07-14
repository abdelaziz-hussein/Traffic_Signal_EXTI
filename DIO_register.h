/*
 * DIO_register.h
 *
 *  Created on: May 17, 2023
 *      Author: Abdelaziz
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/*
 * DEfine AVR Direction Registers
 */
#define DDRA (*(u8*)0x3A)
#define DDRB (*(u8*)0x37)
#define DDRC (*(u8*)0x34)
#define DDRD (*(u8*)0x31)
/*
 * DEfine AVR Registers PORT
 */
#define PORTA (*(u8*)0x3B)
#define PORTB (*(u8*)0x38)
#define PORTC (*(u8*)0x35)
#define PORTD (*(u8*)0x32)
/*
 * DEfine AVR Registers PIN
 */
#define PINA (*(u8*)0x39)
#define PINB (*(u8*)0x36)
#define PINC (*(u8*)0x33)
#define PIND (*(u8*)0x30)


#endif /* DIO_REGISTER_H_ */
