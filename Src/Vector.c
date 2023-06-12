#include "ansi.h"

void printFix(int32_t i) {
// Prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // Handle negative numbers
		printf("-");
		i = ~i + 1;
	}
	printf("%ld.%04ld", i >> 16, 10000 * (uint32_t) (i & 0xFFFF) >> 16);
// Print a maximum of 4 decimal digits to avoid overflow
}

int32_t expand(int32_t i) {
// Converts an 18.14 fixed point number to 16.16
	return i << 2;
}

int32_t sinus(int32_t i) {
	//input int i out 16.16 tal/fixpoint
	if (i < 0) {
		return -SIN[-i & 0x1FF];
	} else {
		return SIN[i & 0x1FF];
	}
}

int32_t cosinus(int32_t i) {
	i += 128;
	//input int i out 16.16 tal/fixpoint
	if (i < 0) {
		return -SIN[-i & 0x1FF];
	} else {
		return SIN[i & 0x1FF];
	}
}

int32_t printSin(int32_t x) {
	printf("Sin(%d%c): ", x, 248);
	printFix(expand(sinus(x)));
	printf("\n");
}

int32_t printCos(int32_t x) {
	printf("Cos(%d%c): ", x, 248);
	printFix(expand(sinus(x + 128)));
	printf("\n");
}

void initVector(vector_t *v) {
	v->x = 10;
	v->y = 20;
}

void rotateVector(vector_t *vec, int32_t angle) {
	int32_t x = vec->x;
	int32_t y = vec->y;

	vec->x = FIX14_MULTI(x, cosinus(angle)) - FIX14_MULTI(y, sinus(angle));
	vec->y = FIX14_MULTI(x, sinus(angle)) + FIX14_MULTI(y, cosinus(angle));

}

void printVec(vector_t v, int32_t angle) {
	printf("Rotated Vector: (");
	printFix(expand(v.x));
	printf(",");
	printFix(expand(v.y));
	printf("),\t%d%c", angle, 248);



	printf("\n");
}
