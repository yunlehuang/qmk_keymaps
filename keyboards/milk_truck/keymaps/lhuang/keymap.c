#include QMK_KEYBOARD_H

#include "lhuang.c"


#define NUM_SCN LT(_NUM, KC_SCLN)
#define OSM_SFT OSM(MOD_LSFT)
#define CTR_LEF C(KC_LEFT)
#define CTR_RIG C(KC_RGHT)
#define PREV RCS(KC_TAB)
#define NEXT C(KC_TAB)
#define VSC_PRE LCTL(KC_PGUP) //previous tab in VS code
#define VSC_NEX LCTL(KC_PGDN) //next tab in VS code
#define ALT_NUM MO(_NUM2)
#define SYMBOL MO(_SYM)
#define NAVIGA MO(_NAV)
#define SPC_MOU LT(_MOU, KC_SPC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define SPC_SFT SFT_T(KC_SPC)
#define MOUSE_ MO(_MOU)
#define LFT_NUM MO(_NUM2)
#define ESC_MOU LT(_MOU, KC_ESC)
#define MUS_STG MO(_MUS)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_WIN] = LAYOUT(
    LGUI(KC_1), LGUI(KC_2), LGUI(KC_3),             KC_LGUI,	KC_Q,	    KC_W,	    KC_E,	    KC_R,	    KC_T,               KC_Y,       KC_U,	    KC_I,	    KC_O,	    KC_P,	    KC_LEAD,
    LGUI(KC_4), LGUI(KC_5), LGUI(KC_6),             KC_LALT,	KC_A,	    KC_S,	    KC_D,	    KC_F,	    KC_G,               KC_H,	    KC_J,	    KC_K,	    KC_L,	    NUM_SCN,	KC_QUOT,
    LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX,    KC_LCTL,	KC_Z,	    KC_X,	    KC_C,	    KC_V,	    KC_B,               KC_N,   	KC_M,	    KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
    KC_MUTE,    KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    ALT_NUM,	            SYMBOL,     KC_LSFT,                KC_SPC,	            NAVIGA, 	ESC_MOU,                XXXXXXX,    XXXXXXX
),

[_MAC] = LAYOUT(
    _______,    _______,    _______,                KC_LCTL,	_______,	_______,	_______,	_______,	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,                _______,	_______,	_______,	_______,	_______,	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    KC_LGUI,	_______,	_______,	_______,	_______,	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	_______,	            _______,    _______,                _______,            _______,    _______,                _______,    _______
),

[_TTS] = LAYOUT(
    _______,    _______,    _______,                KC_TAB,     _______,	_______,	_______,	_______,	_______,            _______,    _______,	_______,	_______,	_______,	KC_BSPC,
    _______,    _______,    _______,                _______,	_______,	_______,	_______,	_______,	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	_______,	_______,	_______,	_______,	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    _______,	_______,    _______,                KC_SPC,     KC_LSFT,                _______,            _______,    KC_ENT,                 _______,    _______
),


[_SYM] = LAYOUT(
    _______,    _______,    _______,                _______,	KC_EXLM,	KC_AT,  	KC_HASH,	KC_DLR, 	KC_PERC,            KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_UNDS,	KC_EQL,		_______,
    _______,    _______,    _______,                _______,	KC_GRV,	    KC_TILD,	KC_LPRN,	KC_RPRN,	KC_BSLS,            KC_PIPE,	KC_LBRC,	KC_RBRC,	KC_MINS,	KC_PLUS,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	KC_WH_D,	KC_WH_U,	KC_LABK,	KC_RABK,	XXXXXXX,            XXXXXXX,	KC_LCBR,	KC_RCBR,	XXXXXXX,	XXXXXXX,	_______,
    _______,    _______,    _______,    _______,    _______,    CTR_LEF,	            XXXXXXX,	CTR_RIG,                _______,	        XXXXXXX,	_______,                _______,    _______
),


[_NAV] = LAYOUT(
    _______,    _______,    _______,                _______,	_______,	KC_BTN2,	KC_MS_U,	KC_BTN1,	KC_WH_U,            KC_PGUP,	LN_HOME,	KC_UP,	    LN_END,	    KC_WH_U,	KC_HOME,
    _______,    _______,    _______,                PREV,      NEXT,	    KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_WH_D,            KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_WH_D,	KC_END,
    _______,    _______,    _______,    XXXXXXX,    _______,	_______,	KC_WH_L,	KC_BTN3,	KC_WH_R,	_______,            _______,	WRDPREV,	XXXXXXX,	WRDNEXT,	_______,	_______,
    _______,    _______,    _______,    _______,    _______,    KC_ACL0,	            KC_ACL1,	KC_ACL2,	            _______,	        XXXXXXX,	_______,                _______,    _______
),

