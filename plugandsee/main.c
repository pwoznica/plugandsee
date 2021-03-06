/*
 * Jeremy Delaporte, Piotr Woznica
 *
*/

// Kernel includes
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "initSystem.h"

#include "taskDataAcquisition.h"
#include "taskDataLogger.h"

#include "sendDataTask.h"
#include "commandsHandlerTask.h"
#include "updateTimestampTask.h"

#define DEBUG_MODE 1

// Global variables used by dataLoggerTask. Access to
// energyCounter and timestamp MUST be done using
// associated mutexes.
uint32_t energyCounter = 0;
static SemaphoreHandle_t mutEnergyCounter;

QueueHandle_t xQueueInput;
QueueHandle_t xQueueOutput;

int main(void)
{
	initSystemBasics();

	TaskHandle_t cHHandle = NULL;
	xTaskCreate(commandsHandlerTask, "commandsHandler", 100, NULL, COMMAND_HANDLER_TASK_PRIORITY, &cHHandle);

	TaskHandle_t dAHandle = NULL;
	xTaskCreate(dataAcquisitionTask, "dataAcquisition", 100, NULL, DATA_ACQUISITION_TASK_PRIORITY, &dAHandle);

	TaskHandle_t sDHandle = NULL;
	xTaskCreate(sendDataTask, "sendData", 100, NULL, SEND_DATA_TASK_PRIORITY, &sDHandle);

	TaskHandle_t dLHandle = NULL;
	xTaskCreate(dataLoggerTask, "dataLogger", 100, NULL, DATA_LOGGER_TASK_PRIORITY, &dLHandle);

	TaskHandle_t uTHandle = NULL;
	xTaskCreate(updateTimestampTask, "updateTimestamp", 100, NULL, UPDATE_TIMESTAMP_TASK_PRIORITY, &uTHandle);

	vTaskStartScheduler();
	for(;;);
}
