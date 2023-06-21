
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

typedef struct{
	int32_t pX, pY, vX, vY, hit;
} ball_st;

typedef struct{
	int32_t x1, y1, x2, y2;
} boarder;


typedef struct{
	int8_t hr, mn, sk, ml, state;
} time_s;

typedef struct{
	int red, blu, gre;
} led_s;



volatile time_s t;
volatile led_s led;


volatile int lcdUpdate, refreshRate, placeLCD;

volatile uint32_t buzzTone;


#endif



