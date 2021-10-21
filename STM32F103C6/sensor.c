#include "sensor.h"

// Funciones privadas
uint16_t SENSOR_Transfer(uint16_t);
void delay_conversion(void);

int SENSOR_Init(void) {
	RCC->APB2ENR |= (1<<12) | (1<<2);  //Activa el clock del SPI1 y del puerto io A
	GPIOA->CRL = (GPIOA->CRL |  0xB4B30000) & (0xB4B3FFFF); 
	// pin7 - MOSI Salida de función alternativa; pin6 - MISO Entrada de alta impedancia; pin5 - Clock Salida de función alternativa; pin4 - Slave select Salida de propósito general
	GPIOA->BRR = (1<<4); //ASegura el esclavo desactivado
	SPI1->CR1 = 0xB75;
	/*Activa el SPI1, modo master, baud-rate 1,125M, transferencia de 16 bits, polaridad de Clock baja y 
	muestreo en flancos pares */
	return 0;
}

uint16_t SENSOR_GetTemperature(void) {
	uint16_t temp = 0;
	GPIOA->BSRR = (1<<4); //Activa el esclavo
	SENSOR_Transfer(0x8011); //Activa el sensor en one-shot
	GPIOA->BRR = (1<<4); //Desactiva el esclavo
	delay_conversion(); 
	GPIOA->BSRR = (1<<4); 
	temp = (SENSOR_Transfer(0x0200)<<2) & 0x03FF;
	temp |= (SENSOR_Transfer(0x0000)>>14);
	/* Lee la temperatura del sensor en dos parates almacenando los 10 bits
	en una variable de 16 bits alineado a la derecha */
	GPIOA->BRR = (1<<4);
	return temp;
}

uint16_t SENSOR_Transfer(uint16_t cmd) {
      SPI1->DR = cmd; // Envía el comando
      while((SPI1->SR&(1<<0)) == 0); // Espera a que termine la comunicación (RXNE en alto)
      return SPI1->DR; // Retorna el dato recibido
}

void delay_conversion(void) {
	/* Demora 160 ms. 
	La medición del sensor toma 150 ms así que se espera 
	un poco más para asegurarse de que terminó*/
	uint16_t l, i;
	for(i = 0; i < 160; i++)
	for(l = 0; l < 12000; l++){}
}
