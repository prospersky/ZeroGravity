/*
 * serial3.c
 *
 *  Created on: Nov 2, 2021
 *      Author: RND-New002
 */

#include "serial3.h"


u8 g_serial3_RxBuffer[SERIAL3_BUFF_SIZE + 1];
u8 g_serial3_TxBuffer[SERIAL3_BUFF_SIZE + 1];

u32 g_serial3_RxBufferTail = 0;

#define SERIAL3_RX_BUFF_HEAD     ((SERIAL3_BUFF_SIZE + 1)- (DMA1_Channel3->CNDTR+1))
#define SERIAL3_RX_SIZE          ((SERIAL3_RX_BUFF_HEAD + (SERIAL3_BUFF_SIZE+1) - g_serial3_RxBufferTail) & SERIAL3_BUFF_SIZE)
#define SERIAL3_RX_BUFF_CLEAR    (g_serial3_RxBufferTail = SERIAL3_RX_BUFF_HEAD);


u32 Serial3_ReadBuff(u8 *buff, u32 size)
{
	u32 i;
	u32 cnt = 0;

	for (i = 0; i < size; i++)
	{
		if (0 == SERIAL3_RX_SIZE) break; // Empty check
		buff[i] = g_serial3_RxBuffer[g_serial3_RxBufferTail];
		g_serial3_RxBufferTail = (g_serial3_RxBufferTail + 1) & SERIAL3_BUFF_SIZE;
		cnt++;
	}

	return cnt;
}


void Serial3_Flush(void)
{
	SERIAL3_RX_BUFF_CLEAR;
}
