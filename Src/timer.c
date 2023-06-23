#include <LED.h>
#include "ansi.h"
#include "stm32f30x_conf.h"
#include "timer.h"
#include "joystick.h"
#include "LED.h"

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
			GameOver();
		}

	}


TIM15->SR &= ~0x0001; // Clear interrupt bit
}

void drawTime(){
	static int hp;
	int red = 0, green = 0, yellow = 0, x = t.sk + (t.mn * 60);

	char greenS[] = "1G  1f 1G  1f 1G  1f 1G  1f 1G 1f 1D 1e 1f 1G  1f 1G  1f 1G  1f 1G  1f 1G 1f 1D1e1f 2c  1G 2c  1G 2c  1G 2c  1G 2c 1G 1g1g1G 2c  1G 2c  1G 2c  1G 2c  1G 2c 1G 1g1g1G  ";
	char yellowS[] = " 2G2G2G2A2B2B2A2G2G2A2B2B2A2G";
	char redS[] = " 3C3C3C3D3E3E3D3C3C3D3E3E3D3C";


	gotoxy(132,3);
	printf("%02d:%02d:%02d", t.mn, t.sk, t.ml);
//	gotoxy(2,3);
//	for (int i = 0; i < 40; i++){
//		printf("%c",32);
//	}

	gotoxy(142,3);
	t.state ? blink(1): blink(0);
	if (x>=80){
		hp = 1;
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
		hp = 2;
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
		hp = 3;

		led.red = t.state;
		fgcolor(1); // red
		for (int i = 0; i < x; i++){
			printf("%c",178);
		}
		blink(0);
		for (int i = x; i < 40; i++){
			printf("%c",32);
		}
	}
	else if (x = 0){
		hp = 0;
	}

	blink(0);
	resetbgcolor();

	switch(hp){
		case 0:
			red = 0;
			green = 0;
			break;
		case 1:
			green = !t.state | timeState;
			break;
		case 2:
			yellow = !t.state | timeState;
			break;
		case 3:
			red = !t.state | timeState;
			break;
	}

	led.gre = green | yellow;
	led.red = red | yellow;

	if (t.state){
		if(green & timeState ){
			playTone(greenS);
		}
		else if(yellow & timeState ){
			playTone(yellowS);
		}
		else if(red & timeState){
			playTone(redS);
		}
	}
	else {
		setFreq(0);
	}

}



void resetTime(){
	t.ml = 0;
	t.sk = 0;
	t.mn = 2;

	t.byThree = (t.sk + (60 * t.mn))/3;

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




