#include QMK_KEYBOARD_H
#include "version.h"


enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
};

//Redefine all the constants I need to make them an even number of spaces.
enum custom_keycodes {
    TP_____NO = KC_NO,
    TP_______ = KC_NO,
    TP_TRANSP = KC_TRANSPARENT,
    TP_RGBSLD = ML_SAFE_RANGE,
    TP_BSLASH = KC_BSLASH,
    TP_BSPACE = KC_BSPACE,
    TP__COMMA = KC_COMMA,
    TP____DOT = KC_DOT,
    TP__ENTER = KC_ENTER,
    TP_ESCAPE = KC_ESCAPE,
    TP__GRAVE = KC_GRAVE,
    TP___LALT = KC_LALT,
    TP__LCTRL = KC_LCTRL,
    TP___LGUI = KC_LGUI,
    TP_LSHIFT = KC_LSHIFT,
    TP__MINUS = KC_MINUS,
    TP___PLUS = KC_KP_PLUS,
    TP__QUOTE = KC_QUOTE,
    TP_RSHIFT = KC_RSHIFT,
    TP_SCOLON = KC_SCOLON,
    TP__SLASH = KC_SLASH,
    TP__SPACE = KC_SPACE,
    TP____TAB = KC_TAB,
    TP__LBRKT = KC_LBRACKET,
    TP___LCBR = KC_LCBR,
    TP__RBRKT = KC_RBRACKET,
    TP___RCBR = KC_RCBR,
    TP___RABK = KC_RABK,
    TP___LEFT = KC_LEFT,
    TP__RIGHT = KC_RIGHT,
    TP_____UP = KC_UP,
    TP___DOWN = KC_DOWN,
    TP__EQUAL = KC_EQUAL,
    TP_DNCE00 = TD(DANCE_0),
    TP_DNCE01 = TD(DANCE_1),
    TP_DNCE02 = TD(DANCE_2),
    TP_DNCE03 = TD(DANCE_3),
    TP___MO01 = MO(1),
    TP___MO02 = MO(2),
    TP_LGUISP = LGUI(KC_SPACE),
    TP___LGRV = LGUI(KC_GRAVE),
    TP_LMMGUI = LM(1,MOD_LGUI),
    TP__LLGRV = LGUI(LSFT(KC_GRAVE)),
    TP___LLTB = LCTL(LGUI(KC_TAB)),
    TP__LLLTB = LCTL(LGUI(LSFT(KC_TAB))),
    TP__LLLSP = LCTL(LGUI(LSFT(KC_SPACE))),
    TP___LLL1 = LALT(LCTL(LGUI(KC_1))),
    TP___LLL2 = LALT(LCTL(LGUI(KC_2))),
    TP___LLL3 = LALT(LCTL(LGUI(KC_3))),
    TP___LLL4 = LALT(LCTL(LGUI(KC_4))),
    TP___LLL5 = LALT(LCTL(LGUI(KC_5))),
    TP___LLL6 = LALT(LCTL(LGUI(KC_6))),
    TP___LLL7 = LALT(LCTL(LGUI(KC_7))),
    TP___LLL8 = LALT(LCTL(LGUI(KC_8))),
    TP_LLLLSP = LALT(LCTL(LGUI(LSFT(KC_SPACE)))),
    TP__LLLLS = LALT(LCTL(LGUI(LSFT(KC_S)))),
    TP__LLLLM = LALT(LCTL(LGUI(LSFT(KC_M)))),
    TP__LLLLL = LALT(LCTL(LGUI(LSFT(KC_L)))),
    TP__LLLL1 = LALT(LCTL(LGUI(LSFT(KC_1)))),
    TP__LLLL2 = LALT(LCTL(LGUI(LSFT(KC_2)))),
    TP__LLLL3 = LALT(LCTL(LGUI(LSFT(KC_3)))),
    TP__LLLL4 = LALT(LCTL(LGUI(LSFT(KC_4)))),
    TP_RGBVAD = RGB_VAD,
    TP_RGBTOG = RGB_TOG,
    TP_RGBMOD = RGB_MOD,
    TP_RGBVAI = RGB_VAI,
    TP__VOLUP = KC_AUDIO_VOL_UP,
    TP__VOLDN = KC_AUDIO_VOL_DOWN,
    TP__RESET = RESET,
    TP______1 = KC_1,
    TP______2 = KC_2,
    TP______3 = KC_3,
    TP______4 = KC_4,
    TP______5 = KC_5,
    TP______6 = KC_6,
    TP______7 = KC_7,
    TP______8 = KC_8,
    TP______9 = KC_9,
    TP______0 = KC_0,
    TP______A = KC_A,
    TP______B = KC_B,
    TP______C = KC_C,
    TP______D = KC_D,
    TP______E = KC_E,
    TP______F = KC_F,
    TP______G = KC_G,
    TP______H = KC_H,
    TP______I = KC_I,
    TP______J = KC_J,
    TP______K = KC_K,
    TP______L = KC_L,
    TP______M = KC_M,
    TP______N = KC_N,
    TP______O = KC_O,
    TP______P = KC_P,
    TP______Q = KC_Q,
    TP______R = KC_R,
    TP______S = KC_S,
    TP______T = KC_T,
    TP______U = KC_U,
    TP______V = KC_V,
    TP______W = KC_W,
    TP______X = KC_X,
    TP______Y = KC_Y,
    TP______Z = KC_Z,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //Base Layer
  [0] = LAYOUT_moonlander(
    TP__GRAVE, TP______1, TP______2, TP______3, TP______4, TP______5, TP_TRANSP,                       TP_TRANSP, TP______6, TP______7, TP______8, TP______9, TP______0, TP__MINUS,
    TP____TAB, TP______Q, TP______W, TP______E, TP______R, TP______T, TP__LLLLS,                       TP_DNCE02, TP______Y, TP______U, TP______I, TP______O, TP______P, TP_BSLASH,
    TP_ESCAPE, TP______A, TP______S, TP______D, TP______F, TP______G, TP__LLLLM,                       TP_DNCE01, TP______H, TP______J, TP______K, TP______L, TP_SCOLON, TP__QUOTE,
    TP_LSHIFT, TP______Z, TP______X, TP_DNCE00, TP______V, TP______B,                                             TP______N, TP______M, TP__COMMA, TP____DOT, TP__SLASH, TP_RSHIFT,
    TP__LLLL4, TP__LCTRL, TP___LALT, TP___LGUI, TP_LMMGUI,                       TP__LLLSP, TP_LLLLSP,                       TP___MO01, TP_TRANSP, TP_TRANSP, TP_TRANSP, TP_______,
                                                           TP_BSPACE, TP___MO02, TP___MO02, TP_LGUISP, TP__ENTER, TP__SPACE
  ),
  //Nav Layer
  [1] = LAYOUT_moonlander(
    TP__LLLLL, TP_______, TP_______, TP_______, TP_______, TP_______, TP_RGBVAD,                       TP_RGBVAI, TP_______, TP_______, TP_______, TP_______, TP_______, TP__RESET,
    TP____TAB, TP_______, TP_______, TP__LLLL3, TP__LBRKT, TP__RBRKT, TP_RGBTOG,                       TP__VOLUP, TP__LLLTB, TP__LLLTB, TP___LLTB, TP___LLTB, TP_______, TP_______,
    TP_______, TP__LLLL1, TP_______, TP_______, TP___LCBR, TP___RCBR, TP_RGBMOD,                       TP__VOLDN, TP___LEFT, TP___DOWN, TP_____UP, TP__RIGHT, TP_______, TP_______,
    TP_LSHIFT, TP_______, TP_______, TP__LLLL2, TP__EQUAL, TP___PLUS,                                             TP__LLGRV, TP__LLGRV, TP___LGRV, TP___LGRV, TP___LLL6, TP___LLL7,
    TP_______, TP_______, TP_______, TP_______, TP_TRANSP,                       TP_______, TP_______,                       TP_______, TP___LLL1, TP___LLL3, TP___LLL4, TP___LLL5,
                                                           TP_______, TP_______, TP_______, TP_______, TP_______, TP___LLL2
  ),
  //Num Layer
  [2] = LAYOUT_moonlander(
    TP_______, TP_______, TP_______, TP_______, TP_______, TP_______, TP_______,                       TP_______, TP_______, TP_______, TP_______, TP_______, TP_______, TP_______,
    TP_______, TP_______, TP_______, TP_______, TP_______, TP_______, TP_______,                       TP_______, TP_______, TP______7, TP______8, TP______9, TP_______, TP_______,
    TP_______, TP_______, TP_______, TP_______, TP_______, TP_______, TP_______,                       TP_______, TP_______, TP______4, TP______5, TP______6, TP_______, TP_______,
    TP_______, TP_______, TP_______, TP_______, TP_______, TP_______,                                             TP_______, TP______1, TP______2, TP______3, TP_______, TP_______,
    TP_______, TP_______, TP_______, TP_______, TP_______,                       TP_______, TP_______,                       TP______0, TP______0, TP____DOT, TP_______, TP_______,
                                                           TP_______, TP_______, TP_______, TP_______, TP_______, TP_______
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
    //Nav Layer
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

    //Num Layer
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

/*
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
*/

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
