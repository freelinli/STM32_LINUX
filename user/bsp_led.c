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

void GPIO_set_value(GPIO_TypeDef *gpio, int pin, int value)
{
	value ? GPIO_SetBits(gpio, pin) : GPIO_ResetBits(gpio, pin);
}

void GPIO_Config(GPIO_TypeDef *gpio, uint32_t clk, int pin, int mode, int speed, int value)
{		
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(clk, ENABLE); 
																   
		GPIO_InitStructure.GPIO_Pin = pin;	
		GPIO_InitStructure.GPIO_Mode = mode;   
		GPIO_InitStructure.GPIO_Speed = speed; 

		GPIO_Init(gpio, &GPIO_InitStructure);	
		GPIO_set_value(gpio, pin, value);	
}
/*
void SysInitIndictor(void)
{
		GPIO_Config(GPIOB, RCC_APB2Periph_GPIOB, GPIO_Pin_0, GPIO_Mode_Out_PP, GPIO_Speed_50MHz, 0);
		GPIO_Config(GPIOF, RCC_APB2Periph_GPIOF, GPIO_Pin_7, GPIO_Mode_Out_PP, GPIO_Speed_50MHz, 1);
		GPIO_Config(GPIOF, RCC_APB2Periph_GPIOF, GPIO_Pin_8, GPIO_Mode_Out_PP, GPIO_Speed_50MHz, 0);
}
*/
