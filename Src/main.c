#include <LED.h>
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "timer.h"
#include "LCD.h"
#include "joystick.h"
#include "asteroid.h"

int main(void) {
	// Setup communication with the PC
	uart_init(112500);

	clrscr();

	// Setup LEDs
	initLed();

	// Setup Joystick
	intiJoystick();

	// Setup Timers with Buzzer
	initTimer();
	initTimer2();
	initBuzz();
	setFreq(0);

	refreshRate = 8;

//	char meg[] = " 3f  3d 3f 3g 2b 2b 4d  3a   3G  3g  3f  3d 3f 3g 2A 2A 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3c 3c 4d  3a   3G  3g  3f  3d 3f 3g 2b 2b 4d  3a   3G  3g  3f  3d 3f 3g 2A 2A 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3c 3c 4d  3a   3G  3g  3f  3d 3f 3g 2b 2b 4d  3a   3G  3g  3f  3d 3f 3g 2A 2A 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3c 3c 4d  3a   3G  3g  3f  3d 3f 3g 2b 2b 4d  3a   3G  3g  3f  3d 3f 3g 2A 2A 4d  3a   3G  3g  3f  3d 3f 3g 3f  3f 3f  3f  3f  3d  3d   3d  3f 3f 3f 3f  3g  3G  3g 3f 3d 3f 3g   3f  3f 3f  3g  3G  3a  4c  3a   4d  4d  4d 3a 4d 4c         3a  3a 3a  3a  3a  3g  3g     3a  3a 3a  3a  3g  3a  4d  3a 3g  4d  3a  3g  3f  4c  3a  3g  3f  3d  3e 3f  3a  4c                 3f 3d 3f 3g 3G 3g 3f 3d 3G 3g 3f 3d 3f 3g         3G  3a 4c  3a 3G 3g 3f 3d 3e 3f  3g  3G  4c   4C  3G  3G 3g 3f 3g         2f  2g  2a  3f  3e    3d    3e    3f    3g    3e    3a        3a 3G 3g 3F 3f 3e 3D 3d 3C        3D                3f 3d 3f 3g 3G 3g 3f 3d 3G 3g 3f 3d 3e 3g         3G  3a  4c  3a 3G 3g 3f 3d 3e 3f  3g  3a  4c  4C  3G  3G 3g 3f 3g       2f  2g  2a  3f  3e    3d    3e    3D 3d 3C        3D          2b      3f                                2b            3f    3e        3d            3d                                2b            3f    3e        3d        3f                                2b            3f    3e    3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3C 3C 4d  3a   3G  3g  3f  3d 3f 3g 3c 3c 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3d 3d 4d  3a   3G  3g  3f  3d 3f 3g 3C 3C 4d  3a   3G  3g  3f  3d 3f 3g 3c 3c 4d  3a   3G  3g  3f  3d 3f 3g                          ";
//
//	char doom[] = "2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a  2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D  2a    2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a      2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4f 4D 4f 4F 4d 4F 4A 4F 4d2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4A 4F4D 4F4A 4F4A 4A 4F4A 4F4A  2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d 2G 2G 3D 3e 2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d     2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d 2G 2G 3D 3e 2G 2G 3G 2G 2G 3F 2G 2G  3b 3b 3b3G 4G 3b 3b 3G3b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 3A 2A 2A 3G 2A 2A 3F 2a 2G 3e     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4D4F 3F3A 4D3A 4F4D 4F4D 3F3A 4D4F 4A 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D  2a    2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2D2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4d3b 3f3A 4f4d 3G3A 4G4f 4d 4A4G3A 4f4d 2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C2D 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D 2D  3c    2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C     2D 2D 3F 2D 2D 3f 2D 2D 6D4A 4F 6D4D4A 4A4F 4D4F 4A4F 6D4A 4F4D 2G 2G 3b 2G 2G 3A 2G 2G 3g 2G 2G 3F 2G  3F 3G 2G 2G 3b 2G 2G 3A 2G 2G 3G 2G 2G  3F    2G 2G 3b 2G 2G 3A 2G 2G 3g 2G 2G 3F 2G 2G 3F 3G 2G 2G 3b 2G 2G 3A 2G 2G 4D4C 4D3b 3G3b 4D3b 4G4D 4D3b 4D3b 3G3b 2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D   3c    2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C2D 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D 2D 3c     3c 3c 4F 3c 3c 4f 3c 3c 4D 3c 3c 4c 3c 3c 4c 4D 2A 2A 4f 2A 2A 4D 2A 2A 4d 2a 2G 3A     2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D  4d 3G3A 3d3f 2A  4f4d3A 3f3G 3d  3D                     ";
//	char bustin[] = "2d  4d  4C  4d  2A  4d  4C  4d  2a  4d  4C  4d  2G  4d  4C  4d  2g  4d  4C  4d  3f  4d  4C  4d  3C  4d  4C  4d  4C  4d  4C  4d  2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b    3f   3d   3f   3d   3f   3d  3f  3d  3c 3C 3d  3f   3d   3f   3d   3f   3d  3f  3d  3c 3C 2d  2d  2f 2F 2a  3c    2b    2d  2d  2f 2F 2a  3c    2b       ";
//	char ballin[] = "2b 2b 2b 2b  3c   2b 2a   2g 2b   3d 3d 3d 3d 2b  3d 3d 3d 3d 3d 3d 3d 3e   3d 3d 3d 3d 3d 3e   2b 2a   2g 2g   3d 3d 3d 3d 3d 3e   2b 2a   2g 2g 2b 2b 2b 3c 2b 2a 2g 2a  2a 2g 2a  2b   2b 2b 2b 3c 2b 2a 2g 2a  2a 2g 3d  2b   2b 2b 2b 2b 2b 2a 2g 2a  2a 2g 3d  2b   3d 3d 3e  2b 2b 2a  2a 2a 2g 3d  2b   2b 2b 2b 3c 2b 2a 2g 2a 2g 2a 2g 2a  2e      3e 3d 3c 2b 2b 2b 2a 2g 2a  2g    2g 2g 3d 3d 3c 2b 2b  2a 2g 2a  2g   2b 2b 2b 2b 2b 2a 2g 2a  2a 2a 2a 2g 2b   3d 3d 3d 3d 3d 3d 2b 2a 2a 2a 2a 2a 2g 2b  2g  3d 3d 3d 3d 3d 3d 3e 2b 2a 2a 2a 2g 2b  2g  3d 3d 3d 3d 3d 3d 3e 2b 2b 2a 2a 2g 2b  2g   2b 2b 2b 3d 3d 2a   2a 2a 2g 2b  2e    3d 3d 3e 2b 2b   3d 3d 3d 3e  2b  3d  3d 2b 3d 3d 3d 2b 2a 2a 2a 2g 2b  2g        3e  2b 2b 2b 2b 2b  2g  3d 3d 3d 3d 3d 3d 3e 2b 2a 2a 2a 2g 2b  2g    3d  3c 2b 2b 2a 2a 2g 2a  2b   3d 3d 3d 3d 2b 3d  3d  3c 2b 2a  2b   3d 3d 3d 3d 2b 3d 3d 3d 3c 2b 2a 2a  2b   3d 3d 3d 3e          3c          3c   2b 2a   2g 2b   3d 3d 3d 3d 2b  3d 3d 3d 3d 3d 3d 3d 3e   3d 3d 3d 3d 3d 3e   2b 2a   2g 2g   3d 3d 3d 3d 3d 3e   2b 2a   2g 2g 2b 2b 2b 3c 2b 2a 2g 2a  2a 2g 2a  2b   2b 2b 2b 3c 2b 2a 2g 2a  2a 2g   2b   2b 2b 2b 2b 2b 2a 2g 2a  2a 2g   2b   3d 3d 3e  2b 2b 2a  2a 2a 2g 3d  2b         ";
//
//	char virus[] ="2e  2a  2b  3c      3d  2b      3c  2a          2a 2G 2a 2b 3c 3d 3e    3e    3e    3e    3e            3d  3e  3f        2b    3c  3d  3e        2a    2a  2b  3c      3d  2b      3c  2a          2e  2a  2b  3c      3d  2b      3c  2a          2a 2G 2a 2b 3c 3d 3e    3e    3e    3e    3e            3d  3e  3f        2b    3c  3d  3e        2a    2a  2b  3c      3d  2b      3c  2a          2e  2a  2b  3c      3d  2b      3c  2a          2a  2G  2a  2b  2e  2D  2e  2b  2e  3e  3d  3d  3c  2b  2a  2a  2b  3c  2a  2b  2g  2F  2g  2b  2g  3g  3f  3f  3e  3d  3c  3c  3d  3e  3c  3C  2a  3C  3e  3a    3g    3f  3e  3d  3C  3d  2a  2G  2a                            3a  3b  3e  3e      3d 3c 2b  3c  3d  2e  3c  2b  2a  2G  2a  2b  3c  2a  2b     2g  2b  3g                 2b              3A  3g  3A  3e  3a  3g  3a  3f  3a  3e  3a  3D      2b  3D  4c    3D    3b    2d  2e  2f  2g  2f  2e  2d          2e  2a  2b  3c      3d  2b      3c  2a          2a 2G 2a 2b 3c 3d 3e    3e    3e    3e    3e            3d  3e  3f        2b    3c  3d  3e        2a    2a  2b  3c      3d  2b      3c  2a          2e  2a  2b  3c      3d  2b      3c  2a          2a 2G 2a 2b 3c 3d 3e    3e    3e    3e    3e            3d  3e  3f        2b    3c  3d  3e        2a    2a  2b  3c      3d  2b      3c  2a          2e  2a  2b  3c      3d  2b      3c  2a          2e  2a  2b  3c    3d  2b    3c  2a      2a  2G  2a  2b  3c  3d  3e    3e  3e    3e  3a      3d  3e  3f      2b  3c  3d  3e      2a    3c    2b                                                       ";

	t.mn = 0;
	t.sk = 10;
	t.state = 0;

	windowSmp(1,2,43,4);

	// initilize keyboard input:
	int i=0;
	uart_clear();
	char random;
	int buffer_lenght;


	while (1) {

		if (lcdUpdate == 0){
//			playTone(virus);

			drawTime();
		}


		readJoystick();

		timeControll();

		writeLed();


//		updateBuzz();



		gotoxy(1,5);
		printf("R:%d, G:%d, B:%d",led.red, led.gre, led.blu);

	}
}








