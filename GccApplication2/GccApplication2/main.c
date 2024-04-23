#define F_CPU16000000UL
#include <avr/io.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "PWM_int.h"
#include "DIO_int.h"
int main(void)
{
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN4, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN5, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7, DIO_U8_OUTPUT);
    PWM_vidInit();
	PWM_vidSetDutyNFreqCH0(10);
	PWM_vidSetDutyNFreqCH1A(50);
	PWM_vidSetDutyNFreqCH1B(50);
	PWM_vidSetDutyNFreqCH2(90);
	
		
	
    while (1) 
    {
		
		
		
		
		
    }
}

