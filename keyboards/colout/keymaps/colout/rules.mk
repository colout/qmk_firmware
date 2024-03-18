
MOUSEKEY_ENABLE = yes    # Mouse keys
OLED_ENABLE     = yes
LTO_ENABLE      = yes

EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = no # Auto Shift

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_KEYPRESSES = yes
RGB_MATRIX_FRAMEBUFFER_EFFECTS = yes

SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

CAPS_WORD_ENABLE = yes

SRC += features/achordion.c
