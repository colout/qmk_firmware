
enum rgb_keycodes {
    KC_HERO_SELECT = 0x5dae
};

bool heroMetaLayer = false;

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

void setLayerConfig (uint8_t h, uint8_t s, uint8_t v, uint8_t mode) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(mode);
    //rgblight_set_speed_noeeprom(255);
    rgblight_sethsv_noeeprom(h,s,v);  // orange

}

bool rgblayeroverride_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_HERO_SELECT) {
        if (record->event.pressed) {
            heroMetaLayer = true;
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(25,255,10);

            rgblight_setrgb_at(0, 0, 255, 12);  // Rein Blue
            rgblight_setrgb_at(255, 255, 255, 21);  // Ball grey (white)
            rgblight_setrgb_at(255, 0, 255, 22);  // Zarya Purple

            rgblight_setrgb_at(255, 255, 255, 13);  // Mei White
            rgblight_setrgb_at(0,0,255, 20);  // Soldier Blue
            rgblight_setrgb_at(255, 0, 255, 23);  // Tracer Yellow

            rgblight_setrgb_at(0, 0, 255, 14);  // Ana
            rgblight_setrgb_at(0,255, 0, 19);  // Lucio
            rgblight_setrgb_at(158,53,255, 24);  // Moira

        } else {
            heroMetaLayer = false;
            setLayerConfig(10, 255, 255, RGBLIGHT_MODE_BREATHING + 2);  // Go back to layer 2 lighting
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case 1:
            setLayerConfig(10, 255, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case 2:
            setLayerConfig(HSV_GREEN, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case 3:
            setLayerConfig(HSV_BLUE, RGBLIGHT_MODE_BREATHING + 2);
            break;
        default:
            reloadRgbFromEeprom();
            break;
    }
    return state;
}