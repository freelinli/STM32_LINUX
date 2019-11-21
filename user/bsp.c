#include "bsp.h"


int bsp_init(void)
{

	SysTick_Init();
	SysInitIndictor();
	USART1_Config();
	USART1_NVIC_Configuration();

}

