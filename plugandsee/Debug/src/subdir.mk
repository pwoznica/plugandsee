################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/commandsHandlerTask.c \
../src/core_cm3.c \
../src/initSystem.c \
../src/sendDataTask.c \
../src/system_LPC177x_8x.c \
../src/taskDataAcquisition.c \
../src/taskDataLogger.c \
../src/updateTimestampTask.c 

OBJS += \
./src/commandsHandlerTask.o \
./src/core_cm3.o \
./src/initSystem.o \
./src/sendDataTask.o \
./src/system_LPC177x_8x.o \
./src/taskDataAcquisition.o \
./src/taskDataLogger.o \
./src/updateTimestampTask.o 

C_DEPS += \
./src/commandsHandlerTask.d \
./src/core_cm3.d \
./src/initSystem.d \
./src/sendDataTask.d \
./src/system_LPC177x_8x.d \
./src/taskDataAcquisition.d \
./src/taskDataLogger.d \
./src/updateTimestampTask.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I/home/jeremy/workspace/plug/FreeRTOS/Source/include -I/home/jeremy/workspace/plug -I/home/jeremy/workspace/plug/inc -I/home/jeremy/workspace/plug/FreeRTOS/Source/portable -I/home/jeremy/workspace/plug/Drivers/include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


