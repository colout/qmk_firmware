#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"
#include "custom_rgb.c"
#include "mouse_automation.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  oled_process_record_user(keycode, record);
  mouse_process_record_user(keycode, record);

  return true;
}

// For two way key communication for oleds on slave
//   https://www.reddit.com/r/olkb/comments/q6s02g/oled_doesnt_update_on_nonmaster_side_is_that/
bool should_process_keypress(void) { return true; }

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[3][MATRIX_ROWS][MATRIX_COLS];  // no keymap.  need to manually upload from qmk in sofle.json in this folder