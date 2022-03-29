#include QMK_KEYBOARD_H
#include "version.h"

#define BASE   0 // default layer
#define LAYER1 1
#define LAYER2 2

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  ^b tmux prefix |           |  ~/` |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+------------------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ^j tmux prefix |           |  {   |   Y  |   U  |   I  |   O  |   P  |   {/]  |
 * |--------+------+------+------+------+------|                 |           |  [   |------+------+------+------+------+--------|
 * | LGui   |   A  |   S  |   D  |   F  |   G  |-----------------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|  ^x func prefix |           |  "   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |                 |           |  '   |   N  |   M  |   ,  |   .  |   /  |   -/_  |
 * `--------+------+------+------+------+------------------------'           `-------------+------+------+------+------+--------'
 *   |MO(L1)|MO(L2)| LAlt | LCtrl|HYPR_E|                                       |HYPR_K|  (   |  )   |   =  |   +  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                                   ,-------------.       ,-------------.
 *                                                   | Home | PgUp |       | PgDn | DEL  |
 *                                            ,------|------|------|       |------+------+------.
 *                                            |      |  ^k  | LAlt |       | RAlt |      |      |
 *                                            | Space|  vim |------|       |------|BackSp| Enter|
 *                                            |      |prefix|   $  |       |   ^  |      |      |
 *                                            `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,     KC_1,       KC_2,    KC_3,    KC_4,       KC_5,    LCTL(KC_B),
  KC_TAB,     KC_Q,       KC_W,    KC_E,    KC_R,       KC_T,    LCTL(KC_J),
  KC_LGUI,    KC_A,       KC_S,    KC_D,    KC_F,       KC_G,
  KC_LSFT,    KC_Z,       KC_X,    KC_C,    KC_V,       KC_B,    LCTL(KC_X),
  TG(LAYER1), MO(LAYER2), KC_LALT, KC_LCTL, HYPR(KC_E),

                                                        KC_HOME,    KC_PGUP,
                                                                    KC_LALT,
                                     LT(LAYER1,KC_SPC), LCTL(KC_K), S(KC_4),
                                                                              // right hand
                                                                              KC_GRV,       KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_BSLS,
                                                                              KC_LBRC,      KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_RBRC,
                                                                                            KC_H,    KC_J,    KC_K,    KC_L,              KC_SCLN,        KC_COLN,
                                                                              KC_QUOT,      KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_MINS,
                                                                              HYPR(KC_K),   S(KC_9), S(KC_0), KC_EQL,  KC_PLUS,

                                                                              KC_PGDN, KC_DEL,
                                                                              KC_RALT,
                                                                              S(KC_6), KC_BSPC, KC_ENT
),
/* Keymap 1: Layer1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Lclk | Rclk | WhClk|      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |WhRght| WhUp |WhDown|WhLeft|      |        |
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
[LAYER1] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // right hand
                                                                  KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
                                                                  KC_TRNS,  KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3,  KC_TRNS, KC_TRNS,
                                                                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,  KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L,  KC_TRNS, KC_TRNS,
                                                                                     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

                                                                  KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,
                                                                  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Layer2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | RESET|           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
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
[LAYER2] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RESET,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // right hand
                                                                  KC_TRNS, KC_F6,   KC_F7,   KC_F8,  KC_F9, KC_F10,  KC_F11,
                                                                  KC_TRNS, KC_UP,   KC_7,    KC_8,   KC_9,  KC_ASTR, KC_F12,
                                                                           KC_DOWN, KC_4,    KC_5,   KC_6,  KC_PLUS, KC_TRNS,
                                                                  KC_TRNS, KC_AMPR, KC_1,    KC_2,   KC_3,  KC_BSLS, KC_TRNS,
                                                                                    KC_TRNS, KC_DOT, KC_0,  KC_EQL,  KC_TRNS,

                                                                  KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,
                                                                  KC_TRNS, KC_TRNS, KC_TRNS
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
