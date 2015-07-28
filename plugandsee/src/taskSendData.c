
#include "taskSendData.h"

// extern QueueHandle_t xQueue;

/*
 * sendDataTask read data from a queue and send them to the
 * mobile application through the Bluetooth module (UART
 * interface for now)
 */
void sendDataTask(void *pvParameters)
{
#ifdef DEBUG_MODE
	uint8_t txBuff[] = "taskSendData launched\r\n";
	UART_Send(LPC_UART0, txBuff, strlen(txBuff), NONE_BLOCKING);
#endif

	for(;;){
	}
}
