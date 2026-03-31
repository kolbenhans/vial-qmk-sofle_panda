#include "custom_lighting.h"

// Predefined LED Groups for easy lightning if wanted
// LEFT
const uint8_t PROGMEM left_row_1[] = {11, 12, 21, 22, 31, 32}; // Number row
const uint8_t PROGMEM left_thumbs[] = {7, 16, 17, 26, 27, 36}; // Thumbs / Bottom row
const uint8_t PROGMEM left_outer_mod[] = {11, 10, 9, 8, 7};    // Left edge

// RIGHT
const uint8_t PROGMEM right_row_1[] = {47, 48, 57, 58, 67, 68}; // Top row (right to left)
const uint8_t PROGMEM right_thumbs[] = {43, 52, 53, 62, 63, 36}; // Bottom row / Thumbs (right to left)
const uint8_t PROGMEM right_outer_mod[] = {47, 46, 45, 44, 43};  // Far right outer (top to bottom)
const uint8_t PROGMEM right_inner_mod[] = {68, 69, 70, 71, 36};  // Far left inner / Potentiometer (top to bottom)
const uint8_t PROGMEM right_numpad[] = {
    53, // 0
    64, 61, 54, // 1, 2, 3
    65, 60, 55, // 4, 5, 6
    66, 59, 56  // 7, 8, 9
};

// make sure all leds get set correctly
void set_led_safe(uint8_t id, uint8_t r, uint8_t g, uint8_t b, uint8_t min, uint8_t max) {
    if (id >= min && id <= max) {
        rgb_matrix_set_color(id, r, g, b);
    }
}

// cutsom lightning by Layers
void apply_custom_lighting(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    if (layer > 0) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, 0, 0, 0); 
        }
    }

    switch(layer) {
        case _GAMING: // 4
            set_led_safe(9,  255, 165, 0,   led_min, led_max);
            set_led_safe(10, 0,   255, 0,   led_min, led_max);
            set_led_safe(19, 255, 0,   0,   led_min, led_max);
            set_led_safe(20, 255, 255, 255, led_min, led_max);
            set_led_safe(23, 255, 0,   0,   led_min, led_max);
            set_led_safe(24, 255, 0,   0,   led_min, led_max);
            set_led_safe(29, 255, 0,   0,   led_min, led_max);
            set_led_safe(30, 255, 255, 255, led_min, led_max);
            set_led_safe(43, 0,   128, 128, led_min, led_max);
            break;
        case _AMBIENT: // 3
            set_led_safe(0,  RGB_BLUE,   led_min, led_max);
            set_led_safe(69, RGB_RED,    led_min, led_max);
            set_led_safe(70, RGB_GREEN,  led_min, led_max);
            set_led_safe(71, RGB_YELLOW, led_min, led_max);
            break;
        case _NUMPAD: // 2
            for (uint8_t i = 0; i < 10; i++) {
                set_led_safe(pgm_read_byte(&right_numpad[i]), RGB_BLUE, led_min, led_max);
            }
            set_led_safe(60, RGB_ORANGE, led_min, led_max);
            set_led_safe(69, RGB_GREEN,   led_min, led_max);
            set_led_safe(70, RGB_RED,   led_min, led_max);
            set_led_safe(49, RGB_GREEN,   led_min, led_max);
            set_led_safe(50, RGB_RED,   led_min, led_max);
            break;
        case _RAISE: // 1
            set_led_safe(34, RGB_PURPLE, led_min, led_max);
            set_led_safe(35, RGB_ORANGE, led_min, led_max);
            set_led_safe(70, RGB_RED,    led_min, led_max);
            set_led_safe(65, RGB_BLUE,   led_min, led_max);
            set_led_safe(60, RGB_GREEN,  led_min, led_max);
            set_led_safe(55, RGB_ORANGE, led_min, led_max);
            break;
    }
}