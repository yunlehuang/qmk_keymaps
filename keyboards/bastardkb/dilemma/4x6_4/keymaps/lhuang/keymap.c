/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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


enum layers {
    _WIN = 0,
    _MAC,
    _TTS,
    _SYM,
    _NAV,
    _NUM,
    _NUM2,
    _GAM,
    _MOU,
    _JIG,
    _MUS
};

// variables for jiggler
static uint32_t key_timer = 0;
static bool key_trigger = false;

// variables for keycodes
static uint16_t base_layer_code = 0;

enum custom_keycodes {
   SETWIN = SAFE_RANGE,
   SETMAC,
   WRDPREV,
   WRDNEXT,
   LN_HOME,
   LN_END,
   T_LEFT,
   T_RGHT,
   T_UP,
   T_DOWN,
};


#define NUM_SCN LT(_NUM, KC_SCLN)
#define CTR_LEF C(KC_LEFT)
#define CTR_RIG C(KC_RGHT)
#define PREV RCS(KC_TAB)
#define NEXT C(KC_TAB)
#define SYMBOL MO(_SYM)
#define NAVIGA MO(_NAV)
#define MOUSE_ MO(_MOU)
#define ESC_MOU LT(_MOU, KC_ESC)
#define MUS_STG MO(_MUS)
#define ALT_NUM MO(_NUM2)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WIN] = LAYOUT(
    KC_ESC,     KC_1,	    KC_2,	    KC_3,	    KC_4,	    KC_5,                               KC_6,       KC_7,	    KC_8,	    KC_9,	    KC_0,	    QK_LEAD,
    KC_LGUI,	KC_Q,	    KC_W,	    KC_E,	    KC_R,	    KC_T,                               KC_Y,       KC_U,	    KC_I,	    KC_O,	    KC_P,	    QK_LEAD,
    KC_LALT,	KC_A,	    KC_S,	    KC_D,	    KC_F,	    KC_G,                               KC_H,	    KC_J,	    KC_K,	    KC_L,	    NUM_SCN,	KC_QUOT,
    KC_LCTL,	KC_Z,	    KC_X,	    KC_C,	    KC_V,	    KC_B,                               KC_N,   	KC_M,	    KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
                                        KC_MUTE,	SYMBOL,	    KC_LSFT,    ALT_NUM,    ESC_MOU,    KC_SPC,	    NAVIGA, 	KC_MUTE
  ),

  [_MAC] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    KC_LCTL,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    KC_LGUI,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
                                        _______,	_______,	_______,    _______,    _______,    _______,	_______,	_______
  ),

  [_TTS] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    KC_TAB,	    _______,	_______,	_______,	_______,	_______,                            _______,    _______,	_______,	_______,	_______,	KC_BSPC,
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
                                        _______,	KC_SPC,     KC_LSFT,    _______,    KC_ENT,     _______,	_______,	_______
  ),


  [_SYM] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	KC_EXLM,	KC_AT,  	KC_HASH,	KC_DLR, 	KC_PERC,                            KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_UNDS,	KC_EQL,		_______,
    _______,	KC_GRV,	    KC_TILD,	KC_LPRN,	KC_RPRN,	KC_BSLS,                            KC_PIPE,	KC_LBRC,	KC_RBRC,	KC_MINS,	KC_PLUS,	_______,
    _______,	KC_WH_D,	KC_WH_U,	KC_LABK,	KC_RABK,	XXXXXXX,                            XXXXXXX,	KC_LCBR,	KC_RCBR,	XXXXXXX,	XXXXXXX,	_______,
                                        _______,	XXXXXXX,	CTR_LEF,    CTR_RIG,    _______,    _______,	XXXXXXX,	_______
  ),


  [_NAV] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	_______,	_______,	T_UP,	    _______,	_______,                            KC_PGUP,	LN_HOME,	KC_UP,	    LN_END,	    KC_WH_U,	KC_HOME,
    _______,    _______,    T_LEFT, 	T_DOWN,	    T_RGHT,	    _______,                            KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_WH_D,	KC_END,
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	WRDPREV,	XXXXXXX,	WRDNEXT,	_______,	_______,
                                        _______,	_______,	_______,    _______,    _______,    _______,	XXXXXXX,	_______
  ),

  [_NUM] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	KC_F1,	    KC_F2,	    KC_F3,	    KC_F4,      _______,                            KC_PSLS,	KC_7,	    KC_8,	    KC_9,   	XXXXXXX,	_______,
    _______,	KC_F5,	    KC_F6,	    KC_F7,	    KC_F8,	    _______,                            KC_PAST,	KC_4,	    KC_5,	    KC_6,   	XXXXXXX,	_______,
    _______,	KC_F9,	    KC_F10,	    KC_F11,	    KC_F12,	    _______,                            KC_PMNS,	KC_1,	    KC_2,	    KC_3,   	XXXXXXX,	_______,
                                        _______,	_______,	_______,    _______,    KC_DOT,     KC_PPLS,	KC_0,	    _______
  ),

  [_NUM2] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    KC_ESC,	    KC_1,       KC_2,	    KC_3,   	_______,    _______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	KC_4,       KC_5,	    KC_6,      SNIPING_MODE,_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	KC_7,       KC_8,	    KC_9,   	KC_0,	    _______,                            _______,	_______,	_______,	_______,	_______,	_______,
                                        _______,    _______,	_______,    _______,    _______,    _______,	_______,	_______
  ),

  [_GAM] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    KC_2,	    KC_TAB, 	KC_Q,	    KC_W,   	KC_E,   	KC_R,                               KC_Y,   	KC_U,   	KC_I,   	KC_O,	    KC_P,   	KC_ESC,
    KC_3,	    KC_LSFT,	KC_A,	    KC_S,   	KC_D,   	KC_F,                               KC_H,   	KC_J,   	KC_K,   	KC_L,	    KC_SCLN,	_______,
    KC_4,	    KC_LALT,	KC_Z,	    KC_X,   	KC_C,   	KC_V,                               KC_N,   	KC_M,   	KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
                                        _______,	KC_SPC,	    KC_1,       KC_LCTL,    TO(_WIN),   KC_SPC,	    KC_ESC,	    _______
  ),

  [_MOU] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    _______,	_______,	_______,	KC_MS_U,	_______,	_______,                            _______,	_______,	KC_WH_U,	_______,	_______,	_______,
    _______,	_______,	KC_MS_L,	KC_MS_D,	KC_MS_R,	_______,                            _______,	KC_BTN1,	KC_WH_D,	KC_BTN2,	_______,	_______,
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	KC_WH_L,	KC_BTN3,	KC_WH_R,	_______,	_______,
                                        _______,	KC_ACL1,	KC_ACL2,    KC_ACL0,    _______,    _______,	_______,	_______
  ),

  [_JIG] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            _______,	_______,	_______,	_______,	_______,	_______,
    XXXXXXX,	KC_Q,	    KC_W,	    KC_E,   	KC_R,   	KC_T,                               KC_Y,   	KC_U,   	KC_I,   	KC_O,	    KC_P,   	KC_MS_U,
    XXXXXXX,	KC_A,	    KC_S,	    KC_D,   	KC_F,   	KC_G,                               KC_H,   	KC_J,   	KC_K,   	KC_L,	    XXXXXXX,	KC_QUOT,
    XXXXXXX,	KC_Z,	    KC_X,	    KC_C,   	KC_V,   	KC_B,                               KC_N,   	KC_M,   	KC_COMM,	KC_DOT,	    KC_SLSH,	MUS_STG,
                                        _______,	XXXXXXX,	XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,	XXXXXXX,	XXXXXXX
  ),

  [_MUS] = LAYOUT(
    _______,	_______,	_______,	_______,	_______,	_______,                            POINTER_SNIPING_DPI_REVERSE,	POINTER_SNIPING_DPI_FORWARD,	_______,	_______,	_______,	_______,
    _______,	RGB_SPI,	RGB_SAI,	RGB_HUI,	RGB_VAI,	_______,                            _______,	_______,	_______,	_______,	SETWIN,	    SETMAC,
    _______,	RGB_SPD,	RGB_SAD,	RGB_HUD,	RGB_VAD,	_______,                            _______,	KC_MPLY,	KC_MPRV,	KC_MNXT,	_______,	_______,
    _______,    _______,	RGB_RMOD,   RGB_MOD,	RGB_TOG,	_______,                            TO(_JIG),   KC_MUTE,	KC_VOLD,	KC_VOLU,	_______,	XXXXXXX,
                                        _______,    _______,	_______,    _______,    TO(_GAM),   TO(_WIN),   TO(_TTS),   _______
  )
};

