
static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Mouse
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 54
    0x09, 0x02,                    // USAGE (Mouse)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x85, 0x01,                    //     REPORT_ID (1)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x75, 0x05,                    //     REPORT_SIZE (5)
    0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
    0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x38,                    //     USAGE (Wheel)
    0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x81, 0x06,                    //     INPUT (Data,Var,Rel)
    0xc0,                          //   END_COLLECTION
    0xc0,                          // END_COLLECTION
};


void mouseMove(int8_t x, int8_t y, uint8_t button) {
    report_mouse_t rpt;
    rpt = pointing_device_get_report();

    rpt.x = x;
    rpt.y = y;
    switch (button) {
        case 1:
            rpt.buttons |= MOUSE_BTN1;
            break;
        case 2:
            rpt.buttons |= MOUSE_BTN2;
            break;
        default:
            rpt.buttons = 0;
    }

    pointing_device_set_report(rpt);
    pointing_device_send();
}

void setLayerConfig (uint8_t h, uint8_t s, uint8_t v, uint8_t mode) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(mode);
    //rgblight_set_speed_noeeprom(255);
    rgblight_sethsv_noeeprom(h,s,v);
}
