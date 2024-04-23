
#ifndef MCAL_PWM_PWM_PRIV_H_
#define MCAL_PWM_PWM_PRIV_H_

#define TIMER0			87
#define TIMER1			8
#define TIMER2			7

#define FAST_PWM            65
#define PHASE_PWM           21

//timer 0
#define TCCR0               *((volatile u8*)0x53)
#define TCNT0               *((volatile u8*)0x52)
#define OCR0                *((volatile u8*)0x5C)
#define TIMSK               *((volatile u8*)0x59)
#define TIFR                *((volatile u8*)0x58)

// timer 1 
#define TCCR1A	*((volatile u8*)0x4F)
#define TCCR1B	*((volatile u8*)0x4E)

#define OCR1A	*((volatile u16*)0x4A)
#define OCR1B	*((volatile u16*)0x48)

#define TCNT1	*((volatile u16*)0x4C)

//timer 2
#define TCCR2	 *((volatile u8*) 0x45)
#define TCNT2	 *((volatile u8*) 0x44)
#define OCR2	 *((volatile u8*) 0x43)









#define SET_CTC_CLR_TOP     23
#define CLR_CTC_SET_TOP     09

#endif 
