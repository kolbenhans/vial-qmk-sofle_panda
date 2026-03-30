#include QMK_KEYBOARD_H
#include "sofle_panda.h"
//#include "oled.c" // We include the manufacturer's display logic
// #include "display_oled.c"  // Mechaboards OLED Display

#ifdef OLED_ENABLE
    #if defined(OLED_EFFECT_SOUNDMONSTER)
    #include "oled/soundmonster.c"
    #elif defined(OLED_EFFECT_LUNA)
    #include "oled/luna.c"
    #elif defined(OLED_EFFECT_BONGOCAT)
    #include "oled/bongocat.c"
    #elif defined(OLED_EFFECT_SNAKEY)
    #include "oled/snakey.c"
    #elif defined(OLED_EFFECT_OLED)
    #include "oled/oled.c"
    #elif defined(OLED_EFFECT_PANDA)
    #include "oled/pandakb.c"
    #elif defined(OLED_EFFECT_MECHABOARDS)
    #include "oled/mechaboards.c"    
    #endif
#endif

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTZ = 0,
    _RAISE,
    _NUMPAD,
    _AMBIENT,
    _GAMING
};

enum custom_keycodes {
    KC_QWERTZ = SAFE_RANGE,
    KC_RAISE,
    KC_NUMPAD,
    KC_AMBIENT,
    KC_GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, MO(3), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RALT(KC_NUBS), KC_NO, KC_LGUI, MO(2), MO(1), KC_SPC, KC_ENT, KC_BSPC, KC_DEL, KC_NO, TG(4)),
    [_RAISE] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TAB, KC_GRV, KC_NO, LGUI(KC_LCTL), KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, RALT(KC_MINS), KC_F12, RALT(KC_7), LGUI(KC_SLSH), LGUI(KC_N), LCS(KC_LGUI), LGUI(KC_LSFT), LCS(KC_TAB), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LSFT(KC_8), RALT(KC_8), RALT(KC_0), RALT(KC_NUBS), RSFT(KC_RBRC), LSFT(KC_EQL), KC_EQL, LCTL(KC_TAB), KC_TRNS, KC_TRNS, KC_NUBS, LCTL(KC_LEFT), LCTL(KC_RGHT), LSFT(KC_NUBS), LSFT(KC_9), RALT(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_NO),
    [_NUMPAD] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_NO), KC_NO, KC_NUM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_GRV, KC_NO, RALT(KC_E), KC_NO, KC_PAUS, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_PAST, KC_NO, KC_NO, KC_NO, LSFT(KC_TAB), KC_NO, KC_NO, KC_PSCR, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCA(KC_DEL), KC_NO, KC_NO, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PDOT, LSFT(KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS, KC_NO),
    [_AMBIENT] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_SATU, RM_HUEU, RM_NEXT, RM_SPDU, RM_VALU, KC_MUTE, MS_BTN1, MS_UP, MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, RM_SATD, RM_HUED, RM_PREV, RM_SPDD, RM_VALD, KC_VOLU, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, UG_TOGG, KC_TRNS, KC_TRNS, KC_VOLD, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_GAMING] = LAYOUT(KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), RGUI(KC_6), KC_LALT, KC_H, KC_Q, KC_W, KC_E, KC_R, LCTL(KC_W), LCTL(KC_T), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_LSFT, KC_A, KC_S, KC_D, KC_F, LCTL(KC_TAB), KC_WBAK, KC_WFWD, LCS(KC_TAB), KC_TRNS, KC_TRNS, KC_LGUI, KC_LCTL, KC_Z, KC_X, KC_C, KC_G, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_NO, KC_Y, KC_M, KC_B, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(4))
};

const uint8_t PROGMEM left_row_1[] = {11, 12, 21, 22, 31, 32}; // Number row
const uint8_t PROGMEM left_thumbs[] = {7, 16, 17, 26, 27, 36}; // Thumbs / Bottom row
const uint8_t PROGMEM left_outer_mod[] = {11, 10, 9, 8, 7};    // Left edge

