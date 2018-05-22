/*
 * Buttons.c
 *
 *  Created on: May 22, 2018
 *      Author: Vlad
 */

#include "PORT_CONFIG.h"
#include "Buttons.h"
#include "GPIO_module.h"

static SwitchesState myButtons;
static ConfigButtons ButtonsCfg;
void Buttons_init(SwitchesState myButtons)
{
	myButtons.button1 = (ButtonState) OFF;
	myButtons.button2 = (ButtonState) OFF;
	myButtons.button3 = (ButtonState) OFF;
	myButtons.button4 = (ButtonState) OFF;
}
void Buttons_set_portB(ConfigButtons ButtonsCfg)
{
	GPIO_set_portB_pin_mode(ButtonsCfg.b1.pin,ButtonsCfg.b1.mode);
	GPIO_set_portB_pinValue(ButtonsCfg.b1.pin,0);
	GPIO_set_portB_pin_mode(ButtonsCfg.b2.pin,ButtonsCfg.b2.mode);
	GPIO_set_portB_pinValue(ButtonsCfg.b2.pin,0);
	GPIO_set_portB_pin_mode(ButtonsCfg.b3.pin,ButtonsCfg.b3.mode);
	GPIO_set_portB_pinValue(ButtonsCfg.b3.pin,0);
	GPIO_set_portB_pin_mode(ButtonsCfg.b4.pin,ButtonsCfg.b4.mode);
	GPIO_set_portB_pinValue(ButtonsCfg.b4.pin,0);
}
SwitchesState Buttons_get_portB(ConfigButtons cfg)
{
	SwitchesState stare;
	if(GPIO_get_portB_value(cfg.b1.pin)==0)
	{
		stare.button1=ON;
	}
	else stare.button1=OFF;
	if(GPIO_get_portB_value(cfg.b2.pin))
	{
		stare.button2=ON;
	}
	else stare.button2=OFF;
	if(GPIO_get_portB_value(cfg.b3.pin))
	{
		stare.button3=ON;
	}
	else stare.button3=OFF;
	if(GPIO_get_portB_value(cfg.b4.pin))
	{
		stare.button4=ON;
	}
	else stare.button4=OFF;

return stare;


}
