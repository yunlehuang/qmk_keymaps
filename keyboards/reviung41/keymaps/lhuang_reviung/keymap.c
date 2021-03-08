/* Copyright 2020 gtips
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

#define _WIN 0
#define _MAC 1
#define _SYM 2
#define _NAV 3
#define _NUM 4
#define _NUM2 5
#define _GAM 6
#define _MOU 7
#define _MUS 8

#define NUM_SCN LT(_NUM, KC_SCLN)
#define OSM_SFT OSM(MOD_LSFT)
#define CTR_LEF C(KC_LEFT)
#define CTR_RIG C(KC_RGHT)
#define PREV RCS(KC_TAB)
#define NEXT C(KC_TAB)
#define VSC_PRE LCTL(KC_PGUP) //previous tab in VS code
#define VSC_NEX LCTL(KC_PGDN) //next tab in VS code
#define ALT_NUM MO(_NUM2)
#define SPC_SFT SFT_T(KC_SPC)
#define SYMBOL MO(_SYM)
#define NAVIGA MO(_NAV)
#define MOUSE_ MO(_MOU)
#define LFT_NUM MO(_NUM2)
#define MUS_STG MO(_MUS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WIN] = LAYOUT_reviung41(
    KC_LGUI, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LFT_NUM, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    NUM_SCN, KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MUS_STG,
                                        KC_LCTL, SYMBOL,  SPC_SFT, NAVIGA,  KC_ESC
  ),
  
  [_MAC] = LAYOUT_reviung41(
    KC_LCTL, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                        KC_LGUI, _______, _______, _______, _______
  ),
  
  [_SYM] = LAYOUT_reviung41(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,  _______,
    _______, KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_BSLS,          KC_PIPE, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS, _______,
    _______, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX,          XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
                                        _______, XXXXXXX, _______, MOUSE_ , _______
  ),
  
  [_NAV] = LAYOUT_reviung41(
    _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_WH_U, _______,
    _______, _______, _______, PREV,    NEXT,    _______,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, _______,
    _______, _______, _______, _______, _______, _______,          _______, CTR_LEF, _______, CTR_RIG, _______, _______,
                                        _______, MOUSE_ , _______, XXXXXXX, _______
  ),

  [_NUM] = LAYOUT_reviung41(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,          KC_PSLS, KC_7,    KC_8,    KC_9,    _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,          KC_PAST, KC_4,    KC_5,    KC_6,    _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          KC_PMNS, KC_1,    KC_2,    KC_3,    _______, _______,
                                        _______, _______, KC_PPLS, KC_0,    KC_DOT
  ),

  [_NUM2] = LAYOUT_reviung41(
    _______, KC_1,    KC_2,    KC_3,    KC_0,    _______,          _______, _______, _______, _______, _______, _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    _______, _______,          _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______
  ),

  [_GAM] = LAYOUT_reviung41(
    KC_2,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,             _______, _______, _______, _______, _______, _______,
    KC_3,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,             _______, _______, _______, _______, _______, _______,
    KC_4,    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,             _______, _______, _______, _______, _______, _______,
                                        KC_LCTL, KC_SPC, KC_1,     _______, _______
  ),

  [_MOU] = LAYOUT_reviung41(
    _______, _______, _______, KC_MS_U, _______, _______,          _______, _______, KC_WH_U, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,          _______, KC_BTN1, KC_WH_D, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, KC_BTN3, _______, _______, _______,
                                        _______, XXXXXXX, _______, XXXXXXX, _______
  ),

  [_MUS] = LAYOUT_reviung41(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,TO(_WIN),TO(_MAC),
    _______, _______, _______, _______, _______, _______,          _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
    RESET,   _______, _______, _______, _______, _______,          _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, XXXXXXX,
                                        _______, _______, _______, _______, _______
  ),
};

enum combos { 
    Q_W_TAB,
    J_COMM_ENT,
    P_BSPC_DEL,
    J_K_BSPC,
    EXLM_AT_1,
    AT_HASH_2,
    HASH_DLR_3,
    GRV_TILD_4,
    TILD_LPRN_5,
    LPRN_RPRN_6,
    LABK_RABK_0,

    CV_COMBO,
    VB_COMBO,
    NY_COMBO
};

const uint16_t PROGMEM q_w_tab_combo[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM j_comm_ent_combo[] = { KC_J, KC_COMM, COMBO_END};
const uint16_t PROGMEM p_bspc_del_combo[] = { KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM j_k_bspc_combo[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM exlm_at_1_combo[] = { KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM at_hash_2_combo[] = { KC_AT, KC_HASH, COMBO_END};
const uint16_t PROGMEM hash_dlr_3_combo[] = { KC_HASH, KC_DLR, COMBO_END};
const uint16_t PROGMEM grv_tild_4_combo[] = { KC_GRV, KC_TILD, COMBO_END};
const uint16_t PROGMEM tild_lprn_5_combo[] = { KC_TILD, KC_LPRN, COMBO_END};
const uint16_t PROGMEM lprn_rprn_6_combo[] = { KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM labk_rabk_0_combo[] = { KC_LABK, KC_RABK, COMBO_END};

const uint16_t PROGMEM comment_combo[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM uncomment_combo[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM vsc_flip_combo[] = { KC_N, KC_Y, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    //basic combos
    [Q_W_TAB] = COMBO(q_w_tab_combo, KC_TAB),
    [J_COMM_ENT] = COMBO(j_comm_ent_combo, KC_ENT),
    [P_BSPC_DEL] = COMBO(p_bspc_del_combo, KC_DEL),
    [J_K_BSPC] = COMBO(j_k_bspc_combo, KC_BSPC),
    [EXLM_AT_1] = COMBO(exlm_at_1_combo, KC_1),
    [AT_HASH_2] = COMBO(at_hash_2_combo, KC_2),
    [HASH_DLR_3] = COMBO(hash_dlr_3_combo, KC_3),
    [GRV_TILD_4] = COMBO(grv_tild_4_combo, KC_4),
    [TILD_LPRN_5] = COMBO(tild_lprn_5_combo, KC_5),
    [LPRN_RPRN_6] = COMBO(lprn_rprn_6_combo, KC_6),
    [LABK_RABK_0] = COMBO(labk_rabk_0_combo, KC_0),
    //action combos
    [CV_COMBO] = COMBO_ACTION(comment_combo),
    [VB_COMBO] = COMBO_ACTION(uncomment_combo),
    [NY_COMBO] = COMBO_ACTION(vsc_flip_combo)
    
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CV_COMBO:
        if (pressed) {
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_C);
        unregister_code(KC_LCTL);
        }
        break;
    case VB_COMBO:
        if (pressed) {
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_U);
        unregister_code(KC_LCTL);
        }
        break;
    case NY_COMBO:
        if (pressed) {
        register_code(KC_LALT);
        register_code(KC_LSFT);
        tap_code(KC_0);
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
        }
        break;
  }
}