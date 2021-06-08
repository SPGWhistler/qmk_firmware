/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define MOONLANDER_USER_LEDS
#undef TAPPING_TERM
#define TAPPING_TERM 230

#define USB_SUSPEND_WAKEUP_DELAY 0
#define RGB_MATRIX_STARTUP_SPD 60

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(CLUEBOARD_SOUND)
  #define GOODBYE_SONG SONG(CLUEBOARD_SOUND)
#endif
