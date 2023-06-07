/*
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"

	uint8_t getOutput(uint8_t P1[10], uint8_t P2[10], uint8_t *O1, uint8_t *O2, uint8_t N1, uint8_t N2);
	uint8_t getFeedback(uint8_t P[10], uint8_t *FB, uint8_t N);
	void shift(uint8_t P[10]);
	void PRN(uint8_t *code, uint16_t N);
	void PRN_alt(uint8_t* code, int16_t N);

	int main(void)
	{
		// Prepare variables
		uint8_t i;
		uint8_t code[10];
		// Setup communication with the PC
		uart_init(9600);

		//Calculate PRN code
		//underline(0);
		//blink(0);
		//inverse(0);
		//color(13,0);
		//clrscr();
		//window(5,5,25,25,"Snass",0);
		//printf("SV1 PRN: ");
		printFix(sinus(0));
		printFix(sinus(64));
		printFix(sinus(-111));
		printFix(sinus(923));
		//printFix(cosinus(0));
		//printFix(cosinus(64));
		//printFix(cosinus(-111));
		//printFix(cosinus(923));
		vector_t v = {1,1};
		// <=>
		//v.x = 1;
		//v.y = 1;
		printf("%d,%d",v.x,v.y);
		//PRN(code,10);

		// Print code
		//for (i = 0 ; i < 10 ; i++){
		//	printf("%d,",code[i]);
		//}
		//printf("...\n");
		//clreol();
		//gotoxy(1,1);
		while (1){}
	}

	void PRN(uint8_t *code, uint16_t N){
	    uint8_t P1[10] = { 1,1,1,1,1,1,1,1,1,1 }; // Register 1
	    uint8_t P2[10] = { 1,1,1,1,1,1,1,1,1,1 }; // Register 2
	    uint8_t FB1[2] = { 3,10 };                // Feedback locations for register 1
	    uint8_t FB2[6] = { 2,3,6,8,9,10 };        // Feedback locations for register 2
	    uint8_t O1[1]  = { 10 };                  // Output locations for register 1
	    uint8_t O2[2]  = { 2,6 }; 				  // Output locations for register 2
	    uint8_t tmp; 							  // Temporary storage
	    uint16_t i; 							  // Iteration variable

	    for (i = 0 ; i < N ; i++) {
	    	code[i] = getOutput(P1,P2,O1,O2,1,2);

	        // HANDLE REGISTER 1
	    	tmp = getFeedback(P1,FB1,2);
	        shift(P1);
	        P1[0] = tmp;

	        // HANDLE REGISTER 2
	        tmp = getFeedback(P2,FB2,6);
	        shift(P2);
	        P2[0] = tmp;
	    }
	}

	uint8_t getFeedback(uint8_t P[10], uint8_t *FB, uint8_t N){
	    uint8_t i, j;
	    uint8_t output = 0;
	    for (i = 0 ; i < N ; i++){
	        j = FB[i] - 1;
	        output ^= P[j];
	    }

	    return output;
	}

	void shift(uint8_t P[10]) {
	    uint8_t i;
	    for (i = 9 ; i > 0 ; i--){
	        P[i] = P[i-1];
	    }
	}

	uint8_t getOutput(uint8_t P1[10], uint8_t P2[10], uint8_t *O1, uint8_t *O2, uint8_t N1, uint8_t N2) {
	    uint8_t i, j;
	    uint8_t output = 0;
	    for (i = 0 ; i < N1 ; i++){
	        j = O1[i] - 1;
	        output ^= P1[j];
	    }
	    for (i = 0 ; i < N2 ; i++){
	        j = O2[i] - 1;
	        output ^= P2[j];
	    }

	    return output;
	}

	void PRN_alt(uint8_t* code, int16_t N){
	    uint16_t P1  = 0x3FF; // Register 1
	    uint16_t P2  = 0x3FF; // Register 2
	    uint16_t FB1 = 0x204; // Feedback locations for register 1
	    uint16_t FB2 = 0x3A6; // Feedback locations for register 2
	    uint16_t O1  = 0x200; // Output locations for register 1
	    uint8_t  O2  = 0x022; // Output locations for register 2
	    uint8_t  tmp; // Temporary storage
	    uint16_t i; // Iteration variable

	    for (i = 0 ; i < N ; i++) {
	    	tmp = (P1 & O1) ^ (P2 & O2); // Extract output bits
			tmp ^= tmp >> 8; tmp ^= tmp >> 4; tmp ^= tmp >> 2; tmp ^= tmp >> 1; // Calculate digit sum (mod 2)
			code[i] = tmp | 0x0001; // Return bit 0 of the output

	        // HANDLE REGISTER 1
	    	tmp = P1 & FB1; // Extract feedback bits
	    	tmp ^= tmp >> 8; tmp ^= tmp >> 4; tmp ^= tmp >> 2; tmp ^= tmp >> 1; // Calculate digit sum (mod 2)
	        P1 >>= 1; P1 &= 0xFFFE; P1 = tmp & 0x0001; // Shift bits and add feedback

	        // HANDLE REGISTER 2
	        tmp = P2 & FB2; // Extract feedback bits
	        tmp ^= tmp >> 8; tmp ^= tmp >> 4; tmp ^= tmp >> 2; tmp ^= tmp >> 1; // Calculate digit sum (mod 2)
	        P2 >>= 1; P2 &= 0xFFFE; P2 |= tmp & 0x0001; // Shift bits and add feedback
	    }
	}
*/
