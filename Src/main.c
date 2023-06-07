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
	clrscr();
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

	printf("%l\n",printFix(sinus(256)));
	printf("%l\n",printFix(cosinus(256)));

	printf("\n-------\n\n");

	vector_t v = {1, 2};
	int32_t angle = 256;
	rotateVector(&v, angle);
	printVec(v, angle);

	vector_t a = {6, 4};
	angle = -14;
	rotateVector(&a, angle);
	printVec(a, angle);

	vector_t b = {-4, -4};
	angle = 1280;
	rotateVector(&b, angle);
	printVec(b, angle);

	vector_t c = {-4, 2};
	angle = -50;
	rotateVector(&c, angle);
	printVec(c, angle);




	while (1) {
	}
}







