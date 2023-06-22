#include "stm32f30x_conf.h"
#include "ansi.h"
#include "timer.h"
#include "joystick.h"


void initTimer2(){

	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
	TIM2->CR1 	= 0x0000; // Configure timer 2

	TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
	TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
	TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
	TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
	TIM2->CCMR2 |= TIM_OCPreload_Enable;
	TIM2->CCR3 = RELOAD_VALUE / 2; // Set duty cycle to 50 %

	TIM2->CR1 	= 0x0001; // Configure timer 2

	TIM2->ARR 	= 0xF9FF; // Set reload value
	TIM2->PSC 	= 0x0009; // Set prescale value
	TIM2->DIER	|= 0x0001;
	TIM2->SR	= 0x0000;

	NVIC_SetPriority(TIM2_IRQn, 1); // Set interrupt priority
	NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt
}

void TIM2_IRQHandler(void) {


//Do whatever you want here, but make sure it doesn’t take too much Time.
TIM2->SR &= ~0x0001; // Clear interrupt bit
}


void initBuzz(){
	// Set pin PA9 to output - BLUE LED
	GPIOB->OSPEEDR &= ~(0x00000003 << (10 * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (10 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz
	GPIOB->OTYPER &= ~(0x0001 << (10 * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (10)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain
	GPIOB->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000002 << (10 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);

}


void updateBuzz() {

	if (timeState){
		if (joy.up) {
			buzzTone = buzzTone + 1;
		}
		else if (joy.down) {
			buzzTone = buzzTone - 1;
		}
		else if (joy.left) {
			buzzTone = buzzTone - 10;
		}
		else if (joy.right) {
			buzzTone = buzzTone + 10;
		}
		else if (joy.center) {
			buzzTone = 0;
		}
	}
	//else (buzzTone = 0);
}

char ballin[] = " 2b 2b 2b 2b  3c";

void playTone(char s[]){
	static int i;

	int length = strlen(s);

	switch(s[i]){
	case '1':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 33;
				break;
			case 'C':
				buzzTone = 35;
				break;

			case 'd':
				buzzTone = 37;
				break;
			case 'D':
				buzzTone = 39;
				break;

			case 'e':
				buzzTone = 41;
				break;

			case 'f':
				buzzTone = 44;
				break;
			case 'F':
				buzzTone = 46;
				break;

			case 'g':
				buzzTone = 49;
				break;
			case 'G':
				buzzTone = 52;
				break;

			case 'a':
				buzzTone = 55;
				break;
			case 'A':
				buzzTone = 58;
				break;

			case 'b':
				buzzTone = 62;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;
	case '2':
		i++;
		printf("%c",s[i]);
		switch(s[i]){
			case 'c':
				buzzTone = 65;
				break;
			case 'C':
				buzzTone = 69;
				break;

			case 'd':
				buzzTone = 73;
				break;
			case 'D':
				buzzTone = 78;
				break;

			case 'e':
				buzzTone = 82;
				break;

			case 'f':
				buzzTone = 87;
				break;
			case 'F':
				buzzTone = 93;
				break;

			case 'g':
				buzzTone = 98;
				break;
			case 'G':
				buzzTone = 104;
				break;

			case 'a':
				buzzTone = 110;
				break;
			case 'A':
				buzzTone = 117;
				break;

			case 'b':
				buzzTone = 123;
				break;
			default:
				buzzTone = 0;
				break;
		}
	break;

	case '3':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 131;
				break;
			case 'C':
				buzzTone = 139;
				break;

			case 'd':
				buzzTone = 147;
				break;
			case 'D':
				buzzTone = 156;
				break;

			case 'e':
				buzzTone = 165;
				break;

			case 'f':
				buzzTone = 175;
				break;
			case 'F':
				buzzTone = 185;
				break;

			case 'g':
				buzzTone = 196;
				break;
			case 'G':
				buzzTone = 208;
				break;

			case 'a':
				buzzTone = 220;
				break;
			case 'A':
				buzzTone = 233;
				break;

			case 'b':
				buzzTone = 247;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	case '4':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 262;
				break;
			case 'C':
				buzzTone = 277;
				break;

			case 'd':
				buzzTone = 294;
				break;
			case 'D':
				buzzTone = 311;
				break;

			case 'e':
				buzzTone = 330;
				break;

			case 'f':
				buzzTone = 349;
				break;
			case 'F':
				buzzTone = 370;
				break;

			case 'g':
				buzzTone = 392;
				break;
			case 'G':
				buzzTone = 415;
				break;

			case 'a':
				buzzTone = 440;
				break;
			case 'A':
				buzzTone = 466;
				break;

			case 'b':
				buzzTone = 494;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	case '5':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 523;
				break;
			case 'C':
				buzzTone = 554;
				break;

			case 'd':
				buzzTone = 587;
				break;
			case 'D':
				buzzTone = 622;
				break;

			case 'e':
				buzzTone = 659;
				break;

			case 'f':
				buzzTone = 698;
				break;
			case 'F':
				buzzTone = 740;
				break;

			case 'g':
				buzzTone = 784;
				break;
			case 'G':
				buzzTone = 831;
				break;

			case 'a':
				buzzTone = 880;
				break;
			case 'A':
				buzzTone = 932;
				break;

			case 'b':
				buzzTone = 988;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	default:
		buzzTone = 0;
		break;
	}

	setFreq(buzzTone);
	gotoxy(1,8);
	printf("Input[%02d]: %c%c, Buzz: %04d | Length: %04d",i, s[i-1], s[i], buzzTone, length);

	if (i > length){
		i = 0;
	}

	i++;

}




void setFreq(uint16_t freq)
{
    // Calculate the new auto-reload value based on the desired frequency
    uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;

    // Set the new auto-reload value
    TIM2->ARR = reload;

    // Set compare register to maintain 50% duty cycle
    TIM2->CCR3 = reload / 2;

    // Generate an update event to apply the new settings
    TIM2->EGR |= TIM_EGR_UG;
}
