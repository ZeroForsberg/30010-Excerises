
#ifndef _ANSI_H_
#define _ANSI_H_
#define ESC 0x1B

#include "stdint.h"
#include "stdio.h"
#include "LUTsin.h"

void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);

#endif _ANSI_H_



