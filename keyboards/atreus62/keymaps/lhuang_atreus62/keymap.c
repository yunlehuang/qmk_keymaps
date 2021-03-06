
#include QMK_KEYBOARD_H

#define NUM_SCN LT(_NUM, KC_SCLN)
#define OSM_SFT OSM(MOD_LSFT)
#define CTR_LEF C(KC_LEFT)
#define CTR_RIG C(KC_RGHT)
#define PREV RCS(KC_TAB)
#define NEXT C(KC_TAB)
#define VSC_PRE LCTL(KC_PGUP) //previous tab in VS code
#define VSC_NEX LCTL(KC_PGDN) //next tab in VS code

#define _WIN 0
#define _MAC 1
#define _SYM 2
#define _NAV 3
#define _NUM 4
#define _GAM 5
#define _MOU 6
#define _MUS 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(_MUS),
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_LGUI, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    NUM_SCN, KC_QUOT,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, MO(_SYM),OSM_SFT, KC_ENT,  KC_BSPC, KC_SPC,  MO(_NAV),KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_MAC] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_LCTL, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_LGUI, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_SYM] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,  _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_BSLS,                   KC_PIPE, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX,                   XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, XXXXXXX, _______, _______, _______, KC_BSPC, MO(_MOU),_______, _______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_NAV] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_WH_U, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, XXXXXXX, XXXXXXX, PREV,    NEXT,    XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, CTR_LEF, XXXXXXX, CTR_RIG, XXXXXXX, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, MO(_MOU),_______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_NUM] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   KC_PSLS, KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   KC_PAST, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_PPLS, KC_0,    KC_DOT,  _______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_GAM] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, MO(_MUS),
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_N,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_M,    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     KC_COMM, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, KC_LCTL, KC_SPC,  KC_1,    KC_2,    _______, _______, CMB_OFF, TO(_WIN),_______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_MOU] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, KC_MS_U, _______, _______,                   _______, _______, KC_WH_U, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                   _______, KC_BTN1, KC_WH_D, KC_BTN2, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, KC_BTN3, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ),

    [_MUS] = LAYOUT(
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, XXXXXXX,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
     _______, _______, _______, _______, _______, _______, _______, _______, _______, CMB_ON,  _______, _______, TO(_WIN),TO(_MAC)
//  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    )
};

enum combos { 
  Q_W_TAB,
  SPC_J_ENT,
  ENT_BSPC_DEL,
};

const uint16_t PROGMEM q_w_tab_combo[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM spc_j_ent_combo[] = { KC_SPC, KC_J, COMBO_END};
const uint16_t PROGMEM ent_bspc_del_combo[] = { KC_ENT, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [Q_W_TAB] = COMBO(q_w_tab_combo, KC_TAB),
  [SPC_J_ENT] = COMBO(spc_j_ent_combo, KC_ENT),
  [ENT_BSPC_DEL] = COMBO(ent_bspc_del_combo, KC_DEL),
};

// layer state transition functionality
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _GAM:
        combo_disable();
        break;
    default:
        combo_enable();
        break;
    }
  return state;
};