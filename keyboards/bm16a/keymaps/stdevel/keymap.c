/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _FN1,
};

// Defines emojis
enum unicode_names {
    DOGE,
    SNEK,
    TREX,
    DUCK,
    NERD,
    ROFL,
    ZANY,
    SNEZ,
    SHIT,
    SHRG,
    ELEP
};

const uint32_t PROGMEM unicode_map[] = {
    [DOGE] = 0x1F415, // 🐕
    [SNEK] = 0x1F40D, // 🐍
    [TREX] = 0x1F996, // 🦖
    [DUCK] = 0x1F986, // 🦆
    [NERD] = 0x1F913, // 🤓
    [ROFL] = 0x1F923, // 🤣
    [ZANY] = 0x1F92A, // 🤪
    [SNEZ] = 0x1F927, // 🤧
    [SHIT] = 0x1F4A9, // 💩
    [SHRG] = 0x1F937, // 🤷🏻‍♂️
    [ELEP] = 0x1F418, // 🐘
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

// Tap Dance declarations
enum {
    TD_VDOWN_PREV,
    TD_MUTE_PAUSE,
    TD_VUP_NEXT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_VDOWN_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MPRV),
    [TD_MUTE_PAUSE] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
    [TD_VUP_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MNXT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MO(_FN1),  TD(TD_VDOWN_PREV),  TD(TD_MUTE_PAUSE),  TD(TD_VUP_NEXT) , \
    KC_F13,  KC_F14,  KC_F15,  KC_F16, \
    KC_F17, KC_F18, KC_F19,  KC_F20, \
    KC_F21, KC_F22, KC_F23, KC_DEL \
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    _______,    _______,    _______,    _______,   \
    X(DOGE),   X(SNEK),    X(TREX),    X(DUCK),   \
    X(NERD),   X(ROFL),    X(ZANY),    X(SNEZ),   \
    X(SHIT),  X(SHRG),    X(ELEP),    RESET   \
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        //SEND_STRING("💩");
        send_unicode_string("💩");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}
