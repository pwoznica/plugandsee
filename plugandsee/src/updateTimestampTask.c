
#include "updateTimestampTask.h"

void updateTimestampTask(void *pvParameters) {
	mutTimestamp = xSemaphoreCreateMutex();

	for(;;){
		vTaskDelay((1000/portTICK_PERIOD_MS)); // 1s

		if(mutTimestamp != NULL) {
			if(xSemaphoreTake(mutTimestamp, (TickType_t) 10) == pdTRUE) {
				timestamp++;
				xSemaphoreGive(mutTimestamp);
			}
		}else {
			// TODO - Error (Must be handled)
		}
	}
}
