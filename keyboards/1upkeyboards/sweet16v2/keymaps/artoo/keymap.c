/* Copyright 2022 ziptyze
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

// variables for ALT_TAB
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// swap hands flag for controlling rgb
bool is_swap_hands_active = false;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  SFT_ALT_TAB,
};

enum sweet16_keymap_artoo_layers {
  LAYER_BASE = 0,
  LAYER_PAR,
  LAYER_NUM,
  LAYER_SYM,
  LAYER_CUS,
  LAYER_MOUSE,
  LAYER_NAV,
  LAYER_UTIL,
};

#define A_PAR LT(LAYER_PAR, KC_A)
#define S_NUM LT(LAYER_NUM, KC_S)
#define E_SYM LT(LAYER_SYM, KC_E)
#define O_CUS LT(LAYER_CUS, KC_O)

// convenience shorthands
#define _____________TRNS_ROW_____________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ___________TO_BASE_ROW____________ KC_TRNS, KC_TRNS, TO(LAYER_BASE), KC_TRNS

#define LAYOUT_LAYER_BASE             \
KC_MUTE,HYPR(KC_F),HYPR(KC_U),KC_MPLY,\
  SH_OFF,KC_SLEP,TG(LAYER_UTIL),SH_ON,\
    A_PAR,    KC_R,    KC_T,   S_NUM, \
    E_SYM,    KC_Y,    KC_I,   O_CUS

#define LAYOUT_LAYER_PAR              \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
    KC_NO, KC_LPRN, KC_RPRN, KC_RCBR, \
    KC_NO, KC_LBRC, KC_RBRC, KC_LCBR

#define LAYOUT_LAYER_NUM              \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
     KC_1,    KC_2,    KC_3,   KC_NO, \
     KC_4,    KC_5,    KC_6,   KC_NO

#define LAYOUT_LAYER_SYM              \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
  KC_EXLM, KC_BSLS, KC_SCLN,  KC_GRV, \
    KC_NO, KC_QUES, KC_MINS,  KC_EQL

#define LAYOUT_LAYER_CUS              \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
  KC_WREF,  KC_INS, KC_WFWD,   KC_NO, \
OSM(MOD_RALT),KC_PSCR,KC_WBAK, KC_NO

#define LAYOUT_LAYER_MOUSE            \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, \
  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D

#define LAYOUT_LAYER_NAV              \
  _____________TRNS_ROW_____________, \
  ___________TO_BASE_ROW____________, \
  KC_HOME,   KC_UP,  KC_END, KC_PGUP, \
  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN

#define LAYOUT_LAYER_UTIL             \
   EE_CLR, KC_TRNS, KC_TRNS, QK_BOOT, \
  ___________TO_BASE_ROW____________, \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________

#if defined(SWAP_HANDS_ENABLE)
// Only mirror the two bottom rows
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
  {{3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{3, 3}, {2, 3}, {1, 3}, {0, 3}},
};
#endif

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x4(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE]  = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_PAR]   = LAYOUT_wrapper(LAYOUT_LAYER_PAR),
  [LAYER_NUM]   = LAYOUT_wrapper(LAYOUT_LAYER_NUM),
  [LAYER_SYM]   = LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_CUS]   = LAYOUT_wrapper(LAYOUT_LAYER_CUS),
  [LAYER_MOUSE] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_NAV]   = LAYOUT_wrapper(LAYOUT_LAYER_NAV),
  [LAYER_UTIL]  = LAYOUT_wrapper(LAYOUT_LAYER_UTIL),
};

const uint16_t PROGMEM artsey_combo_B[] = {E_SYM, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_C[] = {E_SYM, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_D[] = {A_PAR, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_F[] = {A_PAR, KC_R, COMBO_END};
const uint16_t PROGMEM artsey_combo_G[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_H[] = {E_SYM, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_J[] = {KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_K[] = {KC_Y, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_L[] = {E_SYM, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_M[] = {KC_Y, KC_I, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_N[] = {KC_I, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_P[] = {E_SYM, KC_I, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_Q[] = {A_PAR, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_U[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_V[] = {KC_R, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_W[] = {A_PAR, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_X[] = {KC_R, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_Z[] = {A_PAR, KC_R, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_AUML[] = {E_SYM, KC_R, KC_T, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_OUML[] = {A_PAR, KC_Y, KC_I, S_NUM, COMBO_END};

const uint16_t PROGMEM artsey_combo_QUOT[] = {A_PAR, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_DOT[] = {A_PAR, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_COMM[] = {A_PAR, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_SLSH[] = {A_PAR, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_EXLM[] = {KC_T, KC_I, COMBO_END};

const uint16_t PROGMEM artsey_combo_ENT[] = {A_PAR, E_SYM, COMBO_END};
const uint16_t PROGMEM artsey_combo_SPC[] = {E_SYM, KC_Y, KC_I, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_BSPC[] = {E_SYM, KC_R, COMBO_END};
const uint16_t PROGMEM artsey_combo_DEL[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_ESC[] = {A_PAR, KC_R, O_CUS, COMBO_END};
const uint16_t PROGMEM artsey_combo_TAB[] = {A_PAR, KC_R, KC_T, O_CUS, COMBO_END};

const uint16_t PROGMEM artsey_combo_LCTL[] = {E_SYM, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_LGUI[] = {KC_Y, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_LALT[] = {KC_I, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_LSFT[] = {E_SYM, KC_R, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM artsey_combo_CAPS_WORD[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_CAPS[] = {A_PAR, KC_Y, KC_I, O_CUS, COMBO_END};

const uint16_t PROGMEM artsey_combo_7[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM artsey_combo_8[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM artsey_combo_9[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM artsey_combo_0[] = {KC_5, KC_6, COMBO_END};

const uint16_t PROGMEM artsey_combo_MOUSE_ON[] = {A_PAR, KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_MOUSE_OFF[] = {KC_BTN1, KC_MS_D, KC_BTN2, COMBO_END};
const uint16_t PROGMEM artsey_combo_NAV_TO_MOUSE[] = {KC_HOME, KC_DOWN, KC_END, COMBO_END};
const uint16_t PROGMEM artsey_combo_NAV_ON[] = {E_SYM, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_NAV_OFF[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM artsey_combo_MOUSE_TO_NAV[] = {KC_MS_L, KC_MS_U, KC_MS_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(artsey_combo_B, KC_B),
  COMBO(artsey_combo_C, KC_C),
  COMBO(artsey_combo_D, KC_D),
  COMBO(artsey_combo_F, KC_F),
  COMBO(artsey_combo_G, KC_G),
  COMBO(artsey_combo_H, KC_H),
  COMBO(artsey_combo_J, KC_J),
  COMBO(artsey_combo_K, KC_K),
  COMBO(artsey_combo_L, KC_L),
  COMBO(artsey_combo_M, KC_M),
  COMBO(artsey_combo_N, KC_N),
  COMBO(artsey_combo_P, KC_P),
  COMBO(artsey_combo_Q, KC_Q),
  COMBO(artsey_combo_U, KC_U),
  COMBO(artsey_combo_V, KC_V),
  COMBO(artsey_combo_W, KC_W),
  COMBO(artsey_combo_X, KC_X),
  COMBO(artsey_combo_Z, KC_Z),
  COMBO(artsey_combo_AUML, ALGR(KC_Q)),
  COMBO(artsey_combo_OUML, ALGR(KC_P)),
  COMBO(artsey_combo_QUOT, KC_QUOT),
  COMBO(artsey_combo_DOT, KC_DOT),
  COMBO(artsey_combo_COMM, KC_COMM),
  COMBO(artsey_combo_SLSH, KC_SLSH),
  COMBO(artsey_combo_EXLM, KC_EXLM),
  COMBO(artsey_combo_ENT, KC_ENT),
  COMBO(artsey_combo_SPC, KC_SPC),
  COMBO(artsey_combo_BSPC, KC_BSPC),
  COMBO(artsey_combo_DEL, KC_DEL),
  COMBO(artsey_combo_ESC, KC_ESC),
  COMBO(artsey_combo_TAB, KC_TAB),
  COMBO(artsey_combo_LCTL, OSM(MOD_LCTL)),
  COMBO(artsey_combo_LGUI, OSM(MOD_LGUI)),
  COMBO(artsey_combo_LALT, OSM(MOD_LALT)),
  COMBO(artsey_combo_LSFT, OSM(MOD_LSFT)),
  COMBO(artsey_combo_CAPS_WORD, CW_TOGG),
  COMBO(artsey_combo_CAPS, KC_CAPS),
  COMBO(artsey_combo_7, KC_7),
  COMBO(artsey_combo_8, KC_8),
  COMBO(artsey_combo_9, KC_9),
  COMBO(artsey_combo_0, KC_0),
  COMBO(artsey_combo_MOUSE_ON, TG(LAYER_MOUSE)),
  COMBO(artsey_combo_MOUSE_OFF, TG(LAYER_MOUSE)),
  COMBO(artsey_combo_NAV_TO_MOUSE, TO(LAYER_MOUSE)),
  COMBO(artsey_combo_NAV_ON, TG(LAYER_NAV)),
  COMBO(artsey_combo_NAV_OFF, TG(LAYER_NAV)),
  COMBO(artsey_combo_MOUSE_TO_NAV, TO(LAYER_NAV)),
};

#if defined(ENCODER_MAP_ENABLE)
#if defined(SWAP_HANDS_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 0, 1 };
#endif // defined(SWAP_HANDS_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_BASE]  =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(SFT_ALT_TAB, ALT_TAB) },
    [LAYER_PAR]   =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_NUM]   =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_SYM]   =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_CUS]   =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_MOUSE] =  { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [LAYER_NAV]   =  { ENCODER_CCW_CW(KC_MS_L, KC_MS_R),  ENCODER_CCW_CW(KC_MS_D, KC_MS_U) },
    [LAYER_UTIL]  =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) }
};
#endif // defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case SFT_ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_LSFT);
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      break;
    case SH_OFF:
      is_swap_hands_active = false;
      break;
    case SH_ON:
      is_swap_hands_active = true;
      break;
  }

  if (is_swap_hands_active) {
    switch (keycode) {
      case KC_LEFT:
        if (record->event.pressed) {
          register_code(KC_RGHT);
        } else {
          unregister_code(KC_RGHT);
        }
        return false;
      case KC_RGHT:
        if (record->event.pressed) {
          register_code(KC_LEFT);
        } else {
          unregister_code(KC_LEFT);
        }
        return false;
      case KC_HOME:
        if (record->event.pressed) {
          register_code(KC_END);
        } else {
          unregister_code(KC_END);
        }
        return false;
      case KC_END:
        if (record->event.pressed) {
          register_code(KC_HOME);
        } else {
          unregister_code(KC_HOME);
        }
        return false;
      case KC_MS_L:
        if (record->event.pressed) {
          register_code(KC_MS_R);
        } else {
          unregister_code(KC_MS_R);
        }
        return false;
      case KC_MS_R:
        if (record->event.pressed) {
          register_code(KC_MS_L);
        } else {
          unregister_code(KC_MS_L);
        }
        return false;
    }
  }

  return true;
}

void matrix_scan_user(void) {
  // ALT_TAB timer
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void u_set_key_color(uint8_t key, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, RGB_MATRIX_DEFAULT_VAL};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(key, rgb.r, rgb.g, rgb.b);
}

void set_artsey_color(uint8_t h, uint8_t s, uint8_t v) {
  for (uint8_t i = 10; i < 20; i++) {
    if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
      continue;
    }

    u_set_key_color(i, h, s, v);
  }
}

bool rgb_matrix_indicators_user() {
  if (is_swap_hands_active) {
    u_set_key_color(5, HSV_GREEN);
    u_set_key_color(9, HSV_RED);
  } else {
    u_set_key_color(5, HSV_RED);
    u_set_key_color(9, HSV_GREEN);
  }

  if (host_keyboard_led_state().caps_lock) {
    set_artsey_color(HSV_RED);
  }

  switch (get_highest_layer(layer_state|default_layer_state)) {
    case LAYER_MOUSE:
      set_artsey_color(HSV_WHITE);
      break;
    case LAYER_NAV:
      set_artsey_color(HSV_PURPLE);
      break;
    case LAYER_UTIL:
      for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
          u_set_key_color(i, HSV_RED);
        }
      }
  }

  return false;
}
