/*
 * GPIO_module.h
 *
 *  Created on: Apr 24, 2018
 *      Author: Vlad
 */
#include "types.h"
#ifndef GPIO_MODULE_H_
#define GPIO_MODULE_H_

extern void GPIO_init(void);
extern void GPIO_set_portB_pin_mode(uint8 pin,uint8 mode);
extern void GPIO_set_portB_pinValue(uint8 pin,uint8 value);
extern void GPIO_set_portB_pinGroup(uint8 value, uint8 bit_lenght,uint8 bit_poz);
extern int  GPIO_get_portB_value(uint8 pin);
#endif /* GPIO_MODULE_H_ */
