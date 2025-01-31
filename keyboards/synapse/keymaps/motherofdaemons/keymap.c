/* Copyright 2021 qpockets
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

// Layers
enum layers{
  _BASE,
  _SYM,
  _NAV
};

// Combo events
enum combo_events {
 COMBO_BSPC,
 COMBO_ENT,
 COMBO_TAB,
 COMBO_ESC,
 COMBO_DEL
};

// Tap dance

enum {
    TD_CTRL_ESC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
};

// Mod taps
#define KC_DN_BSPC LT(_NAV, KC_BSPC)
#define KC_UP_SPC LT(_SYM, KC_SPC)
#define KC_SSLSH RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default(
    KC_GRV,  KC_Q,    KC_W,    KC_E,          KC_R,      KC_T,      KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    KC_QUOT,
    TD(TD_CTRL_ESC), KC_A,    KC_S,    KC_D,          KC_F,     KC_G,      KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,          KC_V,      KC_B,      KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SSLSH,
    _______, KC_LGUI, KC_LALT, KC_DN_BSPC,    KC_UP_SPC, KC_RALT,   KC_RGUI, _______
  ),

 [_SYM] = LAYOUT_default(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_TRNS,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
    KC_TRNS, KC_PIPE, KC_BSLS, KC_LPRN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_RPRN, KC_PLUS,  KC_UNDS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT_default(
    QK_BOOT, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_END, KC_TRNS,
    KC_TRNS, KC_F4, KC_F5,  KC_F6,  KC_F7,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT,
    KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,  KC_ENT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};



// Combos
const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL)
};
