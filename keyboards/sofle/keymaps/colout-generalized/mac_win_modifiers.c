void sendKey(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
}

bool mac_win_modifiers_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // "A" key on layer 2 changes MAC Mode (Since VIA sucks with custom key codes)
    if (record->event.pressed && keycode == KC_A) {
        if (biton32(layer_state) == 2) {
            isMacMode = !isMacMode;
            return false;
        }
    }

    if (isMacMode) {
        switch (keycode) {    
            case KC_LEFT_CTRL:
                sendKey(KC_LEFT_GUI, record);  
                return false;
                break;
            case KC_LEFT_GUI:
                sendKey(KC_LEFT_CTRL, record);
                return false;
                break;
        }
    }

    return true;
}