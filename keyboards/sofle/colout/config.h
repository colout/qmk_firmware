#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFC32
#define PRODUCT_ID      0x0288
#define DEVICE_VER      0x0001
#define MANUFACTURER    Colout
#define PRODUCT         Sofle Colout


/*
//
// Pin Maps
//

Left Side
---------
D3 GP0
D2 GP1
D1 GP2
D0 GP3
D4 GP4
C6 GP5
D7 GP6
E6 GP7
B4 GP8
B5 GP9

Right Side
----------
F4 GP29
F5 GP28
F6 GP27
F7 GP26
B1 GP22
B3 GP20
B2 GP23
B6 GP21
*/


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { GP5, GP6, GP7, GP8, GP9 }
#define MATRIX_COL_PINS { GP27, GP26, GP22, GP20, GP23, GP21 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 100
#define DEBOUNCE 5

/* encoder support */
#define ENCODERS_PAD_A { GP28 }
#define ENCODERS_PAD_B { GP29 }
#define ENCODERS_PAD_A_RIGHT { GP29 }
#define ENCODERS_PAD_B_RIGHT { GP28 }
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10

/* communication between sides */
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
//#define SERIAL_USART_TX_PIN GP1
#define SOFT_SERIAL_PIN GP1

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
