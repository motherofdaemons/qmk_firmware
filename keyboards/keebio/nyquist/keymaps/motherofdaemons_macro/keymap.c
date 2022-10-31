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

#define _TP_LAYER 1

#define launch_app(app) (SEND_STRING(SS_TAP(X_LGUI)SS_DELAY(300) app SS_DELAY(300)SS_TAP(X_ENT)))
#define term_command(command) (SEND_STRING(SS_LGUI("t") SS_DELAY(300) command SS_TAP(X_ENT)))
enum custom_keycodes {
    TP = SAFE_RANGE,
    DUMP_EVENT_CALLBACKS,
    RECONFIGURE,
    CLEAR_BILLING,
    FILL_LP,
    DUMP_LP,
    LOAD_PROFILE_MAINT,
    WATCHDOG,
    LOGALL,
    SQL_TRACE,
    TERM,
    SSH_METER,
    BUILD,
    SPOTIFY,
    VS_CODE,
    CHROME,
    FILE_EXPLORER,
    SQLITE_BROWSER,
    LXC_BIONIC,
    LXC_TRUSTY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TP:
        if (record->event.pressed) {
            if (IS_LAYER_OFF(_TP_LAYER))
            {
                SEND_STRING("TransactionProcess");
                layer_on(_TP_LAYER);
            } else
            {
                layer_off(_TP_LAYER);
                SEND_STRING(SS_TAP(X_ENT));
            }
        }
        break;
    case DUMP_EVENT_CALLBACKS:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;DumpEventCallbacks;\"");
        }
        break;
    case RECONFIGURE:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;Reconfigure;ce.xml;\"");
        }
        break;
    case CLEAR_BILLING:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;ClearBilling;\"");
        }
        break;
    case LOAD_PROFILE_MAINT:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;LoadProfileMaintenance;\"");
        }
        break;
    case FILL_LP:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;FillLp;1,4000,0,0\"");
        }
        break;
    case DUMP_LP:
        if (record->event.pressed) {
            SEND_STRING(" --event=\"MUSE_V1;DumpLp;billingLoadProfile;All;ALL_DBS;BY_ID_LOW_TO_HIGH\"");
        }
        break;
    case WATCHDOG:
        if (record->event.pressed) {
            SEND_STRING(" --watchdogtimeout=99999");
        }
        break;
    case LOGALL:
        if (record->event.pressed) {
            SEND_STRING(" --logall");
        }
        break;
    case SQL_TRACE:
        if (record->event.pressed) {
            SEND_STRING(" --sqltrace");
        }
        break;
    case TERM:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("t"));
        }
        break;
    case SSH_METER:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("t")SS_DELAY(500)"ssh meter\n"SS_DELAY(1000)"itron\n");
        }
        break;
    case BUILD:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("b")));
        }
        break;
    case SPOTIFY:
        if (record->event.pressed) {
            launch_app("spotify");
        }
        break;
    case VS_CODE:
        if (record->event.pressed) {
            launch_app("visual studio code");
        }
        break;
    case CHROME:
        if (record->event.pressed) {
            launch_app("chrome");
        }
        break;
    case FILE_EXPLORER:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("e"));
        }
        break;
    case SQLITE_BROWSER:
        if (record->event.pressed) {
            launch_app("db browser");
        }
        break;
    case LXC_BIONIC:
        if (record->event.pressed) {
            term_command("enterContainer.sh acidburn-work-RIVA-FIRMWARE-bionic");
            SEND_STRING(SS_DELAY(300)"fish\n");
        }
        break;
    case LXC_TRUSTY:
        if (record->event.pressed) {
            term_command("enterContainer.sh acidburn-work-RIVA-FIRMWARE-trusty");
            SEND_STRING(SS_DELAY(300)"itron\n");
        }
        break;
    }

    return true;
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_WHITE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _TP_LAYER:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
    }
    return state;
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x6(
        QK_BOOT,  LXC_BIONIC,    LXC_TRUSTY,    SSH_METER,    KC_4,   TERM,
        KC_TAB,  KC_Q,    CHROME,    FILE_EXPLORER,    KC_R,    TERM,
        TP,  KC_A,    SPOTIFY,    SQLITE_BROWSER,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    VS_CODE,    KC_V,    BUILD,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV,   KC_MPLY, KC_MNXT
    ),
    [_TP_LAYER] = LAYOUT_ortho_5x6(
        _______, _______, _______, _______, _______, _______,
        _______, _______, WATCHDOG, DUMP_EVENT_CALLBACKS, RECONFIGURE, LOAD_PROFILE_MAINT,
        TP, LOGALL, SQL_TRACE, DUMP_LP, FILL_LP, _______,
        _______, _______, _______, CLEAR_BILLING, _______, _______,
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
