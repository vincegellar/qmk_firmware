#include QMK_KEYBOARD_H
#include "split_util.h"

extern keymap_config_t keymap_config;

enum bfo9000_layers {
  _QWERTY,    // Qwerty
  _GIT,       // Git
  _GAME       // Game
};

enum bfo9000_keycodes {
  QWERTY = SAFE_RANGE,
  GIT,
  GAME,
  ZEROES,
  STATUS,
  LOG,
  STASH,
  POP,
  PULL,
  FETCH,
  REBASE,
  ADD,
  COMMIT,
  AMEND,
  PUSH,
  CHECKOUT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
  ,-----------------------------------------------------------------------.          ,-----------------------------------------------------------------------. 
  | NUMLK |   /   |  ESC  |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |          |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  | PrtSc |Page Up|Page Dn|
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  MUTE |  VOL- |  VOL+ |   ~   |   1   |   2   |   3   |   4   |   5   |          |   6   |   7   |   8   |   9   |   0   |   -   |   =   |Backspc|  NOP  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   7   |   8   |   9   |  TAB  |   Q   |   W   |   E   |   R   |   T   |          |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |  NOP  |  DEL  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   4   |   5   |   6   |   *   |   A   |   S   |   D   |   F   |   G   |          |   H   |   J   |   K   |   L   |   :   |   "   |   ~   | ENTER |  Home |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   1   |   2   |   3   | SHIFT |   \   |   Z   |   X   |   C   |   V   |          |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |   Up  |  End  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   00  |   0   |   .   |  CTRL |  APP  |  ALT  |  NOP  | SPACE |  NOP  |          |  NOP  | SPACE |  NOP  | AltGr |   FN  |  Ctrl |  Left |  Down | Right |
  `-----------------------------------------------------------------------'          `-----------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT(
  KC_NLCK, KC_PSLS, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PGUP, KC_PGDN,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,  
  KC_P7,   KC_P8,   KC_P9,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NO,   KC_DEL,    
  KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,  
  KC_P1,   KC_P2,   KC_P3,   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,   
  ZEROES,  KC_P0,   KC_PDOT, KC_LCTL, KC_APP,  KC_LALT, KC_NO,   KC_SPC,  KC_NO,       KC_NO,   KC_SPC,  KC_NO,   KC_ALGR, GIT,     KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
),

/* GIT
  ,-----------------------------------------------------------------------.          ,-----------------------------------------------------------------------. 
  |  PLAY |   /   |  ESC  |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |          |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  | PrtSc |Page Up|Page Dn|
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  MUTE |  VOL- |  VOL+ |   ~   |   1   |   2   |   3   |   4   |   5   |          |   6   |   7   |   8   |   9   |   0   |   -   |   =   |Backspc|  NOP  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   7   |   8   |   9   |  TAB  |   Q   |   W   |   E   |   R   |   T   |          |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |  NOP  |  DEL  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   4   |   5   |   6   |   *   |   A   |   S   |   D   |   F   |   G   |          |   H   |   J   |   K   |   L   |   :   |   "   |   ~   | ENTER |  Home |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |   1   |   2   |   3   | SHIFT |   \   |   Z   |   X   |   C   |   V   |          |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |   Up  |  End  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  LOG  |   0   |   .   |  CTRL |  APP  |  ALT  |  NOP  | SPACE |  NOP  |          |  NOP  | SPACE |  NOP  | AltGr |   FN  |  Ctrl |  Left |  Down | Right |
  `-----------------------------------------------------------------------'          `-----------------------------------------------------------------------'
*/
[_GIT] = LAYOUT(
  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  AMEND,   PUSH,    CHECKOUT,_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  REBASE,  ADD,     COMMIT,  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  POP,     PULL,    FETCH,   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  LOG,     STATUS,  STASH,   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, GAME,    _______, _______, _______, _______
),

/* GAME
  ,-----------------------------------------------------------------------.          ,-----------------------------------------------------------------------. 
  | NUMLK |   /   |  ESC  |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |          |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  | PrtSc |Page Up|Page Dn|
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  MUTE |  VOL- |  VOL+ |   ~   |   1   |   2   |   3   |   4   |   5   |          |   6   |   7   |   8   |   9   |   0   |   -   |   =   |Backspc|  NOP  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  F22  |  F23  |  F24  |  TAB  |   Q   |   W   |   E   |   R   |   T   |          |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |  NOP  |  DEL  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  F19  |  F20  |  F21  |   *   |   A   |   S   |   D   |   F   |   G   |          |   H   |   J   |   K   |   L   |   :   |   "   |   ~   | ENTER |  Home |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  F16  |  F17  |  F18  | SHIFT |   \   |   Z   |   X   |   C   |   V   |          |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |   Up  |  End  |
  |-------+-------+-------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+-------+-------+-------|
  |  F13  |  F14  |  F15  |  CTRL |  APP  |  ALT  |  NOP  | SPACE |  NOP  |          |  NOP  | SPACE |  NOP  | AltGr |   FN  |  Ctrl |  Left |  Down | Right |
  `-----------------------------------------------------------------------'          `-----------------------------------------------------------------------'
*/
[_GAME] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F22,  KC_F23,  KC_F24,  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F19,  KC_F20,  KC_F21,  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F16,  KC_F17,  KC_F18,  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F13,  KC_F14,  KC_F15,  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, QWERTY,  _______, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        default_layer_set(1UL << _QWERTY);
        layer_off (_GIT);
        layer_off (_GAME);
      }
      return false;
      break;
    case GIT:
      if (record->event.pressed) {
        layer_on(_GIT);
        layer_off (_GAME);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
        layer_off (_GIT);
      }
      return false;
      break;
    case ZEROES:
      if (record->event.pressed) {
        SEND_STRING("``");
      }
      return false;
      break;
    case STATUS:
      if (record->event.pressed) {
        SEND_STRING("git status\n");
      }
      return false;
      break;
    case LOG:
      if (record->event.pressed) {
        SEND_STRING("git log\n");
      }
      return false;
      break;
    case STASH:
      if (record->event.pressed) {
        SEND_STRING("git stash\n");
      }
      return false;
      break;
    case POP:
      if (record->event.pressed) {
        SEND_STRING("git stash pop\n");
      }
      return false;
      break;
    case PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull\n");
      }
      return false;
      break;
    case FETCH:
      if (record->event.pressed) {
        SEND_STRING("git fetch\n");
      }
      return false;
      break;
    case REBASE:
      if (record->event.pressed) {
        SEND_STRING("git rebase\n");
      }
      return false;
      break;
    case ADD:
      if (record->event.pressed) {
        SEND_STRING("git add .\n");
      }
      return false;
      break;
    case COMMIT:
      if (record->event.pressed) {
        SEND_STRING("git commit /m @@" SS_TAP(X_LEFT));
      }
      return false;
      break;
    case AMEND:
      if (record->event.pressed) {
        SEND_STRING("git commit //amend\n");
      }
      return false;
      break;
    case PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push\n");
      }
      return false;
      break;
    case CHECKOUT:
      if (record->event.pressed) {
        SEND_STRING("git checkout // .\n");
      }
      return false;
      break;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  //if (!is_keyboard_master())
  return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
  //return rotation;
}

static void render_status(void) {
  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
  oled_write_P(PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
  oled_write_P(PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("LAYER"), false);
  switch (layer_state) {
    case 1UL << _GIT:
      oled_write_ln_P(PSTR("Git"), false);
      break;
    case 1UL << _GAME:
      oled_write_ln_P(PSTR("Macro"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Base"), false);
      break;
  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else
  {
    
  }
}
#endif
