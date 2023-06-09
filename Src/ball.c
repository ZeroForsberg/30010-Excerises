#include "ansi.h"

void initBall(ball_st *o){
	o -> pX = 0;
	o -> pY = 0;
	o -> vX = 0;
	o -> vY = 0;
	o -> hit = 0;
}


void rotateBall(ball_st *vec, int32_t angle) {
	int32_t x = vec -> vX;
	int32_t y = vec -> vY;

	vec -> vX = FIX14_MULTI(x, cosinus(angle)) - FIX14_MULTI(y, sinus(angle));
	vec -> vY = FIX14_MULTI(x, sinus(angle)) + FIX14_MULTI(y, cosinus(angle));
}

void ballMove(ball_st *o, boarder b){
	int8_t posX = o->pX;
	int8_t posY = o->pY;
	static int32_t x;
	static int32_t y;

	int16_t x1 = b.x1+2;
	int16_t y1 = b.y1+2;
	int16_t x2 = b.x2-2;
	int16_t y2 = b.y2-2;

// 2,2,111,36


	if(posX <= x1 || posX >= x2){
		if(posY <= y1 || posY >= y2){
			rotateBall(o, 256);

			o->hit = o-> hit +2;
			updateHit(o->hit, b);
		}
	}

	if (posX < x1 || posX > x2 || posY < y1 || posY > y2){

		if(posY >= y2 && x>0 || posX >= x2 && y<0 || posY <= y1 && x<0 || posX <=x1 && y>0){
			rotateBall(o, -128);
		}

		if(posY <= y1 && x>0 || posY >= y2 && x<0 || posX >= x2 && y>0 || posX <=x1 && y<0){
			rotateBall(o, 128);
		}

		o->hit = o-> hit + 1;
		updateHit(o->hit, b);
	}


	/*
	gotoxy(2,37);
	printf("%03d, %03d | ", posX, posY);

	gotoxy(13,37);
	printf("%02d, %02d | ", x, y);
*/




	x = o -> vX >> 14;
	y = o -> vY >> 14;

	o -> pX = o->pX + x;
	o -> pY = o->pY + y;



	/*
	if (posY == 35){
		o->pY = o->pY-1;
		rotateBall(o, -128);
		o->hit = o->hit + 1;

		//updateHit(o->hit);

	}
*/


}

void updateHit(int x, boarder b){
	int xm, ym;

	int16_t x1 = b.x1;
	int16_t y1 = b.y1;
	int16_t x2 = b.x2;
	int16_t y2 = b.y2;

	xm = (x1+x2)/2;
	ym = (y1+y2)/2;

	gotoxy(xm,ym);
	printf("%c",43);

	gotoxy(xm-5,ym);
	printf("Hits: %04d",x);

	windowSmp(xm-6,ym-1,xm+6,ym+1);
}




void ballDraw(ball_st o){
	static int A, B;

	gotoxy(A,B);
	printf("%c",250);

	gotoxy(o.pX,o.pY);
	printf("%c",111);

	A = o.pX;
	B = o.pY;

}


void ballDebug(ball_st o){
	static int32_t i = 0;
	int32_t velX = o.vX >> 14;
	int32_t velY = o.vY >> 14;


	printf("%d\t",i);
	printf("%d, %d |\t",o.pX, o.pY);
	printf("%d, %d | \t",velX, velY);
	printf("%d\n",o.hit);
	i++;

}
