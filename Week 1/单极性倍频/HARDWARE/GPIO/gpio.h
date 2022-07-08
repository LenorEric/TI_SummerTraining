#ifndef _GPIO_H
#define _GPIO_H
#include "sys.h"

#define WAVE0 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //PE4
#define WAVE1 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)	//PE3 

void IO_Init(void);

#endif
