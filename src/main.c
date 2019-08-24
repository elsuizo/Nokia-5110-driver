/* -------------------------------------------------------------------------
@file main.c

@date 08/21/19 22:29:28
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Test para hacer funcionar el lcd nokia 5110 con la edu-ciaa
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
#include "sapi.h"
#include "lcd_nokia_5110.h"

/* NOTE(elsuizo:2019-08-22): anduvo el hola mundo */

int main(void) {

   /* initializations */
   boardConfig();
   bool_t result = lcd_nokia_5110_init();
   /* NOTE(elsuizo:2019-08-22): este clear es importante */
   lcd_nokia_5110_clear();

   while(1) {
      for (int index = 0; index < 20; index++) {
         lcd_nokia_5110_write("Martin Noblia", 0, index);
      }
   }
}
