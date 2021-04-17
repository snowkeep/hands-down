#include QMK_KEYBOARD_H


#define _HANDSDOWN 0
#define _DVORAK 1
#define _QWERTY 2
#define _NAV 3
#define _FUNC 4
#define _ADJUST 5

enum custom_keycodes {
  HANDSDOWN = SAFE_RANGE,
  DVORAK,
  QWERTY,
  NAV,
  FUNC,
  ADJUST
};

// home-row tap-holds - Hands Down
#define GUI_R LGUI_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define CTR_N LCTL_T(KC_N)
#define SHF_T LSFT_T(KC_T)
#define AGR_B RALT_T(KC_B)
#define SFT_U RSFT_T(KC_U)
#define CTR_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_A RGUI_T(KC_A)
#define AGR_D RALT_T(KC_DOT)

// home-row tap-holds - Dvorak
#define ALT_O LALT_T(KC_O)
#define AGR_Q RALT_T(KC_Q)
#define SFT_H RSFT_T(KC_H)
#define CTR_T RCTL_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)
#define AGR_V RALT_T(KC_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_HANDSDOWN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_C,    KC_H,    KC_M,    KC_Z,                               KC_V,    KC_K,    KC_O,    KC_J,    KC_SCLN, KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  GUI_R,   ALT_S,   CTR_N,   SHF_T,   KC_P,                               KC_W,    SFT_U,   CTR_E,   ALT_I,   GUI_A,   KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_X,    AGR_B,   KC_L,    KC_D,    KC_G,    KC_HOME,          KC_END,  KC_Y,    KC_F,    KC_COMM, AGR_D,   KC_QUOT, KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_DEL,  NAV,     KC_SPC,                    KC_ENT,  FUNC,    KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  GUI_A,   ALT_O,   CTR_E,   SFT_U,   KC_I,                               KC_D,    SFT_H,   CTR_T,   ALT_N,   GUI_S,   KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_SCLN, AGR_Q,   KC_J,    KC_K,    KC_X,    KC_HOME,          KC_END,  KC_B,    KC_M,    KC_W,    AGR_V,   KC_Z,    KC_RBRC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_DEL,  NAV,     KC_SPC,                    KC_ENT,  FUNC,    KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, NAV,     KC_SPC,                    KC_ENT,  FUNC,    KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PAUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, KC_LPRN,                            KC_RPRN, KC_7,    KC_8,    KC_9,    KC_MINS, KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC,                            KC_RBRC, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, XXXXXXX, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  KC_0,    KC_DOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, HANDSDOWN,        DVORAK,  KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HANDSDOWN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_HANDSDOWN);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_NAV, _FUNC, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_NAV, _FUNC, _ADJUST);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
        update_tri_layer(_NAV, _FUNC, _ADJUST);
      } else {
        layer_off(_FUNC);
        update_tri_layer(_NAV, _FUNC, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

enum combo_events {
  HD_QWERTY,
  XB_UNDO,
  BL_CUT,
  LD_COPY,
  DG_PASTE
};

const uint16_t PROGMEM qwerty_combo[] = {KC_GRV, KC_BSLS, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_X, KC_B, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_B, KC_L, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_D, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [HD_QWERTY] = COMBO_ACTION(qwerty_combo),
  [XB_UNDO] = COMBO_ACTION(undo_combo),
  [BL_CUT] = COMBO_ACTION(cut_combo),
  [LD_COPY] = COMBO_ACTION(copy_combo),
  [DG_PASTE] = COMBO_ACTION(paste_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case HD_QWERTY:
      if (pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case XB_UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case BL_CUT:
      if (pressed) {
        tap_code16(LCTL(KC_X));
      }
      break;
    case LD_COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case DG_PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
  }
}

const key_override_t swap_scolon = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN);
const key_override_t swap_colon = ko_make_basic(KC_NO, KC_SCLN, S(KC_SCLN));

const key_override_t **key_overrides = (const key_override_t *[]){
  &swap_scolon,
  &swap_colon,
  NULL
};
