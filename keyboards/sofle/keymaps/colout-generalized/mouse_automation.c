#define PORTRAIT_UNIT 54      // 76 in 1440p
                              // 54 in 1080p
#define RESOLUTION_SCALAR 0.875  // Horizontal scalar 
                                  // 0.875 == 1920
                                  // 1 == 1920
                                  // 1.333 == 1440

const int8_t portrait_unit = PORTRAIT_UNIT * RESOLUTION_SCALAR;

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

void movePortraitUnit (float x, float y) {  
    mouseMove(portrait_unit * x, portrait_unit * y, 0, 1);  // move to hero
}


void mouseClick (void) {
    mouseMove(0, 0, 1, 1);
    mouseMove(0, 0, 0, 30);
}

void alignToScreen(void) {
    send_char(104); //h
    
    mouseMove(-127, 127, 0, 200);
    for (uint8_t i=20; i>0; --i) {
        mouseMove(-127, 127, 0, 1);
    }

    movePortraitUnit (1, -1); 
    movePortraitUnit (1, -1); 
    movePortraitUnit (0, -0.75);
    //mouseMove(0, -38, 0, 1);  // aligns with bottom of portrait.  supports lower resolutions (at least on y axis)
}

void moveToHero(uint8_t s) {
    for (uint8_t i=s; i>0; --i) {
        movePortraitUnit (1, 0); 
    }
}

void clickHero(void) {
    mouseClick();
    mouseClick();
}

bool mouse_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (heroMetaLayer) {
        switch (keycode) {
            case KC_1:
                if (record->event.pressed) {
                    alignToScreen();
                    moveToHero(2);
                    clickHero();
                    return false;
                }
                break;
            case KC_2:
                if (record->event.pressed) {
                    alignToScreen();
                    moveToHero(6);
                    clickHero();
                    return false;
                }
                break;
            case KC_3:
                if (record->event.pressed) {
                    alignToScreen();
                    moveToHero(7);
                    clickHero();
                    return false;
                }
                break;
            case KC_Q:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);       
                    moveToHero(16);
                    clickHero();
                    return false;
                }
                break;
            case KC_W:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);  
                    moveToHero(19);
                    clickHero();
                    return false;
                }
                break;
            case KC_E:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);
                    moveToHero(23);
                    clickHero();
                    return false;
                }
                break;
           case KC_A:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);       
                    moveToHero(26);
                    clickHero();
                    return false;
                }
                break;
            case KC_S:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);  
                    moveToHero(29);
                    clickHero();
                    return false;
                }
                break;
            case KC_D:
                if (record->event.pressed) {
                    alignToScreen();
                    movePortraitUnit (.5, 0);
                    moveToHero(30);
                    clickHero();
                    return false;
                }
                break;
            }
        }
    }
    return true;
}