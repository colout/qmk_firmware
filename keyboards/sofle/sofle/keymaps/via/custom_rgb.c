

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_config_t rgblight_config;
    switch(biton32(state)) {
        case 1:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING  + 2);
            rgblight_set_speed_noeeprom(255);
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case 2:
            rgblight_enable_noeeprom();	
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
            rgblight_set_speed_noeeprom(255);
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING  + 2);
            rgblight_set_speed_noeeprom(255);
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case 4:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
            rgblight_set_speed_noeeprom(255);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        default:
            rgblight_config.raw = eeconfig_read_rgblight();

            rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
            rgblight_set_speed_noeeprom(rgblight_config.speed);
            rgblight_mode_noeeprom(rgblight_config.mode);
            
            if (rgblight_config.enable) {
                rgblight_enable_noeeprom();
                    
            } else { 
                rgblight_disable_noeeprom();
            }
            break;
    }
    return state;
}