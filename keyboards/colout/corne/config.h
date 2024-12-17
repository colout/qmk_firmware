
// I2C Pins
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

#define SERIAL_USART_SPEED 57600 // halves keep disconnecdting. lower baud might be more stable until I find the hardware problem
// | Speed | Bitbang                    | Half-duplex and Full-duplex |
// | ----- | -------------------------- | --------------------------- |
// | `0`   | 189000 baud (experimental) | 460800 baud                 |
// | `1`   | 137000 baud (default)      | 230400 baud (default)       |
// | `2`   | 75000 baud                 | 115200 baud                 |
// | `3`   | 39000 baud                 | 57600 baud                  |
// | `4`   | 26000 baud                 | 38400 baud                  |
// | `5`   | 20000 baud                 | 19200 baud                  |


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_SHORT 170
#define ACHORDIAN_TIMEOUT 800
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// rgb
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
