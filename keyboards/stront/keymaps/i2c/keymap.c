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

enum combo_events {
E_ACCENT,
E_ACCENT2,
A_ACCENT,
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
#define FUN_DEL LT(_FUNC, KC_DEL)
#define SYS_TAB LT(_SYS, KC_TAB)
#define GAU_SPC LT(_GAMEUP, KC_SPC)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_QUOT LGUI_T(KC_QUOT)

// Define COMBOS!
const uint16_t PROGMEM combo_lpar[] = {HOME_O, HOME_E, COMBO_END};
const uint16_t PROGMEM combo_rpar[] = {HOME_E, HOME_U, COMBO_END};
const uint16_t PROGMEM combo_lbra[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_rbra[] = {KC_DOT, KC_P, COMBO_END}; 
const uint16_t PROGMEM combo_lcbra[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_rcbra[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {HOME_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_semicol[] = {HOME_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_und[] = {HOME_U, KC_P, COMBO_END};

const uint16_t PROGMEM combo_0[] = {HOME_H, HOME_T, HOME_N, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_M, KC_W, KC_V, COMBO_END}; 
const uint16_t PROGMEM combo_4[] = {HOME_H, HOME_T, COMBO_END};
const uint16_t PROGMEM combo_5[] = {HOME_T, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_6[] = {HOME_H, HOME_T, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_G, KC_C, KC_R, COMBO_END};

const uint16_t PROGMEM combo_accente[] = {HOME_E, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_accente2[] = {HOME_E, KC_J, COMBO_END};
const uint16_t PROGMEM combo_accenta[] = {HOME_A, KC_COLN, COMBO_END};

combo_t key_combos[] = {
    [E_ACCENT] = COMBO_ACTION(combo_accente), // put these first else they override the non-named combos
    [E_ACCENT2] = COMBO_ACTION(combo_accente2),
    [A_ACCENT] = COMBO_ACTION(combo_accenta),
    COMBO(combo_lpar, KC_LPRN),
    COMBO(combo_rpar, KC_RPRN),
    COMBO(combo_lbra, KC_LBRC),
    COMBO(combo_rbra, KC_RBRC),
    COMBO(combo_lcbra, KC_LCBR),
    COMBO(combo_rcbra, KC_RCBR),
    COMBO(combo_equal, KC_EQL),
    COMBO(combo_semicol, KC_SCLN),
    COMBO(combo_und, KC_UNDS),
    COMBO(combo_0, KC_0),
    COMBO(combo_1, KC_1),
    COMBO(combo_2, KC_2),
    COMBO(combo_3, KC_3),
    COMBO(combo_4, KC_4),
    COMBO(combo_5, KC_5),
    COMBO(combo_6, KC_6),
    COMBO(combo_7, KC_7),
    COMBO(combo_8, KC_8),
    COMBO(combo_9, KC_9),
};

// doesn't work for now
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}

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
        KC_QUOT,  HOME_A,   HOME_O,  HOME_E,  HOME_U,  KC_I,                KC_D,    HOME_H,   HOME_T,   HOME_N,  HOME_S,  KC_L,
        KC_COLN,  KC_COLN,  KC_Q,    KC_J,    KC_K,    TD(0),               KC_B,    KC_M,     KC_W,     KC_V,    KC_Z,    KC_Z,
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
                                     XXXXXXX,            LCTL(KC_X),         XXXXXXX,            XXXXXXX,             XXXXXXX,  KC_MPLY,  KC_MPRV,  KC_MNXT,
        XXXXXXX, LGUI_T(LCTL(KC_Y)), LALT_T(LCTL(KC_Z)), LCTL_T(LCTL(KC_C)), LSFT_T(LCTL(KC_V)), XXXXXXX,             KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
        XXXXXXX, XXXXXXX,            XXXXXXX,            XXXXXXX,            TG(_GAME),          XXXXXXX,             KC_INS,   KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_APP,
                                                         KC_ESC,             _______,            KC_TAB,              KC_ENT,   KC_BSPC,  KC_DEL
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
        KC_COLN, KC_AT,   KC_LCBR, KC_RCBR,  KC_HASH, KC_BSLS,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_SCLN,  KC_QUES, KC_EXLM,         _______,  NUM_BSPC, FUN_DEL
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

// intercept mods on mod tap for copy/paste/etc on the nav layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(LCTL(KC_C)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LCTL(KC_C)); // Send copy on tap
                return false;        // Return false to ignore further processing of key
            }
            break;

        case LGUI_T(LCTL(KC_Y)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LCTL(KC_Y)); // Send redo on tap
                return false;        // Return false to ignore further processing of key
            }
            break;

        case LALT_T(LCTL(KC_Z)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LCTL(KC_Z)); // Send undo on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
                
        case LSFT_T(LCTL(KC_V)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LCTL(KC_V)); // Send paste on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

// CAPS_WORD on tap dance x
void words_lock_k (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_X);
    } else if (state->count == 2) {
        caps_word_on();
    }
}

tap_dance_action_t tap_dance_actions[] = {
 [0] = ACTION_TAP_DANCE_FN (words_lock_k),
};


// Special Combos
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case E_ACCENT:
      if (pressed) {
        tap_code16(KC_QUOT);
	tap_code16(KC_E);
      }
      break;
    case E_ACCENT2:
      if (pressed) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_E);
      }
      break;
    case A_ACCENT:
      if (pressed) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_A);
      }
      break;
  }
}
