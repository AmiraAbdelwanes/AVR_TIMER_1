#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include "DIO_register.h"
#include "DIO_interface.h"
/***********************TIM_2*****************/
#include "TIMER1_reg.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"



void main ()
{
	DIO_enumSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN4, DIO_U8_OUTPUT); //OC1B
	DIO_enumSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN5, DIO_U8_OUTPUT); //OC1A

	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN5 , DIO_U8_OUTPUT);//Main_LED Indicator


	//ENABLE GIF
	SET_BIT(SREG,7);
	TIMER1_enuInit();
	TIMER1_enuDisableOCBInt();
	TIMER1_enuEnableOCAInt();//OC1A
	TIMER1_enuSetTimerReg(0);
    TIMER1_enuSetCompareChannelA(127);

	while (1)
	{
		DIO_enumSetPinValue( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_HIGH  );
		_delay_ms(500);
		DIO_enumSetPinValue( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_LOW   );
		_delay_ms(500);
	}


}


