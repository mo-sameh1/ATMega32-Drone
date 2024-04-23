#include "STD_types.h"
#include "PWM_config.h"
#include "PWM_priv.h"
#include "BIT_math.h"
#include "DIO_int.h"

void PWM_vidInit(void)
{
	CLEAR_BIT(TCCR0,7);
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	
	// timer 1 channel A
	
	
	SET_BIT(TCCR1A,6);//6
	SET_BIT(TCCR1A,7);//7
	
	SET_BIT(TCCR1A,5);//5
	SET_BIT(TCCR1A,4);//4
	
	CLEAR_BIT(TCCR1A,3);//3
	CLEAR_BIT(TCCR1A,2);//2
	
	CLEAR_BIT(TCCR1A,1);//1
	SET_BIT(TCCR1A,0);//0
	
	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	
	
	SET_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	//timer 2
	CLEAR_BIT(TCCR2, 7);
	SET_BIT(TCCR2, 6);
	SET_BIT(TCCR2, 3);
	SET_BIT(TCCR2,  5);
	SET_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 2);
	SET_BIT(TCCR2, 1);
	SET_BIT(TCCR2, 0);
	
	
}

void PWM_vidSetDutyNFreqCH0(f32 Copy_u8DutyCycle)
{
	TCNT0=0;
	f32 dutycycle=(Copy_u8DutyCycle/100)*256;
	s8 bta3=(s8)dutycycle;
	OCR0=256-bta3;
		
}


void PWM_vidSetDutyNFreqCH1A(f32 Copy_u8DutyCycle)
{
	
	f32 dutycycle=(Copy_u8DutyCycle/100)*256;
	s16 bta3=(s16)dutycycle;
	OCR1A=(256-bta3);
	
}
void PWM_vidSetDutyNFreqCH1B(f32 Copy_u8DutyCycle)
{
	
	f32 dutycycle=(Copy_u8DutyCycle/100)*256;
	s16 bta3=(s16)dutycycle;
	OCR1B=(256-bta3);
	
}

void PWM_vidSetDutyNFreqCH2(f32 Copy_u8DutyCycle){
	TCNT2=0;
	f32 dutycycle=(Copy_u8DutyCycle/100)*256;
	s8 bta3=(s8)dutycycle;
	OCR2=256-bta3;
}
void PWM_vidStopPWM(void)
{
	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	//--------------------------//
	CLEAR_BIT(TCCR1A,2);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);
	//------------------------//
	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);
	//------------------------//
	CLEAR_BIT(TCCR2, 2);
	CLEAR_BIT(TCCR2, 1);
	CLEAR_BIT(TCCR2, 0);
	
    
}

