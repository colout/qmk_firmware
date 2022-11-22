#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 0) {
        if (layer_state_is(_GAME)) {  //TODO: Move to left encoder.
            if (clockwise) {
                incrementHero(1);
            } else {
                incrementHero(-1);
            }
        } else {
            if (clockwise) {
                tap_code(KC_PGDOWN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }
    return true;
}

#endif
