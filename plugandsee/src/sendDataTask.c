
#include "sendDataTask.h"

/*
 * sendDataTask read data from xQueueOutput and send them
 * to the mobile application through the Bluetooth module
 * (UART interface for now is used)
 */
void sendDataTask(void *pvParameters) {

	uint8_t flag = FANION;
	uint8_t buff[MAX_XQUEUEOUTPUT];
	memset(buff, 0, sizeof(buff));

#ifdef DEBUG_MODE
	UART_Send(LPC_UART0, "sendDataTask launched\r\n", strlen("sendDataTask launched\r\n"), NONE_BLOCKING);
#endif

	for(;;) {
		if(xQueueOutput != 0) { // xQueueOutput MUST be valid
			vTaskDelay((PERIOD/portTICK_PERIOD_MS));

			if(uxQueueMessagesWaiting(xQueueOutput) > 0) {
				xQueueReceive(xQueueOutput, buff, (TickType_t) 0);
				UART_Send(LPC_UART0, &flag, 1, NONE_BLOCKING);
				UART_Send(LPC_UART0, buff, sizeof(buff), NONE_BLOCKING);
			}
		}else {
			UART_Send(LPC_UART0, &flag, 1, NONE_BLOCKING);
			UART_Send(LPC_UART0, "Error - xQueueOutput not valid", strlen("Error - xQueueOutput not valid"), NONE_BLOCKING);
		}
	}
}
