/*
 * menu.h
 *
 *  Created on: 10.12.2018
 *      Author: Mateusz Gutowski
 */

#ifndef MENU_H_
#define MENU_H_

#include "main.h"
#include "stm32f1xx_hal.h"
#include "hd44780.h"




void zeroTimer(void);
void actualize_LCD(void);
void pauseTimer(void);
void runTimer(void);
#endif /* MENU_H_ */
