/*
 * switch_control.c
 *
 *  Created on: Sep 1, 2021
 *      Author: RND-New002
 */

#include "switch_control.h"
#include "gpio.h"
//#include "sh1106.h"
#include "user_timer.h"

uint8_t sw_pause = 0;
uint8_t sw_on = 0;
uint8_t sw_off = 0;

uint8_t sw_init_flag = 0;

uint8_t sw_On_flag = 0;    // switch 1
uint8_t sw_Off_flag = 0;   // switch 2
uint8_t sw_Pause_flag = 0; // switch 3

uint8_t sw_On_packet_flag = 0;    // switch 1
uint8_t sw_Off_packet_flag = 0;   // switch 2
uint8_t sw_Pause_packet_flag = 0; // switch 3


uint8_t sw_1_packet_flag = 0; // switch 3
uint8_t sw_2_packet_flag = 0; // switch 3
uint8_t sw_3_packet_flag = 0; // switch 3
uint8_t sw_4_packet_flag = 0; // switch 3
uint8_t sw_5_packet_flag = 0; // switch 3
uint8_t sw_6_packet_flag = 0; // switch 3

extern uint8_t serial1Rx_data;

void Switch_Init(void)
{
	LSW2_TRIGGER_SET;
	LSW4_TRIGGER_SET;
	LSW6_TRIGGER_SET;

//	sh1106_print("Init...", Font_11x18, White);

	UserTimer_Start(SW_INIT_100ms, 130);
}

void Switch_Task(void)
{
	if ( sw_init_flag ) {

		if( (UserTimer_Status(SW1_100ms) == TMR_TIMEOUT) && (sw_On_flag == 1) ) {
			sw_On_flag = 0;
			sw_pause = 0;

			LSW1_TRIGGER_RESET;
			LSW3_TRIGGER_RESET;
			LSW5_TRIGGER_RESET;

//			sh1106_print("            ", Font_11x18, White);
//			sh1106_print("Mode ON OK", Font_11x18, White);
		}

		else if( (UserTimer_Status(SW2_100ms) == TMR_TIMEOUT) && (sw_Off_flag == 1) ) {

			sw_Off_flag = 0;
			sw_pause = 0;

			LSW2_TRIGGER_RESET;
			LSW4_TRIGGER_RESET;
			LSW6_TRIGGER_RESET;

//			sh1106_print("            ", Font_11x18, White);
//			sh1106_print("Mode OFF OK", Font_11x18, White);
		}
		else if ( (UserTimer_Status(SW_PAUSE_10ms) == TMR_TIMEOUT) && (sw_Pause_flag ==1) ) {

			if ( sw_pause )
				sw_pause = 0;
			else
				sw_pause = 1;

			if (sw_pause == 0) {

				if ( sw_On_flag ) {
					UserTimer_Resume(SW1_100ms);

					LSW1_TRIGGER_SET;
					LSW3_TRIGGER_SET;
					LSW5_TRIGGER_SET;
				}
				else if ( sw_Off_flag ) {
					UserTimer_Resume(SW2_100ms);

					LSW2_TRIGGER_SET;
					LSW4_TRIGGER_SET;
					LSW6_TRIGGER_SET;
				}

//				sh1106_print("            ", Font_11x18, White);
//				sh1106_print("Pause OFF", Font_11x18, White);
			}
			else if ( sw_pause ) {
				if ( sw_On_flag ) {
					UserTimer_Pause(SW1_100ms);

					LSW1_TRIGGER_RESET;
					LSW3_TRIGGER_RESET;
					LSW5_TRIGGER_RESET;


				}
				else if ( sw_Off_flag ) {
					UserTimer_Pause(SW2_100ms);

					LSW2_TRIGGER_RESET;
					LSW4_TRIGGER_RESET;
					LSW6_TRIGGER_RESET;
				}
				else ;

//				sh1106_print("            ", Font_11x18, White);
//				sh1106_print("Pause ON", Font_11x18, White);
			}
			sw_Pause_flag = 0;
		}
	}

	// Init Timer is time out
	else if ( sw_init_flag == 0 ){
		if ( UserTimer_Status(SW_INIT_100ms) == TMR_TIMEOUT ) {

			sw_init_flag = 1;

			LSW2_TRIGGER_RESET;
			LSW4_TRIGGER_RESET;
			LSW6_TRIGGER_RESET;

//			sh1106_print("Init Finish", Font_11x18, White);
		}
	}
	else ;
}
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(sw_init_flag) {
		// Chair gravity
//		if( (GPIO_Pin == GPIO_PIN_10) && (sw_On_flag == 0) && (sw_pause == 0) && (sw_Off_flag == 0)  ) {
//			sw_On_flag = 1;
//
//			LSW1_TRIGGER_SET;
//			LSW3_TRIGGER_SET;
//			LSW5_TRIGGER_SET;
//			UserTimer_Start(SW1_100ms, 130);
//
//		}
//
//		// Chair restore
//		else if( (GPIO_Pin == GPIO_PIN_11) && (sw_Off_flag == 0) && (sw_pause == 0) && (sw_On_flag == 0) ) {
//			sw_Off_flag = 1;
//
//			LSW2_TRIGGER_SET;
//			LSW4_TRIGGER_SET;
//			LSW6_TRIGGER_SET;
//
//			UserTimer_Start(SW2_100ms, 130);
//
//		}

//		else if ( (GPIO_Pin == GPIO_PIN_12) && (sw_Pause_flag == 0) && !(UserTimer_Status(SW_PAUSE_10ms) == TMR_RUN) ) {
//
//			cnt3++;
//
//			if(3 <= cnt3) {
//				UserTimer_Start(SW_PAUSE_10ms, 50);
//				sw_Pause_flag = 1;
//				cnt3 = 0;
//			}
//
//
//			//UserTimer_Start(SW_PAUSE_10ms, 100);
//		}
	}
}

