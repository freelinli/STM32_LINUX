#include "stm32f10x.h"
#include "bsp.h"
#define DELAY_TIME 0xffff
void delay(int time)
{
	unsigned int count = DELAY_TIME;
	while(time--) {
		while(count --);
		count = DELAY_TIME;
	}
}
int main(int argc, const char *argv[])
{

	bsp_init();
	
	//*(unsigned int*)(0x40021000+0x18) |= 1<<3;
	RCC->APB2ENR |= 1<<3;
	
	//*(unsigned int*)(0x40010c00+0x00) |= 1<<(4*0);
	GPIOB->CRL |= 1<<(4*0);
	
	//*(unsigned int*)(0x40010c00+0x0c) &= ~(1<<0);
	while(1) {
		Delay_ms(1000);
		GPIOB->ODR &= ~(1<<0);

		Delay_ms(1000);
		GPIOB->ODR |= (1<<0);
	}
}

