#include "stm32f30x_conf.h" // STM32 config
#include "ansi.h"
#include "joystick.h"

void intiJoystick(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

	// Set pin PC0 to input
	GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOC->MODER |=  (0x00000000 << (0 * 2));	// Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOC->PUPDR |=  (0x00000002 << (0 * 2));// Set push/pull register
	// 0x00 - No pull
	// 0x01 - Pull-up
	// 0x02 - Pull-down


	// Set pin PA4 to input
	GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
	GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
	GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
	GPIOA->PUPDR |=  (0x00000002 << (4 * 2)); // Set push/pull register
	// 0x00 - No pull
	// 0x01 - Pull-up
	// 0x02 - Pull-down


	// Set pin PB5 to input
	GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
	GPIOB->MODER |=  (0x00000000 << (5 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out

	GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
	GPIOB->PUPDR |=  (0x00000002 << (5 * 2)); // Set push/pull register
	// 0x00 - No pull
	// 0x01 - Pull-up
	// 0x02 - Pull-down


	// Set pin PC1 to input
	GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOC->MODER |=  (0x00000000 << (1 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
	GPIOC->PUPDR |=  (0x00000002 << (1 * 2)); // Set push/pull register
	// 0x00 - No pull
	// 0x01 - Pull-up
	// 0x02 - Pull-down


	// Set pin PB0 to input
	GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOB->MODER |=  (0x00000000 << (0 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
	GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOB->PUPDR |=  (0x00000002 << (0 * 2)); // Set push/pull register
	// 0x00 - No pull
	// 0x01 - Pull-up
	// 0x02 - Pull-down

}


int16_t readJoystick(){
	int32_t a = GPIOC->IDR & (0x0001 << 0); //Read from pin PCx - right
	int32_t b = GPIOA->IDR & (0x0001 << 4); //Read from pin PCx - up
	int32_t c = GPIOB->IDR & (0x0001 << 5); //Read from pin PCx - center
	int32_t d = GPIOC->IDR & (0x0001 << 1); //Read from pin PCx - left
	int32_t e = GPIOB->IDR & (0x0001 << 0); //Read from pin PCx - down

	if(b){b = 1;}
	if(c){c = 1;}
	if(d){d = 1;}
	if(e){e = 1;}

	joy.right 	= a;
	joy.up 		= b;
	joy.center	= c;
	joy.left	= d;
	joy.down 	= e;

	gotoxy(1,6);
	printf("%d%d%d%d%d\n",a,b,c,d,e);
}





