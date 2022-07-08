#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

/*PWM表中的点数*/
extern uint16_t  POINT_NUM	;
//控制输出波形的频率
extern __IO uint16_t period_class ;

void TIM3_Int_Init(u16,u16);
void TIM4_Int_Init(u16,u16);

#endif
