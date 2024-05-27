/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#define L_BASE 0
#define L_GAME 1
#define L_GAME2 2
#define L_NAV 3
#define L_MOUSE 5
#define L_MEDIA 6
#define L_NUM 7
#define L_SYM 8
#define L_FUN 9

#define MASTER_LEFT
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGBLED_NUM 54 // Number of LEDs
    #define RGB_MATRIX_SPLIT \
        { 27, 27 }

    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_SHORT 170
#define ACHORDIAN_TIMEOUT 800
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
//#define NO_AUTO_SHIFT_ALPHA
//#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
//#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

