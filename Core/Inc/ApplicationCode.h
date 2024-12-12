/*
 * ApplicationCode.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Xavion
 */

#include "LCD_Driver.h"
#include "stm32f4xx_hal.h"
#include "Scheduler.h"
#include "stmpe811.h"
#include <stdio.h>


#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

void ApplicationInit(void);
void LCD_Visual_Demo(void);

void RunDemoForLCD(void);
void testLCD();
//void lvl1();

void delayLED(uint32_t);

// * BUTTON INIT:

// "an application level button init function"
void app_button_init();
void executeButtonPollingRoutine();
#define USE_INTERRUPT_FOR_BUTTON 1
void app_button_interrupt_init();

void app_run_game();

void app_reactiontime();

bool app_getpressed(bool pressed);

void EXTI0_IRQHandler();

#if (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)
void LCD_Touch_Polling_Demo(void);
#endif // (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)

#endif /* INC_APPLICATIONCODE_H_ */
