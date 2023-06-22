#ifndef TIMER_H_
#define TIMER_H_

#define PRESCALER_VALUE 99     // Prescaler value for Timer 2
#define RELOAD_VALUE 63999     // Auto-reload value for Timer 2

void initTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void TIM2_IRQHandler(void);
void drawTime();
void timeControll();

typedef struct{
	int8_t hr, mn, sk, ml, state;
} time_s;

volatile time_s t;


volatile int8_t timeState;

#endif /* TIMER_H_ */
