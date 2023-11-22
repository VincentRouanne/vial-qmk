// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    // clang-format off
    _BASE = 0,
    _GAME,
    _GAMEUP,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC,
    _SYS,
    _MEDIA
    // clang-format on
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)

// Right-hand home row mods
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

// bottom mods
#define MED_ESC LT(_MEDIA, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define NUM_BSPC LT(_NUMBER, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_QUOT LGUI_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *               .---------------------------.                    .---------------------------.
     *               |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |
     * .------+------+------+------+------+------|                    |------+------+------+------+------+------.
     * |  Q   |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   P  |  ;   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  -   |   Z  |   X  |   C  |   V  |   B  |--------.  .--------|   N  |   M  |   ,  |   .  |   /  |  '   |
     * '-----------------------------------------/       /    \       \-----------------------------------------'
     *                         | Esc  | Tab  |  / Space /      \ Enter \  | Bsps | Del  |
     *                         |_FUNC | _NUM | /_SYMBOL/        \ _FUNC \ | _NAV | RAlt |
     *                         `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_BASE] = LAYOUT(
                            KC_COMM, KC_DOT,  KC_P,    KC_Y,                KC_F,    KC_G,    KC_C,     KC_R,
        KC_SQT,   HOME_A,   HOME_O,  HOME_E,  HOME_U,  KC_I,                KC_D,    HOME_H,  HOME_T,   HOME_N,  HOME_S,  KC_L,
        KC_COLN,  KC_COLN,  KC_Q,    KC_J,    KC_K,    KC_X,                KC_B,    KC_M,    KC_W,     KC_V,    KC_Z,    KC_Z,
                                     MED_ESC, NAV_SPC, KC_TAB,              SYM_ENT, NUM_BSPC,FUN_DEL
    ),

    [_GAME] = LAYOUT(
                            KC_2,    KC_3,    KC_4,    KC_P,               TO(_BASE),    KC_U,    KC_I,     KC_O,
        KC_1,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_F,               KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_P,
        KC_ESC,     KC_TAB, KC_A,    KC_S,    KC_D,    KC_B,               KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  LGUI_QUOT,
                                     KC_LSFT, GAU_SPC, KC_LALT,            FUNC_ENT,  NAV_BSPC,  RALT_DEL
    ),

    [_GAMEUP] = LAYOUT(
                                KC_F2,       KC_F3,      KC_F4,      KC_SPC,             KC_Y,    KC_U,    KC_I,     KC_O,
        KC_F1,      LSFT(KC_Q), LSFT(KC_W),  LSFT(KC_E), LSFT(KC_R), KC_F,               KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_P,
        KC_ESC,     KC_TAB,     KC_GRAVE,    KC_T,       KC_T,       KC_ESC,             KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  LGUI_QUOT,
                                             KC_LSFT,    GAU_SPC,    KC_LALT,            FUNC_ENT,  NAV_BSPC,  RALT_DEL
    ),

    [_NAV] = LAYOUT(
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  KC_PGDN,  KC_PGUP,
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,             XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PAUS,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  KC_HOME,  KC_END,   KC_INS,   KC_APP,   XXXXXXX,
                                       FUNC_ESC,   NUM_TAB,   SYM_SPC,     XXXXXXX,  _______,  RALT_DEL
    ),

    [_NUMBER] = LAYOUT(
                            KC_7,    KC_8,    KC_9,    KC_PLUS,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_GRAVE, KC_MINS,  KC_4,    KC_5,    KC_6,    KC_DLR,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_MINS,  KC_ASTR,  KC_1,    KC_2,    KC_3,    KC_SLSH,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     KC_DOT,  KC_0,    TG(_GAME),       FUNC_ENT, _______,  RALT_DEL
    ),

    [_SYMBOL] = LAYOUT(
                          KC_LBRC, KC_RBRC,  KC_AMPR, KC_PIPE,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TILD, KC_UNDS, KC_LPRN, KC_RPRN,  KC_PERC, KC_EQL,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_COLN, KC_AT,   KC_LCBR, KC_RCBR,  KC_HASH, KC_BSLS          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   MO(_SYS), KC_BSPC, _______,     FUNC_ENT,  NAV_BSPC,  RALT_DEL
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,   KC_F8,   KC_F9,   KC_CAPS,            XXXXXXX,  KC_PSCR,  KC_SCRL,  KC_NUM,
        KC_F12,   KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_F12,             XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                         _______, KC_MNXT, KC_MPLY,     _______, XXXXXXX,  MO(_SYS)
    ),

    [_SYS] = LAYOUT(
                            BL_DOWN,  BL_UP,    BL_TOGG,  XXXXXXX,            XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,
        EH_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EH_RGHT,            EH_RGHT,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  EH_LEFT,
                                            _______, QK_BOOT, _______,     _______, QK_BOOT, _______
    )
    // clang-format on
};
