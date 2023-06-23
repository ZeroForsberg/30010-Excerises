#include "window.h"

void helpScreen(){
	windowSmp(1,1,184,58);
	spaceship(2,27,91,31);

	playerInSpaceR(1,23,24);

	playerInShipL(2,37,28);

	gotoxy(100,29);
	for(int i=0; i<3;i++){
		for (int j=0;j<3;j++){
			printf("%c",176+i);
		}
	}

	//Guide PLayer 1
	windowSmp(7,18,42,21);
	gotoxy(9,19);
	printf("Player 1 Action: Center.");
	gotoxy(9,20);
	printf("Joystick: Up, Down, Left, Right.");

	for (int i = 0; i<2;i++){
		gotoxy(24,21+i);
		printf("%c",179);
	}
	gotoxy(24,21);
	printf("%c",194);


	// Guide Player 2
	windowSmp(34,33,58,36);
	gotoxy(36,34);
	printf("Player 2 Action: E.");
	gotoxy(36,35);
	printf("Keyboard: W, A, S, D.");

	for (int i = 0; i<2;i++){
		gotoxy(38,31+i);
		printf("%c",179);
	}
	gotoxy(38,33);
	printf("%c",193);


	//Up & down controll
	for (int i = 0; i<3;i++){
		gotoxy(28,28+i);
		printf("%c",179);
	}

	gotoxy(25,29);
	printf("%c%c%c%c",218,196,196,180);

	for (int i = 0; i<7;i++){
		gotoxy(25,30+i);
		printf("%c",179);
	}

	windowSmp(3,37,41,40);
	gotoxy(5,38);
	printf("UP: Move ontop and press Up or W.");
	gotoxy(5,39);
	printf("Down: Move under and press Up or W.");

	gotoxy(25,37);
	printf("%c",193);


	// Hatches
	for (int i = 0; i<3;i++){
		gotoxy(54,28+i);
		printf("%c",179);
	}
	gotoxy(54,29);
	printf("%c%c%c%c",195,196,196,217);
	for (int i = 0; i<3;i++){
		gotoxy(57,26+i);
		printf("%c",179);
	}

	windowSmp(43,20,74,25);
	gotoxy(45,21);
	printf("Up or W: Move to top deck.");
	gotoxy(45,22);
	printf("Down or S: Move to sub deck.");
	gotoxy(45,23);
	printf("To go back into middle deck,");
	gotoxy(45,24);
	printf("Use down or S.");


	// Canon
	gotoxy(80,29);
	printf("%c%c%c",218,196,196);

	for (int i = 0; i<3;i++){
		gotoxy(80,30+i);
		printf("%c",179);
	}

	windowSmp(62,33,90,36);

	gotoxy(64,34);
	printf("Walk up to the canon,");
	gotoxy(64,35);
	printf("Use Right or D to shoot.");

	gotoxy(80,33);
	printf("%c",193);


	//Astroid
	drawAsteroidSmall(170,15);

	for (int i = 0; i<3;i++){
		gotoxy(162,16+i);
		printf("%c",179);
	}

	gotoxy(162,15);
	printf("%c%c%c",218,196,196);

	windowSmp(142,18,182,23);

	gotoxy(162,18);
	printf("%c",193);

	gotoxy(144,19);
	printf("The Astroids will come from the right");
	gotoxy(144,20);
	printf("Your ship's mass will attract!");
	gotoxy(144,21);
	printf("Either perform evasive maneuvers!");
	gotoxy(144,22);
	printf("Or use the canon to shoot them.");


	//Timer
	windowSmp(141,2,183,4);
	drawTime();

	gotoxy(162,5);
	printf("%c",179);

	windowSmp(142,6,182,11);

	gotoxy(144,7);
	printf("Health is indicated by a timer.");
	gotoxy(144,8);
	printf("When damaged, countdown will begin.");
	gotoxy(144,9);
	printf("This will indicate how much time you");
	gotoxy(144,10);
	printf("Have to fix the damage, Better hurry!");

	gotoxy(162,6);
	printf("%c",193);
}

void GameOver(){
	int score = 101421;
	clrscr();
	windowSmp(1,1,184,58);
	DrawGO();

	gotoxy(72,20);
	printf("Your(s) Score was: %05d",score);
	gotoxy(72,21);
	printf("A new personal Best.");

}

void DrawGO(){
gotoxy(46,5);	printf("  /$$$$$$                                           /$$$$$$                               	");
gotoxy(46,6);	printf(" /$$__  $$                                         /$$__  $$                              	");
gotoxy(46,7);	printf("| $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$       | $$  \\ $$ /$$    /$$ /$$$$$$   /$$$$$$ 	");
gotoxy(46,8);	printf("| $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$      | $$  | $$|  $$  /$$//$$__  $$ /$$__  $$	");
gotoxy(46,9);	printf("| $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$      | $$  | $$ \\  $$/$$/| $$$$$$$$| $$  \\__/	");
gotoxy(46,9);	printf("| $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/      | $$  | $$  \\  $$$/ | $$_____/| $$      	");
gotoxy(46,10);	printf("|  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$      |  $$$$$$/   \\  $/  |  $$$$$$$| $$      	");
gotoxy(46,11);	printf(" \\______/  \\_______/|__/ |__/ |__/ \\_______/       \\______/     \\_/    \\_______/|__/      	");

}

