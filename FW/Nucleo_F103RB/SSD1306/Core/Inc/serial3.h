/*
 * serial3.h
 *
 *  Created on: Nov 2, 2021
 *      Author: RND-New002
 */

#ifndef INC_SERIAL3_H_
#define INC_SERIAL3_H_

#include "main.h"
#include "usart.h"


u32 Serial3_ReadBuff(u8 *buff, u32 size);
void Serial3_Flush(void);

#endif /* INC_SERIAL3_H_ */
