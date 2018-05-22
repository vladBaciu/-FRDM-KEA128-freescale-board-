/*
 * Joystick.h
 *
 *  Created on: May 15, 2018
 *      Author: Vlad
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_


#define x_axis_adc 0
#define y_axis_adc 1
#define push_button_adc 15

typedef enum
{
	X_axis_CENTER=0,
	X_axis_UP=1,
	X_axis_DOWN=2,

}xAxisState;
typedef enum
{
	Y_axis_CENTER=0,
	Y_axis_LEFT=1,
	Y_axis_RIGHT=2,

}yAxisState;
typedef enum
{
	PRESS=0,
	NOT_PRESS=1,
}pushButtonState;
typedef struct
{
	xAxisState  StareX;
	yAxisState  StareY;
	pushButtonState Button;

}buttonsState;
void JoyStick_init(void);
void JoyStick_read_channels();
buttonsState get_state();

#endif /* JOYSTICK_H_ */
