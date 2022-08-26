#pragma once

#define MASTER_LEFT

#define USE_SERIAL_PD2

#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Mousekey options



#define MOUSEKEY_DELAY              0
#define MOUSEKEY_INTERVAL           5     // lower is faster
#define MOUSEKEY_MOVE_DELTA         3     // higher is faster
#define MOUSEKEY_MAX_SPEED          10
#define MOUSEKEY_TIME_TO_MAX        150

#define MOUSEKEY_WHEEL_DELAY        0
#define MOUSEKEY_WHEEL_INTERVAL     100   // lower is faster
#define MOUSEKEY_WHEEL_MAX_SPEED    4   // not really sure what this does
#define MOUSEKEY_WHEEL_TIME_TO_MAX  40     // zero means constant

// combo settings

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_TERM 45


// leader settings
#define LEADER_TIMEOUT 350