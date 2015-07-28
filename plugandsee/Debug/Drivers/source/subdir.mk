################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/source/debug_frmwrk.c \
../Drivers/source/lpc177x_8x_adc.c \
../Drivers/source/lpc177x_8x_can.c \
../Drivers/source/lpc177x_8x_clkpwr.c \
../Drivers/source/lpc177x_8x_crc.c \
../Drivers/source/lpc177x_8x_dac.c \
../Drivers/source/lpc177x_8x_eeprom.c \
../Drivers/source/lpc177x_8x_emc.c \
../Drivers/source/lpc177x_8x_exti.c \
../Drivers/source/lpc177x_8x_gpdma.c \
../Drivers/source/lpc177x_8x_gpio.c \
../Drivers/source/lpc177x_8x_i2c.c \
../Drivers/source/lpc177x_8x_i2s.c \
../Drivers/source/lpc177x_8x_mci.c \
../Drivers/source/lpc177x_8x_mcpwm.c \
../Drivers/source/lpc177x_8x_nvic.c \
../Drivers/source/lpc177x_8x_pinsel.c \
../Drivers/source/lpc177x_8x_pwm.c \
../Drivers/source/lpc177x_8x_qei.c \
../Drivers/source/lpc177x_8x_rtc.c \
../Drivers/source/lpc177x_8x_ssp.c \
../Drivers/source/lpc177x_8x_systick.c \
../Drivers/source/lpc177x_8x_timer.c \
../Drivers/source/lpc177x_8x_uart.c \
../Drivers/source/lpc177x_8x_wwdt.c 

OBJS += \
./Drivers/source/debug_frmwrk.o \
./Drivers/source/lpc177x_8x_adc.o \
./Drivers/source/lpc177x_8x_can.o \
./Drivers/source/lpc177x_8x_clkpwr.o \
./Drivers/source/lpc177x_8x_crc.o \
./Drivers/source/lpc177x_8x_dac.o \
./Drivers/source/lpc177x_8x_eeprom.o \
./Drivers/source/lpc177x_8x_emc.o \
./Drivers/source/lpc177x_8x_exti.o \
./Drivers/source/lpc177x_8x_gpdma.o \
./Drivers/source/lpc177x_8x_gpio.o \
./Drivers/source/lpc177x_8x_i2c.o \
./Drivers/source/lpc177x_8x_i2s.o \
./Drivers/source/lpc177x_8x_mci.o \
./Drivers/source/lpc177x_8x_mcpwm.o \
./Drivers/source/lpc177x_8x_nvic.o \
./Drivers/source/lpc177x_8x_pinsel.o \
./Drivers/source/lpc177x_8x_pwm.o \
./Drivers/source/lpc177x_8x_qei.o \
./Drivers/source/lpc177x_8x_rtc.o \
./Drivers/source/lpc177x_8x_ssp.o \
./Drivers/source/lpc177x_8x_systick.o \
./Drivers/source/lpc177x_8x_timer.o \
./Drivers/source/lpc177x_8x_uart.o \
./Drivers/source/lpc177x_8x_wwdt.o 

C_DEPS += \
./Drivers/source/debug_frmwrk.d \
./Drivers/source/lpc177x_8x_adc.d \
./Drivers/source/lpc177x_8x_can.d \
./Drivers/source/lpc177x_8x_clkpwr.d \
./Drivers/source/lpc177x_8x_crc.d \
./Drivers/source/lpc177x_8x_dac.d \
./Drivers/source/lpc177x_8x_eeprom.d \
./Drivers/source/lpc177x_8x_emc.d \
./Drivers/source/lpc177x_8x_exti.d \
./Drivers/source/lpc177x_8x_gpdma.d \
./Drivers/source/lpc177x_8x_gpio.d \
./Drivers/source/lpc177x_8x_i2c.d \
./Drivers/source/lpc177x_8x_i2s.d \
./Drivers/source/lpc177x_8x_mci.d \
./Drivers/source/lpc177x_8x_mcpwm.d \
./Drivers/source/lpc177x_8x_nvic.d \
./Drivers/source/lpc177x_8x_pinsel.d \
./Drivers/source/lpc177x_8x_pwm.d \
./Drivers/source/lpc177x_8x_qei.d \
./Drivers/source/lpc177x_8x_rtc.d \
./Drivers/source/lpc177x_8x_ssp.d \
./Drivers/source/lpc177x_8x_systick.d \
./Drivers/source/lpc177x_8x_timer.d \
./Drivers/source/lpc177x_8x_uart.d \
./Drivers/source/lpc177x_8x_wwdt.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/source/%.o: ../Drivers/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I/home/jeremy/workspace/plug/FreeRTOS/Source/include -I/home/jeremy/workspace/plug -I/home/jeremy/workspace/plug/inc -I/home/jeremy/workspace/plug/FreeRTOS/Source/portable -I/home/jeremy/workspace/plug/Drivers/include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


