#ifndef TIMER_H_
#define TIMER_H_

#define PRESCALER_VALUE 99     // Prescaler value for Timer 2
#define RELOAD_VALUE 63999     // Auto-reload value for Timer 2

//void initTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void TIM2_IRQHandler(void);

#endif /* TIMER_H_ */
