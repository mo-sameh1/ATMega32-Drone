

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);

void UART_sendByte(const u8 data);

u8 UART_recieveByte(void);

void UART_sendString(const u8 *Str);

void UART_receiveString(u8 *Str); // Receive until #

#endif /* UART_H_ */
