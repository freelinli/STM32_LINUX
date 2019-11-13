/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  lijinnan
  * @version V1.0
  * @date    2015-01-18
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:cyb-bot-smartcar-3
  * ��ַ    :http://www.cyb-bot.com/
  *
  ******************************************************************************
  */ 
	
 
#include "bsp_led.h"
#include "bsp_SysTick.h"
 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
static void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����GPIOB��GPIOF������ʱ��*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOF, ENABLE); 
		
		/*ѡ��Ҫ���Ƶ�GPIOB����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIOB*/
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIOF����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIOF*/
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
