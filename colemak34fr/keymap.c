#include QMK_KEYBOARD_H
#include "keymapconfig.h"


// Combo key sequences
const uint16_t PROGMEM _st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM _fp_combo[] = {KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM _56_combo[] = {RSFT(KC_5), RSFT(KC_6), COMBO_END};
const uint16_t PROGMEM _89_combo[] = {RSFT(KC_8), RSFT(KC_9), COMBO_END}; 

const uint16_t PROGMEM ASTRLPRN_combo[] = {KC_QUOT,   KC_5,         COMBO_END};
const uint16_t PROGMEM HASHDLR_combo[]  = {KC_3,      KC_DLR,       COMBO_END};

// Combo associations
combo_t key_combos[] = {
    [ST_TAB]     = COMBO(_st_combo, KC_TAB),
    [FP_ESC]    = COMBO(_fp_combo, KC_ESC),
    [_56]        = COMBO(_56_combo, KC_TAB),
    [_89]        = COMBO(_89_combo, KC_ESC),
    [ASTRLPRN]   = COMBO(ASTRLPRN_combo, KC_TAB),
    [HASHDLR]    = COMBO(HASHDLR_combo, KC_ESC),
};

// Configuration Unicode pour les accents français

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /*
     * Layer 0: Base (Colemak pour AZERTY)
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  Q  |  W  │  F  │  P  │  B  │       │  J  │  L  │  U  │  Y  │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  A  │  R  │  S  │  T  │  G  │       │  M  │  N  │  E  │  I  │  O  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  Z  │CTL/X│GUI/C│ALT/D│  V  │       │  K  │ALT/H│GUI/,│CTL/.│  /  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ LSFT│SPC  │       │ENTER│NUM  │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_BASE] = LAYOUT_split_3x5_3(
        KC_A,         KC_Z,         KC_F,         KC_P,         KC_B,                  /**/        KC_J,         KC_L,         KC_U,            KC_Y,                  KC_BSPC,
        KC_Q,         KC_R,         KC_S,         KC_T,         KC_G,                  /**/        KC_SCLN,      KC_N,         KC_E,            KC_I,                  KC_O,
        KC_W,         LCTL_T(KC_X), LGUI_T(KC_C), LALT_T(KC_D), KC_V,                  /**/        KC_K,         RALT_T(KC_H), RGUI_T(KC_M),    RCTL_T(KC_COMM), RSFT(KC_DOT),
                                    XXX,          KC_LSFT,      LT(_FUNCTION, KC_SPC), /**/        KC_ENT,       TO(_NUMBERS), XXX
    ),

    /*
     * Layer 1: Numbers and Symbols (pour AZERTY)
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  :  │  7  │  8  │  9  │  ~  │       │  _  │  +  │  "  │  |  │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ;  │  4  │  5  │  6  │  `  │       │  -  │  =  │  '  │  \  │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  0  │  1  │  2  │  3  │ --- │       │ --- │     │  <  │  >  |  ?  │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│MEDIA│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
        KC_DOT,      RSFT(KC_7),    RSFT(KC_8),   RSFT(KC_9),   RALT(KC_2),    /**/        KC_8,         RSFT(KC_EQL), KC_3,         RALT(KC_6),   KC_BSPC,
        KC_COMM,     RSFT(KC_4),    RSFT(KC_5),   RSFT(KC_6),   RALT(KC_7),    /**/        KC_6,         KC_EQL,       KC_4,         RALT(KC_8),   KC_DEL,
        RSFT(KC_0),  RSFT(KC_1),    RSFT(KC_2),   RSFT(KC_3),   XXX,           /**/        XXX,          XXX,          KC_GRV,       RSFT(KC_GRV), RSFT(KC_M),
                                    XXX,          TO(_BASE),    KC_TRNS,       /**/        KC_ENT,       TO(_MEDIA),   XXX
    ),

    /*
     * Layer 2: Media and Advanced Symbols (pour AZERTY)
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  !  │  @  │  #  |  $  │  %  │       │MPRV │MPLY │MNXT │ --- │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  ^  │  &  │  *  │  (  │  )  │       │MUTE │VOLD │VOLU │ --- │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │  [  │  {  │  }  |  ]  │       | --- │ --- │ --- │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│ACCNT│
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_SLSH,      RALT(KC_0),   RALT(KC_3),   KC_RBRC,      RSFT(KC_QUOT), /**/        KC_MPRV,      KC_MPLY,      KC_MNXT,   XXX,          KC_BSPC,
        KC_LBRC,      KC_1,         KC_BSLS,      KC_5,         KC_MINS,       /**/        KC_MUTE,      KC_VOLD,      KC_VOLU,   XXX,          KC_DEL,
        XXX,          RALT(KC_5),   RALT(KC_4),   RALT(KC_EQL), RALT(KC_MINS), /**/        XXX,          XXX,          XXX,       XXX,          XXX,
                                    XXX,          TO(_BASE),    KC_TRNS,       /**/        KC_ENT,       TO(_ACCENTS), XXX
    ),

    /*
     * Layer 3: Function Keys and Navigation (identique)
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ --- │ F1  │ F2  │ F3  │ F4  │       │PSCR │PGDN │PGUP │ --- │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F5  │ F6  │ F7  │ F8  │       │LEFT │DOWN │ UP  │RGHT │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ F9  │F10  │F11  │F12  │       │HOME │ INS │ END │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│TRNS │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        XXX   ,       KC_F1,        KC_F2,        KC_F3,        KC_F4,   /**/        KC_PSCR,      KC_PGDN,      KC_PGUP,      XXX,          KC_BSPC,
        XXX   ,       KC_F5,        KC_F6,        KC_F7,        KC_F8,   /**/        KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      KC_DEL,
        XXX,          KC_F9,        KC_F10,       KC_F11,       KC_F12,  /**/        KC_HOME,      KC_INS,       KC_END,       XXX,          XXX,
                                    XXX,          TO(_BASE),    KC_TRNS, /**/        KC_ENT,       KC_TRNS,      XXX
    ),

    /*
     * Layer 4: Accents et caractères spéciaux français
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │     │     │     |     │     │       │ --- │ --- │  ù  |     │BSPC │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  à  │ --- │ --- │ --- │ --- │       │     │  è  |  é  │     │     │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ --- │ --- │  ç  │ --- │ --- │       │ --- │ --- │ --- │ --- │ --- │
     * └─────┴─────┴─────┼─────┼─────┤       ├─────┼─────┼─────┴─────┴─────┘
     *                   │ --- │BASE │       │ENTER│BASE │
     *                   └─────┴─────┘       └─────┴─────┘
     */
    [_ACCENTS] = LAYOUT_split_3x5_3(
        XXX,          XXX,          XXX,          XXX,          XXX,     /**/        XXX,          XXX,          KC_QUOT,      XXX,      KC_BSPC,
        KC_0,         XXX,          XXX,          XXX,          XXX,     /**/        XXX,          KC_7,         KC_2,         XXX,          XXX,
        XXX,          XXX,          KC_9,          XXX,         XXX,     /**/        XXX,          XXX,          XXX,          XXX,          XXX,
                                    XXX,          TO(_BASE),    KC_TRNS, /**/        KC_ENT,       TO(_BASE),    XXX
    )
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