void reloadRgbFromEeprom (void) {
    rgblight_config_t rgblight_config;
    rgblight_config.raw = eeconfig_read_rgblight();

    rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    //rgblight_set_speed_noeeprom(rgblight_config.speed);
    rgblight_mode_noeeprom(rgblight_config.mode);

    if (rgblight_config.enable) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case _GAME:
            heroInit (selectedHero);
            break;
        case _LOWER:
            SET_TEXT_CLEAR
            setLayerConfig(HSV_GREEN, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case _RAISE:
            SET_TEXT_CLEAR
            setLayerConfig(HSV_BLUE, RGBLIGHT_MODE_BREATHING + 2);
            break;
        default:
            SET_TEXT_CLEAR
            reloadRgbFromEeprom();
            break;
    }
    return state;
}
