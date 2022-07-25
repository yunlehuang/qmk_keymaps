/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Mousekey options

// mk_combined left commented until bug is fixed in QMK.
// #define MK_COMBINED

#define MOUSEKEY_DELAY              0
#define MOUSEKEY_INTERVAL           5     // lower is faster
#define MOUSEKEY_MOVE_DELTA         3     // higher is faster
#define MOUSEKEY_MAX_SPEED          10
#define MOUSEKEY_TIME_TO_MAX        150

#define MOUSEKEY_WHEEL_DELAY        0
#define MOUSEKEY_WHEEL_INTERVAL     100   // lower is faster
#define MOUSEKEY_WHEEL_MAX_SPEED    100   // not really sure what this does
#define MOUSEKEY_WHEEL_TIME_TO_MAX  0     // zero means constant

// combo settings

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_TERM 45

#define LEADER_TIMEOUT 300 


#define RGBLIGHT_ANIMATIONS

#define NO_ACTION_ONESHOT