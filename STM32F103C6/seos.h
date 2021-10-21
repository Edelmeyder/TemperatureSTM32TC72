#ifndef _SEOS_H
#define _SEOS_H

#include <stm32f103x6.h>
#include <inttypes.h>
#include <stdio.h>


/* Overflow */
/* nro de tick del sistema en el que se debe ejecutar la tarea y reiniciar el contador */
#define OVERF_READ 5  //  0.5s
#define OVERF_WRITE 50  // 5 s

/* Out of Phase */
/* Configuracion para evitar que las tareas se deban ejecutar en el mismo tick del sistema */
/*#define OOPH_WRITE 499
#define OOPH_READ 1 */

/* Public Functions */
int SEOS_Boot(void);

int SEOS_Schedule(void);

int SEOS_Dispatch(void);

int SEOS_Sleep(void);


#endif
