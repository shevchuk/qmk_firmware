/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>
Modified 2019 Iason Dimitrakopoulos (idimitrakopoulos) <idimitrakopoulos@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgblight.h"
#include "quantum.h"

#define _QWERTY 0
#define _COLEMAK 1
#define _FN 2
#define _FX 3
#define _NUMS 4
#define _PLACEHOLDER 5
#define _FPAD 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( \

      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_ESC,      KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,       KC_7,      KC_8,       KC_9,       KC_0,      KC_BSPC, \
      //           |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_TAB,      KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,       KC_U,      KC_I,       KC_O,       KC_P,      KC_BSLS, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_CAPS,      KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,       KC_J,      KC_K,       KC_L,      KC_SCLN,    KC_QUOT, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_LSFT,      KC_Z,      KC_X,        KC_C,      KC_V,       KC_B,        KC_N,       KC_M,     KC_COMM,     KC_DOT,   KC_SLSH,    SFT_T(KC_ENT),\
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_LCTL,    KC_LGUI,    KC_LALT,   TG(_NUMS), KC_SPC,LT(_FPAD, KC_BSPC),LT(_NUMS, KC_ENT),_______,_______,  _______,LT(_FN, KC_SPC),LT(_FX, KC_ENT) \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
    ),

    [_COLEMAK] = LAYOUT( \

      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    KC_R,       KC_S,       KC_T,       KC_D,       _______,    KC_N,       KC_E,       KC_I,       KC_O,       _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    KC_K,       _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
    ),

    [_PLACEHOLDER] = LAYOUT( \
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
    ),

    [_NUMS] = LAYOUT( \
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_GRV,   KC_EXLM,      KC_AT,    KC_HASH,     KC_DLR,     KC_PERC,   KC_CIRC,     KC_AMPR,   KC_ASTR,    KC_LPRN,     KC_RPRN,    KC_PIPE, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,     KC_UP,     _______,    _______,    _______,      KC_7,        KC_8,      KC_9,      _______,    _______,\
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,   KC_LEFT,     KC_DOWN,    KC_RIGHT,   _______,    _______,      KC_4,        KC_5,      KC_6,       KC_0,      _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,      KC_1,        KC_2,      KC_3,      _______,   _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
    ),

    [_FPAD] = LAYOUT( \
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,   KC_F10,     KC_F11,      KC_F12,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_PLUS,    KC_TILD,    KC_PIPE,    KC_BSLS,    KC_SLSH,    _______,   _______,     KC_F7,      KC_F8,      KC_F9,      KC_F12,    _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_MINS,    KC_LPRN,    KC_RPRN,     KC_LT,      KC_GT,     _______,   _______,     KC_F4,      KC_F5,      KC_F6,      KC_F10,    _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,    _______,   _______,     KC_F1,      KC_F2,      KC_F3,      KC_F11,    _______, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_EQL,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______  \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
    ),


    [_FN] = LAYOUT( \

      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,   \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_PSCR,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_EQUAL, \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINUS, \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |             |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PGUP,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_END    \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,     -----+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
    ),

    [_FX] = LAYOUT( \

      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  TT(_COLEMAK), \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    BL_ON,      BL_INC,     RGB_TOG,    RGB_MOD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    BL_OFF,     BL_DEC,     RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_SPI,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    RGB_TOG,    BL_STEP,    RGB_HUD,    RGB_SAD,    RGB_VAD,    RGB_SPD,    _______,    _______,    _______,    _______,    _______,  \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+------------+|
      //|          |           |           |           |           |           |           |           |           |           |           |            |
          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   \
      //|          |           |           |           |           |           |           |           |           |           |           |            |
      //, -----+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+'
    ),


};
