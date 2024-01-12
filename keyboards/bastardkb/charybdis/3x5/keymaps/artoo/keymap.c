/**
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 Arto Olli <arto.olli@live.com>
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

enum charybdis_keymap_artoo_layers {
    LAYER_BASE = 0,
    LAYER_FRF,
    LAYER_MC,
    LAYER_GAME,
    LAYER_MEDIA,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_FUN,
    LAYER_SNIPE,
};

enum custom_keycodes {
    BOWSNIP = QK_USER,
};

// Automatically enable sniping when the mouse layer is on.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_MOUSE

#define ESC_FUN LT(LAYER_FUN, KC_ESC)
#define SPC_NUM LT(LAYER_NUM, KC_SPC)
#define TAB_SYM LT(LAYER_SYM, KC_TAB)
#define ENT_MED LT(LAYER_MEDIA, KC_ENT)
#define BSP_NAV LT(LAYER_NAV, KC_BSPC)

#define MOUSE(KC) LT(LAYER_MOUSE, KC)

#define MS_L KC_MS_LEFT
#define MS_R KC_MS_RIGHT
#define MS_D KC_MS_DOWN
#define MS_U KC_MS_UP

#define WH_L KC_MS_WH_LEFT
#define WH_R KC_MS_WH_RIGHT
#define WH_D KC_MS_WH_DOWN
#define WH_U KC_MS_WH_UP

// clang-format off
/** Convenience macro. */
#define _KC_LAYOUT_wrapper(                                                                             \
         k00,      k01,      k02,      k03,      k04,      k05,      k06,      k07,      k08,      k09, \
         k10,      k11,      k12,      k13,      k14,      k15,      k16,      k17,      k18,      k19, \
         k20,      k21,      k22,      k23,      k24,      k25,      k26,      k27,      k28,      k29, \
         ...)                                                                                           \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05, KC_##k06, KC_##k07, KC_##k08, KC_##k09, \
    KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_##k16, KC_##k17, KC_##k18, KC_##k19, \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, \
    __VA_ARGS__
#define KC_LAYOUT_wrapper(...) _KC_LAYOUT_wrapper(__VA_ARGS__)

// Tap Dance
enum {
    CPS_SLP,
};

tap_dance_action_t tap_dance_actions[] = {
    [CPS_SLP] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS, KC_SLEP),
};

// Key Overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, BSP_NAV, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

/** Base layer */
#define LAYOUT_LAYER_BASE KC_LAYOUT_wrapper(                    \
       Q,    O,    M,    B, COMM,  DOT,    F,    W,    D, QUOT, \
       N,    S,    R,    T,    G,    Y,    H,    E,    A,    I, \
       Z,    X,    K,    C,    V,    J,    L,    U,    P, SLSH, \
       ESC_FUN, SPC_NUM, TAB_SYM,    ENT_MED, BSP_NAV)

/** Convenience key shorthands. */
#define U_NA KC_NO // Present but not available for use.
#define U_NU KC_NO // Available but not used.

/** Umlauts */
#define U_AUML ALGR(KC_Q)
#define U_OUML ALGR(KC_P)
#define U_UUML ALGR(KC_Y)

/** Circumflex */
#define U_CIRC ALGR(KC_6)

/** Convenience row shorthands. */
#define __________________RESET_L__________________ \
    QK_BOOT,DF(LAYER_GAME),DF(LAYER_MC),DF(LAYER_BASE),DF(LAYER_FRF)
#define __________________RESET_R__________________ \
    DF(LAYER_FRF),DF(LAYER_BASE),DF(LAYER_MC),DF(LAYER_GAME),QK_BOOT
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA
#define ______________HOME_ROW_ALGR_L______________    U_NA, KC_ALGR,    U_NA,    U_NA,    U_NA
#define ______________HOME_ROW_GACS_R______________    U_NA, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI
#define ______________HOME_ROW_ALGR_R______________    U_NA,    U_NA,    U_NA, KC_ALGR,    U_NA
#define ______________EMPTY_HALF_ROW_______________    U_NU,    U_NU,    U_NU,    U_NU,    U_NU
#define _______________TRNS_HALF_ROW_______________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

/** Layers. */

// Media.
#define LAYOUT_LAYER_MEDIA                                                                    \
  G(KC_F12), KC_WBAK, KC_VOLU, KC_WFWD,G(KC_F10),__________________RESET_R__________________, \
  G(KC_F11), KC_MPRV, KC_VOLD,KC_MNXT,TD(CPS_SLP),______________HOME_ROW_GACS_R______________,\
    KC_CALC, KC_MAIL, KC_WSCH, KC_MYCM, KC_WREF, ______________HOME_ROW_ALGR_R______________, \
                       KC_MUTE, KC_MPLY, KC_MSTP,    U_NA,    U_NA

// Navigation.
#define LAYOUT_LAYER_NAV                                                                      \
    KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_INS, __________________RESET_R__________________, \
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG, ______________HOME_ROW_GACS_R______________, \
       U_NU,  U_OUML,  U_AUML,    U_NU,    U_NU, ______________HOME_ROW_ALGR_R______________, \
                       KC_APP,  KC_SPC,  KC_TAB,    U_NA,    U_NA