[_NUM] = LAYOUT(
    _______,    _______,    _______,                _______,	KC_F1,	    KC_F2,	    KC_F3,	    KC_F4,      _______,            KC_PSLS,	KC_7,	    KC_8,	    KC_9,   	XXXXXXX,	_______,
    _______,    _______,    _______,                _______,	KC_F5,	    KC_F6,	    KC_F7,	    KC_F8,	    _______,            KC_PAST,	KC_4,	    KC_5,	    KC_6,   	XXXXXXX,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	KC_F9,	    KC_F10,	    KC_F11,	    KC_F12,	    _______,            KC_PMNS,	KC_1,	    KC_2,	    KC_3,   	XXXXXXX,	_______,
    _______,    _______,    _______,    _______,    _______,    _______,	            _______,	_______,	            KC_PPLS,	        KC_0,	    KC_DOT,                 _______,    _______
),

[_NUM2] = LAYOUT(
    _______,    _______,    _______,                KC_ESC,	    KC_1,       KC_2,	    KC_3,   	_______,    _______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,                _______,	KC_4,       KC_5,	    KC_6,   	_______,   	_______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	KC_7,       KC_8,	    KC_9,   	KC_0,	    _______,            _______,	_______,	_______,	_______,	_______,	_______,
    _______,    _______,    _______,    _______,    _______,    _______,                _______,	_______,                _______,	        _______,	_______,                _______,    _______
),

[_GAM] = LAYOUT(
    _______,    _______,    _______,                KC_2,	    KC_TAB, 	KC_Q,	    KC_W,   	KC_E,   	KC_R,               KC_Y,   	KC_U,   	KC_I,   	KC_O,	    KC_P,   	KC_ESC,
    _______,    _______,    _______,                KC_3,	    KC_LSFT,	KC_A,	    KC_S,   	KC_D,   	KC_F,               KC_H,   	KC_J,   	KC_K,   	KC_L,	    KC_SCLN,	_______,
    _______,    _______,    _______,    XXXXXXX,    KC_4,	    KC_LALT,	KC_Z,	    KC_X,   	KC_C,   	KC_V,               KC_N,   	KC_M,   	KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
    _______,    _______,    _______,    _______,    _______,    KC_LCTL,	            KC_SPC,	    KC_1,              	    KC_SPC,	            KC_ESC,	    TO(_WIN),               _______,    _______
),

[_MOU] = LAYOUT(
    _______,    _______,    _______,                _______,	_______,	_______,	KC_MS_U,	_______,	_______,            _______,	_______,	KC_WH_U,	_______,	_______,	_______,
    _______,    _______,    _______,                _______,	_______,	KC_MS_L,	KC_MS_D,	KC_MS_R,	_______,            _______,	KC_BTN1,	KC_WH_D,	KC_BTN2,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    _______,	_______,	_______,	_______,	_______,	_______,            _______,	KC_WH_L,	KC_BTN3,	KC_WH_R,	_______,	_______,
    _______,    _______,    _______,    _______,    _______,    KC_ACL0,	            KC_ACL1,	KC_ACL2,                _______,	        _______,	_______,                _______,    _______
),

[_JIG] = LAYOUT(
    _______,    _______,    _______,                XXXXXXX,	KC_Q,	    KC_W,	    KC_E,   	KC_R,   	KC_T,               KC_Y,   	KC_U,   	KC_I,   	KC_O,	    KC_P,   	KC_MS_U,
    _______,    _______,    _______,                XXXXXXX,	KC_A,	    KC_S,	    KC_D,   	KC_F,   	KC_G,               KC_H,   	KC_J,   	KC_K,   	KC_L,	    XXXXXXX,	KC_QUOT,
    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,	KC_Z,	    KC_X,	    KC_C,   	KC_V,   	KC_B,               KC_N,   	KC_M,   	KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
    _______,    _______,    _______,    _______,    _______,    XXXXXXX,	            XXXXXXX,	XXXXXXX,	            XXXXXXX,	        XXXXXXX,	XXXXXXX,                _______,    _______
),

[_MUS] = LAYOUT(
    _______,    _______,    _______,                _______,	RGB_SPI,	RGB_SAI,	RGB_HUI,	RGB_VAI,	_______,            _______,	_______,	_______,	_______,	SETWIN,	    SETMAC,
    _______,    _______,    _______,                _______,	RGB_SPD,	RGB_SAD,	RGB_HUD,	RGB_VAD,	_______,            _______,	KC_MPLY,	KC_MPRV,	KC_MNXT,	_______,	_______,
    _______,    _______,    _______,    XXXXXXX,    RESET,	    _______,	RGB_RMOD,   RGB_MOD,	RGB_TOG,	_______,            TO(_JIG),   KC_MUTE,	KC_VOLD,	KC_VOLU,	_______,	XXXXXXX,
    _______,    _______,    _______,    _______,    _______,    DEBUG,	                _______,	_______,	            TO(_WIN),           TO(_TTS),   TO(_GAM),               _______,    _______
)
};

// layer state transition functionality
layer_state_t layer_state_set_user(layer_state_t state) {
   switch (get_highest_layer(state)) {
   case _TTS:
      combo_disable();
      key_trigger = false;
      break;
   case _GAM:
      combo_disable();
      key_trigger = false;
      break;
   case _JIG:
      key_trigger = true;
      break;
   default:
      combo_enable();
      key_trigger = false;
      break;
   }
   return state;
};