/*
 * terminal_control.c
 *
 *  Created on: Sep 13, 2021
 *      Author: RND-New002
 */

#include "terminal_control.h"



void Terminal_Task(void)
{
	if(Usart2_ReadBuff(g_Serial2_RxBuffer)) {
		if ( (serial2Rx_data=='\n') || (serial2Rx_data=='\r') ) {  // enter
			printf ("123\r\n");
		}
	}

//	memset (term_str, 0, sizeof (s8) * TERM_STR_MAX);
////	printf("Terminal Task\r\n");
//
//	if (Serial3_ReadBuff(&recv_data, 1))
//	{
//		if (TermGetData(recv_data))
//		{
//			token_size = Tokenize (term_str, token);
//			if(0 < token_size)
//			{
//				if(strcmp((char *)token[0], "fs") == 0)
//				{
//
//				}
//				else if(strcmp((char *)token[0], "mkfs") == 0) {
//
//				}
//			}
//			Prompt ();
//			term_str_idx = 0;
//			term_str[term_str_idx] = 0;
//		}
//	}
//	printf ("APP> ");
}
