
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
	printf("To go backinto middle deck,");
	gotoxy(45,24);
	printf("Use down or S.");



}
