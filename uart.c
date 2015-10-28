#include <MKL25Z4.H>
#include "uart.h"

 
void UART_DisableRX(UART_Type* uart){
  uart->C2 &= ~UART_C2_RE_MASK;
}
 
void UART_DisableTX(UART_Type* uart){
  uart->C2 &= ~UART_C2_TE_MASK;
}
 
void UART_EnableRX(UART_Type* uart){
  uart->C2 |= UART_C2_RE_MASK;
}
 
void UART_EnableTX(UART_Type* uart){
  uart->C2 |= UART_C2_TE_MASK;
}
 




void uart_init(void)
{
    SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;    // Turn on clock to PORTA
    SIM->SCGC4 |= SIM_SCGC4_UART2_MASK;    // Turn on clock to UART0
    PORTD->PCR[3] = PORT_PCR_MUX(3);//alternative 2 for pin 1 PORTA (TX)
    PORTD->PCR[2] = PORT_PCR_MUX(3);//alternative 2 for pin 1 PORTA	(RX)
    UART2->C2 = 0;//disable receiver and transmitter
    UART2->C1 = 0;
    UART2->C3 = 0;
    UART2->S2 = 0;
//		UART2->S1 |= 0x1F;	
    UART2->BDH = (((24000000/16/9600) >> 8)& UARTLP_BDH_SBR_MASK);//CLOCK/16/baud_clock
		UART2->BDL = ((24000000/16/9600)&0xff& UARTLP_BDL_SBR_MASK);//CLOCK/16/baud_clock
    UART2->C2 = UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK | UART_C2_RIE_MASK;// Enable the transmitter, receiver, and receive interrupts
    NVIC_EnableIRQ(UART2_IRQn);//enable interrupts
		NVIC_SetPriority (UART2_IRQn, 1);
	
	

}

uint8_t UART2_getChar(void)//function to get
{  
    while(!(UART2->S1 & UART_S1_RDRF_MASK));
    return UART2->D;
}
 
void UART2_putChar(uint8_t ch)//function to put
{
    while(!(UART2->S1 & UART_S1_TDRE_MASK));
    UART2->D = ch;
}
 

