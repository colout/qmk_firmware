
#include "overwatch_hero_names.h" // To save on space and make things readable

uint32_t timerAction = 0;
uint32_t timerActionFromStart = 0;

bool activeAction1 = false;
bool activeAction2 = false;
bool activeActionModifier = false;
uint16_t stepAction = 0;


void heroInit (int8_t hero) {
    SET_TEXT_HERO;
    switch (selectedHero) {
        case HERO_LUCIO:
            SET_TEXT_LUCIO
            setLayerConfig(85, 255, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case HERO_MERCY:
            SET_TEXT_MERCY
            setLayerConfig(0, 0, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case HERO_REIN:
            SET_TEXT_REIN
            setLayerConfig(169, 200, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case HERO_ZARYA:
            SET_TEXT_ZARYA
            setLayerConfig(201, 255, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        case HERO_ASHE:
            SET_TEXT_ASHE
            setLayerConfig(0, 200, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
        default:
            activeAction1 = false;
            SET_TEXT_NONE
            setLayerConfig(10, 255, 255, RGBLIGHT_MODE_BREATHING + 2);
            break;
    }
}

void incrementHero(int8_t i) {
    selectedHero = selectedHero + i;
    if (selectedHero > HERO_COUNT) selectedHero = 0;
    if (selectedHero < 0) selectedHero = HERO_COUNT;
    heroInit(selectedHero);
}

bool overwatch_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_GAME)) {
        if (keycode == KC_OVERWATCH_ACTION1) {
            switch (selectedHero) {
                case HERO_LUCIO:  // Hold shift ctl until 1 second after release
                    if (record->event.pressed) {
                        activeAction1 = true;
                    } else {
                        activeAction1 = false;
                    }
                    break;
                case HERO_MERCY:  // Hold shift ctl until 1 second after release
                    if (record->event.pressed) {
                        // On key down, press ctl shift
                        activeAction1 = false;
                        register_code(KC_LSHIFT);
                        register_code(KC_LCTRL);
                    } else {
                        // on key up, start timer and enable action
                        timerAction = timer_read32();
                        activeAction1 = true;
                    }
                    break;

                case HERO_REIN:  // Swing
                    if (record->event.pressed) {
                        stepAction = 0;
                        timerAction = timer_read32();
                        activeAction2 = true;
                    } else {
                        activeAction2 = false;
                        mouseMove(0,0,0);

                    }
                    break;
                case HERO_ZARYA:
                    if (record->event.pressed) {
                        if (!activeAction1 && !activeAction2) {
                            stepAction = 0;
                            timerActionFromStart = 0;
                            if (activeActionModifier) timerActionFromStart = timer_read32();
                            activeAction1 = true;
                        }
                    }
                    break;
                case HERO_ASHE:  // Shotgun Jump
                    if (record->event.pressed) {
                        stepAction = 0;
                        timerAction = timer_read32();
                        activeAction1 = true;
                    }
                    break;
                default:
                    activeAction1 = false;
                    break;
            }
        } else if (keycode == KC_OVERWATCH_ACTION2) {
            switch (selectedHero) {
                case HERO_REIN:  // Shield hop
                    if (record->event.pressed) {
                        stepAction = 0;
                        timerAction = timer_read32();
                        activeAction1 = true;
                    } else {
                        activeAction1 = false;
                    }
                    break;
                case HERO_ZARYA:
                    if (record->event.pressed) {
                        if (!activeAction1 && !activeAction2) {
                            stepAction = 0;
                            activeAction2 = true;
                        }
                    }
                    break;
                default:
                    activeAction2 = false;
                    break;
            }
        } else if (keycode == KC_LALT) {
                switch (selectedHero) {
                    case HERO_ZARYA:
                        if (!activeAction1 && !activeAction2) {  // can only change mod state if no action
                            if (record->event.pressed) {
                                activeActionModifier = true;
                            } else {
                                activeActionModifier = false;
                            }
                        }
                        break;
            }
        }
    } else {
        activeAction1 = false;
        activeAction2 = false;
    }
    return true;
}

void housekeeping_task_user(void) {
    switch (selectedHero) {
        case HERO_LUCIO:
            //
            // Lucio Bunny Hop
            //
            if (activeAction1) {
                // Spam jump at fastest rate for server communication (16ms)
                if (timer_elapsed32(timerAction) > 16) {  // Left side static frame duration
                    tap_code(KC_SPACE);
                    timerAction = timer_read32();
                }
            }
            break;
        case HERO_MERCY:
            //
            // Mercy Super Jump
            //
            if (activeAction1) {
                // Wait until timer then release ctl shift
                if (timer_elapsed32(timerAction) > HERO_MERCY_HOLD_TIME) {
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_LCTRL);
                    activeAction1 = false;
                }
            }
            break;
        case HERO_REIN:
            //
            // Rein Shield Hop
            //

            // Step 0 Jump and Shield
            if (activeAction1) {
                if (stepAction == 0) {
                    tap_code(KC_SPACE);
                    mouseMove(0,0,2);
                    stepAction = 1;
                }
            }

            // Step 2 Release Shield
            if (stepAction == 1) {
                if (timer_elapsed32(timerAction) > 600) {
                    mouseMove(0,0,0);
                    stepAction = 2;
                }
            }

            // Step 3 Wait before next jump
            if (stepAction == 2) {
                if (timer_elapsed32(timerAction) > 700) {
                    timerAction = timer_read32();
                    stepAction = 0;
                }
            }

            //
            // Rein Corner Swing
            //
            if (activeAction2) {
                if (stepAction == 0) {
                    mouseMove(0,0,1);
                    stepAction = 1;
                }

                else if (stepAction <= REIN_SWING_STEPS) {
                    if (timer_elapsed32(timerAction) > 400) {
                        mouseMove(127,0,1);
                        stepAction++;
                    }
                }
                else if (stepAction <= REIN_SWING_STEPS * 2) {
                    if (timer_elapsed32(timerAction) > 500) {
                        mouseMove(-127,0,1);
                        stepAction++;
                    }
                }

                else if (stepAction <= REIN_SWING_STEPS * 3) {
                    if (timer_elapsed32(timerAction) > 400 + REIN_SWING_FULL_CYCLE_TIME / 2) {
                        mouseMove(-127,0,1);
                        stepAction++;
                    }
                }
                else if (stepAction <= REIN_SWING_STEPS * 4) {
                    if (timer_elapsed32(timerAction) > 500 + REIN_SWING_FULL_CYCLE_TIME / 2) {
                        mouseMove(127,0,1);
                        stepAction++;
                    }
                }
                else if (timer_elapsed32(timerAction) > REIN_SWING_FULL_CYCLE_TIME) {
                    timerAction = timer_read32();
                    stepAction = 0;
                }
            }
            break;
        case HERO_ZARYA:
            //
            // Zarya Single Rocket Jump
            //
            if (activeAction1) {
                // Step 0: Run Backwards if modifer
                if (stepAction == 1) {
                    if (activeActionModifier) {
                        register_code(KC_S);
                        if (timer_elapsed32(timerActionFromStart) > HERO_ZARYA_ROCKET_RUNNING_TIME) {
                            unregister_code(KC_S);
                            register_code(KC_W);
                            stepAction++;
                        }
                    } else {
                        stepAction++; // Skip if no modifiers
                    }
                // Step 1: Look at the floor
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 1) {
                    mouseMove(0, 127, 0);

                    // Keep looking down until last frame.
                    // If on late frame, wait until timer before final increment
                    if (stepAction < HERO_ZARYA_STEPS_MOVEDOWN1 + 1) {
                        stepAction++;
                    } else {  // on last frame of step
                        // If 2x running time (we already ran backward)
                        if (timer_elapsed32(timerActionFromStart) > (2 * HERO_ZARYA_ROCKET_RUNNING_TIME)-HERO_ZARYA_ROCKET_MOUSE_CLICK_TIME-HERO_ZARYA_ROCKET_HOLD_TIME) {
                            stepAction++;
                        }
                    }

                // Step 2: Rocket comes out here
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 2) {
                    mouseMove(0, 0, 2);
                    timerAction = timer_read32();
                    stepAction++;
                // Step 3: Mouse up 30ms later
                //         Keep looking down until mouse up
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 3) {
                    mouseMove(0, 127, 0);

                    if (timer_elapsed32(timerAction) > HERO_ZARYA_ROCKET_MOUSE_CLICK_TIME) {
                        mouseMove(0, 0, 0);
                        timerAction = timer_read32();
                        stepAction++;
                    }
                // Step 4: Jump HERO_ZARYA_ROCKET_HOLD_TIME late
                //         Keep looking down until jump
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 4) {
                    mouseMove(0, 127, 0);
                    if (timer_elapsed32(timerAction) > HERO_ZARYA_ROCKET_HOLD_TIME) {
                        tap_code(KC_SPACE);
                        stepAction++;
                    }
                // Step 5: Reset to horizon
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + HERO_ZARYA_STEPS_MOVEUP1 + 4) {
                    mouseMove(0, -127, 0);
                    stepAction++;
                } else {
                    activeAction1 = false;
                    activeActionModifier = false;
                }
            //
            // Zarya Single Rocket Jump
            //
            } else if (activeAction2) {
                // Step 1: Look at the sky
                if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1) {
                    mouseMove(0, -127, 0);
                    stepAction++;
                // Step 2: Rocket comes out here
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 1) {
                    mouseMove(0, 0, 2);
                    timerAction = timer_read32();
                    stepAction++;
                // Step 3: Mouse up some time later
                //         Keep looking up until mouse up
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + 2) {
                    mouseMove(0, -127, 0);
                    if (timer_elapsed32(timerAction) > HERO_ZARYA_ROCKET_MOUSE_CLICK_TIME) {
                        mouseMove(0, 0, 0);
                        timerAction = timer_read32();
                        stepAction++;
                    }
                // Step 4: Reset to horizon
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + HERO_ZARYA_STEPS_MOVEUP1 + 3) {
                    mouseMove(0, 127, 0);
                    stepAction++;
                // Step 5: Wait 5 sec
                } else if (stepAction <= HERO_ZARYA_STEPS_MOVEDOWN1 + HERO_ZARYA_STEPS_MOVEUP1 + 4) {
                    if (!activeActionModifier) {
                        if (timer_elapsed32(timerAction) > HERO_ZARYA_DOUBLE_ROCKET_HOLD_TIME) stepAction++;
                    } else {
                        if (timer_elapsed32(timerAction) > HERO_ZARYA_DOUBLE_ROCKET_HOLD_TIME_RUNNING) stepAction++;
                    }
                } else {
                    activeAction2 = false;
                    stepAction = 0;
                    if (activeActionModifier) timerActionFromStart = timer_read32();
                    activeAction1 = true;
                }
            }
            break;
        case HERO_ASHE:
            //
            // Shotgun Jump Forward
            //
            if (activeAction1) {
                if (stepAction <= HERO_ASHE_STEPS_BEFORE_FIRING_SHOTGUN) {
                    mouseMove(127,0,0);
                    stepAction++;
                }
                else if (stepAction <= 1 + HERO_ASHE_STEPS_BEFORE_FIRING_SHOTGUN) {
                    tap_code(KC_LSHIFT);
                    stepAction++;
                }
                else if (stepAction <= 1 + HORIZONTAL_360_STEPS) {
                    mouseMove(127,0,0);
                    stepAction++;
                }
                else {
                    timerAction = timer_read32();
                    stepAction = 0;
                    activeAction1 = false;
                }
            }
            break;


    }
}

