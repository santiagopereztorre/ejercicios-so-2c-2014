################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/01-manejoDeListas.c \
../src/02-manejoDeEstructuras.c 

OBJS += \
./src/01-manejoDeListas.o \
./src/02-manejoDeEstructuras.o 

C_DEPS += \
./src/01-manejoDeListas.d \
./src/02-manejoDeEstructuras.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/workspace/commons" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


