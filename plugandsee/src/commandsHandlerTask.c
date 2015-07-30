
#include "commandsHandlerTask.h"
#include "initSystem.h"

uint8_t fifo[SIZE_QUEUE];
uint8_t i = 0;

void UART0_IRQHandler(void) {
	// This handler will be called when a byte is received
	if(i >= 64)
		i = 0;

	fifo[i] = UART_ReceiveByte(LPC_UART0);
	++i;

	if(fifo[(i-1)] == '\n') // End of trame detected so we can send to xQueueInput
		xQueueSend(xQueueInput, fifo, (TickType_t) 10);
}

void commandsHandlerTask(void *pvParameters) {
	uint8_t buff[64]; // TODO - Define as a constant (64)
	memset(buff, 0, sizeof(buff));

	for(;;) {

		if(xQueueInput != 0) { // xQueue MUST be valid
			vTaskDelay((500/portTICK_PERIOD_MS)); // 500 ms

			if(uxQueueMessagesWaiting(xQueueInput) == 0) {
				xQueueReceive(xQueueInput, buff, (TickType_t) 0);

				if(strcmp(&buff[1], "relay on\r\n")) {
					xQueueSend(xQueueOutput, "relay on ok\r\n", (TickType_t) 10); // TODO - Add a physical relay

				} else {
					if(strcmp(&buff[1], "relay off\r\n")) {
						xQueueSend(xQueueOutput, "relay off ok\r\n", (TickType_t) 10); // TODO - Add a physical relay

					} else {
						if(strcmp(&buff[1], "relay status\r\n")) {
							xQueueSend(xQueueOutput, "relay status on\r\n", (TickType_t) 10); // TODO - Add a physical relay

						} else {
							// TODO - Continue the implementation of the commands handler
						}
					}
				}
			} // if(uxQueueMessagesWaiting(xQueue) == 0) {
		}
	}
}
