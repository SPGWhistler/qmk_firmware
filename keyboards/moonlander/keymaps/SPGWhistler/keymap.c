#include QMK_KEYBOARD_H
#include "version.h"


enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                          KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           LALT(LCTL(LGUI(LSFT(KC_S)))),                            TD(DANCE_1),    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           LALT(LCTL(LGUI(LSFT(KC_M)))),                            TD(DANCE_2),    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           TD(DANCE_0),    KC_V,           KC_B,                                                                                    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        LM(1,MOD_LGUI),                 LCTL(LGUI(LSFT(KC_SPACE))),         LALT(LCTL(LGUI(LSFT(KC_SPACE)))),                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_BSPACE,  MO(1),  MO(2),      LGUI(KC_SPACE),  KC_ENTER,  KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    LALT(LCTL(LGUI(LSFT(KC_L)))), KC_NO,                        KC_NO,          KC_NO,                        KC_NO,                   KC_NO,          RGB_VAD,                                   RGB_VAI,           KC_NO,                    KC_NO,                    KC_NO,                  KC_NO,                  KC_NO,                  RESET,
    KC_TAB,                       KC_NO,                        KC_NO,          LALT(LCTL(LGUI(LSFT(KC_3)))), KC_LBRACKET,             KC_RBRACKET,    RGB_TOG,                                   KC_AUDIO_VOL_UP,   LCTL(LGUI(LSFT(KC_TAB))), LCTL(LGUI(LSFT(KC_TAB))), LCTL(LGUI(KC_TAB)),     LCTL(LGUI(KC_TAB)),     KC_NO,                  KC_NO,
    KC_NO,                        LALT(LCTL(LGUI(LSFT(KC_1)))), KC_NO,          KC_NO,                        KC_LCBR,                 KC_RCBR,        RGB_MOD,                                   KC_AUDIO_VOL_DOWN, KC_LEFT,                  KC_DOWN,                  KC_UP,                  KC_RIGHT,               KC_NO,                  KC_NO,
    KC_LSHIFT,                    KC_NO,                        KC_NO,          LALT(LCTL(LGUI(LSFT(KC_2)))), TD(DANCE_3),             KC_RABK,                                                                      LGUI(LSFT(KC_GRAVE)),     LGUI(LSFT(KC_GRAVE)),     LGUI(KC_GRAVE),         LGUI(KC_GRAVE),         LALT(LCTL(LGUI(KC_6))), LALT(LCTL(LGUI(KC_7))),
    KC_NO,                        KC_NO,                        KC_NO,          KC_NO,                        KC_TRANSPARENT,                          KC_NO,                                                 KC_NO,                           LALT(LCTL(LGUI(KC_2))),   LALT(LCTL(LGUI(KC_1))), LALT(LCTL(LGUI(KC_3))), LALT(LCTL(LGUI(KC_4))), LALT(LCTL(LGUI(KC_5))),
                                                                                                                                                       KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, LALT(LCTL(LGUI(KC_8)))
  ),
  [2] = LAYOUT_moonlander(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_NO, KC_NO, KC_7,  KC_8,  KC_9,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_NO, KC_NO, KC_4,  KC_5,  KC_6,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_NO, KC_1,  KC_2,  KC_3,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,                                KC_NO,        KC_0,  KC_0,  KC_DOT, KC_NO, KC_NO,
                                              KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
  ),
};


extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

#define red {0, 255, 255}
#define blue {173, 255, 255}
#define green {100, 255, 255}
#define yellow {50, 255, 255}
#define orange {255, 255, 255}
#define black {0, 0, 0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {
           //Left hand, columns 1 - 6
           //lock screen, tab, no, lshift, no
           red, green, black, green, black,
           //no, no, anfn, no, no
           black, black, yellow, black, black,
           //no, no, no, no, no
           black, black, black, black, black,
           //no, fre, no, cig, no
           black, yellow, black, yellow, black,
           //no, [, {, = +, lcmd+layer 1
           black, green, green, orange, red,
           //no, ], }, >
           black, green, green, green,

           //Left hand, column 7
           //brightness down, toggle leds, toggle pattern
           blue, blue, blue,

           //Left hand, 3 thumb, paddle
           //no, layer 1, no, no
           black, red, black, black,

           //Right hand, columns 1 - 6 (right to left)
           //reset, no, no, Wally, iTerm
           red, black, black, yellow, yellow,
           //no, no, no, Notes, Eclipse
           black, black, black, yellow, yellow,
           //no, next tab, left, next win, VSCode
           black, green, green, green, yellow,
           //no, next tab, up, next win, Zoom
           black, green, green, green, yellow,
           //no, prev tab, down, prev win, Slack
           black, green, green, green, yellow,
           //no, prev tab, left, prev win
           black, green, green, green,

           //Right hand, column 7
           //brightness up, vol up, vol down
           blue, blue, blue,

           //Right hand, 3 thumb, paddle
           //Chrome, no, no, no
           yellow, black, black, black
        },

    [2] = {
            //Left hand, columns 1 - 6
            black, black, black, black, black,
            black, black, black, black, black,
            black, black, black, black, black,
            black, black, black, black, black,
            black, black, black, black, black,
            black, black, black, black,

            //Left hand, column 7
            black, black, black,

            //Left hand, 3 thumb, paddle
            black, black, black, black,

            //Right hand, columns 1 - 6 (right to left)
            black, black, black, black, black,
            black, black, black, black, black,
            black, yellow, yellow, yellow, yellow,
            black, yellow, yellow, yellow, yellow,
            black, yellow, yellow, yellow, yellow,
            black, black, black, black,

            //Right hand, column 7
            black, black, black,

            //Right hand, 3 thumb, paddle
            black, black, black, black
        },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 1: //Nav
            set_layer_color(1);
            break;
        case 2: //Num
            set_layer_color(2);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    switch (get_highest_layer(state)) {
        //Not using ML_LED_2 and ML_LED_5 (the green ones)
        case 1: //Blue Nav Layer
            ML_LED_1(1); //left, blue
            ML_LED_4(1); //right, blue
            break;
        case 2: //Red Num Layer
            ML_LED_3(1); //left, red
            ML_LED_6(1); //right, red
            break;
        default:
            break;
    }

    return state;
}

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if (state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_C);
            break;
        case DOUBLE_TAP:
            register_code16(LCTL(KC_C));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_C);
            register_code16(KC_C);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        case DOUBLE_TAP:
            unregister_code16(LCTL(KC_C));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
    }
    if (state->count > 3) {
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LCTL(LGUI(LSFT(KC_P)))));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
            register_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LCTL(LGUI(LSFT(KC_P)))));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LALT(LCTL(LGUI(LSFT(KC_N)))));
            break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_KP_PLUS));
        tap_code16(LGUI(KC_KP_PLUS));
        tap_code16(LGUI(KC_KP_PLUS));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_KP_PLUS));
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_KP_PLUS));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(KC_KP_MINUS));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_KP_PLUS));
            register_code16(LGUI(KC_KP_PLUS));
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_KP_PLUS));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(KC_KP_MINUS));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_KP_PLUS));
            break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if (state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_EQUAL);
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_EQUAL);
            register_code16(KC_EQUAL);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_EQUAL);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_EQUAL);
            break;
    }
    dance_state[3].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};
