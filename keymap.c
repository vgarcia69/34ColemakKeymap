
#include QMK_KEYBOARD_H
#include "keymapconfig.h"

// ============================================================================
// COMBO DEFINITIONS
// ============================================================================

// Combo key sequences
const uint16_t PROGMEM _st_combo[] = {LGUI_T(KC_S), LALT_T(KC_T), COMBO_END};
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
     * │  Q  │  W  │  F  │  P  │  B  │       │  J  │  L  │  U  │  Y  │  ;  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  A  │CTL/R│GUI/S│ALT/T│ M/G │       │ M/M │ALT/N│GUI/E│CTL/I│  O  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  Z  │  X  │  C  │  D  │  V  │       │  K  │  H  │  ,  │  .  │  /  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │F/SPC│SHIFT│       │N/ENT|BSPC │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                  /**/        KC_J,              KC_L,         KC_U,            KC_Y,           KC_SCLN,
        KC_A,         LCTL_T(KC_R), LGUI_T(KC_S), LALT_T(KC_T), LT(_MEDIA, KC_G),      /**/        LT(_MEDIA, KC_M),  RALT_T(KC_N), RGUI_T(KC_E),    RCTL_T(KC_I),   KC_O,
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                  /**/        KC_K,              KC_H,         KC_COMM,         KC_DOT,         KC_SLSH,
                                    XXX,          LT(_FUNCTION, KC_SPC), KC_LSFT,      /**/        LT(_NUMBERS, KC_ENT),KC_BSPC,    XXX
    ),

    /*
     * Layer 1: Numbers and Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ --- │  7  │  8  │  9  │  ~  │       |MPRV │MPLY │MNXT │ --- | --- │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │  4  │  5  │  6  │  `  │       | MUTE│VOLD │VOLU | --- | DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  0  │  1  │  2  │  3  │ --- │       │ --- │ --- │ --- │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ SPC │SHIFT│       │ENTER│BSPC │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
        XXX,          KC_7,         KC_8,         KC_9,         KC_TILD,   /**/        KC_MPRV,      KC_MPLY,      KC_MNXT,      XXX,          XXX,
        XXX,          KC_4,         KC_5,         KC_6,         KC_GRV,    /**/        KC_MUTE,      KC_VOLD,      KC_VOLU,      XXX,          KC_DEL,
        KC_0,         KC_1,         KC_2,         KC_3,         XXX,       /**/        XXX,          XXX,          XXX,          XXX,          XXX,
                                    XXX,          KC_TRNS,      KC_LSFT,   /**/        KC_ENTER,     KC_BSPC,      XXX
    ),

    /*
     * Layer 2: Media and Advanced Symbols
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  !  │  @  │  #  │  $  │  %  │       │  _  │  +  │  "  │  |  │  :  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ^  │  &  │  *  |  (  |  )  │       │  -  │  =  │  '  │  \  │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │  [  │  {  │  }  │  ]  │       │ --- │ --- │  <  │  >  │  ?  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ SPC │SHIFT│       │BSPC │ENTER│                  
     *                   └─────┴─────┘       └─────┴─────┘                  
     */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,  /**/        KC_UNDS,      KC_PLUS,      KC_DQUO,      KC_PIPE,      RSFT(KC_SCLN),
        KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,  /**/        KC_MINS,      KC_EQL,       KC_QUOT,      KC_BSLS,      KC_DEL,
        XXX,          KC_LBRC,      KC_LCBR,      KC_RCBR,      KC_RBRC,  /**/        XXX,          XXX,      RSFT(KC_COMM),RSFT(KC_DOT),     RSFT(KC_SLSH), 
                                    XXX,          KC_TRNS,      KC_LSFT,  /**/        KC_ENT,      KC_BSPC,       XXX
    ),

    /*
     * Layer 3: Function Keys and Navigation
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ --- │ F7  │ F8  │ F9  │ F10 │       │ --- |PSCR │PGDN │PGUP │ --- │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F4  │ F5  │ F6  │ F11 │       | --- │LEFT │DOWN │ UP  │RGHT │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F1  │ F2  │ F3  │ F12 │       │ --- |HOME │ INS │ END │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │     │LCTRL│       │ENTER│ BSPC│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        XXX,          KC_F7,        KC_F8,        KC_F9,        KC_F10,     /**/    XXX,          KC_PSCR,      KC_PGDN,      KC_PGUP,      XXX,
        XXX,          KC_F4,        KC_F5,        KC_F6,        KC_F11,     /**/    XXX,          KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,
        XXX,          KC_F1,        KC_F2,        KC_F3,        KC_F12,     /**/    XXX,          KC_HOME,      KC_INS,       KC_END,       XXX,
                                    XXX,          KC_TRNS,      KC_LCTL,   /**/     KC_ENT,       KC_BSPC,       XXX
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
