// layer number enum
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

// custom keycodes
enum custom_keycodes {
   SETWIN = SAFE_RANGE,
   SETMAC,
   WRDPREV,
   WRDNEXT,
   LN_HOME,
   LN_END,
   RETRNAL
};

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
   case RETRNAL:
      if (record->event.pressed) {
         tap_code(KC_LSFT);
         _delay_ms(15);
         tap_code(KC_BTN3);
         _delay_ms(15);
         //tap_code(KC_SPC);
         register_code(KC_SPC);
         _delay_ms(75);
         unregister_code(KC_SPC);
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

LEADER_EXTERNS();

void matrix_scan_user(void) { 
   LEADER_DICTIONARY() {
      leading = false;
      leader_end();

      // template for select statement
      SEQ_TWO_KEYS(KC_S, KC_T) {
         SEND_STRING("SELECT \e\n\nFROM\e\n");
      }
      SEQ_TWO_KEYS(KC_S, KC_H) {
         SEND_STRING("SELECT TOP 1000 *\nFROM ");
      }
      SEQ_TWO_KEYS(KC_O, KC_F) { // start an advanced search in outlook
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
      }
      SEQ_TWO_KEYS(KC_O, KC_C) { // quick search category in outlook
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
      }
      SEQ_THREE_KEYS(KC_O, KC_F, KC_S) { // start an advanced search in outlook looking at subject and notes
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
      }
      SEQ_THREE_KEYS(KC_O, KC_F, KC_B) { // start an advanced search for Bryan
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
      }
      SEQ_TWO_KEYS(KC_O, KC_S) { // insert signature outlook
         tap_code(KC_LALT);
         tap_code(KC_N);
         tap_code(KC_A);
         tap_code(KC_S);
         tap_code(KC_ENT);
      }
      SEQ_TWO_KEYS(KC_O, KC_H) { // insert hyperlink outlook
         tap_code(KC_LALT);
         tap_code(KC_N);
         tap_code(KC_I);
         tap_code(KC_I);
      }
      SEQ_ONE_KEY(KC_E) { // personal email
         SEND_STRING("larryhuang64@gmail.com");
      }
      SEQ_TWO_KEYS(KC_E, KC_V) { // work email
         SEND_STRING("larry.huang@vizientinc.com");
      }
      SEQ_TWO_KEYS(KC_V, KC_S) { // VS Code - Change language to SQL
         register_code(KC_LCTL);
         tap_code(KC_K);
         unregister_code(KC_LCTL);
         tap_code(KC_M);
         SEND_STRING("SQL");
         tap_code(KC_ENT);
      }

      // Excel macros: These start with "X"

      // Copy down
      SEQ_TWO_KEYS(KC_X, KC_D) {
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
      }
      SEQ_TWO_KEYS(KC_X, KC_N) {
        // rename sheet name
         tap_code(KC_LALT);
         tap_code(KC_H);
         tap_code(KC_O);
         tap_code(KC_R);
      }
      SEQ_TWO_KEYS(KC_X, KC_W) {
        // resize column width using selected cell
         tap_code(KC_LALT);
         tap_code(KC_H);
         tap_code(KC_O);
         tap_code(KC_I);
      }
      SEQ_TWO_KEYS(KC_X, KC_C) {
        // Delete column
         tap_code(KC_LALT);
         tap_code(KC_H);
         tap_code(KC_D);
         tap_code(KC_C);
      }
   };
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