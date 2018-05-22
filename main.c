

 /* main.c              (c) 2015 Freescale Semiconductor, Inc.
 * Descriptions: ADC functions for conversion example
 * 28 Sept 2015 Pedro Aguayo: Initial version
 * 16 Dec 2015 S Mihalik, O Romero: Modified code
 */

#include "derivative.h"
//#include "ADC.h"
#include "LDrvAdc.h"
#include "clocks.h"
#include "lcd1602a.h"
#include "GPIO_module.h"
#include "types.h";
#include "UART.h"
#include "Joystick.h"
#include "Buttons.h"
uint16_t adcResultCh0 = 0;
uint16_t adcResultCh1 = 0;
uint16_t adcResultCh15 = 0;

buttonsState myJoystickCfg;
static buttonsState lastValue;

static SwitchesState mySwitches;
static ConfigButtons Switches;
void init_main();
void init_clk();
void tx_position(buttonsState cfg);



int main(void){



  int counter = 0;
  int j;
  init_main();
  init_clks_FEE_40MHz();        					/* KEA128 8MHz xtal: core 40 MHz, bus 20MHz */
  Adc_Init();

  tAdcCfg * myCfg = Adc_GetCfgHandle();
  myCfg->AdcOpMode=ADC_OPMODE_SINGLESHOT ;
  myCfg->AdcResolution = ADC_RES_10_BIT;
  Adc_ConfigAcquisition(myCfg);
  UART_init();
  JoyStick_init();
  Buttons_init(Switches);


  //X axis - ch 0; Y_axis - ch 1; Push_button - ch 15
  for(;;)
  {
	  myJoystickCfg=get_state(); // citire joystick
	  tx_position(myJoystickCfg); // transmitere pe seriala pozitie joystick





  }
}
void init_main()
{
	 lastValue.Button=(pushButtonState)NOT_PRESS;
	 lastValue.StareX=(xAxisState) X_axis_CENTER;
	 lastValue.StareY= (yAxisState) Y_axis_CENTER;

}
void tx_position(buttonsState cfg)
{
	/////////***************************************BUTON***********************///////////////////
	if(cfg.Button==(pushButtonState)PRESS &&  lastValue.Button != (pushButtonState)PRESS)
	{
		UART_string("buton_apasat");
        lastValue.Button=(pushButtonState) PRESS;
	}
	else if(cfg.Button==(pushButtonState) NOT_PRESS)
	{

		lastValue.Button=(pushButtonState) NOT_PRESS;
	}

	/////////***************************************BUTON***********************///////////////////



	/////////***************************************AXA X***********************///////////////////
	if(cfg.StareX==(xAxisState) X_axis_UP && lastValue.StareX!=(xAxisState) X_axis_UP)
	{

		UART_string("UP");
		lastValue.StareX=(xAxisState) X_axis_UP;
	}
	else if(cfg.StareX==(xAxisState) X_axis_DOWN & lastValue.StareX!=(xAxisState) X_axis_DOWN)
	{
			UART_string("DOWN");
			lastValue.StareX=(xAxisState) X_axis_DOWN;

	}
	else if (cfg.StareX==(xAxisState) X_axis_CENTER)
	{
		lastValue.StareX=(xAxisState) X_axis_CENTER;

	}
	/////////***************************************AXA X***********************///////////////////


	/////////***************************************AXA Y***********************///////////////////
	if(cfg.StareY==(yAxisState) Y_axis_LEFT && lastValue.StareY!=(yAxisState) Y_axis_LEFT)
	{
				UART_string("LEFT");
				lastValue.StareY= (yAxisState) Y_axis_LEFT;

	}
	else if(cfg.StareY==(xAxisState) Y_axis_RIGHT && lastValue.StareY!=(yAxisState) Y_axis_RIGHT)
	{
				UART_string("RIGHT");
				lastValue.StareY= (yAxisState) Y_axis_RIGHT;

	}
	else if ( cfg.StareY==(xAxisState) Y_axis_CENTER)
	{
		lastValue.StareY= (yAxisState) Y_axis_CENTER;

	}
	/////////***************************************AXA Y***********************///////////////////
}
void init_clk()
{
	ICS_C1|=ICS_C1_IRCLKEN_MASK; 		/* Enable the internal reference clock*/
	ICS_C3= 0x90;						        /* Reference clock frequency = 31.25 KHz*/
	while(!(ICS_S & ICS_S_LOCK_MASK)); /* Wait for PLL lock, now running at 40 MHz (1280 * 31.25Khz) */
    ICS_C2|=ICS_C2_BDIV(2)  ; 			/*div by 2*/
	ICS_S |= ICS_S_LOCK_MASK ; 			/* Clear Loss of lock sticky bit */
}


