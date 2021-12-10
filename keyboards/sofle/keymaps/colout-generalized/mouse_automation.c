
enum my_keycodes {
    KC_HERO1 = SAFE_RANGE, // 0x5da5
    KC_HERO2,
    KC_HERO3,
};

void mouseMove(int8_t x, int8_t y, uint8_t button, int16_t waiter) {
    uint32_t pause_timer = timer_read32();
    while (timer_elapsed32(pause_timer) < waiter) {}

    report_mouse_t rpt;  
    rpt = pointing_device_get_report();
    
    rpt.buttons = 0;
    rpt.x = x;
    rpt.y = y;
    switch (button) {
        case 1:
            rpt.buttons |= MOUSE_BTN1;
    }

    pointing_device_set_report(rpt);
    pointing_device_send();
}

void alignToScreen(void) {
    SEND_STRING("KC_h");
    
    mouseMove(-127, 127, 0, 700);
    for (uint8_t i=0; i<30; ++i) {
        mouseMove(-127, 127, 0, 1);
    }
    mouseMove(127, -127, 0, 10);
    mouseMove(0, -64, 0, 1);
}

void moveToHero(uint8_t s) {
    for (uint8_t i=0; i<s; ++i) {
        mouseMove(76, 0, 0, 1);  // move to hero
    }
}

void clickHero(void) {
    mouseMove(0, 0, 1, 1);
    mouseMove(0, 0, 0, 30);
    mouseMove(0, 0, 1, 50);
    mouseMove(0, 0, 0, 30);
}

bool mouse_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HERO1:
            if (record->event.pressed) {
                alignToScreen();
                moveToHero(2);
                clickHero();
                return false;
            }
            break;
        case KC_HERO2:
            if (record->event.pressed) {
                alignToScreen();
                moveToHero(6);
                clickHero();
                return false;
            }
            break;
        case KC_HERO3:
            if (record->event.pressed) {
                alignToScreen();
                moveToHero(7);
                clickHero();
                return false;
            }
            break;
    }
    return true;
}