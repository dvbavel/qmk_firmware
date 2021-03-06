#include QMK_KEYBOARD_H

#define PGMOD LT(_MOD, KC_PGDN)
#define SPCMOD LT(_MOD, KC_SPACE)
#define VOLMOD LT(_MOD, KC__MUTE)
#define CMDBSP MT(MOD_LGUI, KC_BSPC)
#define ALTDEL MT(MOD_LALT, KC_DEL)
#define BWORD LCTL(KC_BSPC)
#define LWORD LCTL(KC_LEFT)
#define RWORD LCTL(KC_RIGHT)
#define JUMPBACK LSFT(KC_TAB)
#define UNDO LCTL(KC_Z)
#define XPANDR LCTL(LSFT(KC_X))
#define NTAB LCTL(KC_T)
#define CTAB LCTL(KC_W)
#define XPANDR LCTL(LSFT(KC_X))

enum layer_names {
  _BASE,
  _REV,
  _MOD,
  _DEL,
};

enum custom_keycodes {
  LAUNCHCLOCK = SAFE_RANGE,
  CSPEAK,
  SPEAK1,
  SPEAK2,
  SPEAK3,
  SPEAK4,
  PARADOWN,
  WREFRESH,
  PMERGE,
  REMCAPS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
	case CSPEAK:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN));
	break;
	}
	case SPEAK1:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN) SS_LCTRL(SS_TAP(X_1)));
	break;
	}
	case SPEAK2:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN) SS_LCTRL(SS_TAP(X_2)));
	}
	break;
	case SPEAK3:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN) SS_LCTRL(SS_TAP(X_3)));
	}
	break;
	case SPEAK4:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN) SS_LCTRL(SS_TAP(X_4)));
	}
	break;
	case PARADOWN:
		if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_PGDOWN) SS_TAP(X_ENTER) SS_TAP(X_PGDOWN));
    }
    break;
    case PMERGE:
    if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_BSPACE) SS_TAP(X_SPACE) SS_LCTRL(SS_TAP(X_BSPACE)) SS_TAP(X_SPACE));
    }
    break;
    case WREFRESH:
    if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_SPACE) SS_TAP(X_BSPACE));
    }
    break;
    case REMCAPS:
    if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_LCTRL(SS_TAP(X_LEFT)) SS_TAP(X_DELETE));
    }
    break;
 };  
 return true; 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_space(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,       KC_BSPC,      KC_DEL,   NTAB,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,    MO(_MOD),CTAB,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENTER,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,           KC_UP,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴─────┬───┴────────┴───┬─────┴────────┴┬────────┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     CMDBSP,    ALTDEL,   KC_LCTRL,        KC_SPACE,      SPCMOD,          SPCMOD,        MO(_DEL),         KC_LCTL,    KC_RCTRL,      KC_LEFT, KC_DOWN, KC_RGHT
  //└──────────┴──────────┴──────────┴──────────────────┴────────────────┴───────────────┴─────────────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),
    
[_REV] = LAYOUT_split_space(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     _______, _______, _______,  _______, _______, _______,_______,  _______,_______, _______, _______, _______, _______,       _______,     _______, _______,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     KC_LEFT,     _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,KC_HOME, KC_END,  KC_RIGHT,    _______, _______,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     JUMPBACK,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           CSPEAK,          _______,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴──────┬──┴────────┴────┬────┴────────┴┬────────┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     _______,   _______,   _______,        KC_TAB,         PGMOD,         _______,      _______,          _______,   _______,       _______, _______,  _______
  //└──────────┴──────────┴──────────┴───────────────────┴────────────────┴──────────────┴─────────────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),

[_MOD] = LAYOUT_split_space(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     RESET,   _______, _______,  _______, _______, _______,_______,  _______,KC_F8  , _______, _______, _______, _______,       _______,     KC_VOLD, KC_VOLU,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     _______,     _______, WREFRESH,_______, DF(_REV), _______, _______, UNDO,   _______, _______, _______,  _______, _______, _______,      _______, _______,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     KC_CAPS,       _______, _______, _______, _______, _______,  KC_HOME, KC_LEFT,  KC_UP,  KC_RIGHT, KC_END, _______,      PARADOWN,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     _______,           _______, XPANDR, _______,  _______,  _______, _______, PMERGE,   KC_DOWN, _______,  _______,           _______,          KC_F1  ,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴──────┬──┴────────┴────┬────┴────────┴┬────────┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     _______,   _______,   _______,        LWORD,              RWORD,         LWORD,       RWORD,            _______,   _______,       _______, KC_F2  ,  _______
  //└──────────┴──────────┴──────────┴───────────────────┴────────────────┴──────────────┴─────────────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),
  
[_DEL] = LAYOUT_split_space(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────────────┐ ┌────────┬────────┐
     _______, SPEAK1,  SPEAK2,   SPEAK3,  SPEAK4, _______,_______,  _______,_______, _______, _______, _______, _______,       _______,     _______, _______,
  //├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────────────┤ ├────────┼────────┤
     _______,     _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______,
  //├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┤ └────────┴────────┘
     REMCAPS,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,
  //├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤ ┌────────┐
     _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          _______,
  //├──────────┬───────┴──┬─────┴────┬───┴────────┴──────┬──┴────────┴────┬────┴────────┴┬────────┴────────┼────────┴─┬──────────┬────┬──────┴─┬────────┼────────┐
     _______,   _______,   KC_DEL,        KC_BSPC,         BWORD,         _______,      _______,          _______,   _______,       _______, _______,  _______
  //└──────────┴──────────┴──────────┴───────────────────┴────────────────┴──────────────┴─────────────────┴──────────┴──────────┘    └────────┴────────┴────────┘
  ),
};
