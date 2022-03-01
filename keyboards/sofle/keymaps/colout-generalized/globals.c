
enum my_keycodes {
    KC_OVERWATCH_ACTION1 = 0x5dae, // 0x5daf
    KC_OVERWATCH_ACTION2, // 0x5dae
};

#define HERO_COUNT 4

#define HERO_NONE 0

#define HERO_LUCIO 1

#define HERO_MERCY 2
#define HERO_MERCY_HOLD_TIME 500

#define HERO_REIN 3
#define REIN_SWING_STEPS (120 / OVERWATCH_MOUSE_SENSITIVITY)
// From beginning to end.  Measured 50 swings and averaged. 
#define REIN_SWING_FULL_CYCLE_TIME 1842

#define HERO_ZARYA 4
#define OVERWATCH_MOUSE_SENSITIVITY 1.4
#define HERO_ZARYA_STEPS_MOVEDOWN1 (156 / OVERWATCH_MOUSE_SENSITIVITY)
#define HERO_ZARYA_STEPS_MOVEUP1 (105 / OVERWATCH_MOUSE_SENSITIVITY)



// MS Timing for each phase
#define HERO_ZARYA_ROCKET_HOLD_TIME 20
#define HERO_ZARYA_DOUBLE_ROCKET_HOLD_TIME 4700
#define HERO_ZARYA_ROCKET_MOUSE_CLICK_TIME 50

// For Running Jump
#define HERO_ZARYA_ROCKET_RUNNING_TIME 75
const int16_t HERO_ZARYA_DOUBLE_ROCKET_HOLD_TIME_RUNNING = (HERO_ZARYA_ROCKET_RUNNING_TIME/4)+ HERO_ZARYA_DOUBLE_ROCKET_HOLD_TIME - (2*HERO_ZARYA_ROCKET_RUNNING_TIME)+HERO_ZARYA_ROCKET_MOUSE_CLICK_TIME+HERO_ZARYA_ROCKET_HOLD_TIME;


char overwatchTxt[14] = {0};
int8_t selectedHero = HERO_NONE;
bool isMacMode = false;