// Mouse.
#define LAYOUT_LAYER_MOUSE                                                                    \
    __________________RESET_L__________________, __________________RESET_R__________________, \
    ______________HOME_ROW_GACS_L______________, ______________HOME_ROW_GACS_R______________, \
       U_NA, DRGSCRL, SNIPING,  EE_CLR, QK_BOOT, KC_BTN3, KC_BTN1, KC_BTN2, DRGSCRL,    U_NA, \
                      KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN5, KC_BTN4

// Symbols.
#define LAYOUT_LAYER_SYM                                                                      \
    __________________RESET_L__________________, KC_LCBR, KC_AMPR, KC_ASTR, KC_RPRN, KC_RCBR, \
    ______________HOME_ROW_GACS_L______________, KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, \
    ______________HOME_ROW_ALGR_L______________, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, \
                         U_NA,    U_NA,    U_NA, KC_UNDS, KC_LPRN

// Numerals.
#define LAYOUT_LAYER_NUM                                                                      \
    __________________RESET_L__________________, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, \
    ______________HOME_ROW_GACS_L______________,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, \
    ______________HOME_ROW_ALGR_L______________, KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, \
                         U_NA,    U_NA,    U_NA, KC_MINS,    KC_0

// Function keys.
#define LAYOUT_LAYER_FUN                                                                      \
    __________________RESET_L__________________, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12, \
    ______________HOME_ROW_GACS_L______________, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11, \
    ______________HOME_ROW_ALGR_L______________, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, \
                         U_NA,    U_NA,    U_NA,  KC_ENT, KC_BSPC

// Layer for holding snipe while keeping a bow extended in Mincraft
#define LAYOUT_LAYER_SNIPE                                                                    \
    _______________TRNS_HALF_ROW_______________, _______________TRNS_HALF_ROW_______________, \
    _______________TRNS_HALF_ROW_______________, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SNIPING, \
    _______________TRNS_HALF_ROW_______________, _______________TRNS_HALF_ROW_______________, \
                      _______________TRNS_HALF_ROW_______________

/**
 * Add Home Row mod to a layout.
 *
 * Expects a 10-key per row layout.  Adds support for GACS (Gui, Alt, Shift, Ctl)
 * home row and AltGr on bottom row pinky column.  The layout passed in parameter must contain at least 29 keycodes.
 *
 * This is meant to be used with `LAYOUT_LAYER_BASE` defined above, eg.:
 *
 *     HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE)
 */
#define _HOME_ROW_MOD_GACS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      LGUI_T(L10), LALT_T(L11), LCTL_T(L12), LSFT_T(L13),        L14,  \
             R15,  RSFT_T(R16), RCTL_T(R17), LALT_T(R18), RGUI_T(R19), \
             L20,  ALGR_T(L21),        L22,         L23,         L24,  \
             R25,         R26,         R27,  ALGR_T(R28),        R29,  \
      __VA_ARGS__
#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)

#define _RIGHT_ONLY_HOME_ROW_MOD_GACS(                                 \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,  RSFT_T(R16), RCTL_T(R17), LALT_T(R18), RGUI_T(R19), \
             L20,         L21,         L22,         L23,         L24,  \
             R25,         R26,         R27,  ALGR_T(R28),        R29,  \
      __VA_ARGS__
#define RIGHT_ONLY_HOME_ROW_MOD_GACS(...) _RIGHT_ONLY_HOME_ROW_MOD_GACS(__VA_ARGS__)

/**
 * Layer for typing in The Fun Riform.
 *
 * Replaces qwerty q with ü and x with circumflex.
*/
#define _FRF_MOD(                                               \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,             \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,             \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,             \
    ...)                                                          \
         U_UUML,        L01,        L02,        L03,        L04,  \
            R05,        R06,        R07,        R08,        R09,  \
            L10,        L11,        L12,        L13,        L14,  \
            R15,        R16,        R17,        R18,        R19,  \
      MOUSE(L20),    U_CIRC,        L22,        L23,        L24,  \
            R25,        R26,        R27,        R28,  MOUSE(R29), \
      __VA_ARGS__
#define FRF_MOD(...) _FRF_MOD(__VA_ARGS__)

/**
 * Add mouse layer keys to a layout.
 *
 * Expects a 10-key per row layout.  The layout passed in parameter must contain
 * at least 30 keycodes.
 *
 * This is meant to be used with `LAYOUT_LAYER_BASE` defined above, eg.:
 *
 *     MOUSE_MOD(LAYOUT_LAYER_BASE)
 */
#define _MOUSE_MOD(                                               \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,             \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,             \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,             \
    ...)                                                          \
            L00,        L01,        L02,        L03,        L04,  \
            R05,        R06,        R07,        R08,        R09,  \
            L10,        L11,        L12,        L13,        L14,  \
            R15,        R16,        R17,        R18,        R19,  \
      MOUSE(L20),       L21,        L22,        L23,        L24,  \
            R25,        R26,        R27,        R28,  MOUSE(R29), \
      __VA_ARGS__