// Helper lists for the right side (Physical positions)
const uint8_t PROGMEM right_outer_mod[] = {47, 46, 45, 44, 43};  // Far right outer (top to bottom)
const uint8_t PROGMEM right_inner_mod[] = {68, 69, 70, 71, 36};  // Far left inner / Potentiometer (top to bottom)
const uint8_t PROGMEM right_row_1[] = {47, 48, 57, 58, 67, 68}; // Top row (right to left)
const uint8_t PROGMEM right_thumbs[] = {43, 52, 53, 62, 63, 36}; // Bottom row / Thumbs (right to left)
const uint8_t PROGMEM right_numpad[] = {
    53, // 0
    64, 61, 54, // 1, 2, 3
    65, 60, 55, // 4, 5, 6
    66, 59, 56  // 7, 8, 9
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef KEYBOARD_PET
    if (record->event.pressed) {
        oled_timer = timer_read32();
        // Missing WPM update?
        // update_wpm(keycode);
    }
#endif
    switch (keycode) {
        case KC_QWERTZ:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_RAISE, _NUMPAD, _AMBIENT);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_RAISE, _NUMPAD, _AMBIENT);
            }
            return false;
        case KC_NUMPAD:
            if (record->event.pressed) {
                layer_on(_NUMPAD);
                update_tri_layer(_RAISE, _NUMPAD, _AMBIENT);
            } else {
                layer_off(_NUMPAD);
                update_tri_layer(_RAISE, _NUMPAD, _AMBIENT);
            }
            return false;
        case KC_AMBIENT:
            if (record->event.pressed) {
                layer_on(_AMBIENT);
            } else {
                layer_off(_AMBIENT);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTZ] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NUMPAD] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_AMBIENT] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_GAMING] = { ENCODER_CCW_CW(RM_VALU, RM_VALD), ENCODER_CCW_CW(RM_NEXT, RM_PREV) },
};
#endif

void set_led_safe(uint8_t id, uint8_t r, uint8_t g, uint8_t b, uint8_t min, uint8_t max) {
    if (id >= min && id <= max) {
        rgb_matrix_set_color(id, r, g, b);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    if (layer > 0) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, 0, 0, 0); 
        }
    }

    switch(layer) {
        case 4:
            set_led_safe(9,  255, 165, 0,   led_min, led_max); // Orange
            set_led_safe(10, 0,   255, 0,   led_min, led_max); // Green
            set_led_safe(19, 255, 0,   0,   led_min, led_max); // Red
            set_led_safe(20, 255, 255, 255, led_min, led_max); // White
            set_led_safe(23, 255, 0,   0,   led_min, led_max); // Red
            set_led_safe(24, 255, 0,   0,   led_min, led_max); // Red
            set_led_safe(29, 255, 0,   0,   led_min, led_max); // Red
            set_led_safe(30, 255, 255, 255, led_min, led_max); // White
            set_led_safe(43, 0,   128, 128, led_min, led_max); // Teal
            break;

        case 3:
            set_led_safe(0,  RGB_BLUE,   led_min, led_max);
            set_led_safe(69, RGB_RED,    led_min, led_max);
            set_led_safe(70, RGB_GREEN,  led_min, led_max);
            set_led_safe(71, RGB_YELLOW, led_min, led_max);
            break;

        case 2:
            set_led_safe(0,  RGB_MAGENTA, led_min, led_max);
            set_led_safe(68, RGB_TEAL,    led_min, led_max);            
            for (uint8_t i = 0; i < 10; i++) {
                set_led_safe(pgm_read_byte(&right_numpad[i]), RGB_BLUE, led_min, led_max);
            }
            set_led_safe(60, RGB_ORANGE, led_min, led_max);
            set_led_safe(69, RGB_GREEN,   led_min, led_max);
            set_led_safe(70, RGB_RED,   led_min, led_max);
            set_led_safe(49, RGB_GREEN,   led_min, led_max);
            set_led_safe(50, RGB_RED,   led_min, led_max);
            set_led_safe(36, RGB_BLUE,   led_min, led_max);
            break;

        case 1:
            set_led_safe(0,  RGB_GREEN,  led_min, led_max);
            set_led_safe(34, RGB_PURPLE, led_min, led_max);
            set_led_safe(35, RGB_ORANGE, led_min, led_max);
            set_led_safe(70, RGB_RED,    led_min, led_max);
            set_led_safe(65, RGB_BLUE,   led_min, led_max);
            set_led_safe(60, RGB_GREEN,  led_min, led_max);
            set_led_safe(55, RGB_ORANGE, led_min, led_max);
            break;
    }
    return false;
}