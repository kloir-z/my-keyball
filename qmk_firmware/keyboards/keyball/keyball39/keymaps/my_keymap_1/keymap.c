/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licensed/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

static uint16_t combo_timer = 0;

enum custom_keycodes {
    MACRO_PAREN = SAFE_RANGE,
    MACRO_BRAC,
    COMBO_ESC_LANG2,
    COMBO_SHIFT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_PAREN:
            if (record->event.pressed) {
                tap_code16(S(KC_8));
                wait_ms(25);
                tap_code16(S(KC_9));
                wait_ms(25);
                tap_code(KC_LEFT);
            }
            return false;
        case MACRO_BRAC:
            if (record->event.pressed) {
                tap_code(KC_RBRC);
                wait_ms(25);
                tap_code(KC_NUHS);
                wait_ms(25);
                tap_code(KC_LEFT);
            }
            return false;
        case COMBO_ESC_LANG2:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                tap_code(KC_LANGUAGE_2);
            }
            return false;
        case COMBO_SHIFT:
            if (record->event.pressed) {
                combo_timer = timer_read();
                register_mods(MOD_LSFT);
            } else {
                if (timer_elapsed(combo_timer) < TAPPING_TERM) {
                    unregister_mods(MOD_LSFT);
                    set_oneshot_mods(MOD_LSFT);
                } else {
                    unregister_mods(MOD_LSFT);
                }
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM qw_combo[]         = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[]         = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM op_combo[]         = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pl_combo[]         = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM lmin_combo[]       = {KC_L, KC_MINS, COMBO_END};
const uint16_t PROGMEM jk_combo[]         = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[]         = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM uo_combo[]         = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM ip_combo[]         = {KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM up_combo[]         = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM jl_combo[]         = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM kminus_combo[]     = {KC_K, KC_MINS, COMBO_END};
const uint16_t PROGMEM jminus_combo[]     = {KC_J, KC_MINS, COMBO_END};
const uint16_t PROGMEM mdot_combo[]       = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM commslash_combo[]  = {KC_COMM, KC_SLSH, COMBO_END};
const uint16_t PROGMEM qwe_combo[]        = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wr_combo[]         = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM sf_combo[]         = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM xv_combo[]         = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM ad_combo[]         = {KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM dg_combo[]         = {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM sd_combo[]         = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ctrl_shift_combo[] = {KC_LCTL, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[]         = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM we_combo[]         = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[]         = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lboot_combo[]      = {KC_Q, KC_W, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rboot_combo[]      = {KC_N, KC_M, KC_O, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(qw_combo, COMBO_ESC_LANG2),
    COMBO(as_combo, KC_TAB),
    COMBO(op_combo, KC_BACKSPACE),
    COMBO(pl_combo, KC_DELETE),
    COMBO(lmin_combo, KC_ENTER),
    COMBO(jk_combo, KC_LANGUAGE_1),
    COMBO(df_combo, KC_LANGUAGE_2),
    COMBO(uo_combo, KC_RBRC),
    COMBO(ip_combo, KC_NUHS),
    COMBO(up_combo, MACRO_BRAC),
    COMBO(jl_combo, S(KC_8)),
    COMBO(kminus_combo, S(KC_9)),
    COMBO(jminus_combo, MACRO_PAREN),
    COMBO(mdot_combo, S(KC_RBRC)),
    COMBO(commslash_combo, S(KC_NUHS)),
    COMBO(qwe_combo, LALT(KC_F4)),
    COMBO(wr_combo, S(KC_SCLN)),
    COMBO(sf_combo, KC_MINS),
    COMBO(xv_combo, S(KC_QUOT)),
    COMBO(ad_combo, KC_SLSH),
    COMBO(dg_combo, S(KC_MINS)),
    COMBO(sd_combo, COMBO_SHIFT),
    COMBO(kl_combo, COMBO_SHIFT),
    COMBO(ctrl_shift_combo, C(S(KC_NO))),
    COMBO(we_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(io_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(lboot_combo, QK_BOOT),
    COMBO(rboot_combo, QK_BOOT),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______ , _______ , _______ 
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______ , _______ , _______ 
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______ , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______ , _______ , _______ 
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
