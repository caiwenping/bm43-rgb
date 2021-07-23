/* Copyright 2019 mechmerlin
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
#include "bm43rgb.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/

#if defined(RGB_MATRIX_ENABLE)
#define LED_MATRIX_CENTER { 105, 30 }
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { 0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,    11},
        {12,     13,   14,   15,   16,   17,   18,   19,   20,   21, NO_LED, 22},
        {23,      24,    25,   26,   27,   28,   29,   30,   31,  32,NO_LED, 33},
        {34,    35,   36,    37, NO_LED,   38, NO_LED,   39, 40, 41, NO_LED, 42}
    }, 
    {
        // LED Index to Physical Position
        // Esc, Q, W, E, R, T, Y, U, I, O, P, Backspace
        {   0,   0 }, { 19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,   0 }, {  114,   0 }, { 133,   0 }, { 152,   0 }, { 171,   0 }, { 190,   0 }, { 210,   0 }, 
        // Capslock, A, S, D, F, G, H, J, K, L, Enter
        {   2,  19 },     {  23,  19 }, {  43,  19 }, {  62,  19 }, {  80,  19 }, {  100,  19 }, {  119,  19 }, { 138,  19 }, { 157,  19 }, { 171,  19 },         { 202,  19 },
        // LShift, Z, X, C, V, B, N, M, <, up, >
        {  9,  38 },               {  38,  38 }, {  56,  38 }, {  75,  38 }, {  94,  38 }, {  114,  38 }, { 133,  38 }, { 152,  38 }, { 171,  38 }, { 189,  38 }, { 208,  38 }, 
        // Ctrl, GUI, Alt, Space, Space, FN, Left, Down, Right
        {  0,  58 }, {  10,  58 }, {  38,  58 },              {  74,  58 },            {  121,  58 },                   { 152,  58 }, { 171,  58 }, { 190,  58 }, { 210,  58 },
        // UNDERGLOW
        {   170, 29 }, {  140,  29 }, {  110, 29 }, { 80,  29 }, { 50,  29 }, { 30,  29 }
    }, 
    {
        // LED Index to Flag
	    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,  // Tab, Q, W, E, R, T, Y, U, I, O, P, backslash 
	    1, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,  // Capslock, A, S, D, F, G, H, J, K, L, Enter
	    9, 4, 4, 4, 4, 4, 4, 4, 4, 1,    4,  // LShift, Z, X, C, V, B, N, M, <, UP, >
	    1, 1, 1, 1,    1,    1, 1, 1,    1,  // Ctrl, GUI, Alt, Space, RAlt, FN, Ctrl, Left, Down, Right
	    2, 2, 2, 2, 2, 2  // PCB Backlight
    }
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & 8) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
}  // Capslock Light settings

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif
