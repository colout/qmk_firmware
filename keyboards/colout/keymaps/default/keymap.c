// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "achordion.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_4x6_5(
          KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
          KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
          KC_LCTL, LGUI_T(KC_A),  LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,  KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
          KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
          KC_LGUI,KC_LALT,LT(L_FUN, KC_ESC),LT(L_NUM,KC_ENT),LT(L_NAV,KC_TAB),               LT(L_MOUSE, KC_BSPC),LT(L_SYM,KC_SPC),LT(L_MEDIA,KC_DEL), KC_LGUI,KC_LALT
    ),
    [L_GAME] = LAYOUT_split_4x6_5(
          _______,   _______,   _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,  _______,
          _______,   _______,   _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,  _______,
          KC_TAB,   KC_A,      KC_S,       KC_D,       KC_F,       _______,                     _______, LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN),_______,
          _______,   _______,   _______,    _______,    _______,    _______,  _______,   _______, _______,   _______,    _______,    _______,  _______,  TG(L_GAME),
          _______,_______, _______, KC_LCTL,KC_SPC,               KC_ENT, KC_SPC, KC_DEL, _______, _______
    ),

    [L_GAME2] = LAYOUT_split_4x6_5(
          _______,   _______,   _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,  _______,
          _______,    _______,   _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,  _______,
          KC_TAB,    KC_A,      KC_S,       KC_D,       KC_F,       _______,                     _______, LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN),_______,
          _______,   _______,   _______,    _______,    _______,    _______,  _______,   _______,    _______,    _______,    _______,    _______,  _______,  TG(L_GAME2),
          _______,_______, _______, KC_LCTL,KC_SPC,               KC_ENT, KC_SPC, KC_DEL, _______, _______
    ),
  [L_NAV] = LAYOUT_split_4x6_5(
          _______,   _______,   _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,  _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, CW_TOGG, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_INS, TG(L_GAME2),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX,    KC_BSPC, KC_SPC, KC_DEL, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

[L_MOUSE] = LAYOUT_split_4x6_5(
          XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,   KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

[L_MEDIA] = LAYOUT_split_4x6_5(
          XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(L_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, KC_LSFT, KC_MPLY, KC_MUTE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
[L_NUM] = LAYOUT_split_4x6_5(
          XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC, KC_0, KC_DOT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

[L_SYM] = LAYOUT_split_4x6_5(
          XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BACKSLASH, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC,                 XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BACKSLASH, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

[L_FUN] = LAYOUT_split_4x6_5(
          XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F12, KC_F7,   KC_F8,   KC_F9, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_F11, KC_F4,   KC_F5,   KC_F6, KC_SCRL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  KC_F10, KC_F1,   KC_F2,   KC_F3, KC_PAUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
