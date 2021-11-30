/*
 * user_timer.h
 *
 *  Created on: Sep 6, 2021
 *      Author: RND-New002
 */

#ifndef INC_USER_TIMER_H_
#define INC_USER_TIMER_H_

#include "main.h"

typedef enum {
	START_1ms,
	COM_BT_1ms,
	COM_PC_1ms,
	END_1ms,
	START_10ms = END_1ms,
	SW_PAUSE_10ms,
	END_10ms,
	START_100ms = END_10ms,
	SW1_100ms,
	SW2_100ms,
	SW3_100ms,
	SW_INIT_100ms,
	END_100ms,
	MAX_TMR
}USER_TIMER_ID;

enum {
	TMR_STOP,
	TMR_RUN,
	TMR_TIMEOUT,
	TMR_PAUSE,
};

extern void UserTimer_Handler(void);
extern void UserTimer_Start(USER_TIMER_ID timer_type, uint16_t time_out);
extern void UserTimer_Stop(USER_TIMER_ID timer_type);
extern void UserTimer_Pause(USER_TIMER_ID timer_type);
extern void UserTimer_Resume(USER_TIMER_ID timer_type);
extern uint8_t UserTimer_Status(USER_TIMER_ID timer_type);
extern void UserTimer_Read(USER_TIMER_ID timer_type);

#endif /* INC_USER_TIMER_H_ */
