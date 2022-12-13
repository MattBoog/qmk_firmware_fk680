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

#include "fk680.h"

#ifdef RGB_MATRIX_ENABLE 
led_config_t g_led_config = {
{
    // Key Matrix to LED Index
    { 55,     56,     57,     58,     59,     60,     61,     62,     63,    64,     65,     66,       67,    68,   69  },
    { 40,     41,     42,     43,     44,     45,     46,     47,     48,    49,     50,     51,       52,    53,   54  },
    { 26,     27,     28,     29,     30,     31,     32,     33,     34,    35,     36,     37,   NO_LED,    38,   39  },
    { 12,     13,     14,     15,     16,     17,     18,     19,     20,     21,    22, NO_LED,       23,    24,   25  },
    { 0,      1,      2,  NO_LED, NO_LED,      4, NO_LED, NO_LED,      NO_LED,      6,     7,      8,        9,    10,   11  }
}, {
    // LED Index to Physical Position
    // {col, row}
    { 7 , 63 }, { 26 , 63 }, { 45 , 63 }, { 78 , 53 }, { 97 , 63 }, { 116 , 53 }, { 147 , 63 }, { 161 , 63 }, { 175 , 63 }, {190 , 63 },  { 204 , 63 }, { 218 , 63 },
    { 16 , 46 }, { 39 , 46 }, { 52 , 46 }, { 66 , 46 }, { 81 , 46 }, { 95 , 46 }, { 109 , 46 }, { 122 , 46 }, { 137 , 46 }, {151 , 46 }, { 165 , 46 }, { 184 , 46 }, { 204 , 46 }, { 218 , 46 },
    { 12 , 30 }, { 31 , 30 }, { 45 , 30 }, { 59 , 30 }, { 73 , 30 }, { 87 , 30 }, { 102 , 30 }, { 116 , 30 }, { 130 , 30 }, {144 , 30 }, { 158 , 30 }, { 172 , 30 }, { 196 , 30 }, { 218 , 30 },
    { 10 , 14 }, { 28 , 14 }, { 42 , 14 }, { 56 , 14 }, { 70 , 14 }, { 84 , 14 }, { 98 , 14 },  { 112 , 14 }, { 126 , 14 }, {140 , 14 }, { 155 , 14 }, { 169 , 14 }, { 183 , 14 }, { 199 , 14 }, { 218 , 14 },
    { 7 , 0 }, { 21 , 0 }, { 35 , 0 }, { 49 , 0 }, { 63 , 0 }, { 77 , 0 }, { 91 , 0 }, { 105 , 0 }, { 119 , 0 }, { 133 , 0 }, {147, 0 }, { 161 , 0 }, { 175 , 0 }, { 196 , 0 }, { 218 , 0 },
    

    { 224 , 0 }, { 224 , 16 }, { 224 , 32 }, { 224 , 48 }, { 224 , 64 }, 
    { 210 , 64 }, { 196 , 64 }, { 182 , 64 }, { 168 , 64 }, { 154 , 64 }, { 140 , 64 }, { 126 , 64 }, { 112 , 64 }, { 98 , 64 }, { 84 , 64 }, { 70 , 64 }, { 56 , 64 }, { 42 , 64 }, { 28 , 64 }, { 14 , 64 }, 
    { 0 , 64 }, { 0 , 48 }, { 0 , 32 }, { 0 , 16 }, { 0 , 0 }, 
    { 14 , 0 }, { 28 , 0 }, { 42 , 0 }, { 56 , 0 }, { 70 , 0 }, { 84 , 0 }, { 98 , 0 }, { 112 , 0 }, { 126 , 0 }, { 140 , 0 }, { 154 , 0 }, { 168 , 0 }, { 182 , 0 }, { 196 , 0 }, { 210 , 0 },
}, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,        // Ctrl, GUI, Alt, light, Space, light,  RAlt, FN, Ctrl, Left, Down, Right
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete

    // underglow
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

}
};

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(26, 128, 0xFF, 0xFF);
    }
}

#endif