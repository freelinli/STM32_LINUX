#include "stm32f10x.h"

#define DELAY_TIME 0xffff
void delay(int time)
{
	unsigned int count = DELAY_TIME;
	while(time--) {
		while(count --);
		count = DELAY_TIME;
	}
}

int main()
{
	/* 开启GPIOB时钟 */
	//*(unsigned int*)(0x40021000+0x18) |= 1<<3;
	RCC->APB2ENR |= 1<<3;
	
	/* 配置PB0为推挽输出 */
	//*(unsigned int*)(0x40010c00+0x00) |= 1<<(4*0);
	GPIOB->CRL |= 1<<(4*0);
	
	/* PB0输出低电平，点亮绿色LED */
	//*(unsigned int*)(0x40010c00+0x0c) &= ~(1<<0);
	while(1) {
		delay(0x1f);
		GPIOB->ODR &= ~(1<<0);

		delay(0x1f);
		GPIOB->ODR |= (1<<0);
	}
}

