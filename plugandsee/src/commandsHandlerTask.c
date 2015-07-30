
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

	if(fifo[(i-1)] == '\n') { // End of trame detected so we can send to xQueueInput
		xQueueSend(xQueueInput, fifo, (TickType_t) 10);
		memset(fifo, 0, sizeof(fifo));
	}
}

void commandsHandlerTask(void *pvParameters) {
	uint8_t buff[SIZE_QUEUE];

	memset(buff, 0, sizeof(buff));
	memset(fifo, 0, sizeof(fifo));

	for(;;) {

		if(xQueueInput != 0) { // xQueueInput MUST be valid
			vTaskDelay((PERIOD/portTICK_PERIOD_MS));

			if(uxQueueMessagesWaiting(xQueueInput) > 0) {
				xQueueReceive(xQueueInput, buff, (TickType_t) 0);

				if(strcmp(&buff[1], "relay on\r\n")) {
					relayOn();
				} else {
					if(strcmp(&buff[1], "relay off\r\n")) {
						relayOff();
					} else {
						if(strcmp(&buff[1], "relay status\r\n")) {
							relayStatus();
						} else {
							// TODO - Continue the implementation of the commands handler
						}
					}
				}
			} // if(uxQueueMessagesWaiting(xQueue) == 0) {
		}
	} // for(;;) {
}

void relayOn(void) { // TODO - Add a physical relay
	GPIO_SetValue(RELAY_PORT_NUM, RELAY_BIT_VALUE);
	uint32_t status = GPIO_ReadValue(RELAY_PORT_NUM);

	if(status == 1) {
		xQueueSend(xQueueOutput, "relay on ok\r\n", (TickType_t) 10);
	} else {
		xQueueSend(xQueueOutput, "relay on nok\r\n", (TickType_t) 10);
	}
}

void relayOff(void) { // TODO - Add a physical relay
	GPIO_ClearValue(RELAY_PORT_NUM, RELAY_BIT_VALUE);
	uint32_t status = GPIO_ReadValue(RELAY_PORT_NUM);

	if(status == 0) {
		xQueueSend(xQueueOutput, "relay off ok\r\n", (TickType_t) 10);
	} else {
		xQueueSend(xQueueOutput, "relay off nok\r\n", (TickType_t) 10);
	}
}

void relayStatus(void) { // TODO - Add a physical relay
	uint32_t status = GPIO_ReadValue(RELAY_PORT_NUM);

	if(status == 0) {
		xQueueSend(xQueueOutput, "relay status off\r\n", (TickType_t) 10);
	} else {
		xQueueSend(xQueueOutput, "relay status on\r\n", (TickType_t) 10);
	}
}
