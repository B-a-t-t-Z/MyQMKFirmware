#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 1
#define _COLEMAK 4
#define _GAME 5
#define _ARROW 12
#define _LOWER 14
#define _RAISE 15
#define _ADJUST 16

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define DVORAK M(_DVORAK)
#define COLEMAK M(_COLEMAK)
#define GAME M(_GAME)
#define ARROW M(_ARROW)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define M_BL 5

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


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |  .   |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |   -  |  =   |   [  |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC},
  {KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLASH},
  {LT(_RAISE, KC_ENT),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT},
  {KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT },
  {M(M_BL),   KC_LCTL, KC_LALT, KC_LGUI, RAISE,   LT(_LOWER, KC_SPC),  KC_SPC,  LOWER,   KC_MINUS, KC_EQUAL, KC_LBRC,  KC_RBRC}
},


/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | ` ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | ' "  | , <  | . >  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | / ?  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| ; :  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Raise |    Space    |Lower | - _  | =  + | [ {  | ] }  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,    KC_G,     KC_C,    KC_R,    KC_L,    KC_DEL},
  {KC_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,     KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,   KC_J,    KC_K,    KC_X,    KC_B,    KC_M,     KC_W,    KC_V,    KC_Z,    KC_ENT},
  {M(M_BL), KC_LCTL, KC_LALT, KC_LGUI, RAISE,   LT(_LOWER, KC_SPC),  KC_SPC,  LOWER,KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |   -  |  =   |   [  |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
   {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,      KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC},
  {KC_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______},
  {KC_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {M(M_BL), KC_LCTL, KC_LALT, KC_LGUI, RAISE,   LT(_LOWER, KC_SPC),  KC_SPC,  LOWER,  KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | BkSpc|   Up |  Del | Forwd| MBtn1|   MUp| MBtn2|   /  |   7  |   8  |  9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right| Refr  MLeft|  MDn  |MRight|   *  |   4  |   5  |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Vol+| Prev | Play | Next | Back |  MWUp| MBtn3| MWDn |  -   |   1  |  2   |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |      |      |      |      |             |      |   +  | Enter|  0   |  .   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  KC_F1,    KC_F2,   KC_F3,    KC_F4,          KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_DEL},
  {KC_MUTE, KC_BSPC,  KC_UP,   KC_DEL,   KC_WWW_FORWARD, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSLS,  KC_P7,   KC_P8,  KC_P9},
  {_______, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_WWW_REFRESH, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAST,  KC_P4,   KC_P5,  KC_P6},
  {KC_VOLU, KC_MPRV,  KC_MPLY, KC_MNXT,  KC_WWW_BACK,    KC_WH_U, KC_BTN3, KC_WH_D, KC_PMNS,  KC_P1,   KC_P2,  KC_P3},
  {KC_VOLD, _______,  _______, _______,  _______,        _______, _______, _______, KC_PPLS,  KC_PENT, KC_P0,  KC_PDOT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Bksp | PgUp |  Del |      |      |      | PgUp |  Up  | PgDn |   {  |   }  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home | PgDn |  End |      |      | Home | Left | Down | Right|   ?  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Pause| Ins  |      |      | Print|Screen| End  |      |   _  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  :   |   "  |   <  |  >   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_BSPC},
  {_______, KC_BSPC, KC_PGUP, KC_DEL,  _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN,  KC_LCBR, KC_RCBR},
  {_______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUES, KC_PIPE},
  {_______, KC_PAUSE, KC_INS, _______, KC_PSCR, KC_PSCR, _______, KC_END,  _______, KC_UNDS,  KC_PLUS, KC_ENT},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_DQT ,  KC_LT  , KC_GT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |ZELDAT|ZELDAP|SONICR|MARIOU|MARIOC|BSKETC|IMPMRC|ODEJOY|CLOSEE|CLUEBS|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud On|AudOff|MidiOn|MdiOff|qwerty|Dvorak|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus On|MusOff| Sleep| Wake | Arrow|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Reset   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {M(20), M(21), M(22), M(23),  M(24), M(25),M(26),M(27),M(28),M(29),_______,_______},
  {_______, RESET,   _______, _______, _______, _______,          _______,        _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  MI_ON,            MI_OFF,          QWERTY,  DVORAK,  _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  KC_SYSTEM_SLEEP,  KC_SYSTEM_WAKE, ARROW, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, RESET,            RESET,          _______, _______, _______, _______, _______}
}




};

const uint16_t PROGMEM fn_actions[] = {

};

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

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          break;
          /*
        case _QWERTY_SPLIT:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            persistent_default_layer_set(1UL<<_QWERTY_SPLIT);
          }
          break;
          */
        case _DVORAK:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_dvorak);
            #endif
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          break;
          /*
        case _DVORAK_SPLIT:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_dvorak_split);
            #endif
            persistent_default_layer_set(1UL<<_DVORAK_SPLIT);
          }
          break;
          */
        case _ARROW:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            persistent_default_layer_set(1UL<<_LOWER);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
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
      }
    return MACRO_NONE;
};

/*
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
*/

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

/* Qwerty_SPLIT
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  | Esc  | Bksp |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  | Tab  |  \   |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Esc  |  "   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Shift|Enter |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |   -  |  =  |   [   |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_QWERTY_SPLIT] = {
  {KC_1,        KC_2,    KC_3,    KC_4,    KC_5,          KC_ESC,         KC_BSPC,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0},
  {KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,            KC_TAB,         KC_BSLASH,   KC_Y,    KC_U,     KC_I,     KC_O,     KC_P},
  {KC_A,    KC_S,    KC_D,    KC_F,    LT(_RAISE, KC_ENT),  KC_G,           KC_H,      KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT},
  {KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,            KC_LSFT,            KC_N,        KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT },
  {M(M_BL),     KC_LCTL, KC_LALT, KC_LGUI, RAISE,           LT(_LOWER, KC_SPC), KC_SPC,      LOWER,   KC_MINUS, KC_EQUAL, KC_LBRC,  KC_RBRC}
},
*/


/* Dvorak_Split
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   `  | Bksp |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  "   |   ,  |   .  |   P  |   Y  |  Tab | Del  |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |  Esc |   /  |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  | Shift| Enter|   B  |   M  |   W  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |   -  |  =  |   [   |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_DVORAK_SPLIT] = {
  {KC_1,      KC_2,     KC_3,     KC_4,     KC_5,   KC_GRV,         KC_BSPC,  KC_6,    KC_7,      KC_8,   KC_9,     KC_0},
  {KC_QUOT,   KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_TAB,         KC_DEL,   KC_F,    KC_G,      KC_C,     KC_R,     KC_L},
  {KC_A,      KC_O,     KC_E,     KC_U,     KC_I,     KC_ESC,         KC_BSLASH,  KC_D,    KC_H,      KC_T,     KC_N,     KC_S},
  {KC_SCLN,   KC_Q,     KC_J,     KC_K,     KC_X,     KC_LSFT,        KC_ENT,   KC_B,    KC_M,      KC_W,     KC_V,     KC_Z},
  {M(M_BL),   KC_LCTL,  KC_LALT,  KC_LGUI,  RAISE,    LT(_LOWER, KC_SPC),   KC_SPC,   LOWER,   KC_MINUS,  KC_EQUAL, KC_LBRC,  KC_RBRC}
},
*/