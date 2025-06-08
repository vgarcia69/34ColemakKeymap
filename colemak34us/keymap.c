
#include QMK_KEYBOARD_H
#include "keymapconfig.h"
// ============================================================================
// COMBO DEFINITIONS
// ============================================================================

// Combo key sequences
const uint16_t PROGMEM _st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM _cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM _fp_combo[] = {KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM _56_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM _23_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM _89_combo[] = {KC_8, KC_9, COMBO_END}; 

const uint16_t PROGMEM ASTRLPRN_combo[] = {KC_ASTR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM CBR_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM HASHDLR_combo[] = {KC_HASH, KC_DLR, COMBO_END};

// Combo associations
combo_t key_combos[] = {
    [ST_ESC]     = COMBO(_st_combo, KC_ESC),
    [CD_TAB]     = COMBO(_cd_combo, KC_TAB),
    [FP_CAPS]    = COMBO(_fp_combo, KC_CAPS),
    [_56]        = COMBO(_56_combo, KC_ESC),
    [_23]        = COMBO(_23_combo, KC_TAB),
    [_89]        = COMBO(_89_combo, KC_CAPS),
    [ASTRLPRN]   = COMBO(ASTRLPRN_combo, KC_ESC),
    [CBR]        = COMBO(CBR_combo, KC_TAB),
    [HASHDLR]    = COMBO(HASHDLR_combo, KC_CAPS),
};

// ============================================================================
// KEYMAP LAYOUT
// ============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /*
     * Layer 0: Base (Colemak)
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  Q  │  W  │  F  │  P  │  B  │       │  J  │  L  │  U  │  Y  │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  A  │  R  │  S  │  T  │  G  │       │  M  │  N  │  E  │  I  │  O  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  Z  │CTL/X│GUI/C│ALT/D│  V  │       │  K  │ALT/H│GUI/,│CTL/.│  /  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │SHIFT│       │ENTER│NUM  │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                  /**/        KC_J,         KC_L,         KC_U,            KC_Y,           KC_BSPC,
        KC_A,         KC_R,         KC_S,         KC_T,         KC_G,                  /**/        KC_M,         KC_N,         KC_E,            KC_I,           KC_O,
        KC_Z,         LCTL_T(KC_X), LGUI_T(KC_C), LALT_T(KC_D), KC_V,                  /**/        KC_K,         RALT_T(KC_H), RGUI_T(KC_COMM), RCTL_T(KC_DOT), KC_SLSH,
                                    XXX,          KC_LSFT,      LT(_FUNCTION, KC_SPC), /**/        KC_ENT,       TO(_NUMBERS), XXX
    ),

    /*
     * Layer 1: Numbers and Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  :  │  7  │  8  │  9  │  ~  │       │  _  │  +  │  "  │  |  │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ;  │  4  │  5  │  6  │  `  │       │  -  │  =  │  '  │  \  │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  0  │  1  │  2  │  3  │ --- │       │ --- │RALT │RGUI │RCTL │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│MEDIA│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
        KC_COLN,      KC_7,         KC_8,         KC_9,         KC_TILD, /**/        KC_UNDS,      KC_PLUS,      KC_DQUO,      KC_PIPE,      KC_BSPC,
        KC_SCLN,      KC_4,         KC_5,         KC_6,         KC_GRV,  /**/        KC_MINS,      KC_EQL,       KC_QUOT,      KC_BSLS,      KC_DEL,
        KC_0,         KC_1,         KC_2,         KC_3,         XXX,     /**/        XXX,          KC_RALT,      KC_RGUI,      KC_RCTL,      XXX,
                                    XXX,          TO(_BASE),    KC_TRNS, /**/        KC_ENT,       TO(_MEDIA),   XXX
    ),


    /*
     * Layer 2: Media and Advanced Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  !  │  @  │  #  │  $  │  %  │       |MPRV │MPLY │MNXT │ --- |BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ^  │  &  │  *  |  (  |  )  │       | MUTE│VOLD │VOLU | --- | DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │  [  │  {  │  }  │  ]  │       │ --- │ --- │ --- │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│ACCNT│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, /**/        KC_MPRV,      KC_MPLY,      KC_MNXT,      XXX,          KC_BSPC,
        KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN, /**/        KC_MUTE,      KC_VOLD,      KC_VOLU,      XXX,          KC_DEL,
        XXX,          KC_LBRC,      KC_LCBR,      KC_RCBR,      KC_RBRC, /**/        XXX,          XXX,          XXX,          XXX,          XXX,
                                    XXX,          TO(_BASE),    KC_TRNS, /**/        KC_ENT,       TO(_ACCENTS), XXX
    ),

    /*
     * Layer 3: Function Keys and Navigation
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ ESC │ F1  │ F2  │ F3  │ F4  │       │PSCR │PGDN │PGUP │ --- │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ TAB │ F5  │ F6  │ F7  │ F8  │       │LEFT │DOWN │ UP  │RGHT │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F9  │F10  │F11  │F12  │       │HOME │ INS │ END │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│TRNS │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        XXX,          KC_F1,        KC_F2,        KC_F3,        KC_F4,         KC_PSCR,      KC_PGDN,      KC_PGUP,      XXX,          KC_BSPC,
        XXX,          KC_F5,        KC_F6,        KC_F7,        KC_F8,         KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      KC_DEL,
        XXX,          KC_F9,        KC_F10,       KC_F11,       KC_F12,        KC_HOME,      KC_INS,       KC_END,       XXX,          XXX,
                                    XXX,          TO(_BASE),    KC_TRNS,       KC_ENT,       KC_TRNS,      XXX
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif