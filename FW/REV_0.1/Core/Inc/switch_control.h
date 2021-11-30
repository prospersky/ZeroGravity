/*
 * switch_control.h
 *
 *  Created on: Sep 1, 2021
 *      Author: RND-New002
 */

#ifndef INC_SWITCH_CONTROL_H_
#define INC_SWITCH_CONTROL_H_

enum {
	TRG_SET,
	TRG_RESET,
};

void Switch_Init(void);
void Switch_Task(void);
void Bluetooth_Process(void);
#endif /* INC_SWITCH_CONTROL_H_ */
