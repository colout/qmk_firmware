
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

void mouseClick (void) {
    mouseMove(0, 0, 1, 1);
    mouseMove(0, 0, 0, 30);
}

void alignToScreen(void) {
    send_char(104); //h

    mouseMove(-127, 127, 0, 100);
    for (uint8_t i=20; i>0; --i) {
        mouseMove(-127, 127, 0, 1);
    }
    mouseMove(127, -127, 0, 1);
    mouseMove(0, -38, 0, 1);  // aligns with bottom of portrait.  supports lower resolutions (at least on y axis)

    // Now we click on first hero
    mouseClick();

    // click to the lower left a bit in case of lower res
    mouseMove(-50, 60, 0, 1);  
    mouseClick();
    mouseMove(50, -60, 0, 1); // move it back (should combine with next step tho)
}

void moveToHero(uint8_t s) {
    for (uint8_t i=s; i>0; --i) {
        tap_code(KC_RIGHT); // right arrow
    }
}

void clickHero(void) {
    for (uint8_t i=8; i>0; --i) {
        mouseMove(123, 10, 0, 1);  // align to left side of "continue" button
    }
    mouseClick();


    // Try again on the other side of continue (in case of lower res)
    for (uint8_t i=3; i>0; --i) {
        mouseMove(-123, 10, 0, 1);
        mouseClick();
    }

}

void selectCharacter(uint8_t s) {
    alignToScreen(); 
    moveToHero(s);
    clickHero();
}

bool mouse_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HERO1:
            if (record->event.pressed) {
                selectCharacter(2);
                return false;
            }
            break;
        case KC_HERO2:
            if (record->event.pressed) {
                selectCharacter(6);
                return false;
            }
            break;
        case KC_HERO3:
            if (record->event.pressed) {
                selectCharacter(7);
                return false;
            }
            break;
    }
    return true;
}
