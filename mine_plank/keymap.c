#include "preonic.h"
#include "action_layer.h"
//#include "eeconfig.h"

/*
#define _DVORAK 0
#define _LOWER 14
#define _RAISE 15
#define _ADJUST 16
*/
enum preonic_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};


enum preonic_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  COPY,
  PASTE,
  LOCK,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Music
#define ZELDAT M(ZELDA_TREASURE)
#define ZELDAP M(ZELDA_PUZZLE)
#define SONICR M(SONIC_RING)
#define MARIOO M(ONE_UP_SOUND)
#define MARIOC M(COIN_SOUND)
#define BASKETC M(BASKET_CASE)
#define IMPERIALM M(IMPERIAL_MARCH)
#define ODE M(ODE_TO_JOY)
#define CLOSE M(CLOSE_ENCOUNTERS_5_NOTE)
#define CLUEB M(CLUEBOARD_SOUND)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |ZELDAT|ZELDAP|SONICR|MARIOU|MARIOC|BSKETC|IMPMRC|ODEJOY|CLOSEE|CLUEBS|______|______|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Raise |    Space    |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {M(20), M(21), M(22), M(23),  M(24), M(25),M(26),M(27),M(28),M(29), _______, _______},
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {_______, KC_LCTL, KC_LALT, KC_LGUI, RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Raise |    Space    |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {_______, _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {_______, KC_LCTL, KC_LALT, KC_LGUI, RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______},
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | COPY |PASTE |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
	{_______, _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______},
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, COPY    , PASTE, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | LOCK |      |             |      |BCKLIT|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
	{_______, _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______},
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP,  _______,   QWERTY, DVORAK,   _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, LOCK,  _______, _______, _______, _______, BACKLIT, _______, _______, _______}
}

};


/*
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
*/

#ifdef AUDIO_ENABLE
float start_up[][2] = {
   MUSICAL_NOTE(_B5, 20),
   MUSICAL_NOTE(_B6, 8),
   MUSICAL_NOTE(_DS6, 20),
   MUSICAL_NOTE(_B6, 8),
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
//float tone_qwerty_split[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
//float tone_dvorak_split[][2]     = SONG(DVORAK_SOUND);


float tone_zeldat[][2] = SONG(ZELDA_TREASURE);
float tone_zeldap[][2] = SONG(ZELDA_PUZZLE);
float tone_sonicr[][2] = SONG(SONIC_RING);
float tone_marioo[][2] = SONG(ONE_UP_SOUND);
float tone_marioc[][2] = SONG(COIN_SOUND);
float tone_basketc[][2] = SONG(BASKET_CASE);
float tone_imperialm[][2] = SONG(IMPERIAL_MARCH);
float tone_ode[][2] = SONG(ODE_TO_JOY);
float tone_close[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
float tone_clueb[][2] = SONG(CLUEBOARD_SOUND);

float goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case LOCK:
          if (record->event.pressed) {
			      SEND_STRING(SS_LGUI(SS_LSFT(SS_LCTRL("w"))));
          }
          return false;
          break;
        case COPY:
          if (record->event.pressed) {
			      SEND_STRING(SS_LCTRL("c"));
          }
          return false;
          break;
        case PASTE:
          if (record->event.pressed) {
			      SEND_STRING(SS_LCTRL("v"));
          }
          return false;
          break;
    		case BACKLIT:
    		  if (record->event.pressed) {
    			  register_code(KC_RSFT);
    			#ifdef BACKLIGHT_ENABLE
    			  backlight_step();
    			#endif
    			PORTE &= ~(1<<6);
    		  } else {
    			  unregister_code(KC_RSFT);
    			PORTE |= (1<<6);
    		  }
    		  return false;
    		  break;        
        case 20:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_zeldat);
            #endif
          }
          break;
        case 21:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_zeldap);
            #endif
          }
          break;
        case 22:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_sonicr);
            #endif
          }
          break;
        case 23:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_marioo);
            #endif
          }
          break;
        case 24:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_marioc);
            #endif
          }
          break;
        case 25:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_basketc);
            #endif
          }
          break;
        case 26:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_imperialm);
            #endif
          }
          break;
        case 27:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_ode);
            #endif
          }
          break;
        case 28:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_close);
            #endif
          }
          break;
        case 29:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_clueb);
            #endif
          }
          break;
    return true;
};

void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(start_up);
  #endif
}

#ifdef AUDIO_ENABLE

void play_goodbye_tone(void)
{
  PLAY_SONG(goodbye);
  _delay_ms(150);
}

#endif

