#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "timer.h"
#include "LCD.h"
#include "joystick.h"

int main(void) {

	// Setup communication with the PC
	uart_init(115200);
	clrscr();
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


/*
	boarder b = {2,2,110,36};

	windowBall(b,"Ball");

	ball_st o = {5,5, 1 << FIX14_SHIFT, 1 << FIX14_SHIFT, 0};

	int32_t angle = 128;

	//rotateBall(&o, angle);
	//ballDebug(o);
*/

/*
	intiJoystick();

	initLed();

	reJoy_s j = {};
	gotoxy(0,0);



	//t = {.ml = 0, 0, 0, 0};
	windowTimer();
	initTimer();

	t.hr = 0;
	t.mn = 0;
	t.sk = 0;
	t.ml = 0;


			//updateTime();
		drawTime();

		readJoystick(&j);
		writeLed(j);
*/


	initLed();
	writeLed();

	intiJoystick();

	initTimer();
	initTimer2();
	initBuzz();
	setFreq(0);

	refreshRate = 10;

	lcd_init();
	memset(buffer, 0x00, 512);
	char navn[] = "You're going to have a bad time! ";
	placeLCD = 128;

	char notes[] = "d d d a G g f d f g c c d a G g f d f g b b d a G g f d f g A A d";
	char meg[] = "d d dd a G g f dfgcc a G g d d f dfg a G g f dfg bb AA d a G g f dfgdd a G g d d fgcc a G g f dfg a G bb d g f dfg a G g f dfgdd AA d d cc a G g f dfg a G g bb d f dfg a G g f dfgf ff AA f f d d d ffff g G gfdfg c d d d dc f ff g G a a a a aa a a g g a d d c aa a g a ag a g f a c g f d ef a fdfgGgfdGgfdfg G c c C a aGgfdef g G G Ggfg f e d e f g a f g e a aGgF feDdC D fdfgGgfdGgfdeg G c c C a aGgfdef g a G Ggfg f e d e f g a f g e a aGgFfe DdC D b f e d f f e b d d b f e d f f e b d d d dd a G g f dfgdd a G d g f dfgCC a G g f dfgcc d d a G g f dfgdd a G g f d d dfgdd a G g f dfgCC a d G g f dfgcc a G g f dfg";

	char a[] = "abc";
	//char notec[] = "c";
	//playNotes2(notec);
	int i = 0;
	int length = strlen(meg);

	while (1) {

		if (lcdUpdate == 0){
			lcd_update_scroll(navn, placeLCD);

			playTone(meg, i);
			i++;

			if (i > length){
				i = 0;
			}


		}


		writeLed();
		readJoystick();

		updateBuzz();
		setFreq(buzzTone);

		gotoxy(1,2);
		printf("Update: %03d, Place: %03d",lcdUpdate, placeLCD);

		gotoxy(1,4);
		printf("Tone: %06d",buzzTone);



		//gotoxy(1, 1);
		//printf("%03d, %03d\n", lcdUpdate, placeLCD);
		//printf("String Length: %03d",strlen(navn));

	}
}







