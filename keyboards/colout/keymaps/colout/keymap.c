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
#include "oled.c"
#include "achordion.c"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(L_FUN, KC_ESC):
            return 10000;
        default:
            return QUICK_TAP_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, LGUI_T(KC_A),  LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D,  KC_H,    LSFT_T(KC_N),    LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,                 KC_K,   KC_M,     KC_COMM, KC_DOT, KC_SLSH,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             LT(L_FUN, KC_ESC),LT(L_NUM,KC_ENT),LT(L_NAV,KC_TAB),               LT(L_MOUSE, KC_BSPC),LT(L_SYM,KC_SPC),LT(L_MEDIA,KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  [L_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(L_NUM, KC_ESC),  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_A,  KC_S, KC_D, KC_F, KC_G,                            KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,  TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             XXXXXXX,KC_LCTL, KC_SPC,                        KC_ENT, KC_SPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [L_GAME2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(L_NUM, KC_ESC),  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_A,  KC_S, KC_D, KC_F, KC_G,                            KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,  TG(L_GAME2),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             KC_LALT,KC_LCTL, KC_SPC,                        KC_ENT, KC_SPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
  [L_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_DOWN, KC_RIGHT, KC_INS, XXXXXXX, CW_TOGG, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, TG(L_GAME2),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, XXXXXXX, XXXXXXX,    KC_BSPC, KC_SPC, KC_DEL
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
      XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, KC_MPLY, KC_MUTE,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
[L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC, KC_0, KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

[L_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BACKSLASH, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC,                 XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BACKSLASH, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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
                                          XXXXXXX, KC_SPC, KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )

};


layer_state_t layer_state_set_user(layer_state_t state) {

    void setLayerRGB (uint8_t h, uint8_t s, uint8_t v, uint8_t mode) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(mode);
        rgb_matrix_sethsv_noeeprom(h,s,v);
    }

    switch(biton32(state)) {
        case L_NAV:
             setLayerRGB(HSV_BLUE, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_MOUSE:
             setLayerRGB(HSV_AZURE, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_MEDIA:
            rgblight_enable();
            rgb_matrix_reload_from_eeprom();  // no layer here since we set rgb from here
            break;
        case L_NUM:
             setLayerRGB(HSV_YELLOW, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_SYM:
             setLayerRGB(HSV_GREEN, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_FUN:
             setLayerRGB(HSV_MAGENTA, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_GAME:
             setLayerRGB(HSV_ORANGE, RGB_MATRIX_SOLID_COLOR);
            break;
        case L_GAME2:
             setLayerRGB(HSV_BLUE, RGB_MATRIX_SOLID_COLOR);
            break;
        default:
            rgblight_enable();
            rgb_matrix_reload_from_eeprom();
            break;
    }
    return state;
}

