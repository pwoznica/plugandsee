################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/port.c 

OBJS += \
./FreeRTOS/Source/portable/port.o 

C_DEPS += \
./FreeRTOS/Source/portable/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/%.o: ../FreeRTOS/Source/portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I/home/jeremy/workspace/plug/FreeRTOS/Source/include -I/home/jeremy/workspace/plug -I/home/jeremy/workspace/plug/inc -I/home/jeremy/workspace/plug/FreeRTOS/Source/portable -I/home/jeremy/workspace/plug/Drivers/include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


