#include "features/achordion.h"

void matrix_scan_user(void) {
  achordion_task();  // https://getreuer.info/posts/keyboards/achordion/index.html#add-achordion-to-your-keymap
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(L_NUM, KC_ESC):
            return 0;
    }
    return ACHORDIAN_TIMEOUT;
}

bool key_states[2] = {false, false}; // A,D
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Hacky way to fake snaptap
    if (layer_state_is(L_GAME)) { // TODO: maybe make this check a simple bool for efficiency?
        if (keycode == KC_S) {
            key_states[0] = record->event.pressed;

            if (record->event.pressed) {
                unregister_code(KC_F);
            } else if (key_states[1]) {
                register_code(KC_F);
            }
        }

        if (keycode == KC_F) {
            key_states[1] = record->event.pressed;

            if (record->event.pressed) {
                unregister_code(KC_S);
            } else if (key_states[0]) {
                register_code(KC_S);
            }
        }
    }

    if (!process_achordion(keycode, record)) { return false; } // for accordian (same hand homerow mod fixes)

    return true;
}
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return TAPPING_TERM_SHORT;
        case LT(L_NUM,KC_ENT):
            return TAPPING_TERM_SHORT;
        case LT(L_NAV,KC_TAB):
            return TAPPING_TERM_SHORT;
        case LSFT_T(KC_BSPC):
            return TAPPING_TERM_SHORT;
        case LT(L_SYM,KC_SPC):
            return TAPPING_TERM_SHORT;
        case LT(L_MOUSE,KC_DEL):
            return TAPPING_TERM_SHORT;
        default:
            return TAPPING_TERM;
    }
}
