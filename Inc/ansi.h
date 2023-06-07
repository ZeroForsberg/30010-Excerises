
#ifndef _ANSI_H_
#define _ANSI_H_
#define ESC 0x1B

#include "stdint.h"
#include "stdio.h"
#include "LUTsin.h"

void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);

#define FIX14_SHIFT 14
#define FIX14_MULTI(a, b) 	( (a) * (b) >> FIX14_SHIFT)
#define FIX14_DIV(a, b)		( ((a) << FIX14_SHIFT) / b )



typedef struct{
	int32_t x, y;
} vector_t;


#endif _ANSI_H_


