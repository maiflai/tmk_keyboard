static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  KEYMAP( // Layer 0
  // Left hand
  ESC,    1,    2,    3,    4,    5,  ESC,
    TAB,    Q,    W,    F,    P,    G,  EQL,
  LCTRL,    A,    R,    S,    T,    D,
   LSFT,    Z,    X,    C,    V,    B, FN11,
   FN16, LGUI, TRNS, LALT,  FN0,
                                       NUHS,  INS,
                                             HOME,
                                  SPC,  ENT,  END,

  // Right hand
          ESC,    6,    7,    8,    9,    0, ESC,
         MINS,    J,    L,    U,    Y, SCLN, NUBS,
                  H,    N,    E,    I,    O, QUOT,
         FN12,    K,    M, COMM,  DOT, SLSH, RSFT,
                      FN0, LEFT, DOWN,   UP, RGHT,
   INS, RGUI,
   PGUP,
   PGDN,  DEL, BSPC),

  KEYMAP( // Layer 1
  // Left hand
   FN15,   F1,   F2,   F3,   F4,   F5,  F11,
   TRNS, NUBS, SLSH, LBRC, RBRC,  GRV, TRNS,
   TRNS, FN13, FN14,  FN9, FN10, NUHS,
   TRNS,  FN1,  FN2,  FN3,  FN4,  FN5, TRNS,
   TRNS, TRNS, TRNS, TRNS, TRNS,
                                       TRNS, TRNS,
                                             TRNS,
                                 HOME, PGDN, TRNS,

  // Right hand
          F12,   F6,   F7,   F8,   F9,  F10, FN18,
         TRNS,   NO,   NO,   NO,   NO,   NO, TRNS,
               LEFT, DOWN,   UP, RGHT, TRNS, TRNS,
         TRNS,  FN6,  FN7,  FN8,  FN9, FN10, TRNS,
                     TRNS, HOME, PGDN, PGUP,  END,
   TRNS, TRNS,
   TRNS,
   TRNS, PGUP,  END),

  KEYMAP( // Layer 2
  // Left hand
   FN17, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
   PSCR, BTN1, MS_U, BTN2, TRNS, TRNS, TRNS,
   TRNS, MS_L, MS_D, MS_R, TRNS, TRNS,
   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
   TRNS, TRNS, TRNS, TRNS, TRNS,
                                       TRNS, TRNS,
                                             TRNS,
                                 TRNS, TRNS, TRNS,

  // Right hand
         NLCK, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
         CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
               TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
         SLCK, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                     TRNS, TRNS, TRNS, TRNS, TRNS,
   TRNS, TRNS,
   TRNS,
   TRNS, TRNS, TRNS)
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
};

static const uint16_t PROGMEM fn_actions[] = {
  ACTION_LAYER_MOMENTARY(1),
  ACTION_MODS_KEY(MOD_LSFT, KC_1),
  ACTION_MODS_KEY(MOD_LSFT, KC_2),
  ACTION_MODS_KEY(MOD_LSFT, KC_3),
  ACTION_MODS_KEY(MOD_LSFT, KC_4),
  ACTION_MODS_KEY(MOD_LSFT, KC_5),
  ACTION_MODS_KEY(MOD_LSFT, KC_6),
  ACTION_MODS_KEY(MOD_LSFT, KC_7),
  ACTION_MODS_KEY(MOD_LSFT, KC_8),
  ACTION_MODS_KEY(MOD_LSFT, KC_9),
  ACTION_MODS_KEY(MOD_LSFT, KC_0),
  ACTION_MODS_KEY(MOD_LSFT, KC_COMM),
  ACTION_MODS_KEY(MOD_LSFT, KC_DOT),
  ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
  ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
  ACTION_MODS_KEY(MOD_LGUI, KC_L),
  ACTION_LAYER_MOMENTARY(2),
  ACTION_MODS_KEY(MOD_LALT, KC_PSCR),
  ACTION_FUNCTION(TEENSY_KEY),
};


void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}