int bt1_cnt = 0;
int bt2_cnt = 0;
int bt3_cnt = 0;
int bt4_cnt = 0;
int bt5_cnt = 0;
int bt6_cnt = 0;

void Bluetooth_Process(void)
{
	if(sw_init_flag) {
		// Chair gravity
		if( (serial1Rx_data == 0x31) && (sw_On_packet_flag == 1) && (sw_pause == 0) && (sw_Off_flag == 0) ) {
			sw_On_flag = 1;
			sw_On_packet_flag = 0;

			LSW1_TRIGGER_SET;
			LSW3_TRIGGER_SET;
			LSW5_TRIGGER_SET;

			UserTimer_Start(SW1_100ms, 130);

//			sh1106_print("            ", Font_11x18, White);
//			sh1106_print("Mode ON GO", Font_11x18, White);
		}

		// Chair restore
		else if( (serial1Rx_data == 0x32) && (sw_Off_packet_flag == 1) && (sw_pause == 0) && (sw_On_flag == 0) ) {
			sw_Off_flag = 1;
			sw_Off_packet_flag = 0;

			LSW2_TRIGGER_SET;
			LSW4_TRIGGER_SET;
			LSW6_TRIGGER_SET;

			UserTimer_Start(SW2_100ms, 130);

//			sh1106_print("            ", Font_11x18, White);
//			sh1106_print("Mode OFF GO", Font_11x18, White);
		}
#if 0
		else if ( (serial1Rx_data == 0x33) && (sw_Pause_flag == 0) && !(UserTimer_Status(SW_PAUSE_10ms) == TMR_RUN) ) {
//			sw_Pause_flag = 1;

			cnt3++;

			if(2 <= cnt3) {
				UserTimer_Start(SW_PAUSE_10ms, 50);
				sw_Pause_flag = 1;
				cnt3 = 0;
			}
#else
		else if ( (sw_Pause_packet_flag == 1) && !(UserTimer_Status(SW_PAUSE_10ms) == TMR_RUN) ) {
			sw_Pause_packet_flag = 0;
			sw_Pause_flag = 1;
			UserTimer_Start(SW_PAUSE_10ms, 50);
#endif
		}

		if ( sw_1_packet_flag  ) {

			sw_1_packet_flag = 0;

			if( bt1_cnt ) {
				bt1_cnt = 0;
				LSW1_TRIGGER_RESET;
//				sh1106_print("Btn 1 Off", Font_11x18, White);
			}
			else {
				bt1_cnt = 1;
				LSW1_TRIGGER_SET;
//				sh1106_print("Btn 1 On ", Font_11x18, White);
			}
		}
		else if ( sw_2_packet_flag  ) {

			sw_2_packet_flag = 0;

			if( bt2_cnt ) {
				bt2_cnt = 0;
				LSW2_TRIGGER_RESET;
//				sh1106_print("Btn 2 Off", Font_11x18, White);
			}
			else {
				bt2_cnt = 1;
				LSW2_TRIGGER_SET;
//				sh1106_print("Btn 2 On ", Font_11x18, White);
			}
		}
		else if ( sw_3_packet_flag ) {
			sw_3_packet_flag = 0;

			if( bt3_cnt ) {
				bt3_cnt = 0;
				LSW3_TRIGGER_RESET;
//				sh1106_print("Btn 3 Off", Font_11x18, White);
			}
			else {
				bt3_cnt = 1;
				LSW3_TRIGGER_SET;
//				sh1106_print("Btn 3 On ", Font_11x18, White);
			}
		}
		else if ( sw_4_packet_flag ) {
			sw_4_packet_flag = 0;
			if( bt4_cnt ) {
				bt4_cnt = 0;
				LSW4_TRIGGER_RESET;
//				sh1106_print("Btn 4 Off", Font_11x18, White);
			}
			else {
				bt4_cnt = 1;
				LSW4_TRIGGER_SET;
//				sh1106_print("Btn 4 On ", Font_11x18, White);
			}
		}
		else if ( sw_5_packet_flag ) {

			sw_5_packet_flag = 0;
			if( bt5_cnt ) {
				bt5_cnt = 0;
				LSW5_TRIGGER_RESET;

//				sh1106_print("Btn 5 Off", Font_11x18, White);
			}
			else {
				bt5_cnt = 1;
				LSW5_TRIGGER_SET;
//				sh1106_print("Btn 5 On ", Font_11x18, White);
			}
		}
		else if ( sw_6_packet_flag ) {

			sw_6_packet_flag = 0;

			if( bt6_cnt ) {
				bt6_cnt = 0;
				LSW6_TRIGGER_RESET;

//				sh1106_print("Btn 6 Off", Font_11x18, White);
			}
			else {
				bt6_cnt = 1;
				LSW6_TRIGGER_SET;
//				sh1106_print("Btn 6 On ", Font_11x18, White);
			}
		}
	}
}
