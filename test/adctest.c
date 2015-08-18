
#include "LPC13Uxx.h"

#include "gpio.h"

#define PORT_TEST 1
#define PIN_TEST  16

int main(void) {

	SystemCoreClockUpdate();

	GPIOInit();
	GPIOSetDir(PORT_TEST, PIN_TEST, 1); // 1 means output
	GPIOSetBitValue(PORT_TEST, PIN_TEST, 0);

	for(;;);
}
