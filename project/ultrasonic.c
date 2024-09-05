/*
 * ultrasonic.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Mostafa Amr
 */


#include "ultrasonic.h"
#include"icu.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include "gpio.h"
#include <util/delay.h>

Icu_ConfigType config={F_CPU_8,RISING};
static uint16 g_highTime=0;

void Ultrasonic_init(void)
{
	Icu_init(&config);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(triggerPort, triggerPin, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(triggerPort, triggerPin, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(triggerPort, triggerPin, LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void)
{
	static uint16 l_distance=0;
	Ultrasonic_Trigger();
	l_distance=(float32)g_highTime/58 +1;
	return l_distance;

}

void Ultrasonic_edgeProcessing(void)
{
	static uint8 l_edgeCount=0;
	l_edgeCount++;
	if(l_edgeCount==1)
	{
		Icu_clearTimerValue();

		Icu_setEdgeDetectionType(FALLING);

	}
	if(l_edgeCount==2)
	{
		g_highTime=Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(RISING);
		l_edgeCount=0;
	}
}