#define MOUSE_MOD(...) _MOUSE_MOD(__VA_ARGS__)

#define _MC_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,             \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,             \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,             \
              L32, L33, L34,                                      \
    ...)                                                          \
            L00,        L01,        L02,        L03,        L04,  \
            R05,        R06,        R07,        R08,        R09,  \
            L10,        L11,        L12,        L13,        L14,  \
            R15,        R16,    BOWSNIP,        R18,        R19,  \
            L20,        L21,        L22,        L23,        L24,  \
            R25,        R26,        R27,        R28,  MOUSE(R29), \
                                 L32,KC_SPC,LT(LAYER_NUM, KC_TAB),\
      __VA_ARGS__
#define MC_MOD(...) _MC_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] =    LAYOUT_wrapper(MOUSE_MOD(HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))),
  [LAYER_FRF] =     LAYOUT_wrapper(MOUSE_MOD(HOME_ROW_MOD_GACS(FRF_MOD(LAYOUT_LAYER_BASE)))),
  [LAYER_MC] =      LAYOUT_wrapper(MC_MOD(LAYOUT_LAYER_BASE)),
  [LAYER_GAME] =    LAYOUT_wrapper(MOUSE_MOD(RIGHT_ONLY_HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))),
  [LAYER_MEDIA] =   LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
  [LAYER_NAV] =     LAYOUT_wrapper(LAYOUT_LAYER_NAV),
  [LAYER_MOUSE] =   LAYOUT_wrapper(LAYOUT_LAYER_MOUSE),
  [LAYER_SYM] =     LAYOUT_wrapper(LAYOUT_LAYER_SYM),
  [LAYER_NUM] =     LAYOUT_wrapper(LAYOUT_LAYER_NUM),
  [LAYER_FUN] =     LAYOUT_wrapper(LAYOUT_LAYER_FUN),
  [LAYER_SNIPE] =   LAYOUT_wrapper(LAYOUT_LAYER_SNIPE),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BOWSNIP:
            if (record->event.pressed) {
                register_code(KC_E);
                layer_on(LAYER_SNIPE);
            } else {
                layer_off(LAYER_SNIPE);
                unregister_code(KC_E);
            }

            break;
        case ALGR_T(U_CIRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(U_CIRC);
                return false;
            }
            break;
    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(default_layer_state)) {
        case LAYER_GAME:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
            break;
        default:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
    }
    return state;
}

#if defined(POINTING_DEVICE_ENABLE) && defined(CHARYBDIS_AUTO_SNIPING_ON_LAYER)
layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#endif // POINTING_DEVICE_ENABLE && CHARYBDIS_AUTO_SNIPING_ON_LAYER

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

void u_set_key_color(uint8_t key, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, RGB_MATRIX_DEFAULT_VAL};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(key, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_user() {
    // Set inner columns to red if CapsLock is on
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 12; i <= 32; i++) {
            u_set_key_color(i, HSV_RED);

            if (i == 14) {
                i = 29;
            }
        }
    }

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case LAYER_SNIPE:
        case LAYER_MC:
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                switch (i) {
                    case 0:
                    case 1:
                    case 4:
                    case 7:
                    case 8:
                    case 10:
                    case 16:
                        // Movement
                        u_set_key_color(i, HSV_GREEN);
                        break;
                    case 28:
                        // Attack/Destroay
                        u_set_key_color(i, HSV_RED);
                        break;
                    case 31:
                        // Pick Block
                        u_set_key_color(i, HSV_CHARTREUSE);
                        break;
                    case 25:
                        // Use Item/Place Block
                        u_set_key_color(i, HSV_SPRINGGREEN);
                        break;
                    case 30:
                        // Drop Selected Item
                        u_set_key_color(i, HSV_TEAL);
                        break;
                    case 18:
                    case 19:
                    case 21:
                    case 22:
                    case 23:
                    case 24:
                    case 26:
                    case 27:
                    case 29:
                        // Hotbar Slot
                        u_set_key_color(i, HSV_AZURE);
                        break;
                    case 17:
                    case 32:
                        // Inventory
                        u_set_key_color(i, HSV_TURQUOISE);
                        break;
                    case 5:
                    case 6:
                        // Creative Mode
                        u_set_key_color(i, HSV_MAGENTA);
                        break;
                    case 2:
                    case 3:
                    case 34:
                        // Multiplayer
                        u_set_key_color(i, HSV_BLUE);
                        break;
                    case 33:
                        // Open Command
                        u_set_key_color(i, HSV_PURPLE);
                        break;
                    case 12:
                        // Advancements
                        u_set_key_color(i, HSV_YELLOW);
                        break;
                    case 20:
                        // Highlight Players
                        u_set_key_color(i, HSV_OFF);
                        break;
                    case 9:
                    case 11:
                    case 13:
                    case 14:
                        // Miscellaneous
                        u_set_key_color(i, HSV_ORANGE);
                        break;
                    case 15:
                        // Esc
                        u_set_key_color(i, HSV_PINK);
                        break;
                }
            }
        break;
    }

    return false;
}
#endif
