#ifndef USART_INI_H_
#define USART_INI_H_

void USART_Init( unsigned int baud );
void USART_Transmit( unsigned char data );
void USART_Transmit1( unsigned int data );
unsigned char USART_Receive( void );
unsigned int USART_Receive1( void );
void USART_Flush( void );



#endif /* USART_INI_H_ */