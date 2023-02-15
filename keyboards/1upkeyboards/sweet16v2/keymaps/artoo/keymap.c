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

enum sweet16_keymap_artoo_layers {
  LAYER_BASE = 0,
  LAYER_PAR,
  LAYER_NUM,
  LAYER_SYM,
  LAYER_CUS,
  LAYER_MOUSE,
  LAYER_NAV,
};

#define A_PAR LT(LAYER_PAR, KC_A)
#define S_NUM LT(LAYER_NUM, KC_S)
#define E_SYM LT(LAYER_SYM, KC_E)
#define O_CUS LT(LAYER_CUS, KC_O)

// convenience shorthands
#define _____________TRNS_ROW_____________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_LAYER_BASE             \
KC_MUTE,HYPR(KC_F),HYPR(KC_U),QK_BOOT,\
 SH_OFF,G(KC_D),TO(LAYER_BASE),SH_ON, \
    A_PAR,    KC_R,    KC_T,   S_NUM, \
    E_SYM,    KC_Y,    KC_I,   O_CUS

#define LAYOUT_LAYER_PAR              \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
    KC_NO, KC_LPRN, KC_RPRN, KC_RCBR, \
    KC_NO, KC_LBRC, KC_RBRC, KC_LCBR

#define LAYOUT_LAYER_NUM              \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
     KC_1,    KC_2,    KC_3,   KC_NO, \
     KC_4,    KC_5,    KC_6,   KC_NO

#define LAYOUT_LAYER_SYM              \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
  KC_EXLM, KC_SLSH, KC_SCLN,  KC_GRV, \
    KC_NO, KC_QUES, KC_MINS,  KC_EQL

#define LAYOUT_LAYER_CUS              \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
  KC_MUTE,  KC_INS, KC_VOLU,   KC_NO, \
OSM(MOD_RALT), KC_PSCR, KC_VOLD,   KC_NO

#define LAYOUT_LAYER_MOUSE            \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, \
  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D

#define LAYOUT_LAYER_NAV              \
  _____________TRNS_ROW_____________, \
  _____________TRNS_ROW_____________, \
  KC_HOME,   KC_UP,  KC_END, KC_PGUP, \
  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN

// Only mirror the two bottom rows
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
  {{3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x4(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE]  = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_PAR]   = LAYOUT_wrapper(LAYOUT_LAYER_PAR),
  [LAYER_NUM]   = LAYOUT_wrapper(LAYOUT_LAYER_NUM),
  [LAYER_SYM]   = LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_CUS]   = LAYOUT_wrapper(LAYOUT_LAYER_CUS),
  [LAYER_MOUSE] = LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_NAV]   = LAYOUT_wrapper(LAYOUT_LAYER_NAV),
};

const uint16_t PROGMEM artsey_combo_B[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_C[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_D[] = {KC_A, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_F[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM artsey_combo_G[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_H[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_J[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_K[] = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_L[] = {KC_E, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_M[] = {KC_Y, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_N[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_P[] = {KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_Q[] = {KC_A, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_U[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_V[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_W[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_X[] = {KC_R, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_Z[] = {KC_A, KC_R, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_AUML[] = {KC_E, KC_R, KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_OUML[] = {KC_A, KC_Y, KC_I, KC_S, COMBO_END};

const uint16_t PROGMEM artsey_combo_QUOT[] = {KC_A, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_DOT[] = {KC_A, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_COMM[] = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_SLSH[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_EXLM[] = {KC_T, KC_I, COMBO_END};

const uint16_t PROGMEM artsey_combo_ENT[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM artsey_combo_SPC[] = {KC_E, KC_Y, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_BSPC[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM artsey_combo_DEL[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_ESC[] = {KC_A, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM artsey_combo_TAB[] = {KC_A, KC_R, KC_T, KC_Y, COMBO_END};

const uint16_t PROGMEM artsey_combo_LCTL[] = {KC_E, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_LGUI[] = {KC_Y, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_LALT[] = {KC_I, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_LSFT[] = {KC_E, KC_R, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM artsey_combo_CAPS_WORD[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM artsey_combo_CAPS[] = {KC_A, KC_Y, KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM artsey_combo_7[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM artsey_combo_8[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM artsey_combo_9[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM artsey_combo_0[] = {KC_5, KC_6, COMBO_END};

const uint16_t PROGMEM artsey_combo_MOUSE_ON[] = {KC_A, KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM artsey_combo_MOUSE_OFF[] = {KC_BTN1, KC_MS_D, KC_BTN2, COMBO_END};
const uint16_t PROGMEM artsey_combo_NAV_ON[] = {KC_E, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM artsey_combo_NAV_OFF[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END};

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
  COMBO(artsey_combo_CAPS_WORD, CAPS_WORD),
  COMBO(artsey_combo_CAPS, KC_CAPS),
  COMBO(artsey_combo_7, KC_7),
  COMBO(artsey_combo_8, KC_8),
  COMBO(artsey_combo_9, KC_9),
  COMBO(artsey_combo_0, KC_0),
  COMBO(artsey_combo_MOUSE_ON, TG(LAYER_MOUSE)),
  COMBO(artsey_combo_MOUSE_OFF, TG(LAYER_MOUSE)),
  COMBO(artsey_combo_NAV_ON, TG(LAYER_NAV)),
  COMBO(artsey_combo_NAV_OFF, TG(LAYER_NAV)),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),      ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [1] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),      ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [2] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),      ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [3] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),      ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [4] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),      ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [5] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),      ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }
};
#endif