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
}

void clreol() {
	printf("%c[%s", ESC, "2k");
}

void gotoxy(int r, int c) {
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

void window(int x1, int y1, int x2, int y2, char s[], int style) {
	int length = strlen(s);

	int tl = 218; 	// ┌
	int lsd = 180; 	// ┤
	int bl = 192;	// └
	int wll = 179;	// │
	int btt = 196; 	// ─
	int tr = 191; 	// ┐
	int rsd = 195;	// ├
	int br = 217;	// ┘

	if (style == 2){
		tl = 201; 	// ╔
		lsd = 185; 	// ╣
		bl = 200;	// ╚
		wll = 186;	// ║
		btt = 205; 	// ═
		tr = 187; 	// ╗
		rsd = 204;	// ╠
		br = 188;	// ╝
	}


	if (x2 < length+6 | x2<x1){
		x2 = x1 + length + 6;
	}
	if (y2<y1){
		y2 = y1+1;
	}


	printf("\n\nx1:%d, y1:%d\nx2:%d, y2:%d\nString:%s Len:%d\n",x1,y1,x2,y2,s,length);

	for (int i = 0; i < y1; i++){
		printf("\n");
	}


		//Offset by x1
		for (int i=0;i<x1;i++){
			printf("%c",32);
		}
		printf("%c%c", tl, lsd);

		//Top ┌┤ Text ├┐
		blink(1);
		printf("%c%s%c",32,s,32);
		for(int i=0; i<x2-length-6 ;i++){
			printf("%c",32);
		}
		blink(0);
		printf("%c%c\n", rsd, tr);

		//Mid │        │
		for (int i = 1; i < y2-y1; i++) {
			for (int k=0; k < x1; k++){
				printf("%c",32);
			}

			printf("%c", wll);
			for (int j = 0; j < x2-2; j++) {
				printf("%c", 32);
			}
			printf("%c\n", wll);
		}

		//Bottom  └─────────┘
		for (int i=0;i<x1;i++){
			printf("%c",32);
				}
		printf("%c", bl);
		for (int j = 0; j < x2-2; j++) {
			printf("%c", btt);
		}
		printf("%c\n", br);


	}
