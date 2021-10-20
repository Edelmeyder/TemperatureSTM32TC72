#include "data_manager.h"

/* Private Functions */
int store(uint16_t value);
uint16_t comp2(uint16_t);

//static uint16_t therm_buffer[THERM_BUFFERSIZE];
static uint16_t aux;
static volatile int16_t tempe;

static volatile uint8_t printable[] = {'+','0','0','0',',','0','0'};

/*int store(uint16_t value)
{
		therm_buffer[therm_pointer++] = value;
		therm_pointer = therm_pointer % THERM_BUFFERSIZE;
	return 0;
}*/

/*float get_printable()
{
    float average = 0;
	  int i;
	
    for(i = 0 ; i < THERM_BUFFERSIZE ; i++ ){
        average+=therm_buffer[i];
    }
		//average*=THERM_INVERSE;
		average=average/50.0f;
    return average;
}*/

/* Public Functions */

int DATAMANAGER_Init() {
    tempe = 0;
    return 0;
}

int DATAMANAGER_Read() {
    aux = SENSOR_GetTemperature();
	if (aux > 0x0200)
		tempe = tempe - comp2(aux);
	else
		tempe = tempe + aux;
	DATAMANAGER_Write();
    return 0;
}

int DATAMANAGER_Write() {
	volatile uint16_t centi, deci, uni, dece, cente;
	if (tempe < 0) {
		printable[0] = '-';
		tempe = tempe * (-1);
	} else
		printable[0] = '+';
	//tempe = tempe/20;
	tempe = tempe * 25; // tempe *= 25;
	centi = (tempe - 10*(tempe/10)); // === tempe % 10
	tempe = tempe / 10;
	deci = (tempe - 10*(tempe/10));
	tempe = tempe / 10;
	uni = (tempe - 10*(tempe/10));
	tempe = tempe / 10;
	dece = (tempe - 10*(tempe/10));
	tempe = tempe / 10;
	cente = (tempe - 10*(tempe/10));
	tempe = 0;
	printable[6] = centi + 48;
	printable[5] = deci + 48;
	printable[3] = uni + 48;
	printable[2] = dece + 48;
	printable[1] = cente + 48;
	LCD_sendString(printable, 7);
	LCD_goToXY(0,0);
    return 0;
}

uint16_t comp2(uint16_t n){
	return (~n & 0x01FF) + 1;
}
