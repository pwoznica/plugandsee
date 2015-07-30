
#ifndef _UPDATETIMESTAMPTASK_H_
#define _UPDATETIMESTAMPTASK_H_

// Kernel includes
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

uint32_t timestamp;
static SemaphoreHandle_t mutTimestamp;

void updateTimestampTask(void *pvParameters);

#endif /* _UPDATETIMESTAMPTASK_H_ */
