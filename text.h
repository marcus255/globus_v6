#ifndef TEXT_H
#define TEXT_H

#include "MKL25Z4.h"

#define ARRSIZE 4096

#define SIGNWIDTH 5
#define SPACEWIDTH 1
#define NEXTPOSITION 32
#define ARRADDRESS net
									// RGBX
#define BLACK 0   // 0000
#define BLUE 2 		// 0010
#define GREEN 4		// 0100
#define CYAN 6		// 0110
#define RED  8		// 1000
#define VIOLET 10	// 1010
#define YELLOW 12	// 1100
#define WHITE 14	// 1110

void setLine(uint8_t *const ptr, uint8_t code, uint8_t line, uint8_t color);
void setLetter(uint8_t *const adr, uint8_t *ptr, uint8_t *codes, uint8_t line, uint8_t color);

#endif // #define TEXT_H

