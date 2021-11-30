/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define SERIAL1_BUFF_SIZE                        0xFF
#define SERIAL2_BUFF_SIZE                        0xFF

extern uint8_t serial1Rx_buffer[SERIAL1_BUFF_SIZE + 1];
uint8_t g_Serial2_RxBuffer[SERIAL2_BUFF_SIZE + 1];

uint8_t g_Serial2_RxBuffer_Rear;
uint8_t g_Serial2_RxBuffer_Front;

uint8_t serial1Rx_data;
uint8_t serial2Rx_data;


extern uint8_t sw_On_packet_flag;    // switch 1
extern uint8_t sw_Off_packet_flag;   // switch 2
extern uint8_t sw_Pause_packet_flag; // switch 3

extern uint8_t sw_1_packet_flag; // switch 3
extern uint8_t sw_2_packet_flag; // switch 3
extern uint8_t sw_3_packet_flag; // switch 3
extern uint8_t sw_4_packet_flag; // switch 3
extern uint8_t sw_5_packet_flag; // switch 3
extern uint8_t sw_6_packet_flag; // switch 3

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */
uint8_t Usart2_ReadBuff(uint8_t *buf);
void Usart2_WriteBuff();
void Usart2_IsEmptyBuff();
void Usart2_IsFullBuff();
void Usart2_InitBuff();
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