// macros and other custom keycode functionality
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SETWIN:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_WIN);
         base_layer_code = _WIN;
      }
      return false;
      break;
    case SETMAC:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_MAC);
         base_layer_code = _MAC;
      }
      return false;
      break;
   case WRDPREV:
      if (record->event.pressed && base_layer_code == _WIN) {
         register_code(KC_LCTL);
         tap_code(KC_LEFT);
         unregister_code(KC_LCTL);
      }
      else if (record->event.pressed && base_layer_code == _MAC) {
         register_code(KC_LALT);
         tap_code(KC_LEFT);
         unregister_code(KC_LALT);
      }
      return false;
      break;
   case WRDNEXT:
      if (record->event.pressed && base_layer_code == _WIN) {
         register_code(KC_LCTL);
         tap_code(KC_RIGHT);
         unregister_code(KC_LCTL);
      }
      else if (record->event.pressed && base_layer_code == _MAC) {
         register_code(KC_LALT);
         tap_code(KC_RIGHT);
         unregister_code(KC_LALT);
      }
      return false;
      break;
   case LN_HOME:
      if (record->event.pressed && base_layer_code == _WIN) {
         tap_code(KC_HOME);
      }
      else if (record->event.pressed && base_layer_code == _MAC) {
         register_code(KC_LGUI);
         tap_code(KC_LEFT);
         unregister_code(KC_LGUI);
      }
      return false;
      break;
   case LN_END:
      if (record->event.pressed && base_layer_code == _WIN) {
         tap_code(KC_END);
      }
      else if (record->event.pressed && base_layer_code == _MAC) {
         register_code(KC_LGUI);
         tap_code(KC_RIGHT);
         unregister_code(KC_LGUI);
      }
      return false;
      break;
   case T_LEFT:
      if (record->event.pressed) {
         tap_code(KC_LEFT);
         tap_code(KC_LEFT);
         tap_code(KC_LEFT);
      }
      return false;
      break;
   case T_RGHT:
      if (record->event.pressed) {
         tap_code(KC_RGHT);
         tap_code(KC_RGHT);
         tap_code(KC_RGHT);
      }
      return false;
      break;
   case T_UP:
      if (record->event.pressed) {
         tap_code(KC_UP);
         tap_code(KC_UP);
         tap_code(KC_UP);
      }
      return false;
      break;
   case T_DOWN:
      if (record->event.pressed) {
         tap_code(KC_DOWN);
         tap_code(KC_DOWN);
         tap_code(KC_DOWN);
      }
      return false;
      break;
  }
  return true;
}



