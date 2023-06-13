#include "ansi.h"
#include "stm32f30x_conf.h"
#include "timer.h"


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
	/*if(t.state){
	t.ml++;
	}

	if (t.ml == 100){
		t.ml = 0;
		t.sk++;
	}
	if (t.sk == 60) {
		t.sk = 0;
		t.mn++;
	}
	if (t.mn == 60) {
		t.mn = 0;
		t.hr++;
	}*/

/*
	static int i;
	gotoxy(1,6);
	printf("This is Tim15: %d",i);
	i++;
*/
	lcdUpdate++;

	if (lcdUpdate >= refreshRate){

		if (led.blu == 0){
			led.blu = 1;
		}
		else if (led.blu == 1){
			led.blu = 0;
		}

		placeLCD--;
		lcdUpdate = 0;
	}

	if (placeLCD == 0){
		placeLCD = 128;
	}



TIM15->SR &= ~0x0001; // Clear interrupt bit
}

void drawTime(){
	int a = t.ml;
	int b = t.sk;
	int c = t.mn;
	int d = t.hr;

	int x1 = 10, y1 = 10, x2 = 60, y2 = x1+5;

	gotoxy(x1+21,y1+2);
	printf("%01d:%02d:%02d.%02d", d, c, b, a);



}

/*
void updateTime(){
	int x1 = 10, y1 = 10, x2 = 60, y2 = x1+5;
	static int a,b,c,d;

	gotoxy(x1+29,y1+2);
	printf("%02d",a);

	a++;
	if(a > 29){
		a = 0;
		b++;
		gotoxy(x1+26,y1+2);
		printf("%02d",b);
		gotoxy(x1+29,y1+2);
		printf("%02d",a);

	}
	if(b > 59){
		b = 0;
		c++;
		gotoxy(x1+23,y1+2);
		printf("%02d",c);
		gotoxy(x1+26,y1+2);
		printf("%02d",b);

	}
	if(c > 59){
		c = 0;
		d++;
		gotoxy(x1+21,y1+2);
		printf("%01d",d);
		gotoxy(x1+23,y1+2);
		printf("%02d",c);

	}
	if(d > 9){
		d = 0;

	}
}*/


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
	t.mn = 0;
	t.hr = 0;
}







