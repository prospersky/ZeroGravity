/*
 * fonts.h
 *
 *  Created on: Aug 20, 2021
 *      Author: RND-New002
 */

#ifndef INC_FONTS_H_
#define INC_FONTS_H_

#include "main.h"
//
//	Structure om font te definieren
//
typedef struct {
	const uint8_t FontWidth;    /*!< Font width in pixels */
	uint8_t FontHeight;   /*!< Font height in pixels */
	const uint16_t *data; /*!< Pointer to data font data array */
} FontDef;


//
//	De 3 fonts
//
extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

#endif /* INC_FONTS_H_ */
