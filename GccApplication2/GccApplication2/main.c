#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "PWM_int.h"
#include "DIO_int.h"
#include "USART_H.h"
int main(void)
{
	DDRA|=0x0F;
	PORTA&=0xF0;
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN4, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN2, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN5, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7, DIO_U8_OUTPUT);
	DIO_voidSetPinValue(DIO_U8_PORTD, DIO_U8_PIN2, DIO_U8_LOW);
	DIO_voidSetPinValue(DIO_U8_PORTD, DIO_U8_PIN3, DIO_U8_HIGH);
    PWM_vidInit();
	USART_Init(9600);
	f32 curr = 2;
	f32 change_freq = 0.55;
	PWM_vidSetDutyNFreqCH0(curr);
	PWM_vidSetDutyNFreqCH1A(curr);
	PWM_vidSetDutyNFreqCH1B(curr);
	PWM_vidSetDutyNFreqCH2(curr);
    while (1) 
    {
		
		u8 rec=USART_RxChar();
		if ((rec=='U' && curr >= 14) ||( rec =='D' && curr <= 3)){
			continue;
		}
		else if(rec=='U'){
			curr += change_freq;
			USART_TxChar('R');
			PWM_vidSetDutyNFreqCH0(curr);
			PWM_vidSetDutyNFreqCH1A(curr);
			PWM_vidSetDutyNFreqCH1B(curr);
			PWM_vidSetDutyNFreqCH2(curr);			
			_delay_ms(1000);
		}
		else if (rec =='D'){
			curr -= change_freq;
			USART_TxChar('R');
			PWM_vidSetDutyNFreqCH0(curr);
			PWM_vidSetDutyNFreqCH1A(curr);
			PWM_vidSetDutyNFreqCH1B(curr);
			PWM_vidSetDutyNFreqCH2(curr);
			_delay_ms(1000);
		}
    }
}

