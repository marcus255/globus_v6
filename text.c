#include "text.h"
#include "MKL25Z4.h"

extern uint8_t syl[];
extern uint8_t linux[];
extern uint8_t net[];

uint8_t M_LETTER[SIGNWIDTH] = {127,32,12,32,127};
uint8_t A_LETTER[SIGNWIDTH] = {63,100,68,100,63};
uint8_t R_LETTER[SIGNWIDTH] = {127,72,76,74,49};
uint8_t E_LETTER[SIGNWIDTH] = {127,73,73,73,65};
uint8_t K_LETTER[SIGNWIDTH] = {127,8,20,34,65};

void setLine(uint8_t *const ptr, uint8_t code, uint8_t line, uint8_t color) //lines are from 0 to 7
{
		uint8_t i;
		if(!(line % 2)) // if the line number is even (0, 2, 4, 6)
				color <<= 4; // converts 0000RGB0 mask into RGB00000
		for(i = 0; i < 8; i++)
				if (code & (1<<i)) // checking if bits are set
						*(ptr + 4*i + line/2) |= color; // modifing byte nibble to set selected color
}

void setLetter(uint8_t *const adr, uint8_t *ptr, uint8_t *codes, uint8_t line, uint8_t color)
{
		uint8_t i;
		ptr = adr;
		for(i = 0; i < SIGNWIDTH; i++)
		{
				setLine(ptr, *(codes + i), line, color);
				if (ptr + 32 > adr + 4096 - 32) // to avoid segmentation fault
						ptr+=NEXTPOSITION; // moving pointer to the next pixels column
				else 
						ptr = adr; // returning to the beginning of data array
		}
		if (ptr + 32 > adr + 4096 - 32)
				ptr+=NEXTPOSITION; // adding some space (one column of pixels) beetwen letters
		else 
				ptr = adr;  // returning to the beginning of data array
}
