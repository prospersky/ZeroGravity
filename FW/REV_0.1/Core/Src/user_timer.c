/*
 * user_timer.c
 *
 *  Created on: Sep 6, 2021
 *      Author: RND-New002
 */

#include "user_timer.h"

#define USER_TIMER_FREQ                        1000        // 1ms

typedef struct {
	uint8_t status;
	uint32_t count;
	uint32_t value;
} USER_TIMER_EX;

USER_TIMER_EX user_timer_list[MAX_TMR];

void UserTimer_Handler(void)
{
	int i;

	for (i=0; i<MAX_TMR; i++) {
		if(user_timer_list[i].status == TMR_RUN) {
			user_timer_list[i].count++;

			if(user_timer_list[i].value <= user_timer_list[i].count) {
				user_timer_list[i].status = TMR_TIMEOUT;
			}
		}
	}
}

void UserTimer_Start(USER_TIMER_ID timer_type, uint16_t time_out)
{
	user_timer_list[timer_type].status = TMR_RUN;
	user_timer_list[timer_type].count = 0;

	if( ( START_10ms < timer_type ) && (timer_type<END_10ms) ) {
		user_timer_list[timer_type].value = (uint32_t) time_out * 10;
	}
	else if ( (START_100ms < timer_type ) && (timer_type < END_100ms) ) {
		user_timer_list[timer_type].value = (uint32_t) time_out * 100;
	}
	else {
		user_timer_list[timer_type].value = (uint32_t) time_out;
	}
}

void UserTimer_Stop(USER_TIMER_ID timer_type)
{
	user_timer_list[timer_type].status = TMR_STOP;
	user_timer_list[timer_type].count = 0;
}

void UserTimer_Pause(USER_TIMER_ID timer_type)
{
	user_timer_list[timer_type].status = TMR_PAUSE;
}

void UserTimer_Resume(USER_TIMER_ID timer_type)
{
	if(user_timer_list[timer_type].status == TMR_PAUSE) {
		user_timer_list[timer_type].status = TMR_RUN;
	}
}

uint8_t UserTimer_Status(USER_TIMER_ID timer_type)
{
	return user_timer_list[timer_type].status;
}

void UserTimer_Read(USER_TIMER_ID timer_type)
{
	uint32_t ret;

	if( ( START_10ms < timer_type ) && (timer_type<END_10ms) ) {
		ret = user_timer_list[timer_type].count / 10;
	}
	else if ( (START_100ms < timer_type ) && (timer_type < END_100ms) ) {
		ret = user_timer_list[timer_type].count / 100;
	}
	else {
		ret = user_timer_list[timer_type].count;
	}

//	return ret;
}

