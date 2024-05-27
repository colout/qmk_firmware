/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/achordion.h"

#define L_BASE 0
#define L_NAV 1
#define L_MOUSE 6
#define L_MEDIA 7
#define L_NUM 8
#define L_SYM 9
#define L_FUN 10
#define L_GAME 11

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return 10000;  // Don't double tap to hold for escape (anoying for vim)
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return TAPPING_TERM_SHORT;
        case LT(L_NAV, KC_SPC):
            return TAPPING_TERM_SHORT;
        case LT(L_SYM, KC_ENT):
            return TAPPING_TERM_SHORT;
        case LCTL_T(KC_BSPC):
            return TAPPING_TERM_SHORT;
        case LSFT_T(KC_TAB):
            return TAPPING_TERM_SHORT;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, LGUI_T(KC_A),  LALT_T(KC_S), KC_D, LT(L_NUM,KC_F), KC_G,     KC_H,    LT(L_MOUSE,KC_J),    KC_K, LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, LT(L_FUN,KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,   KC_M,  KC_COMM, KC_DOT, LT(L_MEDIA,KC_SLSH),  KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             LCTL_T(KC_ESC), LT(L_NAV, KC_ENT), LSFT_T(KC_TAB),                        KC_RSFT, LT(L_SYM, KC_SPC), LCTL_T(KC_BSPC)
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_ENT, KC_LSFT,    KC_LSFT, KC_SPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

[L_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,   KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

[L_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_MPLY, KC_MUTE,    KC_LSFT, KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),
[L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_ENT, KC_LSFT,    KC_LSFT, KC_0, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

[L_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_GRV, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BACKSLASH, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC,                 XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_ENT, KC_LSFT,    KC_LSFT, KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

[L_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F12, KC_F7,   KC_F8,   KC_F9, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_F11, KC_F4,   KC_F5,   KC_F6, KC_SCRL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F10, KC_F1,   KC_F2,   KC_F3, KC_PAUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, KC_ENT, KC_LSFT,    KC_LSFT, KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),
[L_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_A,  KC_S, KC_D, KC_F, KC_G,     KC_H,    LT(L_MOUSE,KC_J),    KC_K, LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,   KC_M,  KC_COMM, KC_DOT, LT(L_MEDIA,KC_SLSH),  TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             KC_LCTL, KC_SPC, KC_LSFT,                        KC_RSFT, LT(L_SYM, KC_ENT), LCTL_T(KC_BSPC)
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}



void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("Navegate"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

layer_state_t layer_state_set_user(layer_state_t state) {

    void setLayerRGB (uint8_t h, uint8_t s, uint8_t v, uint8_t mode) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(mode);
        rgb_matrix_sethsv_noeeprom(h,s,v);
    }

    switch(biton32(state)) {
        case L_NAV:
             setLayerRGB(HSV_BLUE, RGB_MATRIX_SOLID_REACTIVE);
            break;
        case L_MOUSE:
             setLayerRGB(HSV_AZURE, RGB_MATRIX_SOLID_REACTIVE);
            break;
        case L_MEDIA:
            rgblight_enable();
            rgb_matrix_reload_from_eeprom();  // no layer here since we set rgb from here
            break;
        case L_NUM:
             setLayerRGB(HSV_YELLOW, RGB_MATRIX_SOLID_REACTIVE);
            break;
        case L_SYM:
             setLayerRGB(HSV_GREEN, RGB_MATRIX_SOLID_REACTIVE);
            break;
        case L_FUN:
             setLayerRGB(HSV_MAGENTA, RGB_MATRIX_SOLID_REACTIVE);
            break;
        case L_GAME:
             setLayerRGB(HSV_ORANGE, RGB_MATRIX_SOLID_REACTIVE);
            break;
        default:
            rgblight_enable();
            rgb_matrix_reload_from_eeprom();
            break;
    }
    return state;
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

//void matrix_scan_user(void) {
//  achordion_task();  // https://getreuer.info/posts/keyboards/achordion/index.html#add-achordion-to-your-keymap
//}

//uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//  return ACHORDIAN_TIMEOUT;
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
