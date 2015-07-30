
#ifndef _SENDDATATASK_H_
#define _SENDDATATASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "lpc177x_8x_uart.h"


#define MAX_XQUEUEOUTPUT	(64)
#define FANION				(0x7f)
#define PERIOD				(200)

extern QueueHandle_t xQueueOutput;

void sendDataTask(void *pvParameters);

#endif /* _SENDDATATASK_H_ */
