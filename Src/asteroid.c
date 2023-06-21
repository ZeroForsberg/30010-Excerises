#include "stdio.h"
#include "ansi.h"
#include "asteroid.h"
#include "joystick.h"
#include "timer.h"

void initAstro(){
	ship.px = 30;
	ship.py = 39;
	ship.vx = 0;
	ship.vy = 0;

	bllt.px = 0;
	bllt.py = 0;
	bllt.vx = 0;
	bllt.vy = 0;

	ast1.px = 220;
	ast1.py = 15;
	ast1.vx = -1;
	ast1.vy = 0;

//	ast2.px = 40;
//	ast2.py = 39;
//	ast2.vx = -2;
//	ast2.vy = 0;


}


void asteroidUpdate(){
	smallship();
	moveBullet();
	asteroid1();
//	asteroid2();
}

void readjoy() {

	if (timeState) {
		if (joy.up) {
			ast1.py -= 1;
		} else if (joy.down) {
			ast1.py += 1;
		} else if (joy.left) {
			ast1.px -= 2;
		} else if (joy.right) {
			ast1.px += 2;
		}
	}
}

void readkey() {

	if (key.up) {
		ship.py -= 1;
		key.up =0;
	}
	else if (key.down) {
		ship.py += 1;
		key.down =0;
	}
	else if (key.center) {
		shoot();
		key.center =0;
	}

}


void smallship(){
	gotoxy(ship.px,ship.py);
	clearAsteroSmall(ship.px, ship.py);

	readkey();

	gotoxy(5,3);
	printf("ship: %03d,%02d | %d, %d",ship.px, ship.py, ship.vx, ship.vy);

	drawAsteroidSmall(ship.px, ship.py);

	gotoxy(ship.px,ship.py);

	printf("%c",42);

}

void shoot(){
bllt.state = 1;
bllt.px = ship.px + 6;
bllt.py = ship.py;


}

void moveBullet(){
	setFreq(0);
	if (bllt.state){
		drawBullet();
		setFreq(10);
	}

	gotoxy(5,7);
	printf("Bullet: %03d, %03d, %d", bllt.px, bllt.py, bllt.state);
}

void drawBullet(){
	gotoxy(bllt.px,bllt.py);

	for (int j=0;j<9;j++){
		printf("%c",32);
	}

	if (bllt.px < 223-9){
	bllt.px += 9;
	gotoxy(bllt.px,bllt.py);

	for(int i=0; i<3;i++){
		for (int j=0;j<3;j++){
			printf("%c",176+i);
		}
	}

//	printf("%c%c%c",176,177,178);
	if (bllt.px <= ast1.px+3 && bllt.px >= ast1.px-3 && bllt.py >= ast1.py-9 && bllt.py <= ast1.py+9){
		for (int j=0;j<9;j++){
			printf("%c",32);
		}

		gotoxy(5,6);
		printf("Hit!");
		ast1.state = 1;
		bllt.state = 0;
		setFreq(20);

	}

	}
	else{

		for (int j=0;j<9;j++){
			printf("%c",32);
		}

		bllt.state = 0;
		bllt.px = 6;
	}





}

void asteroid1(){
	static int i;
	gotoxy(ast1.px,ast1.py);
	clearAsteroSmall(ast1.px, ast1.py);

	ast1.px += ast1.vx;

	switch(i){
		case 3:
			i = 0;

			ast1.py += ast1.vy;
			if(ast1.py > ship.py && ast1.vy != -1){
				ast1.vy -= 1;
			}else if (ast1.py < ship.py && ast1.vy != 1){
				ast1.vy += 1;
			}



			break;

		default:
			i++;
			break;
	}

	gotoxy(5,4);
	printf("ast: %03d,%02d | %03d, %03d",ast1.px, ast1.py, ast1.vx, ast1.vy);
	gotoxy(5,5);
	printf("i:%03d force:%03d", i, force);

	if (ast1.px <= 10 || ast1.py >= 70 || ast1.py < 10 || ast1.state){
		ast1.px = 215;
		ast1.py = 15;
		ast1.vx = -1;
		ast1.vy = 0;
		ast1.state = 0;
		setFreq(0);
	}


	drawAsteroidSmall(ast1.px, ast1.py);
}




void asteroid2(){

	gotoxy(ast2.px,ast2.py);
	printf("%c",32);
	drawAsteroidMedium(ast2.px, ast2.py);


	ast2.px = ast2.px + ast2.vx;
	ast2.py = ast2.py + ast2.vy;

	gotoxy(4,5);
	printf("%03d,%02d | %d, %d",ast2.px, ast2.py, ast2.vx, ast2.vy);


	if (ast2.px <= 20){
		ast2.px = 110;
	}

	gotoxy(ast2.px,ast2.py);
	printf("%c",42);


}



void clearAsteroSmall(int16_t x, int16_t y) {
    gotoxy(x - 3, y - 2);
    printf("       ");
    gotoxy(x - 4, y - 1);
    printf("         ");
    gotoxy(x - 5, y);
    printf("           ");
    gotoxy(x - 4, y + 1);
    printf("         ");
    gotoxy(x - 3, y + 2);
    printf("       ");
}

void drawAsteroidSmall(int16_t x, int16_t y) {
    gotoxy(x - 3, y - 2);
    printf(".-~~~-.");

    gotoxy(x - 4, y - 1);
    printf("/ O     \\");

    gotoxy(x - 5, y);
    printf(":      o  :");

    gotoxy(x - 4, y + 1);
    printf("\\  O    /");

    gotoxy(x - 3, y + 2);
    printf("` ~~~ '");
}



void drawAsteroidMedium(int16_t x, int16_t y) {
    gotoxy(x - 8, y - 3);
    printf("    .-~~~-. ");

    gotoxy(x - 8, y - 2);
    printf(" .-`   O   `-. ");

    gotoxy(x - 8, y - 1);
    printf("/    o     O   \\ ");

    gotoxy(x - 8, y);
    printf(":     o     o   : ");

    gotoxy(x - 8, y + 1);
    printf(" \\    O     o   / ");

    gotoxy(x - 8, y + 2);
    printf("  `.   o    O .' ");

    gotoxy(x - 8, y + 3);
    printf("    `.-~~~~-.' ");
}


