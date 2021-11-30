/*
 * terminal.h
 *
 *  Created on: Nov 2, 2021
 *      Author: RND-New002
 */

#ifndef INC_TERMINAL_H_
#define INC_TERMINAL_H_


#include <stdio.h>
#include "usart.h"
#include "serial3.h"

void Terminal_Task();
u8 Terminal_GetData (u8 data);
s32 Terminal_ReadBuff (u8 *buff, s32 size);
s32 Tokenize (s8 *str, s8 token[4][16]);

#endif /* INC_TERMINAL_H_ */
