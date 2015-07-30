
#ifndef _INITSYSTEM_H_
#define _INITSYSTEM_H_

// Kernel includes
#include "FreeRTOS.h"
#include "queue.h"

#include <string.h>

#include "lpc177x_8x_uart.h"
#include "lpc177x_8x_gpio.h"
#include "lpc177x_8x_adc.h"

// Priorities at which the tasks are created (TBC)
#define UPDATE_TIMESTAMP_TASK_PRIORITY		(tskIDLE_PRIORITY + 6)
#define DATA_LOGGER_TASK_PRIORITY		(tskIDLE_PRIORITY + 5)
#define DATA_ACQUISITION_TASK_PRIORITY		(tskIDLE_PRIORITY + 4)
#define	COMMAND_HANDLER_TASK_PRIORITY		(tskIDLE_PRIORITY + 3)
#define SEND_DATA_TASK_PRIORITY			(tskIDLE_PRIORITY + 2)
#define SAVING_DATA_TASK_PRIORITY			(tskIDLE_PRIORITY + 1)

#define SIZE_QUEUE							(64) // TBC

#define RELAY_PORT_NUM						(0)  // TODO - To update when the relay will be connected
#define RELAY_BIT_VALUE						(0)  // TODO - To update when the relay will be connected

#define TEMP_PORT_NUM						(0)  // TODO - To update when the temp. sensor will be connected
#define TEMP_BIT_VALUE						(12) // TODO - To update when the temp. sensor will be connected

#define CURRENT_PORT_NUM					(0)  // TODO - To check which input is used on actual hardware
#define CURRENT_BIT_VALUE					(13) // TODO - To check which input is used on actual hardware

extern QueueHandle_t xQueueInput;
extern QueueHandle_t xQueueOutput;

void initSystemBasics(void);

#endif /* _INITSYSTEM_H_ */
