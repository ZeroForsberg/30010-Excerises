#include "stm32f30x_conf.h" // STM32 config
#include "ansi.h"


void intiJoystick(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A

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

/*
void outJoystick(int pin){
	// Set pin PA1 to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (pin * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (pin * 2)); // set speed register (0x01 - 10
	//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)

	GPIOA->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (pin)); // Set output type register (0x00 -
	//Push pull, 0x01 - Open drain)

	GPIOA->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (pin * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	GPIO(s)->ODR |= (0x0001 << pin); //Set pin PA1 to high

}*/

int16_t readJoystick(reJoy_s *j){
	int32_t a = GPIOC->IDR & (0x0001 << 0); //Read from pin PCx - up
	int32_t b = GPIOA->IDR & (0x0001 << 4); //Read from pin PCx - up
	int32_t c = GPIOB->IDR & (0x0001 << 5); //Read from pin PCx - up
	int32_t d = GPIOC->IDR & (0x0001 << 1); //Read from pin PCx - up
	int32_t e = GPIOB->IDR & (0x0001 << 0); //Read from pin PCx - up

	if(b){b = 1;}
	if(c){c = 1;}
	if(d){d = 1;}
	if(e){e = 1;}

	printf("Joystick:\n%d%d%d%d%d\n",a,b,c,d,e);
	printf("Right:%d Up:%d Center:%d Left:%d Down:%d \n",a,b,c,d,e);

	printf("%d%d%d%d%d\n",j->right,j->up ,j->center,j->left ,j->down);

	j -> right 	= a;
	j -> up 	= b;
	j -> center	= c;
	j -> left	= d;
	j -> down 	= e;

	printf("%d%d%d%d%d\n",j->right,j->up ,j->center,j->left ,j->down);
}


void initLed(){
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

void writeLed(reJoy_s j){
	int32_t a =	j.right;
	int32_t b =	j.up;
	int32_t c =	j.center;
	int32_t d =	j.left;
	int32_t e =	j.down;

	// Right - Blue
	if(a){
		GPIOA->ODR &= (0x0000 << 9); //Set pin PA9 to low - on
	}
	else{
		GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high - off
	}

	// Up - Green
	if(b){
		GPIOC->ODR &= (0x0000 << 7); //Set pin PC7 to low - on
	}
	else{
		GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high - off
	}

	// Left - Red
	if(d){
		GPIOB->ODR &= (0x0000 << 4); //Set pin PB4 to low - on
	}
	else{
		GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high - off
	}

	// Down - Blue & Red
	if(e && !(a || d)){
		GPIOA->ODR &= (0x0000 << 9); //Set pin PA9 to low - on
		GPIOB->ODR &= (0x0000 << 4); //Set pin PB4 to low - on
	}


	// Center - White(All)
	if(c && !(a || b || d)){
		GPIOA->ODR &= (0x0000 << 9); //Set pin PA9 to low - on
		GPIOC->ODR &= (0x0000 << 7); //Set pin PC7 to low - on
		GPIOB->ODR &= (0x0000 << 4); //Set pin PB4 to low - on
	}






	printf("\n\nLED:\n%d%d%d%d%d\n",a,b,c,d,e);
	printf("Right:%d Up:%d Center:%d Left:%d Down:%d \n",a,b,c,d,e);

	printf("%d%d%d%d%d\n",j.right, j.up, j.center, j.left ,j.down);




}




/*
	// Set pin PA1 to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (1 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (1 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz

	GPIOA->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain

	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (1 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out
GPIOA->ODR |= (0x0001 << 1); //Set pin PA1 to high
*/
