################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arbitro.cpp \
../src/Casillero.cpp \
../src/Dibujante.cpp \
../src/Presentador.cpp \
../src/principal.cpp 

OBJS += \
./src/Arbitro.o \
./src/Casillero.o \
./src/Dibujante.o \
./src/Presentador.o \
./src/principal.o 

CPP_DEPS += \
./src/Arbitro.d \
./src/Casillero.d \
./src/Dibujante.d \
./src/Presentador.d \
./src/principal.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


