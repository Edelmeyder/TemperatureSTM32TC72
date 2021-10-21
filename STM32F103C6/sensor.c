#include "sensor.h"

uint16_t SENSOR_Transfer(uint16_t);
void delay_conversion(void);

int SENSOR_Init(void) {
      RCC->APB2ENR |= (1<<12) | (1<<2);  //enable SPI1 and io port A clocks
      GPIOA->CRL = (GPIOA->CRL |  0xB4B30000) & (0xB4B3FFFF); 
      // pin7 - MOSI Alternate function output; pin6 - MISO Floating input; pin5 - Clock Alternate function output; pin4 - Slave select GP output
     GPIOA->BRR = (1<<4);  //disable slave
	SPI1->CR1 = 0xB75;
     // SPI1->CR1 = 0b0000101101110101; //((1<<6) | (1<<2) | (1<<8) | (1<<9) | (0b110<<3));
      //Enable SPI1, master mode, baud rate = 1,125M 
      
	return 0;
}

uint16_t SENSOR_GetTemperature(void) {
   uint16_t temp = 0;
   GPIOA->BSRR = (1<<4); //enable slave
   SENSOR_Transfer(0x8011); //activate one temperature conversion on the sensor
	GPIOA->BRR = (1<<4);
   delay_conversion(); 
	GPIOA->BSRR = (1<<4); 
   temp = (SENSOR_Transfer(0x0200)<<2) & 0x03FF;
   temp |= (SENSOR_Transfer(0x0000)>>14);
   GPIOA->BRR = (1<<4);
   return temp;
}

uint16_t SENSOR_Transfer(uint16_t cmd) {
      SPI1->DR = cmd; /* send the command */
      while((SPI1->SR&(1<<0)) == 0); /* wait until RXNE is set */
      return SPI1->DR; /* return the received data */
}

void delay_conversion(void) {
   uint16_t l, i;
   for(i = 0; i < 200; i++)
	for(l = 0; l < 10000; l++){}
}
