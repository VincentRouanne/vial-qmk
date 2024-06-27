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
	LINE_SEL,
};

enum custom_keycodes {
    KC_LINESEL = SAFE_RANGE,
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

const uint16_t PROGMEM combo_0[] = {KC_D, HOME_H, COMBO_END};
const uint16_t PROGMEM combo_1[] = {HOME_H, HOME_T, COMBO_END};
const uint16_t PROGMEM combo_2[] = {HOME_T, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_3[] = {HOME_H, HOME_T, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_M, KC_W, KC_V, COMBO_END}; 
const uint16_t PROGMEM combo_7[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_G, KC_C, KC_R, COMBO_END};

const uint16_t PROGMEM combo_accente[] = {HOME_E, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_accente2[] = {HOME_E, KC_J, COMBO_END};
const uint16_t PROGMEM combo_accenta[] = {HOME_A, KC_COLN, COMBO_END};
const uint16_t PROGMEM combo_line_selection[] = {KC_MPLY, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_next_desktop[] = {HOME_E, HOME_O, HOME_U, COMBO_END};
const uint16_t PROGMEM combo_prev_desktop[] = {HOME_A, HOME_E, HOME_O, COMBO_END};

combo_t key_combos[] = {
    [E_ACCENT] = COMBO_ACTION(combo_accente), // put these first else they override the non-named combos
    [E_ACCENT2] = COMBO_ACTION(combo_accente2),
    [A_ACCENT] = COMBO_ACTION(combo_accenta),
    [LINE_SEL] = COMBO_ACTION(combo_line_selection),
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
    COMBO(combo_next_desktop, LCTL(LGUI(KC_RIGHT))),
    COMBO(combo_prev_desktop, LCTL(LGUI(KC_LEFT))),
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
        KC_COLN,  KC_COLN,  KC_Q,    KC_J,    KC_K,    KC_X,                KC_B,    KC_M,     KC_W,     KC_V,    KC_Z,    CW_TOGG,
                                     MOU_ESC, NAV_SPC, SYS_TAB,             SYM_ENT, NUM_BSPC, FUN_DEL
    ),

    [_GAME] = LAYOUT(
                            KC_2,    KC_3,    KC_4,    KC_P,               TO(_BASE), XXXXXXX,  XXXXXXX,  XXXXXXX,
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
        KC_MINS, KC_ASTR,  KC_1,    KC_2,     KC_3,      KC_SLSH,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     _______, KC_0,      KC_DLR,          KC_ENT,   XXXXXXX,  KC_DEL
    ),

    [_NAV] = LAYOUT(
                                     LCAG(KC_1),         LCAG(KC_2),         LCAG(KC_3),         KC_F5,            KC_MNXT,  KC_MPLY,  LCTL(KC_T), LCTL(KC_R),
        XXXXXXX, LGUI_T(LCTL(KC_Y)), LALT_T(LCTL(KC_Z)), LCTL_T(LCTL(KC_C)), LSFT_T(LCTL(KC_V)), KC_F9,            KC_CAPS,  KC_LEFT,  KC_UP,      KC_DOWN,  KC_RGHT,  XXXXXXX,
        XXXXXXX, XXXXXXX,            KC_F1,              LCTL(KC_X),         KC_LINESEL,         LCTL(KC_D),       KC_INS,   KC_HOME,  KC_PGUP,    KC_PGDN,  KC_END,   KC_APP,
                                                         KC_ESC,             _______,            TG(_GAME),        KC_ENT,   KC_BSPC,  KC_DEL
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
        KC_COLN, KC_AT,   KC_LCBR, KC_RCBR,  KC_HASH, KC_BSLS,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_SCLN,  KC_QUES, KC_EXLM,         _______,  NUM_BSPC, QK_BOOT
    ),

    [_NUMBER] = LAYOUT(
                            KC_9,    KC_8,    KC_7,    KC_PLUS,         KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,
        KC_GRAVE, KC_MINS,  KC_3,    KC_2,    KC_1,    KC_EQL,          XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        KC_MINS,  KC_ASTR,  KC_6,    KC_5,    KC_4,    KC_SLSH,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     KC_DOT,  KC_0,    KC_DLR,          KC_ENT,   _______,  KC_DEL
    ),

    [_FUNC] = LAYOUT(
                            KC_F9,   KC_F8,   KC_F7,   KC_F12,            XXXXXXX,  KC_PSCR,  KC_SCRL,  KC_NUM,
        KC_F12,   KC_F11,   KC_F3,   KC_F2,   KC_F1,   KC_F10,            XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
        XXXXXXX,  KC_F10,   KC_F6,   KC_F5,   KC_F4,   KC_F11,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     XXXXXXX, KC_MNXT, KC_MPLY,           XXXXXXX,  XXXXXXX,   _______
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
			
		case KC_LINESEL:
		    if (record->event.pressed) {
				tap_code16(KC_HOME);
				tap_code16(LSFT(KC_END));
			}
			break;
    }
    return true;
}


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
	case LINE_SEL: // can be removed after key test
      if (pressed) {
        tap_code16(KC_HOME);
        tap_code16(LSFT(KC_END));
      }
      break;
  }
}

// Encoders default behavior
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code_delay(KC_VOLU, 10);
//         } else {
//             tap_code_delay(KC_VOLD, 10);
//        }
//     } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code16(LCTL(KC_RIGHT));
//         } else {
//             tap_code16(LCTL(KC_LEFT));
//         }
//     }
//     return false;
// }

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP),		ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          	ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          	ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),         	 	ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), 				ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [5] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          	ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [6] = { ENCODER_CCW_CW(KC_DOWN, KC_UP),             	ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [7] = { ENCODER_CCW_CW(LCTL(KC_LEFT), LCTL(KC_RIGHT)),	ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [8] = { ENCODER_CCW_CW(LCTL(KC_PGDN), LCTL(KC_PGUP)),          		ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif