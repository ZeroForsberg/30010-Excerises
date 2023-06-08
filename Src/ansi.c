#include "ansi.h"

void fgcolor(uint8_t foreground) {
	/*  Value      foreground     Value     foreground
	 ------------------------------------------------
	 0        Black            8       Dark Gray
	 1        Red              9       Light Red
	 2        Green           10       Light Green
	 3        Brown           11       Yellow
	 4        Blue            12       Light Blue
	 5        Purple          13       Light Purple
	 6        Cyan            14       Light Cyan
	 7        Light Gray      15       White
	 */
	uint8_t type = 22;             // normal text
	if (foreground > 7) {
		type = 1;                // bold text
		foreground -= 8;
	}
	printf("%c[%d;%dm", ESC, type, foreground + 30);
}

void bgcolor(uint8_t background) {
	/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
	 Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
	 The designers of HyperTerminal, however, preferred black text on white background, which is why
	 the colors are initially like that, but when the background color is first changed there is no
	 way comming back.
	 Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

	 Value      Color
	 ------------------
	 0        Black
	 1        Red
	 2        Green
	 3        Brown
	 4        Blue
	 5        Purple
	 6        Cyan
	 7        Gray
	 */
	printf("%c[%dm", ESC, background + 40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
	uint8_t type = 22;             // normal text
	if (foreground > 7) {
		type = 1;                // bold text
		foreground -= 8;
	}
	printf("%c[%d;%d;%dm", ESC, type, foreground + 30, background + 40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
	printf("%c[m", ESC);
}

void clrscr() {
	printf("%c[%s", ESC, "2J");
	printf("%c[%s", ESC, "3J");
	resetbgcolor();

	gotoxy(0, 0);
}

void clreol() {
	printf("%c[%s", ESC, "2k");
}

void gotoxy(int c, int r) {
	printf("%c[%d;%dH", ESC, r, c);
}

void underline(int state) {
	if (state) {
		//printf("\x1b[4m");
		printf("%c[%dm", ESC, 4);
	} else {
		//printf("\x1b[24m");
		printf("%c[%dm", ESC, 24);
	}
}

void blink(int state) {
	if (state) {
		//printf("\x1b[5m");
		printf("%c[%dm", ESC, 5);
		printf("%c[%dm", ESC, 7);
	} else {
		//printf("\x1b[25m");
		printf("%c[%dm", ESC, 25);
		printf("%c[%dm", ESC, 27);
	}
}
