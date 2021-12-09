
report_mouse_t rpt;  

enum my_keycodes {
    KC_HERO1 = SAFE_RANGE,
};

void mouseMove(int8_t x, int8_t y, uint8_t button, int16_t waiter) {
    rpt = pointing_device_get_report();

    switch (button) {
        case 0:   // set to 0 for mouse move
            rpt.x = x;
            rpt.y = y;
            break;
        case 1:
            rpt.buttons |= MOUSE_BTN1;
        case 2:
            rpt.buttons |= MOUSE_BTN2;  
            break;
        case 7:  // release all buttons
            rpt.buttons &= MOUSE_BTN1;
            break;
    }

    pointing_device_set_report(rpt);
    pointing_device_send();

    uint32_t pause_timer = timer_read32();
    while (timer_elapsed32(pause_timer) < waiter) {}

}


bool mouse_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HERO1:
            if (record->event.pressed) {
                for (uint8_t i=0; i<30; ++i) {
                    mouseMove(-127, 127, 0, 1);
                }
                mouseMove(127, -127, 0, 10);
                mouseMove(0, -64, 0, 10);
                mouseMove(0, 0, 1, 10);
                mouseMove(0, 0, 0, 100);
                mouseMove(0, 0, 1, 10);
                mouseMove(0, 0, 0, 10);
                return false;
            }
            break;
    }
    return true;
}