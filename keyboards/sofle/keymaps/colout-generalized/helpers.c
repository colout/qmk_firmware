
void setLayerConfig (uint8_t h, uint8_t s, uint8_t v, uint8_t mode) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(mode);
    //rgblight_set_speed_noeeprom(255);
    rgblight_sethsv_noeeprom(h,s,v);  // orange
}


void mouseMove(int8_t x, int8_t y, uint8_t button) {
    report_mouse_t rpt;  
    rpt = pointing_device_get_report();
    
    rpt.buttons = 0;
    rpt.x = x;
    rpt.y = y;
    switch (button) {
        case 1:
            rpt.buttons |= MOUSE_BTN1;
            break;
        case 2:
            rpt.buttons |= MOUSE_BTN2;
            break;
    }

    pointing_device_set_report(rpt);
    pointing_device_send();
}