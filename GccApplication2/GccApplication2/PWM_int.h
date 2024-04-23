#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_

void PWM_vidInit(void);

void PWM_vidSetDutyNFreqCH0(f32 Copy_u8DutyCycle);
void PWM_vidSetDutyNFreqCH1A(f32 Copy_u8DutyCycle);
void PWM_vidSetDutyNFreqCH1B(f32 Copy_u8DutyCycle);
void PWM_vidSetDutyNFreqCH2(f32 Copy_u8DutyCycle);

void PWM_vidStopPWM(void);

#endif 
