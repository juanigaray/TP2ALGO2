################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EasyBMP/EasyBMP.cpp 

OBJS += \
./src/EasyBMP/EasyBMP.o 

CPP_DEPS += \
./src/EasyBMP/EasyBMP.d 


# Each subdirectory must supply rules for building sources it contributes
src/EasyBMP/%.o: ../src/EasyBMP/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


