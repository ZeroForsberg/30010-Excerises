#include "ansi.h"

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

	if (style == 2) {
		tl = 201; 	// ╔
		lsd = 185; 	// ╣
		bl = 200;	// ╚
		wll = 186;	// ║
		btt = 205; 	// ═
		tr = 187; 	// ╗
		rsd = 204;	// ╠
		br = 188;	// ╝
	}

	if (x2 < length + 6 | x2 < y1) {
		x2 = x1 + length + 6;
	}
	if (y2 < y1) {
		y2 = y1 + 1;
	}

	blink(0);
	//Debug
	//printf("\n\nx1:%d, y1:%d\nx2:%d, y2:%d\nString:%s Len:%d\n", x1, y1, x2, y2,s, length);


	//Top ┌┤ Text ├┐
	gotoxy(x1, y1);
	printf("%c%c", tl, lsd);
	blink(1);
		printf("%c%s%c", 32, s, 32);
		for (int i = x1; i < x2 - length - 6; i++) {
			printf("%c", 32);
		}
	blink(0);
	printf("%c%c\n", rsd, tr);

	//Mid │        │
	for (int i = y1+1; i < y2; i++) {
		gotoxy(x1, i);
		printf("%c", wll);
		gotoxy(x2-1,i);
		printf("%c", wll);
	}

	//Bottom  └─────────┘
	gotoxy(x1,y2);
	printf("%c", bl);
	for (int i=x1; i < x2-2; i++){
		printf("%c", btt);
	}
	printf("%c\n", br);
}

void windowSmp(int x1, int y1, int x2, int y2) {

		int tl = 218; 	// ┌
		int lsd = 180; 	// ┤
		int bl = 192;	// └
		int wll = 179;	// │
		int btt = 196; 	// ─
		int tr = 191; 	// ┐
		int rsd = 195;	// ├
		int br = 217;	// ┘

		//Top ┌──────┐
		gotoxy(x1, y1);
		printf("%c", tl);
		for (int i=x1+1;i<x2-1;i++){
			printf("%c",btt);
		}


		printf("%c\n", tr);

		//Mid │        │
		for (int i = y1+1; i < y2; i++) {
			gotoxy(x1, i);
			printf("%c", wll);
			gotoxy(x2-1,i);
			printf("%c", wll);
		}

		//Bottom  └─────────┘
		gotoxy(x1,y2);
		printf("%c", bl);
		for (int i=x1; i < x2-2; i++){
			printf("%c", btt);
		}
		printf("%c\n", br);
	}

void windowBall(boarder b, char s[], ball_st *o) {
	int length = strlen(s);
	int hit = 2;

	int32_t x1 = b.x1;
	int32_t y1 = b.y1;
	int32_t x2 = b.x2;
	int32_t y2 = b.y2;


	int tl = 201; 	// ╔
	int lsd = 185; 	// ╣
	int bl = 200;	// ╚
	int wll = 186;	// ║
	int btt = 205; 	// ═
	int tr = 187; 	// ╗
	int rsd = 204;	// ╠
	int br = 188;	// ╝


	if (x2 < length + 6 | x2 < y1) {
		x2 = x1 + length + 6;
	}
	if (y2 < y1) {
		y2 = y1 + 1;
	}


	blink(0);
	//Debug
	//printf("\n\nx1:%d, y1:%d\nx2:%d, y2:%d\nString:%s Len:%d\n", x1, y1, x2, y2,s, length);


	//Top ┌┤ Text ├┐
	gotoxy(x1, y1);
	printf("%c%c", tl, lsd);
	blink(1);
		printf("%c%s%c", 32, s, 32);
		for (int i = x1; i < x2 - length - 5; i++) {
			printf("%c", 32);
		}
	blink(0);
	printf("%c%c\n", rsd, tr);

	//Mid │        │
	for (int i = y1+1; i < y2; i++) {
		gotoxy(x1, i);
		printf("%c", wll);
		gotoxy(x2, i);
		printf("%c", wll);
	}

	//Bottom  └─────────┘
	gotoxy(x1,y2);
	printf("%c", bl);
	for (int i=x1; i <= x2-2; i++){
		printf("%c", btt);
	}
	printf("%c\n", br);

}


