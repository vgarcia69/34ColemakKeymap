/*
COLEMAK LAYERED KEYBOARD CONFIGURATION
US English Colemak layout.
34 Keys keymap.
*/

#pragma once

#include QMK_KEYBOARD_H

// ============================================================================
// LAYER DEFINITIONS
// ============================================================================
enum layers {
    _BASE = 0,     // Colemak base layer
    _NUMBERS,      // Numbers and basic symbols
    _MEDIA,        // Media controls and advanced symbols
    _FUNCTION,     // Function keys and navigation
};

// ============================================================================
// COMBO DEFINITIONS
// ============================================================================
enum combo_events {
    ST_TAB,       // S+T = Escape
    FP_ESC,      // F+P = Caps Lock
    _56,          // 5+6 combo
    _89,          // 8+9 combo
    ASTRLPRN,     // *+(
    HASHDLR,      // #+$ combo
    COMBO_LENGTH
};

// ============================================================================
// CONVENIENCE DEFINES
// ============================================================================
#define XXX KC_NO           // Empty key
#define ___ KC_TRNS         // Transparent key

// ============================================================================
// RGB CONFIGURATION
// ============================================================================
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
