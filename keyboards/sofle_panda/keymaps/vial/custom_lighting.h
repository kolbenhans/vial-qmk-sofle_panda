#pragma once
#include "quantum.h"

// 1. Layer Definitionen (Damit beide .c Dateien die gleichen Namen nutzen)
enum sofle_layers {
    _QWERTZ = 0,
    _RAISE,
    _NUMPAD,
    _AMBIENT,
    _GAMING
};

// delare of custom functions
void set_led_safe(uint8_t id, uint8_t r, uint8_t g, uint8_t b, uint8_t min, uint8_t max);
void apply_custom_lighting(uint8_t led_min, uint8_t led_max);

// left
extern const uint8_t PROGMEM left_row_1[];
extern const uint8_t PROGMEM left_thumbs[];
extern const uint8_t PROGMEM left_outer_mod[];

// right
extern const uint8_t PROGMEM right_row_1[];
extern const uint8_t PROGMEM right_thumbs[];
extern const uint8_t PROGMEM right_outer_mod[];
extern const uint8_t PROGMEM right_inner_mod[];
extern const uint8_t PROGMEM right_numpad[];