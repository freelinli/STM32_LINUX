/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  lijinnan
  * @version V1.0
  * @date    2015-01-18
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:cyb-bot-smartcar-3
  * 网址    :http://www.cyb-bot.com/
  *
  ******************************************************************************
  */ 
	
 
#include "bsp_led.h"
#include "bsp_SysTick.h"
 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
static void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启GPIOB和GPIOF的外设时钟*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOF, ENABLE); 
		
		/*选择要控制的GPIOB引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	
		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIOB*/
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
		
		/*选择要控制的GPIOF引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(GPIOF, &GPIO_InitStructure);
		
}
#define LED_DELAY 300

void SysInitIndictor(void)
{

		LED_GPIO_Config();

		LED1_ON;
		LED2_ON;
		LED3_ON;
		Delay_ms(LED_DELAY);

	
		LED1_OFF;
		LED2_OFF;
		LED3_OFF;
		Delay_ms(LED_DELAY);

}



/*********************************************END OF FILE**********************/
