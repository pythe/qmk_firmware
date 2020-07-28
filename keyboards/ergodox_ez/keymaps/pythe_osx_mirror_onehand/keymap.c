// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // qwerty, numbers, punctuation, mac modifiers
#define MIRROR 1 // mirrored keys for one hand typing
#define SYMB 2 // symbols
#define UTIL 3 // media keys
#define _______ KC_TRNS // more transparent transparency
#define SMASH LCAG_T // Whimsical Mac names for key combinations
#define MAGIC MEH_T // Whimsical Mac names for key combinations

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           | UTIL |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | \      |   Q  |   W  |   E  |   R  |   T  | SYMB |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+------|MO_MIR|           | Magic|------+------+------+------+------+--------|
 * | LShf/( |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShf/) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Alt  |  `  |  \   | Left | Right|                                       | Left | Down |   Up  | Right |Super|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Super | Ctrl |       | Alt  | Ctrl |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back-|      | Home |       | PgUp |        |      |
 *                                 | space| Space|------|       |------| Enter  |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_MINS,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_ESC,
        KC_BSLS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_TAB,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSPO,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   MO(MIRROR),
        KC_LALT,        KC_GRV,       KC_BSLS,KC_LEFT,KC_RGHT,
                                                      KC_LGUI,KC_LCTRL,
                                                              KC_HOME,
                                               KC_BSPC,KC_SPC,KC_END,
        // right hand
             OSL(UTIL),   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_EQL,
             KC_LBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_RBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
             SMASH(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSPC,
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,  KC_RGUI,
             KC_RALT,KC_RCTRL,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_SPC
    ),
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   0  |   9  |   8  |   7  |   6  | ESC  |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | [      |   p  |   o  |   i  |   u  |   y  | ]    |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | '      |   ;  |   l  |   k  |   j  |   h  |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | RShf/) |   /  |   .  |   ,  |   m  |   n  |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |     |      |      |      |                                       |      |      |       |       |     |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Super | Ctrl |       | Alt  | Ctrl |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | PgUp |       | PgUp |        |      |
   *                                 | Enter| Del  |------|       |------| Enter  |Space |
   *                                 |      |      | PgDn |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [MIRROR] = LAYOUT_ergodox(  // layer 0 : default
          // left hand
          KC_EQL,         KC_0,         KC_9,   KC_8,   KC_7,   KC_6,   KC_ESC,
          KC_LBRC,        KC_P,         KC_O,   KC_I,   KC_U,   KC_Y,   KC_RBRC,
          KC_QUOT,        KC_SCLN,      KC_L,   KC_K,   KC_J,   KC_H,
          KC_RSPC,        KC_SLSH,      KC_DOT, KC_COMM,KC_M,   KC_N,   _______,
          _______,        _______,      _______,_______,_______,
                                                        _______,_______,
                                                                KC_PGUP,
                                                 KC_ENT ,KC_DELT,KC_PGDN,
          // right hand
         _______,_______,_______,_______,_______,_______,_______,
         _______,_______,_______,_______,_______,_______,_______,
                 _______,_______,_______,_______,_______,_______,
         _______,_______,_______,_______,_______,_______,_______,
                         _______,_______,_______,_______,_______,
         _______,_______,
         _______,
         _______,_______, _______
      ),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,_______,
       _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, _______,
                         _______,KC_DOT,  KC_0,    KC_EQL,  _______,
       _______, _______,
       _______,
       _______, _______, KC_0
),
/* Keymap 3: Util: Reset and change mac/win mode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |RESET |           |TGUTIL| TGWIN|      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// UTILITY
[UTIL] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______,   RESET,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (layer_state & (1UL << UTIL)) {
      ergodox_board_led_on();
    }
    if (layer_state & (1UL << SYMB)) {
      ergodox_right_led_1_on();
    }
    // if (layer_state[]){
    //   ergodox_right_led_2_on();
    // }
    if (layer_state & (1UL << MIRROR)) {
      ergodox_right_led_3_on();
    }
};
