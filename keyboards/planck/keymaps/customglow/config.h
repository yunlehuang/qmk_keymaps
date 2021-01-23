#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 170

#define PERMISSIVE_HOLD

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 2

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 3

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 200

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60

#define FIRMWARE_VERSION u8"zrEAa/Eo6G5"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 2


#define PLANCK_EZ_LED_LOWER 2
#define PLANCK_EZ_LED_RAISE 3
#define PLANCK_EZ_LED_ADJUST 4