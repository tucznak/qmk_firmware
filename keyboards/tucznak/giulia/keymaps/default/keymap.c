/* Copyright 2021 TuCZnak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
	_LEFT,
	_RIGHT,
	_NUM,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * ,-------------------------------------------------------------------------.
     * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
     * |-------------------------------------------------------------------------+
     * | Tab  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |Enter |
     * |-------------------------------------------------------------------------+
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  Up | FN  |
     * |-------------------------------------------------------------------------+
     * | Ctrl| Win | LAlt| NUM | LEFT |   Space   | RIGHT| RAlt| Left| Down|Right|
     * `-------------------------------------------------------------------------'
     */

    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MO(_FN),
        KC_LCTL, KC_LGUI, KC_LALT, MO(_NUM),MO(_LEFT),   KC_SPC,   MO(_RIGHT),  KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Left function layer (1)
	 * F keys and navigation
     * ,-------------------------------------------------------------------------.
     * | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12   |
     * |-------------------------------------------------------------------------+
     * |      |     |     |     |     |     |     |     |     |     |     | Ins  |
     * |-------------------------------------------------------------------------+
     * |       | Caps|     |PrtSc|ScrLk|Pause|     |     |     |     | PgUp| Del |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          |       | Menu| Home| PgDn| End |
     * `-------------------------------------------------------------------------'
     */

    [_LEFT] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
        _______, KC_CAPS, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, KC_PGUP, KC_DEL,
        _______, _______, _______, _______, _______,     _______,      _______, KC_APP,  KC_HOME, KC_PGDN, KC_END
    ),

    /* Right function layer (2)
	 * National and special characters
     * ,-------------------------------------------------------------------------.
     * | +1  | ě2  | š3  | č4  | ř5  | ž6  | ý7  | á8  | í9  | é0  | ´   |   ˇ   |
     * |-------------------------------------------------------------------------+
     * |  ;°  |  |  |     |     |     |     |  (  |  )  |  §  |  !  |  ú  |  /   |
     * |-------------------------------------------------------------------------+
     * |       |  \  |     |     |     |     |  %  |  =  |  ¨  |  '  |  -  |  _  |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          |       |     |     |     |     |
     * `-------------------------------------------------------------------------'
     */

    [_RIGHT] = LAYOUT(
        KC_1,    KC_2,          KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,          KC_EQL,  LSFT(KC_EQL),
        KC_GRV,  LSFT(KC_NUBS), _______, _______, _______, _______, LSFT(KC_RBRC), KC_RBRC, KC_QUOT, LSFT(KC_QUOT), KC_LBRC, LSFT(KC_LBRC),
        _______, KC_NUBS,       _______, _______, _______, _______, LSFT(KC_MINS), KC_MINS, KC_BSLS, LSFT(KC_BSLS), KC_SLSH, LSFT(KC_SLSH),
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    ),

    /* Numpad layer (3)
     * ,-------------------------------------------------------------------------.
     * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |       |
     * |-------------------------------------------------------------------------+
     * |      |     |     |     |     |     |     |  4  |  5  |  6  |  /  |      |
     * |-------------------------------------------------------------------------+
     * |       |NumLk|     |     |     |     |     |  1  |  2  |  3  |  *  |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          |   0   |  .  |  +  |  -  |     |
     * `-------------------------------------------------------------------------'
    */

    [_NUM] = LAYOUT(
        _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, _______,
        _______, KC_NLCK, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, _______,
        _______, _______, _______, _______, _______,     _______,      KC_KP_0, KC_DOT,  KC_PPLS, KC_PMNS, _______
    ),
	
	/* Function layer (4)
     * Backlighting, keyboard controls, music etc.
     * ,-------------------------------------------------------------------------.
     * |Reset|     |     |     |     |     |     |     |     |     |     |  Vol+ |
     * |-------------------------------------------------------------------------+
     * |      | VLK | Mod+| Hue+| Sat+| Val+|     |     |     |     |     | Vol- |
     * |-------------------------------------------------------------------------+
     * |       | TOG | Mod-| Hue-| Sat-| Val-|     |     |     |     | Stop| Mute|
     * |-------------------------------------------------------------------------+
     * |Sleep|     |     |     |      |   C+A+D  | C+A+I |     | Prev|Pause| Next|
     * `-------------------------------------------------------------------------'
    */

    [_FN] = LAYOUT(
        RESET,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, VLK_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, KC_VOLD,
        _______, RGB_TOG, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, KC_MSTP, KC_MUTE,
        KC_SLEP, _______, _______,  _______, _______,  LCA(KC_DEL), LCA(KC_INS), _______, KC_MPRV, KC_MPLY, KC_MNXT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
