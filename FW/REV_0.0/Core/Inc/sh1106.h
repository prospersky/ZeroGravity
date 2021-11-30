/*
 * sh1106.h
 *
 *  Created on: Aug 31, 2021
 *      Author: RND-New002
 */

#ifndef INC_SH1106_H_
#define INC_SH1106_H_

#include "main.h"
#include "fonts.h"

//	Deze library is door Olivier Van den Eede 2016 geschreven en aangepast voor gebruik met
//	Stm32 microcontrollers en maakt gebruik van de HAL-i2c library's.
//
//	Deze library is gemaakt om gebruik te kunnen maken van een sh1106 gestuurd oled display.
//	Voor het gebruik moeten zeker de onderstaande defines juist ingesteld worden.
//	Zoals de gebruikte i2c poort en de groote van het scherm.
//
//	De library maakt gebruik van 2 files (fonts.c/h) Hierin staan 3 fonts beschreven.
//	Deze fonts kunnen zo gebruikt worden: 	- Font_7x10
//											- Font_11x18
//											- Font_16x26

// i2c port naam in main programma gegenereerd door cube
#define SH1106_I2C_PORT		hi2c1
// I2C address
#define SH1106_I2C_ADDR        0x78
// sh1106 width in pixels
#define SH1106_WIDTH			132
// sh1106 LCD height in pixels
#define SH1106_HEIGHT          64
#define ABS(x)   ((x) > 0 ? (x) : -(x))


//
//	Enum voor de kleuren van het scherm Black en White
//
typedef enum {
	Black = 0x00, /*!< Black color, no pixel */
	White = 0x01  /*!< Pixel is set. Color depends on LCD */
} SH1106_COLOR;

//
//	Struct om wijzigingen bij te houden
//
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} SH1106_t;

//	De i2c poort staat in de main
extern I2C_HandleTypeDef SH1106_I2C_PORT;

uint8_t sh1106_Init(void);
void sh1106_Fill(SH1106_COLOR color);
void sh1106_UpdateScreen(void);
void sh1106_DrawPixel(uint8_t x, uint8_t y, SH1106_COLOR color);
char sh1106_WriteChar(char ch, FontDef Font, SH1106_COLOR color);
char sh1106_WriteString(char* str, FontDef Font, SH1106_COLOR color);
void sh1106_SetCursor(uint8_t x, uint8_t y);
void sh1106_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, SH1106_COLOR c);
void sh1106_DrawRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SH1106_COLOR c);
void sh1106_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SH1106_COLOR c);
void sh1106_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SH1106_COLOR color);
void sh1106_DrawFilledTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SH1106_COLOR color);
void sh1106_DrawCircle(int16_t x0, int16_t y0, int16_t r, SH1106_COLOR c);
void sh1106_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, SH1106_COLOR c);

void sh1106_ON(void);
void sh1106_OFF(void);
void sh1106_test(void);

static void sh1106_WriteCommand(uint8_t command);

#endif /* INC_SH1106_H_ */
