#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

/*PWM���еĵ���*/
extern uint16_t  POINT_NUM	;
//����������ε�Ƶ��
extern __IO uint16_t period_class ;

void TIM3_Int_Init(u16,u16);
void TIM4_Int_Init(u16,u16);

#endif
