/*
Copyright 2020 Danny Nguyen <danny@keeb.io>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define launch_app(app) (SS_TAP(X_LGUI)SS_DELAY(300) app SS_DELAY(300)SS_TAP(X_ENT))

enum custom_keycodes {
    TP = SAFE_RANGE,
    TERM,
    SSH_METER,
    BUILD,
    SPOTIFY,
    VS_CODE,
    CHROME,
    FILE_EXPLORER,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TP:
        if (record->event.pressed) {
            SEND_STRING("TransactionProcess --event=\"MUSE_V1;");
        }
        break;
    case TERM:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("t"));
        }
        break;
    case SSH_METER:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("t")SS_DELAY(500)"ssh meter\n"SS_DELAY(500)"itron\n");
        }
        break;
    case BUILD:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("b")));
        }
        break;
    case SPOTIFY:
        if (record->event.pressed) {
            SEND_STRING(launch_app("spotify"));
        }
        break;
    case VS_CODE:
        if (record->event.pressed) {
            SEND_STRING(launch_app("visual studio code"));
        }
        break;
    case CHROME:
        if (record->event.pressed) {
            SEND_STRING(launch_app("chrome"));
        }
        break;
    case FILE_EXPLORER:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("e"));
        }
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x6(
        QK_BOOT,  SSH_METER,    KC_2,    KC_3,    KC_4,   TERM,
        KC_TAB,  KC_Q,    CHROME,    FILE_EXPLORER,    TP,    TERM,
        KC_ESC,  KC_A,    SPOTIFY,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    VS_CODE,    KC_V,    BUILD,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV,   KC_MPLY, KC_MNXT
    ),
    [1] = LAYOUT_ortho_5x6(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_ortho_5x6(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_ortho_5x6(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
    )
};
