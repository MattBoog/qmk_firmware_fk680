/* Copyright 2022 ZhaQian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

#define VENDOR_ID       0x8657
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         FK680Pro

#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { B3, B4, B5, B6, B7 }
#define MATRIX_COL_PINS { A4, A5, A6, A7, B0, B1, B10, B11, B12, B13, B14, B15, A8, A9, A10}
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN A15
#define RGBLED_NUM 110 
#define DRIVER_LED_TOTAL RGBLED_NUM
//#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 192
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#ifdef RGB_MATRIX_CUSTOM_KB
  #define RGB_MATRIX_CUSTOM_ANIMATION
#endif
