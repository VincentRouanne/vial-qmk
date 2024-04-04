// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    // clang-format off
    _BASE = 0,
    _GAME,
    _GAMEUP,
    _MOUSE,
    _NAV,
    _SYS,
    _SYMBOL,
    _NUMBER,
    _FUNC
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
#define MOU_ESC LT(_MOUSE, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define NUM_BSPC LT(_NUMBER, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)
#define SYS_TAB LT(_SYS, KC_TAB)

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
                            KC_COMM, KC_DOT,  KC_P,    KC_Y,                KC_F,    KC_G,     KC_C,     KC_R,
        KC_SQT,   HOME_A,   HOME_O,  HOME_E,  HOME_U,  KC_I,                KC_D,    HOME_H,   HOME_T,   HOME_N,  HOME_S,  KC_L,
        KC_COLN,  KC_COLN,  KC_Q,    KC_J,    KC_K,    KC_X,                KC_B,    KC_M,     KC_W,     KC_V,    KC_Z,    KC_Z,
                                     MOU_ESC, NAV_SPC, SYS_TAB,             SYM_ENT, NUM_BSPC, FUN_DEL
    ),

    [_GAME] = LAYOUT(
                            KC_2,    KC_3,    KC_4,    KC_P,               XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_1,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_F,               XXXXXXX,   KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_ESC,     KC_TAB, KC_A,    KC_S,    KC_D,    KC_B,               XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     KC_LSFT, GAU_SPC, KC_LALT,            TO(_BASE), NUM_BSPC, FUN_DEL
    ),

    [_GAMEUP] = LAYOUT(
                                KC_F2,       KC_F3,      KC_F4,      KC_SPC,             KC_Y,    KC_U,    KC_I,     KC_O,
        KC_F1,      LSFT(KC_Q), LSFT(KC_W),  LSFT(KC_E), LSFT(KC_R), KC_F,               KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_P,
        KC_ESC,     KC_TAB,     KC_GRAVE,    KC_T,       KC_T,       KC_ESC,             KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  LGUI_QUOT,
                                             KC_LSFT,    _______,    KC_LALT,            XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
                           KC_7,    KC_8,     KC_9,      KC_PLUS,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_SCRL, KC_LSCR,  KC_BTN3, KC_BTN2,  KC_BTN1,   KC_EQL,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_MINS, KC_ASTR,  KC_1,    KC_2,     TG(_GAME), KC_SLSH,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     _______, KC_0,      KC_DLR,          KC_ENT,   XXXXXXX,  KC_DEL
    ),

    [_NAV] = LAYOUT(
                                          XXXXXXX,               XXXXXXX,              XXXXXXX,              XXXXXXX,             XXXXXXX,  KC_MPLY,  KC_MPRV,  KC_MNXT,
        LCTL(KC_X),  LGUI_T(LCTL(KC_C)),  LALT_T(LCTL(KC_V)),    LCTL_T(LCTL(KC_Z)),   LSFT_T(LCTL(KC_Y)),   XXXXXXX,             KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PAU,
        XXXXXXX,     XXXXXXX,             XXXXXXX,               XXXXXXX,              TG(_GAME),            XXXXXXX,             KC_INS,   KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_APP,
                                                                 KC_ESC,               _______,              KC_TAB,              KC_ENT,   KC_BSPC,  KC_DEL
    ),

    [_SYS] = LAYOUT(
                            BL_DOWN,  BL_UP,    BL_TOGG,  XXXXXXX,            XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_RMOD,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,
        EH_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EH_RGHT,            EH_RGHT,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  EH_LEFT,
                                      _______,  QK_BOOT,  _______,            _______,  QK_BOOT, _______
    ),

    [_SYMBOL] = LAYOUT(
                          KC_LBRC, KC_RBRC,  KC_AMPR, KC_PIPE,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TILD, KC_UNDS, KC_LPRN, KC_RPRN,  KC_PERC, KC_EQL,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_COLN, KC_AT,   KC_LCBR, KC_RCBR,  KC_HASH, KC_BSLS          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_SCLN,   KC_QUES, KC_EXLM,         _______,  NUM_BSPC, FUN_DEL
    ),

    [_NUMBER] = LAYOUT(
                            KC_7,    KC_8,    KC_9,    KC_PLUS,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_GRAVE, KC_MINS,  KC_4,    KC_5,    KC_6,    KC_EQL,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_MINS,  KC_ASTR,  KC_1,    KC_2,    KC_3,    KC_SLSH,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     KC_DOT,  KC_0,    KC_DLR,          KC_ENT,   _______,  KC_DEL
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,   KC_F8,   KC_F9,   KC_CAPS,            XXXXXXX,  KC_PSCR,  KC_SCRL,  KC_NUM,
        KC_F12,   KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_F12,             XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     XXXXXXX, KC_MNXT, KC_MPLY,            XXXXXXX,  XXXXXXX,   _______
    )
    // clang-format on
};
