#include "uart.h"
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

void UART_init(void)
{
	UCSRA = (1<<U2X);
	UCSRB = (1<<RXEN) | (1<<TXEN);	 	
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); 	
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
}
	
void UART_sendByte(u8 data)
{
	while((UCSRA,UDRE)){}
	UDR = data;	
}

u8 UART_recieveByte(void)
{	
	while(!(GET_BIT(UCSRA,RXC))){} 
    return UDR;		
}

void UART_sendString(const u8*Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

void UART_receiveString(u8 *Str)
{
	u8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}
