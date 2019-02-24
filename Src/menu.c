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
RTC_TimeTypeDef sTime_pause;
enum boolean timerPause = TRUE;


//uint8_t menu_position = 0;
//uint8_t menu_collection_position = 0;
//boolean menu(gpio_switch button)
//{
//	const char checked[4] = "[*]";
//	const char unchecked[4] = "[ ]";
//
//
//	switch (menu_collecttion_position)
//	{
//	case 0://MAIN MENU
//		lcd_print("START(16850)");
//		if(menu_position == 0)
//			lcd_print(checked);
//		else
//			lcd_print(unchecked);
//
//		lcd_write(SET_SECOND_LINE);
//		lcd_print("MANUAL CURRENT");
//		if(menu_position == 1)
//			lcd_print(checked);
//		else
//			lcd_print(unchecked);
//		break;
//	case 1: //MANUAL CONTROL
//
//		break;
//	}
//
//
//
//	if(button == SW1)//OK
//	{
//		switch (menu_collecttion_position)
//		{
//			case 0:
//				switch(menu_position)
//				{
//					case 0://start measure
//						break;
//					case 1://go to manual control
//						menu_collection_position = 1;
//						position = 0;
//						break;
//				}
//				break;
//			case 1:
//				switch(menu_position)
//				{
//					case 0://set
//						break;
//					case 1://increase
//						break;
//					case 2://decrease
//						break;
//				}
//				break;
//		}
//	}
//	else if(button == SW2)//NEXT
//	{
//
//	}
//}

void zeroTimer(void)
{
	sTime.Hours = 0;
	sTime.Minutes = 0;
	sTime.Seconds = 0;
	HAL_RTC_SetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
}
void pauseTimer(void)
{
	if(timerPause == FALSE)
	{
		timerPause = TRUE;
		sTime_pause = sTime;
	}
}
void runTimer()
{
	if(timerPause == TRUE)
	{
		timerPause = FALSE;
		HAL_RTC_SetTime(&hrtc,&sTime_pause,RTC_FORMAT_BIN);
	}
}


void actualize_LCD(void)
{
	//first line
	lcd_write(DISPLAY_CLEAR);
	lcd_print_int(battery_voltage);
	lcd_print("mV  ");
	lcd_print_int(shount_current);
	lcd_print("mA");




	//------second line
	lcd_write(SET_SECOND_LINE);

	if(timerPause == TRUE)
			sTime = sTime_pause;
	else
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
	lcd_print("mAh");


}

//uint16_t currentSetByBattery(void)
//{
//	char
//
//	lcd_write(DISPLAY_CLEAR);
//	lcd_write
//
//}
