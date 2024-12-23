#include QMK_KEYBOARD_H
#include "keymap_canadian_multilingual.h"
#include "os_detection.h"
#include "luna.c"
#include "space.c"
#include "osLogo.c"

#define AL_VOLU KC_KB_VOLUME_UP
#define AL_VOLD KC_KB_VOLUME_DOWN
#define AL_MUTE KC_KB_MUTE
#define AL_HYPER LCAG_T(KC_TRNS)

enum layer_number {
  _WRITE = 0,
  _LOWER,
  _RAISE,
  _FCT,
};

bool is_base_layer = true; // Variable to track the current layer state

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WRITE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ù   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  è   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   é  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CTRL | LALT |LGUI  | /Space  /       \Enter \  |BackSP| HYPER|      |
 *                   |      |      |      |/ LOWER /         \ RAISE\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_WRITE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LALT(KC_LBRC),
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_BSPC, AL_HYPER, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   \  |   [  |   ]  |   <  |   >  |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   !  |   ?  |   @  |   #  |   $  |   %  |-------.    ,-------|   /  |   (  |   )  |   =  |   -  |   +  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   _  |   {  |   }  |   &  |   *  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CTRL | LALT |LGUI  | /Space  /       \Enter \  |BackSP| HYPER|      |
 *                   |      |      |      |/ LOWER /         \ RAISE\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                   LSFT(KC_NUBS), CA_LBRC, CA_RBRC, LALT(KC_COMM), LALT(KC_DOT), LALT(KC_RBRC),
  KC_EXLM, LSFT(KC_6), KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                KC_NUBS, KC_LPRN, KC_RPRN, KC_EQL, KC_MINS, KC_PLUS,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, CA_LCBR, CA_RCBR, KC_AMPR, KC_ASTR, LALT(KC_MINS),
                             _______, _______, _______, MO(_LOWER), MO(_RAISE),  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  ### |  Up  | ###  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|  ### | Left | Down |Right | ###  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CTRL | LALT |LGUI  | /Space  /       \Enter \  |BackSP| HYPER|      |
 *                   |      |      |      |/ LOWER /         \ RAISE\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                     _______, LALT(KC_LEFT), KC_UP, LALT(KC_RIGHT), _______, _______,
  KC_F7,  KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,                       LGUI(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LGUI(KC_RIGHT), XXXXXXX,
  _______,   _______,   _______,   _______,  _______,  _______,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, LALT(KC_BSLS),
                             _______, _______, _______,  MO(_LOWER), MO(_RAISE),  _______, _______, _______
),
/* FCT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | SLEEP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | BR DW| BR UP|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MUTE |VOL DW|VOL UP|      |-------.    ,-------|      |      |PREC  | P/P  | NXT  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | LCH  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CTRL | LALT |LGUI  | /Space  /       \Enter \  |BackSP| HYPER|      |
 *                   |      |      |      |/ LOWER /         \ RAISE\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FCT] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_A, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, AL_MUTE, AL_VOLD, AL_VOLU, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _FCT);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
const char *read_keylog(void);
const char *read_keylogs(void);

bool oled_task_user(void) {
 	if (is_keyboard_master()) {
			render_os_logo();

      switch (get_highest_layer(layer_state)) {
      case _WRITE:
        oled_write_ln("WRITE", false);
        break;
      case _LOWER:
        oled_write_ln("LOWER", false);
        break;
      case _RAISE:
        oled_write_ln("RAISE", false);
        break;
      case _FCT:
        oled_write_ln("FCT  ", false);
        break;
      default:
        oled_write_ln("Undef-1", false);
        break;
    }

		static char wpm_str[4];
  	sprintf(wpm_str, "%03d", get_current_wpm());
		oled_write_ln("wpm:", false);
		oled_write(wpm_str, false);
		
		render_luna(0,13);
  } else {
    render_space();
  }
	return true;
}
#endif // OLED_ENABLE

void toggle_layer(void) {
    if (is_base_layer) {
        layer_on(_WRITE);
        layer_off(_FCT);
    } else {
        layer_on(_FCT);
        layer_off(_WRITE);
    }
    is_base_layer = !is_base_layer; // Toggle the layer state
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		case KC_LCTL:
		case KC_RCTL:
			if (record->event.pressed) {
				isSneaking = true;
			} else {
				isSneaking = false;
			}
			break;
		case KC_SPC:
			if (record->event.pressed) {
				isJumping  = true;
				showedJump = false;
			} else {
				isJumping = false;
			}
			break;
	}
    return true;
}
