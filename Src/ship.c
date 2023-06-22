

void spaceship(int x1, int y1, int x2, int y2) { // Ship
	fgcolor(1);
	int ex = 0;
	gotoxy(x1+15, y1);
	for(int i = 0; i <9; i++) {
	printf("%c",219);
	}
	bgcolor(5);
	fgcolor(0);
	printf("  UP  ");
	bgcolor(0);
	fgcolor(1);
	for(int i = 0; i <20; i++) {
	printf("%c",219);
	}
	bgcolor(6);
	fgcolor(0);
	printf("HATCH");
	fgcolor(1);
	for(int i = 0; i <29; i++) {
	printf("%c",219);
	}
	gotoxy(x1+15, y1+4);
	for(int i = 0; i <9; i++) {
	printf("%c",219);
	}
	bgcolor(5);
	fgcolor(0);
	printf(" DOWN ");
	bgcolor(0);
	fgcolor(1);
	for(int i = 0; i <20; i++) {
	printf("%c",219);
	}
	bgcolor(6);
	fgcolor(0);
	printf("HATCH");
	fgcolor(1);
	for(int i = 0; i <29; i++) {
	printf("%c",219);
	}
	int a = 0;
	for (int j = 0; j < 3; j++){
	for(int i = 0; i < 7; i++){
	gotoxy(x1+9+i+a, y1-3+j);
	printf("%c",219);
	gotoxy(x1+9+i+a, y1+7-j);
	printf("%c",219);
	} a+=2;
	}
	for(int i = 1; i < 4; i++) {
	gotoxy(x1+15, y1+i);
	printf("%c",219);
	for(int j = 0; j < 6; j++){
	gotoxy(x2-8+j, y1+i);
	printf("%c",219);
	ex++;
	if (ex < 5){
	gotoxy(x2-3+j, y1+i+1);
	printf("%c",219);
	}
	}
	}
	gotoxy(83,y1+2);
	fgcolor(0);
	bgcolor(7);
	printf(" CANON   ");
	resetbgcolor();
}


void playerInSpaceR(int p, int x, int y){   //duck
	if (p == 1) {
	fgcolor(15);
	bgcolor(7);
	gotoxy(x+2,y);
	printf("%c",254	);
	bgcolor(0);

	gotoxy(x,y+1);
	printf("%c",223);
	printf("%c",219);
	printf("%c",219);

	fgcolor(9);
	gotoxy(x+1,y+2);
	printf("%c",192);
	printf("%c",192);

	bold(1);
	fgcolor(9);
	bgcolor(7);
	gotoxy(x+3,y);
	printf("%c",60);
	bgcolor(0);
	fgcolor(2);
	bold(0);
	}

	if (p == 2) {
	fgcolor(11);
	bgcolor(7);
	gotoxy(x+2,y);
	printf("%c",254	);
	bgcolor(0);

	gotoxy(x,y+1);
	printf("%c",223);
	printf("%c",219);
	printf("%c",219);

	fgcolor(9);
	gotoxy(x+1,y+2);
	printf("%c",192);
	printf("%c",192);

	bold(1);
	fgcolor(9);
	bgcolor(7);
	gotoxy(x+3,y);
	printf("%c",60);
	bgcolor(0);
	fgcolor(2);
	bold(0);
	}
	resetbgcolor();
}

void playerInShipL(int p,int x, int y){

	if (p == 1) {
	fgcolor(15);
	gotoxy(x+1,y);
	printf("%c",254	);

	gotoxy(x+1,y+1);
	printf("%c",219);
	printf("%c",219);
	printf("%c",223);

	fgcolor(9);
	gotoxy(x+1,y+2);
	printf("%c",217);
	printf("%c",217);

	bold(1);
	fgcolor(9);
	gotoxy(x,y);
	printf("%c",62);
	fgcolor(2);
	bold(0);
	}

	if (p == 2) {
	fgcolor(11);
	gotoxy(x+1,y);
	printf("%c",254	);

	gotoxy(x+1,y+1);
	printf("%c",219);
	printf("%c",219);
	printf("%c",223);

	fgcolor(9);
	gotoxy(x+1,y+2);
	printf("%c",217);
	printf("%c",217);

	bold(1);
	fgcolor(9);
	gotoxy(x,y);
	printf("%c",62);
	resetbgcolor();
	bold(0);
	}
}
