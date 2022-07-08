#include "pwm.h"
#include "usart.h"



void TIM8_PWM_Init(u32 arr,u32 psc)
{     
    GPIO_InitTypeDef  GPIO_InitStructure;	
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
	  TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
     
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE); 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);	  
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);   //使能PORTA时钟
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	  
	  GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM8);
	  GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM8);
	  GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM8); 
	  GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_TIM8);
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM8); 
     
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;  //GPIOA8/A7
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOC,&GPIO_InitStructure);  
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;  //GPIOA8/A7
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOB,&GPIO_InitStructure);  
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOC,&GPIO_InitStructure);  
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOA,&GPIO_InitStructure);  
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
    GPIO_Init(GPIOA,&GPIO_InitStructure);  
     
	  TIM_TimeBaseStructure.TIM_Prescaler = psc; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_CenterAligned3;    //中心对齐
	  TIM_TimeBaseStructure.TIM_Period = arr;                        //自动重装载值
	  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;        
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM8,&TIM_TimeBaseStructure);  
		
 	  //初始化TIM1 Channel1 PWM模式	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;     //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //比较输出使能
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;    //互补输出允许
    TIM_OCInitStructure.TIM_Pulse = (arr+1)/2;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;  //互补输出，与以上相反
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
 
    TIM_OC1Init(TIM8,&TIM_OCInitStructure);   
 	  TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);
		
		 //初始化TIM1 Channel1 PWM模式	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;     //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //比较输出使能
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;    //互补输出允许
    TIM_OCInitStructure.TIM_Pulse = (arr+1)/2;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;  //互补输出，与以上相反
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
 
    TIM_OC2Init(TIM8,&TIM_OCInitStructure);   
 	  TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);

    
		//死区
		 TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
     TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
     TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
     TIM_BDTRInitStructure.TIM_DeadTime = 0;
     TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
     TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low;
     TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
     TIM_BDTRConfig(TIM8, &TIM_BDTRInitStructure);
		 
		 TIM_ARRPreloadConfig(TIM8,ENABLE);//ARPE使能 
    
		TIM_Cmd(TIM8,ENABLE);
    TIM_CtrlPWMOutputs(TIM8,ENABLE); //使能TIM1的PWM输出
                               
}


