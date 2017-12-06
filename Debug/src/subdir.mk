################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arbitro.cpp \
../src/Bandera.cpp \
../src/Casillero.cpp \
../src/Dibujante.cpp \
../src/Juego.cpp \
../src/Jugador.cpp \
../src/Presentador.cpp \
../src/Tablero.cpp \
../src/ppal.cpp 

OBJS += \
./src/Arbitro.o \
./src/Bandera.o \
./src/Casillero.o \
./src/Dibujante.o \
./src/Juego.o \
./src/Jugador.o \
./src/Presentador.o \
./src/Tablero.o \
./src/ppal.o 

CPP_DEPS += \
./src/Arbitro.d \
./src/Bandera.d \
./src/Casillero.d \
./src/Dibujante.d \
./src/Juego.d \
./src/Jugador.d \
./src/Presentador.d \
./src/Tablero.d \
./src/ppal.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


