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

enum custom_keycodes {
  MYRGB_TG = SAFE_RANGE
};

bool rgbinit = true;
bool rgbon = true;

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {1,5,5}; //only using the first one

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  led_set_user(host_keyboard_leds());
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _FPAD:
      rgblight_sethsv_noeeprom(240,255,255);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _NUMS:
      rgblight_sethsv_noeeprom(0,255,255);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _FN:
      rgblight_sethsv_noeeprom(0,255,255);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
      break;
    default: //_DEFLT
      rgblight_sethsv_noeeprom(0,0,255);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
  }

  return state;
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
  } else {
    layer_state_set_user(layer_state);
  }
}

void myrgb_toggle(void) {
  if (rgbon) {
    rgblight_disable_noeeprom();
    rgbon = false;
  } else {
    rgblight_enable_noeeprom();
    layer_state_set_user(layer_state);
    led_set_user(host_keyboard_leds());
    rgbon = true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MYRGB_TG:
      if (record->event.pressed) {
        myrgb_toggle();
      }
      return false;
    default:
      return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( \

      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+.
      //|          |           |           |           |           |           |           |           |           |           |           |           |
       LT(_FX,KC_CAPS), KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,       KC_7,      KC_8,       KC_9,       KC_0,      KC_BSPC, \
      //           |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_TAB,      KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,       KC_U,      KC_I,       KC_O,       KC_P,      KC_BSLS, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
           KC_ESC,      KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,       KC_J,      KC_K,       KC_L,      KC_SCLN,    KC_QUOT, \
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_LSFT,      KC_Z,      KC_X,        KC_C,      KC_V,       KC_B,        KC_N,       KC_M,     KC_COMM,     KC_DOT,   KC_SLSH,  SFT_T(KC_ENT),\
      //|          |           |           |           |           |           |           |           |           |           |           |           |
      //,----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+|
      //|          |           |           |           |           |           |           |           |           |           |           |           |
          KC_LCTL,    KC_LGUI,     KC_LALT,    KC_DEL,     KC_SPC,LT(_NUMS, KC_BSPC),LT(_FPAD,KC_ENT),TG(_FN),_______,KC_RALT,   KC_RGUI,     KC_RCTL \
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
