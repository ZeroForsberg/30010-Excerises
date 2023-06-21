#include "ansi.h"
#include "stm32f30x_conf.h"
#include "timer.h"
#include "joystick.h"

void initTimer(){

	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 	= 0x0001; // Configure timer 15
	TIM15->ARR 	= 0xF9FF; // Set reload value
	TIM15->PSC 	= 0x0009; // Set prescale value
	TIM15->DIER	|= 0x0001;
	TIM15->SR	= 0x0000;
	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}


void TIM1_BRK_TIM15_IRQHandler(void) {
	static int8_t state;

	lcdUpdate++;
	if (lcdUpdate >= refreshRate){

		if (timeState == 0){
			timeState = 1;

		}
		else if (timeState == 1){
			timeState = 0;

		}

		placeLCD--;
		lcdUpdate = 0;
	}


	if (placeLCD == 0){
		placeLCD = 128;
	}

	if(t.state){
		if (t.ml <= 0){
			t.ml = 99;
			t.sk--;
		}
		if (t.sk < 0){
			t.sk = 59;
			t.mn--;
		}
		t.ml--;
		if (t.mn < 0){
			t.state = 0;
			t.mn = 0;
			t.sk = 0;
			t.ml = 0;
		}

	}


TIM15->SR &= ~0x0001; // Clear interrupt bit
}

void drawTime(){

	int x = t.sk + (t.mn * 60);
	int y = 40;

	gotoxy(15,1);
	printf("%02d:%02d:%02d | %d | %03d", t.mn, t.sk, t.ml, t.state,x);
//	gotoxy(2,3);
//	for (int i = 0; i < 40; i++){
//		printf("%c",32);
//	}

	gotoxy(2,3);
	t.state ? blink(1): blink(0);
	if (x>=80){
		fgcolor(2); // green
		for (int i = 0; i < x-80; i++){
			printf("%c",178);
		}
		fgcolor(11); // yellow
		for (int i = x-80; i < 40; i++){
			printf("%c",178);
		}
	}
	else if (x>=40){
		fgcolor(11); // yellow
		for (int i = 0; i < x-40; i++){
			printf("%c",178);
		}
		fgcolor(1); // red
		for (int i = x-40; i < 40; i++){
			printf("%c",178);
		}
	}
	else if (x<40){
		fgcolor(1); // red
		for (int i = 0; i < x; i++){
			printf("%c",178);
		}
		blink(0);
		for (int i = x; i < 40; i++){
			printf("%c",32);
		}
	}

	blink(0);
	resetbgcolor();

}


void windowTimer() {

	int x1 = 10;
	int y1 = 10;
	int x2 = 43;
	int y2 = x1+5;

	char s[] = "Stop Watch";
	char l1[] = "Time since start:";
	char l2[] = "Split time 1:";
	char l3[] = "split time 2:";

	char *arrl[] = {"Time since start:", "Split time 1:", "Split time 1:"};

	int length = strlen(s);

	int tl = 218; 	// ┌
	int lsd = 180; 	// ┤
	int bl = 192;	// └
	int wll = 179;	// │
	int btt = 196; 	// ─
	int tr = 191; 	// ┐
	int rsd = 195;	// ├
	int br = 217;	// ┘

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


	for(int i = 0; i<=2;i++){
		gotoxy(x1+2, y1+2+i);
		printf("%s", arrl[i]);

		gotoxy(x1+21,y1+2+i);
		printf("-:--:--.--");
	}

}


void splitTime1(int i){
	int a = t.ml;
	int b = t.sk;
	int c = t.mn;
	int d = t.hr;


	int x1 = 10, y1 = 10, x2 = 60, y2 = x1+5;

		gotoxy(x1+21,y1+2+i);
		printf("%01d:%02d:%02d.%02d", d, c, b, a);
}

void resetTime(){
	t.ml = 0;
	t.sk = 0;
	t.mn = 2;
	t.hr = 0;
}


void timeControll(){

	readJoystick();

	if(joy.up){
		t.state = 0;
	}
	else if (joy.down){
		t.state = 1;
	}
	else if (joy.right){
		resetTime();
	}



}




