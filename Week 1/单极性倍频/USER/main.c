#include "sys.h"
#include "delay.h"
#include "oled.h"
#include "timer.h"
#include "adc.h"
#include "usart.h"
#include "dac.h"
#include "iir.h"
#include "gpio.h"
#include "PID.h"
#include "pwm.h"
#include "stm32f4xx.h"


int main(void)
{ 
	delay_init(168);  //初始化延时函数
	uart_init(115200);
	//PID_init();
	//Rheostat_Init();
	//Dac1_Init();
	//TIM4_Int_Init(42-1,2-1);
	TIM8_PWM_Init(4000-1,2-1);
	TIM3_Int_Init(2100-1,2-1);	
	while(1)
	{
	}
}
