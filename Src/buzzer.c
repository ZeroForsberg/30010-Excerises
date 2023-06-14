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
/*
	static int i;
	gotoxy(1,4);
	printf("This is Tim2: %d",i);
	i++;
*/

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

	if (led.blu){
		if (joy.down) {
			buzzTone = 50;
		}
		else if (joy.left) {
			buzzTone = 100;
		}
		else if (joy.up) {
			buzzTone = 150;
		}
		else if (joy.right) {
			buzzTone = 200;
		}
		else if (joy.center) {
			buzzTone = 0;
		}
	}
	//else (buzzTone = 0);
}


void playTone(char s[],int i){
	int length = strlen(s);


	switch(s[i]){
    case 'c':
        buzzTone = 261;
        break;
    case 'd':
        buzzTone = 293;
        break;
    case 'e':
        buzzTone = 329;
        break;
    case 'f':
        buzzTone = 349;
        break;
    case 'g':
        buzzTone = 392;
        break;
    case 'a':
        buzzTone = 440;
        break;
    case 'b':
        buzzTone = 491;
        break;
    case 'C':
        buzzTone = 525;
        break;
    case 'D':
        buzzTone = 561;
        break;
    case 'E':
        buzzTone = 581;
        break;
    case 'F':
        buzzTone = 601;
        break;
    case 'G':
        buzzTone = 644;
        break;
    case 'A':
        buzzTone = 692;
        break;
    case 'B':
        buzzTone = 745;
        break;
    default:
        buzzTone = 0;
        break;

	}

	gotoxy(1,8);
	printf("Input[%02d]: %c, Buzz: %04d | Length: %03d",i, s[i],buzzTone,length);





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
