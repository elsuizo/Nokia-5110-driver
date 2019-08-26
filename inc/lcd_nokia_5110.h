/* -------------------------------------------------------------------------
@file lcd_nokia_5110.h

@date 08/21/19 23:25:05
@author Martin Noblia
@email mnoblia@disroot.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
/* NOTE(elsuizo:2019-08-22): es mejor tener enums antes de que defines ya que en un error el compilador lo puede notar mejor */

#include "sapi.h"

/* macros */
#define SET_BIT(b) (1UL << (b))


/* prototypes */


/* custom data-types */

enum LCD_SCREEN {
   LCD_SCREEN_X_MAX = 84,
   LCD_SCREEN_Y_MAX = 48,
};

/**
 * @brief: Pins for the lcd Nokia 5110
 */
enum LCD_PIN {
   LCD_PIN_RES   = GPIO0, /* external reset input: warning is active in low mode */
   LCD_PIN_SCE   = GPIO2, /* chip enable: warning is active in low mode */
   LCD_PIN_DC    = GPIO4, /* data/clock mode select */
   LCD_PIN_SDIN  = GPIO6, /* serial data input */
   LCD_PIN_SCLK  = GPIO8, /* serial clock input */
   LCD_PIN_LIGHT = PWM0, /* light pin map to a pwm value */
};

enum BYTE_ENCODING_TYPES {
   LSBFIRST,
   MSBFIRST
};

enum LCD_INTRUCTIONS {
   FUNCTION_SET            = SET_BIT(5), /* set the bit 5 to begins table 1 */
   EXTENDED_FUNCTION_SET   = FUNCTION_SET | SET_BIT(0), /* for set the extendend set of instructions */
   BASIC_FUNCTION_SET      = FUNCTION_SET, /* set H to low */
   DISPLAY_CONTROL_SET     = SET_BIT(3),
   SET_Y                   = SET_BIT(6),
   SET_X                   = SET_BIT(7),
   NORMAL_MODE_SET         = DISPLAY_CONTROL_SET | SET_BIT(2),
   BIAS_SYSTEM_ENABLED_SET = SET_BIT(4), /* set the bias of voltages bit ready for initialization */
   MUX_48_SET              = BIAS_SYSTEM_ENABLED_SET | SET_BIT(1) | SET_BIT(0),
   V_OP_SET                = SET_BIT(7), /* set bits values for initialize the contrast */
};

/*-------------------------------------------------------------------------
                     prototypes
-------------------------------------------------------------------------*/

bool_t lcd_nokia_5110_init(void);

void lcd_nokia_5110_send_character(char c);

void lcd_nokia_5110_clear(void);

void lcd_nokia_5110_write(const char* message, uint8_t position_x, uint8_t position_y);

void lcd_nokia_5110_set_contrast(uint8_t constrast_value);
