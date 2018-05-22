/*
 * GPIO_module.c
 *
 *  Created on: Apr 24, 2018
 *      Author: Vlad
 */
#include "types.h"
#include "GPIO_module.h"
#include "derivative.h"
#define PIN_MODE_IN  0
#define PIN_MODE_OUT 1

void GPIO_init()
{

}
int GPIO_get_portB_value(uint8 pin)
{
		return GPIOB_PDIR & (1<<pin);
}
void GPIO_set_portB_pin_mode(uint8 pin,uint8 mode)
{
	if (pin>7)
		return;
	if(mode==PIN_MODE_IN)   //sterge biti
	{
		GPIOA_PDDR &= ~(1u << (pin +8));  //mascare pt stergere
		GPIOA_PIDR &= ~(1u << (pin +8));
	}
	else
	{
		GPIOA_PDDR |= (1u << (pin +8));
		GPIOA_PIDR |= (1u << (pin +8));
	}
}
void GPIO_set_portB_pinValue(uint8 pin ,uint8 value)
{
	if (pin>7)
			return;

	if(value==0)
		GPIOA_PCOR =  (1u << (pin +8));
	else
		GPIOA_PSOR =  (1u << (pin +8));
}
void GPIO_set_portB_pinGroup(uint8 value, uint8 bit_lenght,uint8 bit_poz)
{
	volatile uint32 tempreg;
	uint32 i,mask=0;																					//modificare valoare intr-o variablia si apoi incarcarea in port
	tempreg =GPIOA_PDOR;																// lucrul direct cu porturile poate duce la stari intermediare nedorite
	for(i=0;i<bit_lenght;i++)
	{
		mask |= (1u << i);             //masca de marimea bit lenght
	}
	mask= (mask << (bit_poz + 8 ));
	tempreg &= ~mask;

	tempreg |= value<<(bit_poz +8);

	GPIOA_PDOR = tempreg;
}
