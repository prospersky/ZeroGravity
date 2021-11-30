/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define LSW1_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET)
#define LSW1_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET)

#define LSW2_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET)
#define LSW2_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET)

#define LSW3_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)
#define LSW3_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)

#define LSW4_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define LSW4_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)

#define LSW5_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET)
#define LSW5_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)

#define LSW6_TRIGGER_SET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET)
#define LSW6_TRIGGER_RESET	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET)

#define LIMIT_SIG1_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10)
#define LIMIT_SIG2_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11)
//#define LIMIT_SIG3_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12)
//#define LIMIT_SIG4_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
//#define LIMIT_SIG5_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14)
//#define LIMIT_SIG6_STATE	HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15)

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
