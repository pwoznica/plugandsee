
#include "taskDataAcquisition.h"

void dataAcquisitionTask(void *pvParameters)
{
	uint8_t txBuff[]="taskDataAcquisition\r\n";
	UART_Send(LPC_UART0, txBuff, strlen(txBuff), BLOCKING);

	for(;;);
}
