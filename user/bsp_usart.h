#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>

// UART1  log  调试打印信息

void USART1_Config(void);
void  USART1_NVIC_Configuration(void);
//int  fputc(int ch, FILE *f);

void USART1_printf(USART_TypeDef* USARTx, char *Data,...);

int _write (int fd, char *pBuffer, int size);

#endif /* __USART1_H */
