#include "stm32f10x.h"
#include "bsp.h"

int main(int argc, const char *argv[])
{

	bsp_init();

	while(1) {
		Delay_ms(1000);
		LED1(1);
		LED2(1);
		LED3(1);

		Delay_ms(1000);
		LED1(0);
		LED2(0);
		LED3(0);
		printf("hello\r\n");
		USART1_printf(USART1, "world\r\n");
	}
}

