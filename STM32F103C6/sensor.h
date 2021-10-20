#ifndef _SENSOR_H
#define _SENSOR_H
          
#include <stdint.h>
#include <inttypes.h>
#include <stm32f103x6.h>

#include "lcd.h"
#include "sensor.h"


/* Public Functions */
int SENSOR_Init(void);
uint16_t SENSOR_GetTemperature(void);

#endif