// Combos
enum combos { 
	Q_W_TAB,
	J_COMM_ENT,
	J_K_BSPC,
	C_F_ENT,
	D_F_BSPC,
	E_F_SPC,
	F_G_DEL,
	T_G_ESC,
	Z_X_LEFT,
	X_C_DOWN,
	C_V_RGHT,
	S_D_UP,
    
	FUN1,
	FUN2,
	FUN3,
	FUN4,
	FUN5,
	FUN6,
	FUN7,
	FUN8,
	FUN9,
	FUN10,
	FUN11,
	FUN12,

	ZC_COMBO,
	ZV_COMBO,
	NY_COMBO,
	Q_C_COMBO,
    MAC_SCREENSHOT,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// controls per-combo combo term
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case Q_W_TAB:
            return 80;
    }

    return COMBO_TERM;
}


const uint16_t PROGMEM q_w_tab[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM j_comm_ent[] = { KC_J, KC_COMM, COMBO_END};
const uint16_t PROGMEM j_k_bspc[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_f_ent[] = { KC_C, KC_F, COMBO_END};
const uint16_t PROGMEM d_f_bspc[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM e_f_spc[] = { KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM f_g_del[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM t_g_esc[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM z_x_left[] = { KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM x_c_down[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_v_rght[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM s_d_up[] = { KC_S, KC_D, COMBO_END};

const uint16_t PROGMEM fun_1[] = { KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM fun_2[] = { KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM fun_3[] = { KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM fun_4[] = { KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM fun_5[] = { KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM fun_6[] = { KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM fun_7[] = { KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM fun_8[] = { KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM fun_9[] = { KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM fun_10[] = { KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM fun_11[] = { KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM fun_12[] = { KC_R, KC_V, COMBO_END};

const uint16_t PROGMEM comment_combo[] = { KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM uncomment_combo[] = { KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM vsc_flip_combo[] = { KC_N, KC_Y, COMBO_END};
const uint16_t PROGMEM copy_value_combo[] = { KC_Q, KC_C, COMBO_END};
const uint16_t PROGMEM mac_screenshot_combo[] = { KC_T, KC_B, COMBO_END};

combo_t key_combos[] = {
	//basic combos
	[Q_W_TAB] = COMBO(q_w_tab, KC_TAB),
	[J_COMM_ENT] = COMBO(j_comm_ent, KC_ENT),
	[J_K_BSPC] = COMBO(j_k_bspc, KC_BSPC),
	[C_F_ENT] = COMBO(c_f_ent, KC_ENT),
	[D_F_BSPC] = COMBO(d_f_bspc, KC_BSPC),
	[E_F_SPC] = COMBO(e_f_spc, KC_SPC),
	[F_G_DEL] = COMBO(f_g_del, KC_DEL),
	[T_G_ESC] = COMBO(t_g_esc, KC_ESC),
	[Z_X_LEFT] = COMBO(z_x_left, KC_LEFT),
	[X_C_DOWN] = COMBO(x_c_down, KC_DOWN),
	[C_V_RGHT] = COMBO(c_v_rght, KC_RGHT),
	[S_D_UP] = COMBO(s_d_up, KC_UP),

    //function keys
    [FUN1] = COMBO(fun_1, KC_F1),
    [FUN2] = COMBO(fun_2, KC_F2),
    [FUN3] = COMBO(fun_3, KC_F3),
    [FUN4] = COMBO(fun_4, KC_F4),
    [FUN5] = COMBO(fun_5, KC_F5),
    [FUN6] = COMBO(fun_6, KC_F6),
    [FUN7] = COMBO(fun_7, KC_F7),
    [FUN8] = COMBO(fun_8, KC_F8),
    [FUN9] = COMBO(fun_9, KC_F9),
    [FUN10] = COMBO(fun_10, KC_F10),
    [FUN11] = COMBO(fun_11, KC_F11),
    [FUN12] = COMBO(fun_12, KC_F12),

	//action combos
	[ZC_COMBO] = COMBO_ACTION(comment_combo),
	[ZV_COMBO] = COMBO_ACTION(uncomment_combo),
	[NY_COMBO] = COMBO_ACTION(vsc_flip_combo),
	[Q_C_COMBO] = COMBO_ACTION(copy_value_combo),
    [MAC_SCREENSHOT] = COMBO_ACTION(mac_screenshot_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZC_COMBO:
        if (pressed) {
            if (base_layer_code == _MAC) {
                register_code(KC_LGUI);
                tap_code(KC_K);
                tap_code(KC_C);
                unregister_code(KC_LGUI);
            }
            else if (base_layer_code == _WIN) {
                register_code(KC_LCTL);
                tap_code(KC_K);
                tap_code(KC_C);
                unregister_code(KC_LCTL);
            }
        }
        break;
    case ZV_COMBO:
        if (pressed) {
            if (base_layer_code == _MAC) {
                register_code(KC_LGUI);
                tap_code(KC_K);
                tap_code(KC_U);
                unregister_code(KC_LGUI);
            }
            else if (base_layer_code == _WIN) {
                register_code(KC_LCTL);
                tap_code(KC_K);
                tap_code(KC_U);
                unregister_code(KC_LCTL);
            }
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
    case Q_C_COMBO: // In Excel, copies the cell's value without copying the range.
        if (pressed) {
        tap_code(KC_F2);
        register_code(KC_LCTL);
        tap_code(KC_A);
        tap_code(KC_C);
        unregister_code(KC_LCTL);
        tap_code(KC_ESC);
        }
        break;
    case MAC_SCREENSHOT: // On MacOS, this copies a screen clip to clipboard
        if (pressed) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        register_code(KC_LGUI);
        tap_code(KC_4);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
        }
        break;
  }
}


// leader key
void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_S, KC_T)) {
        SEND_STRING("SELECT \e\n\nFROM\e\n");
    } else if (leader_sequence_two_keys(KC_S, KC_H)) {
        SEND_STRING("SELECT TOP 1000 *\nFROM ");
    } else if (leader_sequence_two_keys(KC_O, KC_F)) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_F);
        unregister_code(KC_LCTL);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        tap_code(KC_A);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_ENT);
    } else if (leader_sequence_two_keys(KC_O, KC_C)) {
        register_code(KC_LCTL);
        tap_code(KC_E);
        unregister_code(KC_LCTL);
        wait_ms(200);
        tap_code(KC_TAB);
        tap_code(KC_ENT);
        tap_code(KC_A);
        tap_code(KC_ENT);
        tap_code(KC_ESC);
        SEND_STRING("category:");
    } else if (leader_sequence_three_keys(KC_O, KC_F, KC_S)) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_F);
        unregister_code(KC_LCTL);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        tap_code(KC_A);
        tap_code(KC_TAB);
        tap_code(KC_S);
        tap_code(KC_TAB);
        tap_code(KC_ENT);
    } else if (leader_sequence_three_keys(KC_O, KC_F, KC_B)) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_F);
        unregister_code(KC_LCTL);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        tap_code(KC_A);
        tap_code(KC_TAB);
        tap_code(KC_S);
        tap_code(KC_TAB);
        tap_code(KC_ENT);
        SEND_STRING("Shaw,Bryan");
        tap_code(KC_ENT);
        tap_code(KC_ENT);
    } else if (leader_sequence_two_keys(KC_O, KC_S)) {
        tap_code(KC_LALT);
        tap_code(KC_N);
        tap_code(KC_A);
        tap_code(KC_S);
        tap_code(KC_ENT);
    } else if (leader_sequence_two_keys(KC_O, KC_H)) {
        tap_code(KC_LALT);
        tap_code(KC_N);
        tap_code(KC_I);
        tap_code(KC_I);
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING("larryhuang64@gmail.com");
    } else if (leader_sequence_two_keys(KC_E, KC_V)) {
        SEND_STRING("larry.huang@vizientinc.com");
    } else if (leader_sequence_two_keys(KC_V, KC_S)) {
        register_code(KC_LCTL);
        tap_code(KC_K);
        unregister_code(KC_LCTL);
        tap_code(KC_M);
        SEND_STRING("SQL");
        tap_code(KC_ENT);
    } else if (leader_sequence_two_keys(KC_X, KC_D)) {
        register_code(KC_LCTL);
        tap_code(KC_C);
        unregister_code(KC_LCTL);

        tap_code(KC_LEFT);

        register_code(KC_LCTL);
        tap_code(KC_DOWN);
        unregister_code(KC_LCTL);

        tap_code(KC_RIGHT);

        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_UP);
        unregister_code(KC_LSFT);
        tap_code(KC_V);
        unregister_code(KC_LCTL);
    } else if (leader_sequence_two_keys(KC_X, KC_N)) {
    // rename sheet name
        tap_code(KC_LALT);
        tap_code(KC_H);
        tap_code(KC_O);
        tap_code(KC_R);
    } else if (leader_sequence_two_keys(KC_X, KC_W)) {
    // resize column width using selected cell
        tap_code(KC_LALT);
        tap_code(KC_H);
        tap_code(KC_O);
        tap_code(KC_I);
    } else if (leader_sequence_two_keys(KC_X, KC_C)) {
    // Delete column
        tap_code(KC_LALT);
        tap_code(KC_H);
        tap_code(KC_D);
        tap_code(KC_C);
    }
}



void matrix_scan_user(void) { 
   // Jiggler
   if (timer_elapsed32(key_timer) > 3000) { // 3 seconds
      key_timer = timer_read32();  // resets timer
      if (key_trigger) {
         tap_code(KC_MS_UP);
         tap_code(KC_MS_DOWN);
         tap_code(KC_MS_LEFT);
         tap_code(KC_MS_RIGHT);
      };
   }
}


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

// clang-format on