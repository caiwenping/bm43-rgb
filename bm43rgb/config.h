/*
Copyright 2019 mechmerlin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6061
#define DEVICE_VER      0x0001
#define MANUFACTURER    KPrepublic
#define PRODUCT         BM43 RGB 40%

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { E6, B6, B4, B5 }
#define MATRIX_COL_PINS { C6, D2, D1, D0, D7, D6, D4, D5, D3, B7, B3, B2 }

#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN E2
#define DRIVER_LED_TOTAL 49

#ifdef RGB_DI_PIN
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define VIALRGB_NO_DIRECT
    
    #define DISABLE_RGB_MATRIX_BREATHING
    #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_BAND_SAT
    #define DISABLE_RGB_MATRIX_BAND_VAL
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define DISABLE_RGB_MATRIX_CYCLE_ALL
    #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define DISABLE_RGB_MATRIX_DUAL_BEACON
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_HUE_BREATHING
    #define DISABLE_RGB_MATRIX_HUE_PENDULUM
    #define DISABLE_RGB_MATRIX_HUE_WAVE
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define TAPPING_TOGGLE 3
#define NO_AUTO_SHIFT_ALPHA


#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 30            //Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 1           //Step size
#define MOUSEKEY_MAX_SPEED 30           //Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 190         //Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 100        //Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 100     //Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED 8      //Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 50   //Time until maximum scroll speed is reached

