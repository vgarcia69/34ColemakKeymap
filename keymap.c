
#include QMK_KEYBOARD_H
#include "keymapconfig.h"

// ============================================================================
// COMBO DEFINITIONS
// ============================================================================

// Combo key sequences
const uint16_t PROGMEM _st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM _fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM _lu_combo[] = {KC_L, KC_U, COMBO_END};

const uint16_t PROGMEM _56_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM _89_combo[] = {KC_8, KC_9, COMBO_END}; 

const uint16_t PROGMEM ASTRLPRN_combo[] = {KC_ASTR,   KC_LPRN,         COMBO_END};
const uint16_t PROGMEM HASHDLR_combo[]  = {KC_HASH,      KC_DLR,       COMBO_END};

// Combo associations
combo_t key_combos[] = {
    [ST_TAB]     = COMBO(_st_combo, KC_TAB),
    [FP_ESC]     = COMBO(_fp_combo, KC_ESC),
    [LU_CAPS]    = COMBO(_lu_combo, KC_CAPS),
    [_56]        = COMBO(_56_combo, KC_TAB),
    [_89]        = COMBO(_89_combo, KC_ESC),
    [ASTRLPRN]   = COMBO(ASTRLPRN_combo, KC_TAB),
    [HASHDLR]    = COMBO(HASHDLR_combo, KC_ESC),
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
     * │  Z  │CTL/X│GUI/C│ALT/D│  V  │       │  K  │ALT/H│GUI/,│CTL/.│  ;  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ SPC │SHIFT│       │NUM  │ENTER|
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                  /**/        KC_J,         KC_L,         KC_U,            KC_Y,           KC_BSPC,
        KC_A,         KC_R,         KC_S,         KC_T,         KC_G,                  /**/        KC_M,         KC_N,         KC_E,            KC_I,           KC_O,
        KC_Z,         LCTL_T(KC_X), LGUI_T(KC_C), LALT_T(KC_D), KC_V,                  /**/        KC_K,         RALT_T(KC_H), RGUI_T(KC_COMM), RCTL_T(KC_DOT), KC_SCLN,
                                    XXX,          LT(_FUNCTION, KC_SPC), KC_LSFT,      /**/        TO(_MEDIA), KC_ENT,       XXX
    ),

    /*
     * Layer 1: Numbers and Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  ?  │  7  │  8  │  9  │  ~  │       |MPRV │MPLY │MNXT │ --- |BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  /  │  4  │  5  │  6  │  `  │       | MUTE│VOLD │VOLU | --- | DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  0  │  1  │  2  │  3  │ --- │       │ --- │ --- │ --- │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │BASE │ENTER│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
        RSFT(KC_SLSH),KC_7,         KC_8,         KC_9,         KC_TILD,   /**/        KC_MPRV,      KC_MPLY,      KC_MNXT,      XXX,          KC_BSPC,
        KC_SLSH,      KC_4,         KC_5,         KC_6,         KC_GRV,    /**/        KC_MUTE,      KC_VOLD,      KC_VOLU,      XXX,          KC_DEL,
        KC_0,         KC_1,         KC_2,         KC_3,         XXX,       /**/        XXX,          KC_RALT,      KC_RGUI,      KC_RCTL,      XXX,     
                                    XXX,          KC_TRNS,      TO(_BASE), /**/        TO(_BASE), KC_ENT,       XXX
    ),


    /*
     * Layer 2: Media and Advanced Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  !  │  @  │  #  │  $  │  %  │       │  _  │  +  │  "  │  |  │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ^  │  &  │  *  |  (  |  )  │       │  -  │  =  │  '  │  \  │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │  [  │  {  │  }  │  ]  │       │ --- │  /  │  <  │  >  │  :  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│MEDIA│                  
     *                   └─────┴─────┘       └─────┴─────┘                  
     */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,  /**/        KC_UNDS,      KC_PLUS,      KC_DQUO,      KC_PIPE,      KC_BSPC,
        KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,  /**/        KC_MINS,      KC_EQL,       KC_QUOT,      KC_BSLS,      KC_DEL,
        XXX,          KC_LBRC,      KC_LCBR,      KC_RCBR,      KC_RBRC,  /**/        XXX,          KC_SLSH,      RSFT(KC_COMM),RSFT(KC_DOT), RSFT(KC_SCLN), 
                                    XXX,          KC_TRNS,      TO(_BASE),/**/        TO(_NUMBERS),    KC_ENT,       XXX
    ),

    /*
     * Layer 3: Function Keys and Navigation
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ --- │ F1  │ F2  │ F3  │ F4  │       │PSCR │PGDN │PGUP │ --- │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F5  │ F6  │ F7  │ F8  │       | --- │LEFT │DOWN │ UP  │RGHT │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F9  │F10  │F11  │F12  │       │HOME │ INS │ END │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│TRNS │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        XXX,          KC_F1,        KC_F2,        KC_F3,        KC_F4,      /**/    XXX,          KC_PSCR,      KC_PGDN,      KC_PGUP,      KC_BSPC,
        XXX,          KC_F5,        KC_F6,        KC_F7,        KC_F8,      /**/    XXX,          KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,
        XXX,          KC_F9,        KC_F10,       KC_F11,       KC_F12,     /**/    XXX,          KC_HOME,      KC_INS,       KC_END,       XXX,
                                    XXX,          KC_TRNS,      TO(_BASE),  /**/    KC_TRNS,      KC_ENT,       XXX
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
