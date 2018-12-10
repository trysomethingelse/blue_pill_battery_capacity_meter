/*
 * menu.c
 *
 *  Created on: 10.12.2018
 *      Author: Mateusz Gutowski
 */
#include "menu.h"

extern RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;

void zeroTimer(void)
{
	sTime.Hours = 0;
	sTime.Minutes = 0;
	sTime.Seconds = 0;
	HAL_RTC_SetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
}
void actualizeTimeOnLCD(void)
{

	HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
	lcd_write(DISPLAY_CLEAR);
	uint8_t number = sTime.Hours;
	if (number < 10) lcd_print_letter('0');
	lcd_print_int(number);
	lcd_print_letter(':');
	number = sTime.Minutes;
	if(number < 10) lcd_print_letter('0');
	lcd_print_int(number);
	lcd_print_letter(':');
	number = sTime.Seconds;
	if(number < 10) lcd_print_letter('0');
	lcd_print_int(number);
}
