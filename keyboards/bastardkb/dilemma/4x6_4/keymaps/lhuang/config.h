#pragma once


#define TAPPING_TERM 150
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Mousekey options

// TODO: Add MK_COMBINED when the bug in qmk gets fixed.
// #define MK_COMBINED

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

#define LEADER_TIMEOUT 350 


#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE