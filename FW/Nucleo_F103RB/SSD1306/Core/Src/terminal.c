/*
 * terminal.c
 *
 *  Created on: Aug 24, 2021
 *      Author: RND-New002
 */

#include "terminal.h"

#define TERM_STR_MAX                32
s8 term_str[TERM_STR_MAX];
s8 term_str2[128];
s32 term_str_idx = 0;

s8 token[4][16];
s32 token_size;
s32 tap_cnt = 0;

void Terminal_Task()
{
	u8 recv_data = 0;

	if (Serial3_ReadBuff(&recv_data,1))
	{
		if (Terminal_GetData(recv_data))
		{
			token_size = Tokenize (term_str, token);

			if(0 < token_size) {
				if(strcmp((char *)token[0], "load") == 0) {
						printf("Load Program\r\n");
				}
			}

			printf ("F103RB> ");
			term_str_idx = 0;
			term_str[term_str_idx] = 0;
		}
	}
}

u8 Terminal_GetData (u8 data)
{
	u8 ret = FALSE;

	if (data=='\n' || data=='\r')
	{               		 // enter
		printf ("\r\n");
		//term_recv_comp = TRUE;
		ret = TRUE;
	}
	else if (data == '\b')
	{                        // backspace
		u8 tmp[10];
//			Timer_DelayMS(5);
		Terminal_ReadBuff (tmp, 2);

		if (0 < term_str_idx)
		{
			printf ("\b \b");
			--term_str_idx;
		}
		term_str[term_str_idx] = 0;
	}
	else
	{
		term_str[term_str_idx] = data;
		if (term_str_idx < TERM_STR_MAX-1) ++term_str_idx;
		term_str[term_str_idx] = 0;
		printf ("%c", data);
		tap_cnt = 0;
	}

	return ret;
}

s32 Terminal_ReadBuff (u8 *buff, s32 size)
{
        return Serial3_ReadBuff(buff, size);
}

s32 Tokenize (s8 *str, s8 token[4][16])
{
	s8 tmp[TERM_STR_MAX];
	s8 *p;
	s32 cnt = 0;

	strcpy ((char *)tmp, (char *)str);
	p = (s8 *)strtok ((char *)tmp, " =");

	for (;;) {
			token[cnt][0] = 0;
			strcpy ((char *)token[cnt], (char *)p);
			cnt++;
			p = (s8 *)strtok (NULL, (char *)" =");
			if (p == NULL) break;
	}

	return cnt;
}
