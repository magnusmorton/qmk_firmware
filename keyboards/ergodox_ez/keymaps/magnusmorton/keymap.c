#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_uk.h"
#include "quantum.h"

#define QWR 0 // default layer
#define SYMB 1 // symbols
#define GMR 2 // media keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  RCKT

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |  =   |           | -    |   6  |   7  |   8  |   9  |   0  |   #    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     | '      |
 * |--------+------+------+------+------+------|   [  |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Win  |  `   |Alt   | Left | Right|                                       |  Up  | Down  | Left | right| ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | PrtScr|RAlt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space| Ctl  |------|       |------|  Ctl   |Enter |
 *                                 |      |      | lalt |       | LAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWR] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,        UK_2,          KC_3,    KC_4,    KC_5,    KC_EQL,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),
  KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_LBRC,
  KC_LGUI,         UK_GRV,      KC_LALT, KC_LEFT, KC_RGHT,
                                                           KC_HOME, KC_END,
                                                                          KC_DEL,
                                                         KC_SPC, KC_LCTL, KC_LALT,
  // right hand
  KC_MINS,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           UK_HASH,
  TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           UK_BSLS,
  KC_H,         KC_J,    KC_K,    KC_L,    KC_SCLN,           KC_QUOT,
  KC_RBRC,      KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_UP,        KC_DOWN, KC_LEFT, KC_RIGHT, TT(SYMB),
  KC_PSCREEN,  KC_RALT,
  KC_PGUP,
  KC_LALT, KC_LCTL, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |  L2  |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       | VolUp|Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       | VDown|      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, KC_TRNS,
                                                        KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  TG(GMR), KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, RGB_SLD,
  KC_VOLU,
  KC_VOLD, RGB_HUD, RGB_HUI
),

/* Keymap 2: GMR
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |  =   |           | -    |   6  |   7  |   8  |   9  |   0  |   #    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     | '      |
 * |--------+------+------+------+------+------|   [  |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl  |  Win   |Alt   | Left | Right|                                       |  Up  | Down  | Left | right| ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | PrtScr|RAlt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space| Ctl  |------|       |------|  Ctl   |Enter |
 *                                 |      |      | lalt |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[GMR] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,        UK_2,          KC_3,    KC_4,    KC_5,    KC_EQL,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(GMR),
  KC_CAPS,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_LBRC,
  KC_LCTL,         KC_LGUI,      KC_LALT, KC_LEFT, KC_RGHT,
                                                           KC_HOME, KC_END,
                                                                          KC_DEL,
                                                         KC_SPC, KC_LCTL, UK_GRV,
  // right hand
  KC_MINS,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           UK_HASH,
  TG(GMR),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           UK_BSLS,
  KC_H,         KC_J,    KC_K,    KC_L,    KC_SCLN,           KC_QUOT,
  KC_RBRC,      KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_UP,        KC_DOWN, KC_LEFT, KC_RIGHT, TT(SYMB),
  KC_PSCREEN,  KC_RALT,
  KC_PGUP,
  KC_PGDN, KC_LCTL, KC_ENT
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case RCKT:
        SEND_STRING ("->");
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
