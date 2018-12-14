/*
 * menu.c
 *
 *  Created on: 10.12.2018
 *      Author: Mateusz Gutowski
 */
#include "menu.h"

extern RTC_HandleTypeDef hrtc;
extern uint16_t battery_voltage;
extern uint16_t shount_current;
extern double measured_energy;
RTC_TimeTypeDef sTime;

void zeroTimer(void)
{
	sTime.Hours = 0;
	sTime.Minutes = 0;
	sTime.Seconds = 0;
	HAL_RTC_SetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
}
void actualizeLCD(void)
{
	//first line
	lcd_write(DISPLAY_CLEAR);
	lcd_print_int(battery_voltage);
	lcd_print("mV  ");
	lcd_print_int(shount_current);
	lcd_print("mA");

	//------second line
	lcd_write(SET_SECOND_LINE);

	HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
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

	lcd_print_letter(' ');
	lcd_print_int((uint16_t)measured_energy);
	lcd_print("mWh");


}
