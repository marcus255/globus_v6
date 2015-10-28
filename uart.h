#include <MKL25Z4.H>
void uart_init(void);
uint8_t UART2_getChar(void);
void UART2_putChar(uint8_t ch);
void UART2_putStr(const uint8_t *str);
