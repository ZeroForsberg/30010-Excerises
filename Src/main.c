#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"


int main(void) {

	// Setup communication with the PC
	uart_init(9600);

	/*
	 color(15,0);
	 underline(0);
	 blink(1);
	 // Calculate PRN code
	 printf("SV1 PRN: ");
	 PRN(code,10);


	 underline(1);
	 blink(0);
	 // Print code
	 for (i = 0 ; i < 10 ; i++){
	 printf("%d,",code[i]);
	 }
	 printf("...\n");

	 //clrscr();
	 //clreol();
	 //gotoxy(2,2);


	 window(0,0,10,2,"Hello Wolrd",1);
	 window(2,2,20,5,"Hello Wolrd2",2);
	 window(5,5,30,10,"Hello Wolrd3",1);
	 window(0,0,20,20,"Window Panel",2);
	 */
	/*
	printf("\n\n===========\n");

	printSin(0);

	//printSin(45);
	printSin(64); // 45

	//printSin(-78);
	printSin(-111);


	//printSin(649);
	printSin(923);

	printf("\n-------\n\n");

	printCos(0);

	//printCos(45);
	printCos(64);

	//printCos(-78);
	printCos(-111);

	//printCos(649);
	printCos(923);

	printf("\n-------\n\n");
*/
	/*
	printf("%l\n",printFix(expand(sinus(256))));
	printf("%l\n",printFix(expand(cosinus(256))));

	printf("\n-------\n\n");

	vector_t v = {1 << FIX14_SHIFT, 2 << FIX14_SHIFT};
	int32_t angle = 128;
	printVec(v, angle);

	for (int i=0; i<4;i++){
		rotateVector(&v, angle);
		printVec(v, angle);
	}
*/

	clrscr();
/*
	boarder b = {2,2,110,36};

	windowBall(b,"Ball");

	ball_st o = {5,5, 1 << FIX14_SHIFT, 1 << FIX14_SHIFT, 0};

	int32_t angle = 128;

	//rotateBall(&o, angle);
	//ballDebug(o);
*/

	intiJoystick();
	initLed();

	reJoy_s j = {};


	while (1) {
		gotoxy(0,0);
		readJoystick(&j);
		writeLed(j);

	}
}







