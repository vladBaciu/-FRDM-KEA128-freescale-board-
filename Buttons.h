/*
 * Buttons.h
 *
 *  Created on: May 22, 2018
 *      Author: Vlad
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_




typedef enum
{
	IN=0,
	OUT=1,

}ButtonMode;

typedef enum
{
	ON=0,
	OFF=1,

}ButtonState;

typedef struct
{
	int pin;
	ButtonMode mode;

}ConfigButton;

typedef struct
{
	ConfigButton b1;
	ConfigButton b2;
	ConfigButton b3;
	ConfigButton b4;
}ConfigButtons;

typedef struct
{
	ButtonState button1;
	ButtonState button2;
	ButtonState button3;
	ButtonState button4;

}SwitchesState;


void Buttons_init(ButtonsState);
void Buttons_set_portB(ConfigButtons);
SwitchesState Buttons_get_portB(ConfigButtons);


#endif /* BUTTONS_H_ */
