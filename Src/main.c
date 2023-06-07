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

	sinOp(0);

	//sinOp(45);
	sinOp(64);

	//sinOp(-78);
	sinOp(-111);


	//sinOp(649);
	sinOp(923);

	printf("\n-------\n");

	cosOp(0);

	//cosOp(45);
	cosOp(64);

	//cosOp(-78);
	cosOp(-111);

	//cosOp(649);
	cosOp(923);



	while (1) {
	}
}







