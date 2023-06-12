#include "stm32f30x_conf.h"
#include "ansi.h"
#include "timer.h"


void initTimer2(){
	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
	TIM2->CR2 	= 0x0001; // Configure timer 2
	TIM2->ARR 	= 0xF9FF; // Set reload value
	TIM2->PSC 	= 0x0009; // Set prescale value
	TIM2->DIER	|= 0x0001;
	TIM2->SR	= 0x0000;


	TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
	TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
	TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
	TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
	TIM2->CCMR2 |= TIM_OCPreload_Enable;
	TIM2->CCR3 = RELOAD_VALUE / 2; // Set duty cycle to 50 %

	//GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);


	NVIC_SetPriority(TIM2_IRQn, 0); // Set interrupt priority
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
	GPIOB->MODER |= (0x00000001 << (10 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out


}


/*
TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
TIM2->CCMR2 |= TIM_OCPreload_Enable;
TIM2->CCR3 = RELOAD_VALUE / 2; // Set duty cycle to 50 %
*/

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
