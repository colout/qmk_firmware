        /* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#include "config_common.h"


///#define SERIAL_DEBUG


#undef MK_3_SPEED
#undef MK_COMBINED
#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_MOVE_DELTA 1
#define MOUSEKEY_INITIAL_SPEED 1
#define ENCODER_RESOLUTIONS { 4 }  // Left encoder seems to have double-output issue but right does not.

#define ENCODER_RESOLUTIONS_RIGHT { 2 }  // Left encoder seems to have double-output issue but right does not.

// Already have this manually implemented.  Seems to cause bug on right side?
#define OLED_DISABLE_TIMEOUT

// Look out for performance problems.  For OLED Slave
#define SPLIT_TRANSPORT_MIRROR
//#define RGBLIGHT_LAYERS

// Space saver
//#define NO_ACTION_TAPPING  // this one breaks layers
#define NO_ACTION_ONESHOT


#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
//#define SPLIT_USB_DETECT

#if defined(KEYBOARD_sofle_rev1)
// Add RGB underglow and top facing lighting
#    define RGB_DI_PIN GP0
#    define RGBLED_NUM 72
#    define RGBLED_SPLIT \
        { 36, 36 }
#    ifdef RGB_MATRIX_ENABLE
#        define DRIVER_LED_TOTAL RGBLED_NUM
#        define RGB_MATRIX_SPLIT RGBLED_SPLIT
#        define SPLIT_TRANSPORT_MIRROR
#    else
//#        define RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_LIMIT_VAL 120
#        define RGBLIGHT_HUE_STEP  10
#        define RGBLIGHT_SAT_STEP  17
#        define RGBLIGHT_VAL_STEP  17
#    endif
#endif
