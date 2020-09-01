// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ergo_42.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ergo_42_layers
  {
   _QWERTY,
   _SYMS,
   _NUMPAD,
   _NUMCHARS,
   _FBUTTONS,
   _MACROS
  };

#define KC_CHAR LT(_NUMCHARS, KC_CAPS)
#define KC_SSYM LT(_SYMS, KC_SPC)
#define KC_CTLZ CTL_T(KC_Z)
#define KC_CTLS CTL_T(KC_SLSH)
#define KC_ALTC ALT_T(KC_C)
#define KC_ALCM ALT_T(KC_COMM)
#define KC_SFTD LSFT_T(KC_DOT)
#define KC_SFTX LSFT_T(KC_X)
#define KC_ALSF MT(MOD_LALT | MOD_LSFT, KC_F4)

#define KC_TBNP LT(_NUMPAD, KC_TAB)
#define KC_FBTN LT(_FBUTTONS, KC_F12)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_PWD  M(0)
#define KC_EMAI M(1)
#define KC_PUSH M(2)
#define KC_LGHT M(5)
#define KC_CAD LALT(LCTL(KC_DEL))

#define LONGPRESS_DELAY 5000
#define LAYER_TOGGLE_DELAY 30

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     MESC, Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     TBNP, A  , S  , D  , F  , G  ,       H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     FBTN,CTLZ,SFTX,ALTC, V  , B  ,       N  , M  ,ALCM,SFTD,CTLS,ALSF,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                    TAB ,SSYM,BSPC,      ENT ,CHAR,FBTN
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_SYMS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,PGDN, UP ,PGUP,PSCR,      GRV ,LCBR,RCBR,SLSH,LBRC,RBRC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     CAPS,HOME,LEFT,DOWN,RGHT,END ,      MINS,LPRN,RPRN,LT  ,GT  ,TILD,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,INS ,DEL ,    ,      UNDS,LBRC,RBRC,DOT ,PIPE,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                        ,    ,    ,      EQL ,PLUS,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,      SLSH, 7  , 8  , 9  ,ASTR,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,      PLUS, 4  , 5  , 6  , 0  ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,      MINS, 1  , 2  , 3  ,DOT ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                        ,    ,    ,       LT , GT , EQL
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_FBUTTONS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          , F7 , F8 , F9 ,F12 ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          , F4 , F5 , F6 ,F10 ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          , F1 , F2 , F3 ,F11 ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                        ,    ,    ,          ,    ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_NUMCHARS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,AMPR,ASTR,LPRN,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,DLR ,PERC,CIRC,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,EXLM, AT ,HASH,RPRN,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                        ,    ,    ,          ,    ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,    ,          ,EMAI,PWD ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,    ,    ,PUSH,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                        ,    ,    ,          ,    ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        SEND_STRING("<secret>");
        return MACRO( T(LEFT), END);
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("mikhail.shevchuk@gmail.com");
        return MACRO( T(ENT), END );
      }
      break;
    case 2:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
    case 5:
      if (record->event.pressed){
        set_led_green;
      }
      break;
  }
  return MACRO_NONE;
};
 

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
    
  switch (layer) {
  case _QWERTY:
    set_led_green;
    break;
  case _SYMS:
    set_led_magenta;
    break;
  case _NUMPAD:
    set_led_blue;
    break;
  case _NUMCHARS:
    set_led_white;
    break;
  case _FBUTTONS:
    set_led_red;
    break;
  case _MACROS:
    set_led_cyan;
    break;
  default:
    set_led_green;
    break;
  }
};
