
#include "initSystem.h"

void initSystemBasics(void)
{
	uint8_t success[]="Smart Outlet Project\r\n";
	uint8_t error[]="Smart Outlet Project\r\n";

	UART_CFG_Type UART_ConfigStruct;
	UART_ConfigStruct.Baud_rate = 115200;
	UART_ConfigStruct.Parity = UART_PARITY_NONE;
	UART_ConfigStruct.Databits = UART_DATABIT_8;
	UART_ConfigStruct.Stopbits = UART_STOPBIT_1;

	UART_Init(LPC_UART0, &UART_ConfigStruct);
	UART_IntConfig(LPC_UART0, UART_INTCFG_RBR, ENABLE);

	xQueueInput = xQueueCreate(SIZE_QUEUE, sizeof(uint8_t));
	xQueueOutput = xQueueCreate(SIZE_QUEUE, sizeof(uint8_t));

#ifdef DEBUG_MODE
	if(xQueueInput == 0 && xQueueOutput == 0) {
		UART_Send(LPC_UART0, error, strlen(error), NONE_BLOCKING);
	}else {
		UART_Send(LPC_UART0, success, strlen(success), NONE_BLOCKING);
	}
#endif

	GPIO_SetDir(RELAY_PORT_NUM, RELAY_BIT_VALUE, 1);
	GPIO_SetValue(RELAY_PORT_NUM, RELAY_BIT_VALUE);

	ADC_Init(LPC_ADC, 1000); // TODO - Check if 1000 means 1kHz. Should it be only "1"
}
