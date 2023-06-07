/*
void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
	printf("%c[m", ESC);
}

void clrscr() {
	printf("%c[%iJ", ESC, 2);
}
void clreol() {
	printf("%c[K", ESC);
}
void gotoxy(int i, int j) {
	printf("%c[%d;%dH", ESC, i, j);
}
void underline(uint8_t on) {
	if (on) {
		printf("%c[%im", ESC, 4);
	} else {
		printf("%c[%im", ESC, 24);
	}
}
void blink(uint8_t on) {
	if (on) {
		printf("%c[%im", ESC, 5);
	} else {
		printf("%c[%im", ESC, 25);
	}
}
void inverse(uint8_t on) {
	if (on) {
		printf("%c[%im", ESC, 7);
	} else {
		printf("%c[%im", ESC, 27);
	}
}

void printFix(int32_t i) {
// Prints a signed 16.16 fixed point number
if ((i & 0x80000000) != 0) { // Handle negative numbers
printf("-");
i = ~i + 1;
}
printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
// Print a maximum of 4 decimal digits to avoid overflow
}

int32_t expand(int32_t i) {
// Converts an 18.14 fixed point number to 16.16
return i << 2;
}

int32_t sinus(int32_t i) {
	//input int i out 16.16 tal/fixpoint
	printf("\n");
	if (i > 0) {
	return expand(SIN[i & 0x1FF]);
	}
	if (i < 0) {
		return expand(-SIN[-i & 0x1FF]);
	}
}

int32_t cosinus(int32_t i) {
	//input int i out 16.16 tal/fixpoint
	i += 128;
	printf("\n");
	if (i > 0) {
	return expand(SIN[i & 0x1FF]);
	}
	if (i < 0) {
		return expand(-SIN[-i & 0x1FF]);
	}
}
void initVector(vector_t* v) {
v -> x = 10;
v -> y = 20;
}
*/
