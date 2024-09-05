/*
 * ultrasonic.h
 *
 *  Created on: Oct 11, 2022
 *      Author: Mostafa Amr
 */
#include "std_types.h"

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define triggerPort PORTB_ID
#define triggerPin PIN5_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function to initialize the Ultrasonic driver
 */
void Ultrasonic_init(void);

/*
 *  Description : Function to trigger the Ultrasonic sensor
 */
void Ultrasonic_Trigger(void);

/*
 *  Description : Function to read the distance given from Ultrasonic sensor
 */
uint16 Ultrasonic_readDistance(void);

/*
 *  Description : Function to process the time till Ultrasonic reaches the target
 */
void Ultrasonic_edgeProcessing(void);




#endif /* ULTRASONIC_H_ */
