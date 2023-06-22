#include "stm32f30x_conf.h" // STM32 config
#include "ansi.h"

void initLed(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

	// Set pin PA9 to output - BLUE LED
	GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz
	GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain
	GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out


	// Set pin PC7 to output - GREEN LED
	GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz
	GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
	GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain
	GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out


	// Set pin PB4 to output - RED LED
	GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz
	GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain
	GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
}


void writeLed(){

	// Right - Blue
	if(led.blu){
		GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low - on
	}
	else{
		GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high - off
	}


	// Up - Green
	if(led.gre){
		GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to low - on
	}
	else{
		GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high - off
	}


	// Left - Red
	if(led.red){
		GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to low - on
	}
	else{
		GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high - off
	}

}
