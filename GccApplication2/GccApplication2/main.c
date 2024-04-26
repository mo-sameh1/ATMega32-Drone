#define F_CPU 16000000UL
#include <avr/io.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "PWM_int.h"
#include "DIO_int.h"
#include "uart.h"
int main(void)
{
	DDRA|=0x0F;
	PORTA&=0xF0;
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN4, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN5, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7, DIO_U8_OUTPUT);

	
    PWM_vidInit();
	UART_init();
    while (1) 
    {
		
		char rec=UART_recieveByte();
		switch(rec){
			case '1':
			PWM_vidSetDutyNFreqCH0(20);			
			break;
			case '2':
			PWM_vidSetDutyNFreqCH1A(20);
			break;
			case '3':
			PWM_vidSetDutyNFreqCH1B(90);
			break;
			case '4':
			PWM_vidSetDutyNFreqCH2(20);
			break;
			case 'a':
			
			break;
		}
			
		
		
		
		
		
		
    }
}

