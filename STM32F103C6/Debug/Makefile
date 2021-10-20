###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = STM32F103C6
COMPILER = "Keil for ARM"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
ASMFLAGS=--cpu=cortex-m3 --thumb -g
CCFLAGS=--cpu=cortex-m3 --thumb -I.. -I../../../../../../../../Keil_v5/ARM/CMSIS/Include -g
LDFLAGS=--scatter ../stm32f103x6.sct

## Processing Tools
CC=armcc.exe
LD=armlink.exe
ASM=armasm.exe
BIN2HEX=fromelf.exe
#  C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/Debug.elf: TOOL=LD
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/main.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/main.c
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/SYSTEM~1.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/system_stm32f1xx.c
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/STARTU~1.o: TOOL=ASM
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/startup_stm32f103.s
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/DATA_M~1.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/data_manager.c
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/lcd.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/lcd.c
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/sensor.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/sensor.c
#     C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/Debug/seos.o: TOOL=CC
#        C:/Users/Edelmiro/Desktop/Taller de proyecto I/Proyectos/TP2-Simulación/STM32F103C6/seos.c

# Build tree:
all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o SYSTEM~1.o STARTU~1.o DATA_M~1.o lcd.o sensor.o seos.o 
	$(LD)  $(LDFLAGS)  "main.o" "SYSTEM~1.o" "STARTU~1.o" "DATA_M~1.o" "lcd.o" "sensor.o" "seos.o" --output "Debug.elf"

main.o:	../main.c 
	$(CC) $(CCFLAGS)  "../main.c" -c -o "main.o"

SYSTEM~1.o:	../system_stm32f1xx.c 
	$(CC) $(CCFLAGS)  "../system_stm32f1xx.c" -c -o "SYSTEM~1.o"

STARTU~1.o:	../startup_stm32f103.s 
	$(ASM) $(ASMFLAGS)  "../startup_stm32f103.s" -o "STARTU~1.o"

DATA_M~1.o:	../data_manager.c 
	$(CC) $(CCFLAGS)  "../data_manager.c" -c -o "DATA_M~1.o"

lcd.o:	../lcd.c 
	$(CC) $(CCFLAGS)  "../lcd.c" -c -o "lcd.o"

sensor.o:	../sensor.c 
	$(CC) $(CCFLAGS)  "../sensor.c" -c -o "sensor.o"

seos.o:	../seos.c 
	$(CC) $(CCFLAGS)  "../seos.c" -c -o "seos.o"

# tidy - delete all temporary files which are not involved in the target generation
tidy:

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf SYSTEM~1.o
	rm -rf STARTU~1.o
	rm -rf DATA_M~1.o
	rm -rf lcd.o
	rm -rf sensor.o
	rm -rf seos.o
