
#ifndef _TASKCOMMANDSHANDLER_H_
#define _TASKCOMMANDSHANDLER_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <string.h>

#include "lpc177x_8x_uart.h"

extern QueueHandle_t xQueueInput;
extern QueueHandle_t xQueueOutput;

void commandsHandlerTask(void *pvParameters);

#endif /* _TASKCOMMANDSHANDLER_H_ */
